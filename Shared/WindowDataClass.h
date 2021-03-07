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

class WindowDataClass {
public:
	std::wstring title;
	DWORD  pid;
	std::wstring name;
	std::wstring pathname;
	std::wstring url = L"null";

	bool browser = false;

	WindowDataClass(std::wstring title_, DWORD  pid_, std::wstring name_, std::wstring pathname_) {
		title = title_;
		pid = pid_;
		name = name_;
		pathname = pathname_;
	}

	void print_yaml() {
		std::wcout << std::endl << "- title: \"" << title << "\"";
		std::wcout << std::endl << "  pid: " << pid;
		std::wcout << std::endl << "  name:  " << name;
		std::wcout << std::endl << "  pathname:  " << pathname;
		std::wcout << std::endl << "  url:  " << url;
		std::wcout << std::endl << "  browser:  " << (browser ? "true" : "false");
		std::wcout << std::endl;
		;
	}
};

