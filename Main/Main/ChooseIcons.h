#pragma once

namespace main {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ChooseIcons
	/// </summary>
	public ref class ChooseIcons : public System::Windows::Forms::Form
	{
	public:
		ChooseIcons(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

		System::String^ ReturnData() {
			return listView1->SelectedItems[0]->ImageKey;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ChooseIcons()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^  listView1;
	private: System::Windows::Forms::ImageList^  imageList1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::ListViewItem^  listViewItem1 = (gcnew System::Windows::Forms::ListViewItem(L"1", L"Windows 7 (5).ico"));
			System::Windows::Forms::ListViewItem^  listViewItem2 = (gcnew System::Windows::Forms::ListViewItem(L"2", L"Windows 7 (15).ico"));
			System::Windows::Forms::ListViewItem^  listViewItem3 = (gcnew System::Windows::Forms::ListViewItem(L"3", L"Windows 7 (6).ico"));
			System::Windows::Forms::ListViewItem^  listViewItem4 = (gcnew System::Windows::Forms::ListViewItem(L"4", L"Windows 7 (18).ico"));
			System::Windows::Forms::ListViewItem^  listViewItem5 = (gcnew System::Windows::Forms::ListViewItem(L"5", L"Windows 7 (68).ico"));
			System::Windows::Forms::ListViewItem^  listViewItem6 = (gcnew System::Windows::Forms::ListViewItem(L"6", L"Windows 7 (89).ico"));
			System::Windows::Forms::ListViewItem^  listViewItem7 = (gcnew System::Windows::Forms::ListViewItem(L"7", L"Windows 7 (22).ico"));
			System::Windows::Forms::ListViewItem^  listViewItem8 = (gcnew System::Windows::Forms::ListViewItem(L"8", L"Windows 7 (20).ico"));
			System::Windows::Forms::ListViewItem^  listViewItem9 = (gcnew System::Windows::Forms::ListViewItem(L"9", L"Windows 7 (7).ico"));
			System::Windows::Forms::ListViewItem^  listViewItem10 = (gcnew System::Windows::Forms::ListViewItem(L"10", L"Windows 7 (156).ico"));
			System::Windows::Forms::ListViewItem^  listViewItem11 = (gcnew System::Windows::Forms::ListViewItem(L"11", L"Windows 7 (111).ico"));
			System::Windows::Forms::ListViewItem^  listViewItem12 = (gcnew System::Windows::Forms::ListViewItem(L"12", L"Windows 7 (112).ico"));
			System::Windows::Forms::ListViewItem^  listViewItem13 = (gcnew System::Windows::Forms::ListViewItem(L"13", L"Windows 7 (129).ico"));
			System::Windows::Forms::ListViewItem^  listViewItem14 = (gcnew System::Windows::Forms::ListViewItem(L"14", L"Windows 7 (130).ico"));
			System::Windows::Forms::ListViewItem^  listViewItem15 = (gcnew System::Windows::Forms::ListViewItem(L"15", L"Windows 7 (131).ico"));
			System::Windows::Forms::ListViewItem^  listViewItem16 = (gcnew System::Windows::Forms::ListViewItem(L"16", L"Windows 7 (132).ico"));
			System::Windows::Forms::ListViewItem^  listViewItem17 = (gcnew System::Windows::Forms::ListViewItem(L"17", L"Windows 7 (133).ico"));
			System::Windows::Forms::ListViewItem^  listViewItem18 = (gcnew System::Windows::Forms::ListViewItem(L"18", L"Windows 7 (134).ico"));
			System::Windows::Forms::ListViewItem^  listViewItem19 = (gcnew System::Windows::Forms::ListViewItem(L"19", L"Windows 7 (209).ico"));
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ChooseIcons::typeid));
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// listView1
			// 
			listViewItem1->StateImageIndex = 0;
			this->listView1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(19) {
				listViewItem1, listViewItem2,
					listViewItem3, listViewItem4, listViewItem5, listViewItem6, listViewItem7, listViewItem8, listViewItem9, listViewItem10, listViewItem11,
					listViewItem12, listViewItem13, listViewItem14, listViewItem15, listViewItem16, listViewItem17, listViewItem18, listViewItem19
			});
			this->listView1->LargeImageList = this->imageList1;
			this->listView1->Location = System::Drawing::Point(24, 23);
			this->listView1->Margin = System::Windows::Forms::Padding(5);
			this->listView1->MultiSelect = false;
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(471, 228);
			this->listView1->SmallImageList = this->imageList1;
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			// 
			// imageList1
			// 
			this->imageList1->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"imageList1.ImageStream")));
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			this->imageList1->Images->SetKeyName(0, L"Windows 7 (5).ico");
			this->imageList1->Images->SetKeyName(1, L"Windows 7 (15).ico");
			this->imageList1->Images->SetKeyName(2, L"Windows 7 (6).ico");
			this->imageList1->Images->SetKeyName(3, L"Windows 7 (18).ico");
			this->imageList1->Images->SetKeyName(4, L"Windows 7 (68).ico");
			this->imageList1->Images->SetKeyName(5, L"Windows 7 (89).ico");
			this->imageList1->Images->SetKeyName(6, L"Windows 7 (22).ico");
			this->imageList1->Images->SetKeyName(7, L"Windows 7 (20).ico");
			this->imageList1->Images->SetKeyName(8, L"Windows 7 (7).ico");
			this->imageList1->Images->SetKeyName(9, L"Windows 7 (156).ico");
			this->imageList1->Images->SetKeyName(10, L"Windows 7 (111).ico");
			this->imageList1->Images->SetKeyName(11, L"Windows 7 (112).ico");
			this->imageList1->Images->SetKeyName(12, L"Windows 7 (129).ico");
			this->imageList1->Images->SetKeyName(13, L"Windows 7 (130).ico");
			this->imageList1->Images->SetKeyName(14, L"Windows 7 (131).ico");
			this->imageList1->Images->SetKeyName(15, L"Windows 7 (132).ico");
			this->imageList1->Images->SetKeyName(16, L"Windows 7 (133).ico");
			this->imageList1->Images->SetKeyName(17, L"Windows 7 (134).ico");
			this->imageList1->Images->SetKeyName(18, L"Windows 7 (209).ico");
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(329, 274);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"ОК";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ChooseIcons::button1_Click);
			// 
			// button2
			// 
			this->button2->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button2->Location = System::Drawing::Point(420, 274);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Отмена";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ChooseIcons::button2_Click);
			// 
			// ChooseIcons
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->button2;
			this->ClientSize = System::Drawing::Size(517, 309);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listView1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ChooseIcons";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Выбрать иконку...";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}


	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (listView1->SelectedItems->Count == 0)
			MessageBox::Show("Не выбрали иконку!");
		else
		{
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			


		}


	}
	};
}
