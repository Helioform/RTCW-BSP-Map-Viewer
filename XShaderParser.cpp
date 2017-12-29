#include "XShaderParser.h"


XShaderParser::~XShaderParser()
{

}

char* XShaderParser::SkipWhites(char* text, bool & hasNewLines)
{
	char c = text[0];

	while (c <= ' ') 
	{
		if (c == '\n')
			hasNewLines = true;

		text++;
		c = *text;
	}

	return text;
}


std::string XShaderParser::ParseToken(char** text, bool allowLineBreaks)
{
	int c = 0, len;
	bool hasNewLines = false;
	char *data;
//	memset(m_currentToken, 0, MAX_TOKEN_CHARS);
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
	return std::string(m_currentToken);
}


void XShaderParser::Tokenize()
{
	int i = m_scriptData->length();
	char* text = new char[i];
	memcpy(text, m_scriptData->c_str(), i);
	std::string token = " ";
	
	m_tokens.reserve(i);

	while (i > 0)
	{
		token = ParseToken(&text, false);

		if (token != "")
		{
			m_tokens.push_back(token);
			m_numTokens++;
		}

		i = strlen(text);
	}

}


bool XShaderParser::ParseShader(int index)
{
	std::string token;
	int pos = index+1;

	std::vector<std::string>::iterator it = m_tokens.begin();
	it++;

	// make sure the syntax is valid
	if (*it != "{")
		return false;

	while (1)
	{
		token = *it;
		it++;

		if (token == "}")
		{
			break;
		}
		else if (token == "surfaceparm")
		{
			token = *it;
			it++;
			ParseSurfaceParams(token);
		}
		else if (token == "map")
		{
			token = *it; 
			it++;
			ParseTextureMapNames(token);
		}
		else
			it++;
	}
	
	return true;
}

int XShaderParser::FindShader(const std::string& shaderName)
{
	std::vector<std::string>::iterator it;

	it = std::find(m_tokens.begin(), m_tokens.end(), shaderName);
			
	if (it != m_tokens.end())
	{
		return std::distance(m_tokens.begin(), it);
	}
	
	return -1;
}

void XShaderParser::ParseSurfaceParams(std::string & text)
{
	if (text == "nodraw")
		m_surfaceParams.push_back(SURF_NODRAW);
	else if (text == "fog")
		m_surfaceParams.push_back(CONTENTS_FOG);

}

void XShaderParser::ParseTextureMapNames(std::string & text)
{
	m_textureMapNames.push_back(text);
}

void XShaderParser::ParseBlend(std::string & text)
{
}

void XShaderParser::ParseTCMod(std::string & text)
{
}

void XShaderParser::ParseVector(std::string & text, float * v)
{
}

void XShaderParser::BuildShader(XShader * pShader)
{
	for (auto i : m_surfaceParams)
		pShader->SetSurfaceFlags(i);

	for (int i = 0; i < m_textureMapNames.size(); ++i)
		pShader->SetTextureName(i, m_textureMapNames[i]);

	m_textureMapNames.clear();
	m_surfaceParams.clear();
}
