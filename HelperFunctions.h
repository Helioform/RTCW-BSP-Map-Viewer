#pragma once

#if _WIN32 || _WIN64
#if _WIN64
#define ENV64BIT
#else
#define ENV32BIT
#endif
#endif

#include <windows.h>
#include <cassert>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <tchar.h> 
#include <stdio.h>
#include <strsafe.h>
#include <atlstr.h>

LPCWSTR StringToLPCWSTR(const std::string& s);

void HSVtoRGB(float h, float s, float v, float* rgb);
void ColorShiftLightingBytes(unsigned char in[4], unsigned char out[4]);
bool GetFileNames(const std::string& path, std::vector<std::string>& fileNames);
int StrCaseCmpN(const char *s1, const char *s2, int n);
int StrCaseCmp(const char *s1, const char *s2);