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
#include <iostream>
#include "../Shared/common.h"

int hold()
{
	return true;
}

int main()
{
	CoInitialize(NULL);
	HWND hWnd;
	hWnd = GetForegroundWindow();
	std::vector<WindowDataClass> windowTitles;

	// std::cout << hWnd;

	getProcessInfo(hWnd, windowTitles, true);
	
	for (size_t i = 0; i < windowTitles.size(); i++)
	{
		auto elem = windowTitles[i];
		elem.print_yaml();
	}
	
	
	CoUninitialize();
}