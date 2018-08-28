#include "XShaderParser.h"


XShaderParser::~XShaderParser()
{

}

char* XShaderParser::SkipWhites(char* text, bool & hasNewLines)
{
	char c = text[0];

	while (c <= ' ' && c != '\0') 
	{
		if (c == '\n')
			hasNewLines = true;

		text++;
	
		c = *text;
	}

	return text;
}


char* XShaderParser::ParseToken(char** text, bool allowLineBreaks)
{
	int c = 0, len;
	bool hasNewLines = false;
	char *data;
	data = *text;
	len = 0;
	m_currentToken[0] = 0;

	// make sure incoming data is valid
	if (!data)
	{
		*text = NULL;
		return m_currentToken;
	}

	while (1)
	{
		// skip whitespace
		data = SkipWhites(data, hasNewLines);
		if (!data)
		{
			*text = NULL;
			return m_currentToken;
		}
		if (hasNewLines && !allowLineBreaks)
		{
			*text = data;
			return m_currentToken;
		}

		c = *data;

		// skip double slash comments
		if (c == '/' && data[1] == '/')
		{
			data += 2;
			while (*data && *data != '\n')
			{
				data++;
			}
		}
		// skip /* */ comments
		else if (c == '/' && data[1] == '*')
		{
			data += 2;
			while (*data && (*data != '*' || data[1] != '/'))
			{
				data++;
			}
			if (*data)
			{
				data += 2;
			}
		}
		else
		{
			break;
		}
	}

	// handle quoted strings
	if (c == '\"')
	{
		data++;
		while (1)
		{
			c = *data++;
			if (c == '\"' || !c)
			{
				m_currentToken[len] = 0;
				*text = (char *)data;
				return m_currentToken;
			}
			if (len < MAX_TOKEN_CHARS)
			{
				m_currentToken[len] = c;
				len++;
			}
		}
	}

	// parse a regular word
	do
	{
		if (len < MAX_TOKEN_CHARS)
		{
			m_currentToken[len] = c;
			len++;
		}
		data++;
		c = *data;
	
	} while (c > ' ');

	if (len == MAX_TOKEN_CHARS)
	{
		len = 0;
	}

	m_currentToken[len] = '\0';

	*text = (char *)data;
	return m_currentToken;
}


void XShaderParser::ParseShaderFile()
{
	int i = m_scriptData->length();
	char* text = new char[i];
	memcpy(text, m_scriptData->c_str(), i);
	char* token = " ";

	while (i > 0)
	{
		token = ParseToken(&text, false);
		
		if (StrCaseCmp(token, ""))
		{
			memset(m_currentShaderName, 0, MAX_TOKEN_CHARS);
			memcpy(m_currentShaderName, token, strlen(token));
			
			ParseShader(&text);
		}

		i = strlen(text);
	}

}


