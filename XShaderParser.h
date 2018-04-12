#pragma once

#include "XShader.h"


#define MAX_TOKEN_CHARS 1024

class XShaderParser
{
protected:
	std::string*				m_scriptData;
	std::unordered_map<std::string, XShader>	m_shaders;
	int							m_numShaders;
	char						m_currentToken[MAX_TOKEN_CHARS];
	char						m_currentShaderName[MAX_TOKEN_CHARS];
public:
	XShaderParser() : m_numShaders(0) { }
	XShaderParser(std::string* scriptData) { m_scriptData = scriptData; m_numShaders = 0; }
	~XShaderParser();

	char*		SkipWhites(char* text, bool& hasNewLines);
	char*		ParseToken(char** text, bool allowLineBreaks);
	void		ParseShaderFile();
	bool		ParseShader(char** text);
	bool		FindShader(const std::string& shaderName, XShader* sh);
	unsigned int ParseSurfaceParams(const std::string& text);
	unsigned int ParseBlend(const std::string& text);
	void		ParseTCMod(const std::string& text);
	void	ParseVector(const std::string& text, float* v);
	void		BuildShader(XShader* pShader);
};

