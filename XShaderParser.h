#pragma once

#include "XShader.h"


#define MAX_TOKEN_CHARS 1024

class XShaderParser
{
protected:
	std::string*				m_scriptData;
	std::vector<int>			m_surfaceParams;
	std::vector<std::string>	m_textureMapNames;
	std::vector<std::string>	m_tokens;
	int							m_numTokens;
	char						m_currentToken[1024];

public:
	XShaderParser() : m_numTokens(0) { }
	XShaderParser(std::string* scriptData) { m_scriptData = scriptData; m_numTokens = 0;  }
	~XShaderParser();

	char*		SkipWhites(char* text, bool& hasNewLines);
	std::string	ParseToken(char** text, bool allowLineBreaks);
	void		Tokenize();
	bool		ParseShader(int index);
	int			FindShader(const std::string& shaderName);
	void		ParseSurfaceParams(std::string& text);
	void		ParseTextureMapNames(std::string& text);
	void		ParseBlend(std::string& text);
	void		ParseTCMod(std::string& text);
	void		ParseVector(std::string& text, float* v);
	void		BuildShader(XShader* pShader);
};

