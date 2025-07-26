#include "Utils.h"
#include <Windows.h>
#include <fstream>

std::wstring GetEXEPath()
{
    TCHAR buffer[MAX_PATH] = { 0 };
    GetModuleFileName(NULL, buffer, MAX_PATH);
    std::wstring::size_type pos = std::wstring(buffer).find_last_of(L"\\/");
    return std::wstring(buffer).substr(0, pos);
}


bool OpenLogFile(const std::string& fileName)
{
    std::ofstream file("LOG.txt", std::ios::binary);

    if (file.is_open())
        return true;
    else
        return false;
     
}

bool LogToFile(const std::string& s)
{
    std::ofstream file("LOG.txt", std::ios::binary|std::ios::app);

    if (file.is_open())
    {
        file.write(s.c_str(), s.length());
        file.close();
        return true;
    }
    else
        return false;
}