bool XShaderParser::ParseShader(char** text)
{
	int stack[64]; // used to parse nested bracket content
	int s = 0;
	memset(stack, 0, 64 * sizeof(int));
	char* token = ParseToken(text, false);
	int numStages = 0;
	unsigned int surfaceParams = 0, blendDest = 0, blendSrc = 0;
	float	animFreq = 0;
	std::string textureName;
	std::string animTextureNames[8];
	int numAnimTextures = 0;
	XShader sh;

	while(!StrCaseCmp(token, ""))
		token = ParseToken(text, false);

	// make sure the syntax is valid
	if (!StrCaseCmp(token, "{"))
		stack[s++] = 1;
	else
		return false;

	while(stack[0]) // while the stack is not empty
	{	
		token = ParseToken(text, false);
		
		if (!StrCaseCmp(token, ""))
			continue;

		if (!StrCaseCmp(token, "{"))
		{
			stack[s++] = 1;
			if (s >= 64)
				return false;

			numStages++;
			token = ParseToken(text, false);
		}
		else if (!StrCaseCmp(token, "}"))
		{
			stack[--s] = 0;
			if (numStages) 
			{
				if (stack[0])
				{
					TextureStage ts;
					ts.animated = false;
					ts.destBlend = blendDest;
					ts.srcBlend = blendSrc;
					ts.animFrequency = animFreq;
					ts.textureName = textureName;
					ts.numAnimTextures = numAnimTextures;
					if (numAnimTextures)
						ts.animated = true;
					for (int i = 0; i < numAnimTextures; i++)
						ts.animTexturesNames[i] = animTextureNames[i];
					sh.SetTextureStage(ts);
					animFreq = 0.0f;
					blendDest = blendSrc = 0;
					textureName = "";
					numAnimTextures = 0;
				}
			}

			token = ParseToken(text, false);
		}
		else if (!StrCaseCmp(token, "surfaceparm"))
		{	
			token = ParseToken(text, false);
			surfaceParams |= ParseSurfaceParams(token);
			token = ParseToken(text, false);
		}
		else if (!StrCaseCmp(token, "map"))
		{
			token = ParseToken(text, false);
			textureName = std::string(token);
			token = ParseToken(text, false);
		}
		else if (!StrCaseCmp(token, "animMap"))
		{
			// parse frequency
			token = ParseToken(text, false);
			animFreq = std::stof(token);
			// parse first texture name
			token = ParseToken(text, false);
			animTextureNames[numAnimTextures++] = token;
			int i = 0;

			while (token[0] == 't' && i < 7)
			{
				token = ParseToken(text, false);
				animTextureNames[numAnimTextures++] = token;
				i++;
			}

		}
		else if (!StrCaseCmp(token, "blendFunc"))
		{
			token = ParseToken(text, false);
			if (!StrCaseCmp(token, "filter"))
				continue;

			if (!StrCaseCmp(token, "add"))
				continue;

			if (!StrCaseCmp(token, "blend"))
				continue;

			if (!StrCaseCmp(token, "GL_add"))
				continue;

			blendSrc |= ParseBlend(token);
			token = ParseToken(text, false);
			blendDest |= ParseBlend(token);
			token = ParseToken(text, false);
		}
		else
		{
			token = ParseToken(text, false);
		}
	}
	
	sh.SetName(m_currentShaderName);
	sh.SetSurfaceFlags(surfaceParams);
	m_shaders[m_currentShaderName] = sh;
	m_numShaders++;

	return true;
}

bool XShaderParser::FindShader(const std::string& shaderName, XShader* sh)
{
	std::unordered_map<std::string, XShader>::const_iterator it = m_shaders.find(shaderName);

	if (it == m_shaders.end())
		return false;
	else
	{
		*sh = it->second;
		return true;
	}
}

unsigned int XShaderParser::ParseSurfaceParams(const std::string& text)
{
	if (!StrCaseCmp(text.c_str(), "nodraw"))
		return SURF_NODRAW;
	else if (!StrCaseCmp(text.c_str(), "fog"))
		return CONTENTS_FOG;

	return 0;
}

unsigned int XShaderParser::ParseBlend(const std::string & text)
{
	if (!StrCaseCmp(text.c_str(), "GL_ZERO"))
		return D3D11_BLEND_ZERO;
	else if (!StrCaseCmp(text.c_str(), "GL_ONE"))
		return D3D11_BLEND_ONE;
	else if (!StrCaseCmp(text.c_str(), "GL_DST_COLOR"))
		return D3D11_BLEND_DEST_COLOR;
	else if (!StrCaseCmp(text.c_str(), "GL_SRC_COLOR"))
		return D3D11_BLEND_SRC_COLOR;
	else if (!StrCaseCmp(text.c_str(), "GL_ONE_MINUS_DST_COLOR"))
		return D3D11_BLEND_INV_DEST_COLOR;
	else if (!StrCaseCmp(text.c_str(), "GL_SRC_ALPHA"))
		return D3D11_BLEND_SRC_ALPHA;
	else if (!StrCaseCmp(text.c_str(), "GL_ONE_MINUS_SRC_ALPHA"))
		return D3D11_BLEND_INV_SRC_ALPHA;

	return 0;
}

void XShaderParser::ParseTCMod(const std::string & text)
{
}

void XShaderParser::ParseVector(const std::string & text, float * v)
{
}

void XShaderParser::BuildShader(XShader * pShader)
{
	
}

