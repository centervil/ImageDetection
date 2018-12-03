#pragma once

#include <Windows.h>
#include <vector>
#include <string>
#include <stdexcept>
#include <locale> 
#include <codecvt> 
#include <cstdio>

using namespace std;

#define WSTR2STR(x) CUtil::ConvertToString(x)
#define STR2WSTR(x) CUtil::ConvertToWstring(x)

class CUtil
{
public:
	CUtil();
	~CUtil();

	static vector<wstring> get_file_path_in_dir(const wstring& dir_name, const wstring& extension);
	static wstring ConvertToWstring(const string str);
	static string ConvertToString(const wstring wstr);
	int testMethod();

};

