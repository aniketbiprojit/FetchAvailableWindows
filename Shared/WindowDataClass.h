#pragma once
#include <Windows.h>
#include <AtlBase.h>
#include <AtlCom.h>
#include <UIAutomation.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <tchar.h>
#include <sstream>
#include <psapi.h>
#include <codecvt>


std::string escaped(const std::string& input)
{
	std::string output;
	output.reserve(input.size());
	for (const char c : input) {
		switch (c) {
		case '\a':  output += "\\a";        break;
		case '\b':  output += "\\b";        break;
		case '\f':  output += "\\f";        break;
		case '\n':  output += "\\n";        break;
		case '\r':  output += "\\r";        break;
		case '\t':  output += "\\t";        break;
		case '\v':  output += "\\v";        break;
		case '\\':  output += "\\\\";			break;
		default:    output += c;            break;
		}
	}

	return output;
}

inline std::string to_utf8(const std::wstring& str)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
	auto s = escaped(myconv.to_bytes(str));

	return s;
}

class WindowDataClass {
public:
	std::string title;
	DWORD  pid;
	std::string name;
	std::string pathname;
	std::string url = "null";

	bool browser = false;

	WindowDataClass(std::wstring title_, DWORD  pid_, std::wstring name_, std::wstring pathname_) {
		title = to_utf8(title_);
		pid = pid_;
		name = to_utf8(name_);
		pathname = to_utf8(pathname_);
	}

	void print_yaml() {
		std::cout << std::endl << "- title:  \"" << title << "\"";
		std::cout.clear();
		std::cout << std::endl << "  pid:  \"" << pid << "\"";
		std::cout.clear();
		std::cout << std::endl << "  name:  \"" << name << "\"";
		std::cout.clear();
		std::cout << std::endl << "  pathname:  \"" << pathname << "\"";;
		std::cout.clear();
		std::cout << std::endl << "  url:  \"" << url << "\"";
		std::cout.clear();
		std::cout << std::endl << "  browser:  \"" << (browser ? "true" : "false") << "\"";
		std::cout.clear();
		std::cout << std::endl;
		;
	}
};

