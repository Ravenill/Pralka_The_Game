#include "Tools.h"
#include <Windows.h>

std::wstring Str2Wstr(const std::string& string)
{
    int slenght = static_cast<int>(string.length() + 1);
    int lenght = MultiByteToWideChar(CP_ACP, 0, string.c_str(), slenght, 0, 0);

    wchar_t* buffer = new wchar_t[lenght];

    MultiByteToWideChar(CP_ACP, 0, string.c_str(), slenght, buffer, lenght);
    std::wstring wstring(buffer);

    delete[] buffer;

    return wstring;
}