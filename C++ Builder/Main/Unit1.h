//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *Edit1;
	TEdit *Edit2;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TTabSheet *TabSheet2;
	TOpenDialog *OpenDialog1;
	TGroupBox *GroupBox1;
	TCheckBox *CheckBox1;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TCheckBox *CheckBox2;
	TOpenDialog *OpenDialog2;
	TEdit *Edit3;
	TGroupBox *GroupBox2;
	TCheckBox *CheckBox3;
	TRadioButton *RadioButton3;
	TRadioButton *RadioButton4;
	TCheckBox *CheckBox4;
	TEdit *Edit4;
	TGroupBox *GroupBox3;
	TButton *Button4;
	TButton *Button5;
	TImage *Image1;
	TLabel *Label4;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	std::string __fastcall createini();
	void __fastcall RadioButton1Click(TObject *Sender);
	void __fastcall RadioButton3Click(TObject *Sender);
	void __fastcall CheckBox2Click(TObject *Sender);
	void __fastcall CheckBox4Click(TObject *Sender);
	void __fastcall PageControl1Change(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
