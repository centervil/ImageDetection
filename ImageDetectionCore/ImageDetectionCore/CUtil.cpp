#include "CUtil.h"

using namespace std;


CUtil::CUtil()
{
}


CUtil::~CUtil()
{
}

vector<wstring> CUtil::get_file_path_in_dir(const wstring & dir_name, const wstring & extension) noexcept(false)
{
	HANDLE hFind;
	WIN32_FIND_DATA win32fd;//defined at Windwos.h
	vector<wstring> file_names;

	//ägí£éqÇÃê›íË
	wstring search_name = dir_name + L"\\*." + extension;

	hFind = FindFirstFile(search_name.c_str(), &win32fd);

	if (hFind == INVALID_HANDLE_VALUE) {
		throw runtime_error("file not found");
	}

	do {
		if (win32fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
		}
		else {
			file_names.push_back(win32fd.cFileName);
			//printf("%s\n", file_names.back().c_str());

		}
	} while (FindNextFile(hFind, &win32fd));

	FindClose(hFind);

	return file_names;
}

wstring CUtil::ConvertToWstring(const string str)
{
	wstring wstr;
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> cv;
	wstr = cv.from_bytes(str);
	return wstr;
}

string CUtil::ConvertToString(const wstring wstr)
{
	string str;
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> cv;
	str = cv.to_bytes(wstr);
	return str;
}

int CUtil::testMethod()
{
	return 0;
}
