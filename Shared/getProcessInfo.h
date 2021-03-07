#pragma once
#include <Windows.h>
#include <AtlBase.h>
#include <AtlCom.h>
#include <UIAutomation.h>
#include <iostream>
#include <string>
#include <vector>
#include <tchar.h>
#include <psapi.h>
#include "getUrl.h"
#include "WindowDataClass.h"
#include "getChromeUrl.h"

void getProcessInfo(HWND hWnd, std::vector<WindowDataClass>& windowTitles, bool single=false) {
	TCHAR lpFilename[MAX_PATH] = TEXT("<unknown>");
	TCHAR lpExeName[MAX_PATH] = TEXT("<unknown>");
	TCHAR lpPathName[MAX_PATH] = TEXT("<unknown>");

	std::wstring name;
	std::wstring title;
	std::wstring pathname;
	std::wstring url = L"";

	DWORD pid = 0;


	if (IsWindowVisible(hWnd) && GetWindowText(hWnd, lpFilename, sizeof(lpFilename) / sizeof(TCHAR))) {
		title = std::wstring(lpFilename);

		// Fetch PID
		GetWindowThreadProcessId(hWnd, &pid);

		// Fetch Exe Name
		//GetWindowModuleFileName(hWnd, lpExeName, sizeof(lpExeName) / sizeof(TCHAR));


		HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
			PROCESS_VM_READ,
			FALSE, pid);
		if (NULL != hProcess)
		{
			HMODULE hMod;
			DWORD cbNeeded;
			if (EnumProcessModulesEx(hProcess, &hMod, sizeof(hMod), &cbNeeded, LIST_MODULES_ALL)) {
				GetModuleFileNameEx(hProcess, hMod, lpPathName, sizeof(lpPathName) / sizeof(TCHAR));
				GetModuleBaseName(hProcess, hMod, lpExeName, sizeof(lpExeName) / sizeof(TCHAR));
				name = std::wstring(lpExeName);
				pathname = std::wstring(lpPathName);
			}
			CloseHandle(hProcess);
		}
		// GetModuleFileNameEx(pid);

		auto wdc = WindowDataClass(title, pid, name, pathname);
		if (name == L"chrome.exe") {
			// url = getUrl(hWnd);
			if (single) {
				url = getChromeUrlSingle();
			}
				
			if (url != L"") {
				wdc.url = to_utf8(url);
				wdc.browser = true;
			}
		}

		// fetchIcon(lpPathName);

		windowTitles.push_back(wdc);
	};
}
