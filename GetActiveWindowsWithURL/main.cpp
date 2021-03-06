#define UNICODE
#include <Windows.h>
#include <AtlBase.h>
#include <AtlCom.h>
#include <UIAutomation.h>
#include <iostream>
#include <string>
#include <vector>
#include <tchar.h>
#include <psapi.h>
#include "ChromeURL.h"
#include "enumerateProcesses.h"
#include "main.h"
#include "../Shared/common.h"


HICON fetchIcon(LPWSTR module_name) {
	TCHAR lpIconPath[MAX_PATH] = TEXT("<unknown>");
	// HICON hIcon = ExtractAssociatedIcon(GetModuleHandle(module_name), lpIconPath,);
	return NULL;
}


static BOOL CALLBACK enumWindowCallBack(HWND   hWnd, LPARAM lParam) {
	std::vector<WindowDataClass>& windowTitles = *reinterpret_cast<std::vector<WindowDataClass>*>(lParam);
	getProcessInfo(hWnd, windowTitles);
	// _tprintf(TEXT("ok"));
	return TRUE;
}



int main()
{
	CoInitialize(NULL);
	
    // getChromeUrl();
	std::vector<WindowDataClass> windowTitles;

	EnumWindows(enumWindowCallBack, reinterpret_cast<LPARAM>(&windowTitles));
	
	// std::wcout << windowTitles.size();
	for (size_t i = 0; i < windowTitles.size(); i++)
	{
		auto elem = windowTitles[i];
		
		elem.print_yaml();
	}

	// bool retflag;
	// int retval = enumerateProcessesAndPrint(retflag);
	// if (retflag) return retval;
	CoUninitialize();
	return 0;
}

