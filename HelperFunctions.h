#pragma once

#include <windows.h>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <tchar.h> 
#include <stdio.h>
#include <strsafe.h>
#include <atlstr.h>

#pragma comment(lib, "User32.lib")

LPCWSTR StringToLPCWSTR(const std::string& s);

void HSVtoRGB(float h, float s, float v, float* rgb);
void ColorShiftLightingBytes(unsigned char in[4], unsigned char out[4]);
bool GetFileNames(const std::string& path, std::vector<std::string>& fileNames);