#pragma once
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

std::wstring getUrl(HWND hwnd) {
	CComQIPtr<IUIAutomation> uia;
	if (FAILED(uia.CoCreateInstance(CLSID_CUIAutomation)) || !uia)
		return L"";

	CComPtr<IUIAutomationElement> root;
	if (FAILED(uia->ElementFromHandle(hwnd, &root)) || !root)
		return L"";

	CComPtr<IUIAutomationCondition> condition;

	//URL's id is 0xC354, or use UIA_EditControlTypeId for 1st edit box
	uia->CreatePropertyCondition(UIA_ControlTypePropertyId,
		CComVariant(0xC354), &condition);

	//or use edit control's name instead
	//uia->CreatePropertyCondition(UIA_NamePropertyId, 
	//      CComVariant(L"Address and search bar"), &condition);

	CComPtr<IUIAutomationElement> edit;
	if (FAILED(root->FindFirst(TreeScope_Descendants, condition, &edit))
		|| !edit)
		return L""; //maybe we don't have the right tab, continue...

	CComVariant url;
	edit->GetCurrentPropertyValue(UIA_ValueValuePropertyId, &url);
	std::wstring s(url.bstrVal, SysStringLen(url.bstrVal));

	// std::wcout << s;

	return s;
}
