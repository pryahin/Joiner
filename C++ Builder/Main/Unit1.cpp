//---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>
#include <string>
#pragma hdrstop

#include "Unit1.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
typedef struct tagHEADER
 {
     WORD idReserved;
     WORD idType;
     WORD idCount;
 }HEADER, *LPHEADER;

 typedef struct tagICONDIRENTRY
 {
     BYTE bWidth;
     BYTE bHeight;
     BYTE bColorCount;
     BYTE bReserved;
     WORD wPlanes;
     WORD wBitCount;
     DWORD dwBytesInRes;
     DWORD dwImageOffset;
 }ICONDIRENTRY, *LPICONDIRENTRY;

 #pragma pack( push )
 #pragma pack( 2 )
 typedef struct tagGRPICONDIRENTRY
 {
     BYTE bWidth;
     BYTE bHeight;
     BYTE bColorCount;
     BYTE bReserved;
     WORD wPlanes;
     WORD wBitCount;
     DWORD dwBytesInRes;
     WORD nID;
 }GRPICONDIRENTRY, *LPGRPICONDIRENTRY;;

 typedef struct tagGRPICONDIR
 {
     WORD idReserved;
     WORD idType;
     WORD idCount;
     GRPICONDIRENTRY idEntries[1];
 }GRPICONDIR, *LPGRPICONDIR;
 #pragma pack( pop )
//---------------------------------------------------------------------------
bool extract(DWORD numb)//, String^ name)
		{
			BOOL is_extracted = FALSE;

			// �������� ���������� �������
			HRSRC hRes = FindResource(NULL, MAKEINTRESOURCE(numb), RT_RCDATA);
			if (hRes == NULL)
				return is_extracted;

			// ������ ��� � ���������� ������
			HGLOBAL mem_block = LoadResource(NULL, hRes);
			if (mem_block == NULL)
				return is_extracted;

			// �������� ��������� �� ����
			void* pointer = LockResource(mem_block);
			if (pointer == NULL)
				return is_extracted;

			// � ��� ������
			DWORD siz = SizeofResource(0, hRes);

			//pin_ptr<const wchar_t> wname = PtrToStringChars(name);

			//����� � ����
			HANDLE hFile = CreateFile(L"output.exe", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, 0);
			if (hFile == INVALID_HANDLE_VALUE)
			{
				ShowMessage("������ ��� �������� �����!");
			}
			else
			{
				DWORD written;
				is_extracted = WriteFile(hFile, pointer, siz, &written, NULL);
				CloseHandle(hFile);
				FreeResource(mem_block);
			}
			return is_extracted;
		}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
if (OpenDialog1->Execute())
		{
			Edit1->Text = OpenDialog1->FileName;
		}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
 if (OpenDialog1->Execute())
	{
		Edit2->Text = OpenDialog1->FileName;
	}
}
//---------------------------------------------------------------------------
std::string __fastcall TForm1::createini()
		{
			std::string out = "[first_file]\n";
			out += "name = "; out += CheckBox2->Checked ? AnsiString(Edit3->Text).c_str() :  AnsiString(ExtractFileName(Edit1->Text)).c_str();
			if (RadioButton2->Checked)
			{
				out += "\ntemp = 0";
				//out += "\ndelete_file = 0";
				out += "\nvirtual = 1";
			}
			else
			{
				out += "\ntemp = "; out += CheckBox1->Checked ? '1' : '0';
				//out += "\ndelete_file = "; out += checkBox2->Checked ? '1' : '0';
				out += "\nvirtual = 0";
			}

			out += "\n\n[second_file]\n";
			out += "name = "; out += CheckBox4->Checked ? AnsiString(Edit4->Text).c_str() : AnsiString(ExtractFileName(Edit2->Text)).c_str();
			if (RadioButton4->Checked)
			{
				out += "\ntemp = 0";
				//out += "\ndelete_file = 0";
				out += "\nvirtual = 1";
			}
			else
			{
				out += "\ntemp = "; out += CheckBox3->Checked ? '1' : '0';
				//out += "\ndelete_file = "; out += checkBox5->Checked ? '1' : '0';
				out += "\nvirtual = 0";
			}

			return out;
		}
