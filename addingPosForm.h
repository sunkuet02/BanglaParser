#pragma once
#include "Markup.h"
#using <System.Xml.dll>
#include <msclr\marshal_cppstd.h>
#include <msclr\marshal.h>
#include<vector>
#include<string>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<hash_map>
#include<ctime>

namespace TextBox {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Xml;
	using namespace System::Runtime::InteropServices;
	using namespace msclr::interop;
	using namespace stdext;
	using namespace System::IO;


	/// <summary>
	/// Summary for addingPosForm
	/// </summary>
	public ref class addingPosForm : public System::Windows::Forms::Form
	{
	public:
		String ^ receivedString;
		String ^ returnString; 
	public:
		addingPosForm(Void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		addingPosForm(String ^ text)
		{
			InitializeComponent();
			receivedString = text;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~addingPosForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lblText;
	private: System::Windows::Forms::Label^  lblShowPosName;
	private: System::Windows::Forms::Button^  btnCancel;
	private: System::Windows::Forms::Button^  btnSave;
	private: System::Windows::Forms::ComboBox ^  comboBox;


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
			this->lblText = (gcnew System::Windows::Forms::Label());
			this->lblShowPosName = (gcnew System::Windows::Forms::Label());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// comboBox
			// 
			this->comboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox->FormattingEnabled = true;
			this->comboBox->Items->AddRange(gcnew cli::array< System::Object^  >(6) { L"noun", L"pron", L"verb", L"adv", L"adj", L"conj" });
			this->comboBox->Location = System::Drawing::Point(247, 35);
			this->comboBox->Name = L"comboBox";
			this->comboBox->Size = System::Drawing::Size(121, 21);
			this->comboBox->TabIndex = 2;
			// 
			// lblText
			// 
			this->lblText->AutoSize = true;
			this->lblText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblText->Location = System::Drawing::Point(12, 9);
			this->lblText->Name = L"lblText";
			this->lblText->Size = System::Drawing::Size(34, 13);
			this->lblText->TabIndex = 0;
			this->lblText->Text = L"label";
			// 
			// lblShowPosName
			// 
			this->lblShowPosName->AutoSize = true;
			this->lblShowPosName->Location = System::Drawing::Point(80, 43);
			this->lblShowPosName->Name = L"lblShowPosName";
			this->lblShowPosName->Size = System::Drawing::Size(35, 13);
			this->lblShowPosName->TabIndex = 1;
			this->lblShowPosName->Text = L"label1";
			// 
			// btnCancel
			// 
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancel->Location = System::Drawing::Point(245, 94);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(180, 23);
			this->btnCancel->TabIndex = 3;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &addingPosForm::btnCancel_Click);
			// 
			// btnSave
			// 
			this->btnSave->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSave->Location = System::Drawing::Point(15, 94);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(180, 23);
			this->btnSave->TabIndex = 3;
			this->btnSave->Text = L"Add ";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &addingPosForm::btnSave_Click);
			// 
			// addingPosForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(437, 129);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(comboBox);
			this->Controls->Add(this->lblShowPosName);
			this->Controls->Add(this->lblText);
			this->Name = L"addingPosForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"addingPosForm";
			this->Load += gcnew System::EventHandler(this, &addingPosForm::addingPosForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
	private: System::Void addingPosForm_Load(System::Object^  sender, System::EventArgs^  e) {

				 lblText->Text = "The word " + receivedString + " not Found. Do you want to add this to POS Tagger ? ";
				 lblShowPosName->Text = receivedString;

	}
	private: System::Void btnSave_Click(System::Object^  sender, System::EventArgs^  e) {
				 XmlDocument^ doc = gcnew XmlDocument;

				 doc->Load("temp.xml");

				 XmlNode^ root = doc->DocumentElement;

				 //Create a new node.
				 XmlElement^ elem = doc->CreateElement(receivedString);
				 
				 elem->InnerText = comboBox->Text;

				 //Add the node to the document.
				 root->AppendChild(elem);

				 doc->Save("temp.xml");
				 

				 this->Close();
	}
	private: System::Void btnCancel_Click(System::Object^  sender, System::EventArgs^  e) {

				 this->Close();
	}
	};
}
