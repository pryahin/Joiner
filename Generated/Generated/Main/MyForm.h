#pragma once
#include "windows.h"
#include <vcclr.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>

using namespace msclr::interop;



namespace main {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Resources;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}






	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;

	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TabPage^  tabPage2;


	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label4;



	private: System::Windows::Forms::OpenFileDialog^  openFileDialog2;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TextBox^  textBox4;

	private: System::Windows::Forms::CheckBox^  checkBox6;
	private: System::Windows::Forms::CheckBox^  checkBox5;
	private: System::Windows::Forms::CheckBox^  checkBox4;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  textBox3;

	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;






































	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(2, 7);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(434, 278);
			this->tabControl1->TabIndex = 8;
			this->tabControl1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::tabControl1_SelectedIndexChanged);
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->button3);
			this->tabPage1->Controls->Add(this->button2);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->textBox2);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->textBox1);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(426, 252);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Основное";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(380, 44);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(38, 20);
			this->button3->TabIndex = 15;
			this->button3->Text = L"...";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(380, 19);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(38, 20);
			this->button2->TabIndex = 14;
			this->button2->Text = L"...";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(17, 49);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(75, 13);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Второй файл:";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(102, 45);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(272, 20);
			this->textBox2->TabIndex = 12;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(17, 23);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(79, 13);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Первый файл:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(190, 133);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 13);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Статус";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(102, 19);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(272, 20);
			this->textBox1->TabIndex = 9;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(13, 90);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(405, 28);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Создать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->groupBox2);
			this->tabPage2->Controls->Add(this->groupBox1);
			this->tabPage2->Controls->Add(this->button5);
			this->tabPage2->Controls->Add(this->pictureBox1);
			this->tabPage2->Controls->Add(this->button4);
			this->tabPage2->Controls->Add(this->label4);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(426, 252);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Настройки";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBox4);
			this->groupBox2->Controls->Add(this->checkBox6);
			this->groupBox2->Controls->Add(this->checkBox5);
			this->groupBox2->Controls->Add(this->checkBox4);
			this->groupBox2->Controls->Add(this->radioButton4);
			this->groupBox2->Controls->Add(this->radioButton3);
			this->groupBox2->Location = System::Drawing::Point(219, 8);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(200, 177);
			this->groupBox2->TabIndex = 12;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Второй файл";
			// 
			// textBox4
			// 
			this->textBox4->Enabled = false;
			this->textBox4->Location = System::Drawing::Point(18, 147);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(165, 20);
			this->textBox4->TabIndex = 9;
			// 
			// checkBox6
			// 
			this->checkBox6->AutoSize = true;
			this->checkBox6->ForeColor = System::Drawing::SystemColors::ControlText;
			this->checkBox6->Location = System::Drawing::Point(18, 124);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(138, 17);
			this->checkBox6->TabIndex = 9;
			this->checkBox6->Text = L"Изменить имя файла:";
			this->checkBox6->UseVisualStyleBackColor = true;
			this->checkBox6->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox6_CheckedChanged);
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->ForeColor = System::Drawing::SystemColors::ControlText;
			this->checkBox5->Location = System::Drawing::Point(18, 101);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(160, 17);
			this->checkBox5->TabIndex = 9;
			this->checkBox5->Text = L"Удалять после просмотра";
			this->checkBox5->UseVisualStyleBackColor = true;
			this->checkBox5->Visible = false;
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->ForeColor = System::Drawing::SystemColors::ControlText;
			this->checkBox4->Location = System::Drawing::Point(18, 86);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(157, 17);
			this->checkBox4->TabIndex = 2;
			this->checkBox4->Text = L"Копировать в папку Temp";
			this->checkBox4->UseVisualStyleBackColor = true;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(18, 43);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(168, 30);
			this->radioButton4->TabIndex = 1;
			this->radioButton4->Text = L"Запускать из памяти\r\n(только исполняемый файл)";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton4_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Checked = true;
			this->radioButton3->Location = System::Drawing::Point(18, 19);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(120, 17);
			this->radioButton3->TabIndex = 0;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Сохранять на диск";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->checkBox3);
			this->groupBox1->Controls->Add(this->checkBox2);
			this->groupBox1->Controls->Add(this->checkBox1);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Location = System::Drawing::Point(6, 8);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 177);
			this->groupBox1->TabIndex = 11;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Первый файл";
			// 
			// textBox3
			// 
			this->textBox3->Enabled = false;
			this->textBox3->Location = System::Drawing::Point(18, 147);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(165, 20);
			this->textBox3->TabIndex = 9;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->checkBox3->Location = System::Drawing::Point(18, 124);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(138, 17);
			this->checkBox3->TabIndex = 9;
			this->checkBox3->Text = L"Изменить имя файла:";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox3_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->checkBox2->Location = System::Drawing::Point(18, 101);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(160, 17);
			this->checkBox2->TabIndex = 9;
			this->checkBox2->Text = L"Удалять после просмотра";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->Visible = false;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->checkBox1->Location = System::Drawing::Point(18, 86);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(157, 17);
			this->checkBox1->TabIndex = 2;
			this->checkBox1->Text = L"Копировать в папку Temp";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(18, 43);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(168, 30);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->Text = L"Запускать из памяти\r\n(только исполняемый файл)";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton2_CheckedChanged);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(18, 19);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(120, 17);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Сохранять на диск";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->ForeColor = System::Drawing::Color::Red;
			this->button5->Location = System::Drawing::Point(327, 199);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(74, 41);
			this->button5->TabIndex = 8;
			this->button5->Text = L"Выбрать иконку";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(51, 208);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(32, 32);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			// 
			// button4
			// 
			this->button4->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button4->Location = System::Drawing::Point(246, 199);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 41);
			this->button4->TabIndex = 6;
			this->button4->Text = L"Загрузить иконку";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(21, 188);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(94, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Текущая иконка:";
			// 
			// openFileDialog2
			// 
			this->openFileDialog2->Filter = L"Файлы значков (*.ico)|*.ico";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(436, 287);
			this->Controls->Add(this->tabControl1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Джойнер(почти)";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		bool extract(DWORD numb)//, String^ name)
		{
			BOOL is_extracted = FALSE;

			// Получаем дескриптор ресурса
			HRSRC hRes = FindResource(NULL, MAKEINTRESOURCE(numb), RT_RCDATA);
			if (hRes == NULL)
				return is_extracted;

			// грузим его в глобальную память
			HGLOBAL mem_block = LoadResource(NULL, hRes);
			if (mem_block == NULL)
				return is_extracted;

			// получаем указатель на него
			void* pointer = LockResource(mem_block);
			if (pointer == NULL)
				return is_extracted;

			// и его размер
			DWORD siz = SizeofResource(0, hRes);

			//пишем в файл
			HANDLE hFile = CreateFile("output.exe", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, 0);
			if (hFile == INVALID_HANDLE_VALUE)
			{
				MessageBox::Show("Ошибка при создании файла!");
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

		std::string createini()
		{
			marshal_context mc;
			std::string out = "[first_file]\n";
			out += "name = "; out += checkBox3->Checked ? marshal_as<std::string>(textBox3->Text) : marshal_as<std::string>(Path::GetFileName(textBox1->Text));
			if (radioButton2->Checked)
			{
				out += "\ntemp = 0";
				//out += "\ndelete_file = 0";
				out += "\nvirtual = 1";
			}
			else
			{
				out += "\ntemp = "; out += checkBox1->Checked ? '1' : '0';
				//out += "\ndelete_file = "; out += checkBox2->Checked ? '1' : '0';
				out += "\nvirtual = 0";
			}

			out += "\n\n[second_file]\n";
			out += "name = "; out += checkBox6->Checked ? mc.marshal_as<std::string>(textBox4->Text) : mc.marshal_as<std::string>(Path::GetFileName(textBox2->Text));
			if (radioButton4->Checked)
			{
				out += "\ntemp = 0";
				//out += "\ndelete_file = 0";
				out += "\nvirtual = 1";
			}
			else
			{
				out += "\ntemp = "; out += checkBox4->Checked ? '1' : '0';
				//out += "\ndelete_file = "; out += checkBox5->Checked ? '1' : '0';
				out += "\nvirtual = 0";
			}

			return out;
		}

		std::vector<unsigned char> GetFile(LPCSTR name)
		{
			HANDLE hFile;
			DWORD dwBytesRead, size;
			hFile = CreateFile(name, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
			if (hFile == INVALID_HANDLE_VALUE)
			{
				//marshal_context mc;
				MessageBox::Show("Ошибка при чтении файла!"+ marshal_as<System::String^>(name));
				DeleteFile("output.exe");
			}
			else
			{
				size = GetFileSize(hFile, NULL);
				dwBytesRead = 0x0;
				std::vector<unsigned char> buffer(static_cast<size_t>(size));
				ReadFile(hFile, buffer.data(), static_cast<DWORD>(buffer.size()), &dwBytesRead, NULL);
				CloseHandle(hFile);
				return buffer;
			}
			std::vector<unsigned char> buffer;
			return buffer;
		}



	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (textBox1->Text == "" || textBox2->Text == "")
		{
			MessageBox::Show("Выберите файлы!");
		}
		else
		{
			if (extract(1001)) //, textBox1->Text + ".exe")) {
			{	
				label1->Text = "Отлично";
				std::string ini_s = createini();
				std::vector<unsigned char> ini;
				std::copy(ini_s.begin(), ini_s.end(), std::back_inserter(ini));

				// Переменные для работы с ресурсами
				HANDLE hUpdateRes;
				BOOL result;
				HANDLE hFile;
				DWORD dwBytesRead, size1, size2;
				std::vector<unsigned char> buffer1, buffer2,icon;
				marshal_context mc;

				//Конвертируем из String^ в LPCSTR
				LPCSTR name1_change = mc.marshal_as<LPCSTR>(textBox1->Text);
				LPCSTR name2_change = mc.marshal_as<LPCSTR>(textBox2->Text);
				LPCSTR name1_withoutPath = mc.marshal_as<LPCSTR>(Path::GetFileName(textBox1->Text));
				LPCSTR name_icon = mc.marshal_as<LPCSTR>(openFileDialog2->FileName);
				if (openFileDialog2->FileName!="")
					icon = GetFile(name_icon);

				//Открываем 1-ый файл для чтения
				buffer1 = GetFile(name1_change);
				if (!buffer1.empty()) {
					//Открываем 2-ый файл для чтения
					buffer2 = GetFile(name2_change);
					if (!buffer2.empty())
					{
						// Пытаемся начать обновлять ресурс файла
						hUpdateRes = BeginUpdateResource("output.exe", false);
						if (hUpdateRes == NULL)
						{
							MessageBox::Show("Ошибка при объединеннии [1]");
						}
						else {
							// Собственно тут и происходит обновление ресурса 
							result = UpdateResource(hUpdateRes, RT_RCDATA, MAKEINTRESOURCE(1001), MAKELANGID(LANG_RUSSIAN, SUBLANG_RUSSIAN_RUSSIA), buffer1.data(), static_cast<DWORD>(buffer1.size()));
							result *= UpdateResource(hUpdateRes, RT_RCDATA, MAKEINTRESOURCE(1002), MAKELANGID(LANG_RUSSIAN, SUBLANG_RUSSIAN_RUSSIA), buffer2.data(), static_cast<DWORD>(buffer2.size()));
							result *= UpdateResource(hUpdateRes, RT_RCDATA, MAKEINTRESOURCE(2000), MAKELANGID(LANG_RUSSIAN, SUBLANG_RUSSIAN_RUSSIA), ini.data(), static_cast<DWORD>(ini.size()));
							if (openFileDialog2->FileName != "")
								result *= UpdateResource(hUpdateRes, RT_ICON, MAKEINTRESOURCE(108), MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL), icon.data(), static_cast<DWORD>(icon.size()));
							if (!result)
							{
								MessageBox::Show("Ошибка при объединеннии [2]");
								DeleteFile("output.exe");
							}
						}

						EndUpdateResource(hUpdateRes, FALSE);
						buffer2.clear();
					}
					buffer1.clear();
				}
			}
			else
			{
				label1->Text = "Что-то пошло не так";
			}
		}

	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			textBox1->Text = openFileDialog1->FileName;
		}
	}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		textBox2->Text = openFileDialog1->FileName;
	}
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	if (openFileDialog2->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		//textBox2->Text = openFileDialog1->FileName;
		pictureBox1->Image = Image::FromFile(openFileDialog2->FileName);
	}
}
private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (radioButton1->Checked)
	{
		checkBox1->Enabled = true;
		checkBox2->Enabled = true;
		checkBox3->Enabled = true;
		if (checkBox3->Checked)
			textBox3->Enabled = true;
	}
	else
	{
		checkBox1->Enabled = false;
		checkBox2->Enabled = false;
		checkBox3->Enabled = false;
		textBox3->Enabled = false;
	}
}
private: System::Void radioButton4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (radioButton3->Checked)
	{
		checkBox6->Enabled = true;
		checkBox5->Enabled = true;
		checkBox4->Enabled = true;
		if (checkBox6->Checked)
			textBox4->Enabled = true;
	}
	else
	{
		checkBox6->Enabled = false;
		checkBox5->Enabled = false;
		checkBox4->Enabled = false;
		textBox4->Enabled = false;
	}
}
private: System::Void checkBox3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	textBox3->Enabled = textBox3->Enabled ? false : true;
}
private: System::Void checkBox6_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	textBox4->Enabled = textBox4->Enabled ? false : true;
}
private: System::Void tabControl1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	if (tabControl1->Height == 182) {
		tabControl1->Height = 278;
		Height = 326;
	}
	else
	{
		tabControl1->Height = 182;
		Height = 230;
	}
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	Width = 452;
	Height = 230;
	tabControl1->Height = 182;
}
};
}