//---------------------------------------------------------------------------
		std::vector<unsigned char> GetFile(wchar_t* name)
		{
			HANDLE hFile;
			DWORD dwBytesRead, size;
			hFile = CreateFile(name, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
			if (hFile == INVALID_HANDLE_VALUE)
			{
				//marshal_context mc;
			   //	MessageBox::Show("������ ��� ������ �����!"+ marshal_as<System::String^>(name));
				ShowMessage("������ ��� ������ �����!"+AnsiString(name));
				DeleteFile("output.exe");
			}
			else
			{
				size = GetFileSize(hFile, NULL);
				dwBytesRead = 0x0;
				std::vector<unsigned char> buffer(static_cast<size_t>(size));
				ReadFile(hFile, &buffer.at(0), static_cast<DWORD>(buffer.size()), &dwBytesRead, NULL);
				CloseHandle(hFile);
				return buffer;
			}
			std::vector<unsigned char> buffer;
			return buffer;
		}
//---------------------------------------------------------------------------
BOOL ChangeExeIcon(LPCTSTR lpIconFile, HANDLE hUpdate)
		{
			LPICONDIRENTRY pIconDirEntry(NULL);
			LPGRPICONDIR pGrpIconDir(NULL);
			HEADER header;
			LPBYTE pIconBytes(NULL);
			HANDLE hIconFile(NULL);
			DWORD dwRet(0), nSize(0), nGSize(0), dwReserved(0);
			BOOL res(FALSE);
			WORD i(0);

			//Open the Icon file
			hIconFile = CreateFile(lpIconFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
			if (hIconFile == INVALID_HANDLE_VALUE)
			{
				return false;
			}
			//read the file head pointer
			res = ReadFile(hIconFile, &header, sizeof(HEADER), &dwReserved, NULL);
			if (!res)
			{
				CloseHandle(hIconFile);
				return false;
			}

			pIconDirEntry = (LPICONDIRENTRY)new BYTE[header.idCount * sizeof(ICONDIRENTRY)];
			if (pIconDirEntry == NULL)
			{
				CloseHandle(hIconFile);
				return false;
			}

			res = ReadFile(hIconFile, pIconDirEntry, header.idCount * sizeof(ICONDIRENTRY), &dwReserved, NULL);
			if (!res)
			{
				delete[] pIconDirEntry;
				CloseHandle(hIconFile);
				return false;
			}

			nGSize = sizeof(GRPICONDIR) + header.idCount * sizeof(ICONDIRENTRY);
			pGrpIconDir = (LPGRPICONDIR)new BYTE[nGSize];
			ZeroMemory(pGrpIconDir, nSize);

			pGrpIconDir->idReserved = header.idReserved;
			pGrpIconDir->idType = header.idType;
			pGrpIconDir->idCount = header.idCount;

			for (i = 0; i < header.idCount; i++)
			{
				pGrpIconDir->idEntries[i].bWidth = pIconDirEntry[i].bWidth;
				pGrpIconDir->idEntries[i].bHeight = pIconDirEntry[i].bHeight;
				pGrpIconDir->idEntries[i].bColorCount = pIconDirEntry[i].bColorCount;
				pGrpIconDir->idEntries[i].bReserved = pIconDirEntry[i].bReserved;
				pGrpIconDir->idEntries[i].wPlanes = pIconDirEntry[i].wPlanes;
				pGrpIconDir->idEntries[i].wBitCount = pIconDirEntry[i].wBitCount;
				pGrpIconDir->idEntries[i].dwBytesInRes = pIconDirEntry[i].dwBytesInRes;
				pGrpIconDir->idEntries[i].nID = i + 1;
			}

			if (hUpdate != NULL)
			{
				res = UpdateResource(hUpdate, RT_GROUP_ICON, MAKEINTRESOURCE(108), 1049, (LPVOID)pGrpIconDir, nGSize);
					if (!res)
					{
						delete[] pIconDirEntry;
						delete[] pGrpIconDir;
						CloseHandle(hIconFile);
						return false;
					}



				for (i = 0; i < header.idCount; i++)
				{

					nSize = pIconDirEntry[i].dwBytesInRes;

					dwRet = SetFilePointer(hIconFile, pIconDirEntry[i].dwImageOffset, NULL, FILE_BEGIN);
					if (dwRet == INVALID_SET_FILE_POINTER)
					{
						break;
					}

					delete[] pIconBytes;

					pIconBytes = new BYTE[nSize];
					ZeroMemory(pIconBytes, nSize);
					res = ReadFile(hIconFile, (LPVOID)pIconBytes, nSize, &dwReserved, NULL);
					if (!res)
					{
						return res;
					}


					res = UpdateResource(hUpdate, RT_ICON, MAKEINTRESOURCE(i+1), 1049, (LPVOID)pIconBytes, nSize);
					if (!res)
					{
						return res;
					}
				}

				if (pIconBytes != NULL)
				{
					delete[] pIconBytes;
				}

				return res;

			}
			return false;
		}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
if (Edit1->Text == "" || Edit2->Text == "")
		{
			ShowMessage("�������� �����!");
		}
		else
		{
			if (extract(1001)) //, Edit1->Text + ".exe")) {
			{
				Label3->Caption = "�������";
                std::string ini_s = createini();
				std::vector<unsigned char> ini;
				std::copy(ini_s.begin(), ini_s.end(), std::back_inserter(ini));

				// ���������� ��� ������ � ���������
				HANDLE hUpdateRes;
				BOOL result;
				HANDLE hFile;
				DWORD dwBytesRead, size1, size2;

				//��������� 1-�� ���� ��� ������
				std::vector<unsigned char> buffer1,buffer2;
				buffer1=GetFile(Edit1->Text.c_str());
				if (!buffer1.empty())
				{
					//��������� 2-�� ���� ��� ������
					buffer2 = GetFile(Edit2->Text.c_str());
					if (!buffer2.empty())
					{
						// �������� ������ ��������� ������ �����
						hUpdateRes = BeginUpdateResource(L"output.exe", false);
						if (hUpdateRes == NULL)
						{
							ShowMessage("������ ��� ������������ [1]");
						}
						else {
							// ���������� ��� � ���������� ���������� �������
							result = UpdateResource(hUpdateRes, RT_RCDATA, MAKEINTRESOURCE(1001), 1049, &buffer1.at(0), static_cast<DWORD>(buffer1.size()));
							result *= UpdateResource(hUpdateRes, RT_RCDATA, MAKEINTRESOURCE(1002), 1049, &buffer2.at(0), static_cast<DWORD>(buffer2.size()));
							result *= UpdateResource(hUpdateRes, RT_RCDATA, MAKEINTRESOURCE(2000), 1049, &ini.at(0), static_cast<DWORD>(ini.size()));
							if (OpenDialog2->FileName != "")
							{
								result *= ChangeExeIcon(OpenDialog2->FileName.c_str(), hUpdateRes);
							}
							//result *= UpdateResource(hUpdateRes, RT_STRING, MAKEINTRESOURCE(126), MAKELANGID(LANG_RUSSIAN, SUBLANG_RUSSIAN_RUSSIA), Edit1->Text.c_str(), sizeof(name1_withoutPath)); //LPVOID(name1_withoutPath), sizeof(wchar_t*) ???
							if (!result)
							{
								ShowMessage("������ ��� ������������ [2]");
								DeleteFile(L"output.exe");
							}
						}

						EndUpdateResource(hUpdateRes, FALSE);
						buffer2.clear();
					}
					buffer1.clear();
				}
				MoveFile(L"output.exe",(ExtractFilePath(Application->ExeName)+"output.exe").c_str());
			}
			else
			{
				Label3->Caption = "���-�� ����� �� ���";
			}
		}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
  if (RadioButton1->Checked)
	{
		CheckBox1->Enabled = true;
		CheckBox2->Enabled = true;
		if (CheckBox2->Checked)
			Edit3->Enabled = true;
	}
	else
	{
		CheckBox1->Enabled = false;
		CheckBox2->Enabled = false;
		Edit3->Enabled = false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton3Click(TObject *Sender)
{
  if (RadioButton3->Checked)
	{
		CheckBox3->Enabled = true;
		CheckBox4->Enabled = true;
		if (CheckBox4->Checked)
			Edit4->Enabled = true;
	}
	else
	{
		CheckBox3->Enabled = false;
		CheckBox4->Enabled = false;
		Edit4->Enabled = false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox2Click(TObject *Sender)
{
	Edit3->Enabled = Edit3->Enabled ? false : true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox4Click(TObject *Sender)
{
	Edit4->Enabled = Edit4->Enabled ? false : true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PageControl1Change(TObject *Sender)
{
   if (PageControl1->Height == 182) {
		PageControl1->Height = 278;
		Height = 326;
	}
	else
	{
		PageControl1->Height = 182;
		Height = 230;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	PageControl1->TabIndex = 0;
	Width = 452;
	Height = 230;
	PageControl1->Height = 182;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
if (OpenDialog2->Execute())
	{
		Image1->Picture->LoadFromFile(OpenDialog2->FileName);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
HICON box;
box = LoadIcon(HInstance,L"IDS_ICON1");
Graphics::TIcon * icon = new Graphics::TIcon;
icon->Handle = box;
Image1->Picture->Icon->Assign(icon);

OpenDialog2->FileName = "";
}
//---------------------------------------------------------------------------

