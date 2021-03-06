#pragma once

void PrintProcessNameAndID(DWORD processID)
{
	TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");
	TCHAR lpFilename[MAX_PATH] = TEXT("<unknown>");
	// Get a handle to the process.

	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
		PROCESS_VM_READ,
		FALSE, processID);

	// Get the process name.

	if (NULL != hProcess)
	{
		HMODULE hMod;
		DWORD cbNeeded;

		if (EnumProcessModulesEx(hProcess, &hMod, sizeof(hMod), &cbNeeded, LIST_MODULES_ALL)) {
			GetModuleBaseName(hProcess, hMod, szProcessName, sizeof(szProcessName) / sizeof(TCHAR));
			GetModuleFileNameEx(hProcess, hMod, lpFilename, sizeof(lpFilename) / sizeof(TCHAR));

		}
	}

	if (_tcscmp(szProcessName, TEXT("chrome.exe")) == 0) {
		//	_tprintf(TEXT("ok"));
	}

	if (_tcscmp(szProcessName, TEXT("<unknown>")) != 0) {
		_tprintf(TEXT("{\"name\":\"%s\",\"filename\":\"%s\",\"PID\": \"%u\"}\n"), szProcessName, lpFilename, processID);
	}

	// Release the handle to the process.

	CloseHandle(hProcess);
}

inline int enumerateProcessesAndPrint(bool &retflag)
{
	retflag = true;
	DWORD aProcesses[1024], cbNeeded, cProcesses;
	unsigned int i;

	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
	{
		return 1;
	}


	// Calculate how many process identifiers were returned.

	cProcesses = cbNeeded / sizeof(DWORD);

	// Print the name and process identifier for each process.

	for (i = 0; i < cProcesses; i++)
	{
		if (aProcesses[i] != 0)
		{
			PrintProcessNameAndID(aProcesses[i]);
		}
	}
	retflag = false;
	return {};
}
