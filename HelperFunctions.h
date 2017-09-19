#pragma once

#include <windows.h>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

LPCWSTR StringToLPCWSTR(const std::string& s);

void HSVtoRGB(float h, float s, float v, float rgb[3]);
void ColorShiftLightingBytes(char in[4], char out[4]);
