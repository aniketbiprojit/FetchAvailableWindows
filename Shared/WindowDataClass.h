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
		std::wcout << "\n- title: " << title
			<< " \n  pid: " << pid
			<< " \n  name:  " << name
			<< " \n  pathname:  " << pathname
			<< " \n  url:  " << url
			<< " \n  browser:  " << (browser ? "true" : "false")
			<< std::endl;
		;
	}
};

