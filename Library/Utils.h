#pragma once
#include <string>

std::wstring GetEXEPath();

bool OpenLogFile(const std::string& fileName);
bool LogToFile(const std::string& s);

