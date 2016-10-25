// Generated.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include "resource.h"
#include <Windows.h>
#include <iostream>
#include <exception>

template <typename T>
void log(T mes)
{
	std::cout << mes << std::endl;
}

bool extract(DWORD numb, LPCWSTR name)
{
	try {
		// ѕолучаем дескриптор ресурса
		HRSRC hRes = FindResource(NULL, MAKEINTRESOURCE(numb), RT_RCDATA);
		// грузим его в глобальную пам€ть
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

		return is_extracted;
	}
	catch (std::exception &e)
	{
		log(e.what());
	}
	return false;
}

int main()
{
	wchar_t buffer1[100], buffer2[100];
	LPWSTR firstname, secondname;


	int res = LoadString(NULL, 2001, buffer1, sizeof(buffer1));
	firstname = buffer1;

	res = LoadString(NULL, 2002, buffer2, sizeof(buffer2));
	secondname = buffer2;

	log(firstname);
	log(secondname);

	if (extract(1001, firstname))
		log("Success first");
	if (extract(1002, secondname))
		log("Success second");

	system("pause");

	return 0;
}
