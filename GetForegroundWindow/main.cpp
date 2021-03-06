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

int main()
{
	HWND hWnd;
	hWnd = GetForegroundWindow();
	std::vector<WindowDataClass> windowTitles;
	
	getProcessInfo(hWnd, windowTitles);

	for (size_t i = 0; i < windowTitles.size(); i++)
	{
		auto elem = windowTitles[i];
		elem.print_yaml();
	}
    // std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
