#pragma once
#include "Markup.h"
#include "addingPosForm.h"
#include "aboutForm.h"
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
	/// Summary for MyForm
	/// </summary>
	map<string, int> noOfSymbol, npdaSymbol;
	vector<string >grammer;
	vector<string> parseTable[200][200], cnfTable[200];
	vector<int>tot_word;
	hash_map<wstring, string> hash;
	hash_map<wstring, bool > bivoktiMap;
	hash_map<wchar_t, int> delimiterMarker;
	hash_map<wstring, string>::const_iterator it;
	vector<string>splitgrammer[100][100];
	vector<string>FIRST[100], FOLLOW[100];
	vector<string>Nonterminal, terminal;
	int totProduction[100];

	int textMarker[1000005];
	int totalSentences;


	bool notFound = false;
	bool ischeckfinished;
	int tot_line;
	//
	/// Timmer class 
	//



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
	private: System::Windows::Forms::TextBox^  mainTextBox;
	private: System::Windows::Forms::TextBox^  lastTextBox;
	protected:

	protected:

	private: System::Windows::Forms::Button^  sendButton;
	private: System::Windows::Forms::Button^  exitButton;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^  addPOSToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openFileToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  boxPreporcessing;
	private: System::Windows::Forms::TextBox^  boxExecution;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;



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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->mainTextBox = (gcnew System::Windows::Forms::TextBox());
			this->lastTextBox = (gcnew System::Windows::Forms::TextBox());
			this->sendButton = (gcnew System::Windows::Forms::Button());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addPOSToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->boxPreporcessing = (gcnew System::Windows::Forms::TextBox());
			this->boxExecution = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// mainTextBox
			// 
			this->mainTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mainTextBox->Location = System::Drawing::Point(0, 169);
			this->mainTextBox->Multiline = true;
			this->mainTextBox->Name = L"mainTextBox";
			this->mainTextBox->Size = System::Drawing::Size(294, 281);
			this->mainTextBox->TabIndex = 0;
			// 
			// lastTextBox
			// 
			this->lastTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lastTextBox->Location = System::Drawing::Point(455, 169);
			this->lastTextBox->Multiline = true;
			this->lastTextBox->Name = L"lastTextBox";
			this->lastTextBox->ReadOnly = true;
			this->lastTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->lastTextBox->Size = System::Drawing::Size(303, 281);
			this->lastTextBox->TabIndex = 1;
			// 
			// sendButton
			// 
			this->sendButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sendButton->Location = System::Drawing::Point(300, 198);
			this->sendButton->Name = L"sendButton";
			this->sendButton->Size = System::Drawing::Size(149, 34);
			this->sendButton->TabIndex = 2;
			this->sendButton->Text = L"Predictive Parse";
			this->sendButton->UseVisualStyleBackColor = true;
			this->sendButton->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// exitButton
			// 
			this->exitButton->Location = System::Drawing::Point(335, 450);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(92, 23);
			this->exitButton->TabIndex = 3;
			this->exitButton->Text = L"Exit";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &MyForm::exitButton_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(300, 389);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(149, 36);
			this->button1->TabIndex = 5;
			this->button1->Text = L"NPDA";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(291, 27);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(167, 39);
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->fileToolStripMenuItem,
					this->addPOSToolStripMenuItem, this->aboutToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(758, 24);
			this->menuStrip1->TabIndex = 7;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->openFileToolStripMenuItem,
					this->saveToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openFileToolStripMenuItem
			// 
			this->openFileToolStripMenuItem->Name = L"openFileToolStripMenuItem";
			this->openFileToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->openFileToolStripMenuItem->Text = L"Open File";
			this->openFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openFileToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->saveToolStripMenuItem->Text = L"Save ";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			// 
			// addPOSToolStripMenuItem
			// 
			this->addPOSToolStripMenuItem->Name = L"addPOSToolStripMenuItem";
			this->addPOSToolStripMenuItem->Size = System::Drawing::Size(66, 20);
			this->addPOSToolStripMenuItem->Text = L"Add POS";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::aboutToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(300, 300);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(149, 31);
			this->button2->TabIndex = 8;
			this->button2->Text = L"View POS";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::viewPosButtonFunction);
			// 
			// boxPreporcessing
			// 
			this->boxPreporcessing->Location = System::Drawing::Point(0, 104);
			this->boxPreporcessing->Multiline = true;
			this->boxPreporcessing->Name = L"boxPreporcessing";
			this->boxPreporcessing->ReadOnly = true;
			this->boxPreporcessing->Size = System::Drawing::Size(294, 59);
			this->boxPreporcessing->TabIndex = 9;
			// 
			// boxExecution
			// 
			this->boxExecution->Location = System::Drawing::Point(455, 104);
			this->boxExecution->Multiline = true;
			this->boxExecution->Name = L"boxExecution";
			this->boxExecution->ReadOnly = true;
			this->boxExecution->Size = System::Drawing::Size(303, 59);
			this->boxExecution->TabIndex = 9;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(77, 88);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(118, 13);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Preprocessing Time";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(575, 88);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(94, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Execution Time";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(758, 475);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->boxExecution);
			this->Controls->Add(this->boxPreporcessing);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->sendButton);
			this->Controls->Add(this->lastTextBox);
			this->Controls->Add(this->mainTextBox);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"বাংলা পদ-বিশ্লেষক";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		array<String^>^ words;


		array<String^>^ grammerWords = gcnew array<String^>(110);

		array<String^, 2>^ allGrammerWords = gcnew array<String^, 2>(100, 100);
		String ^ showSentence;

		array<String^>^ MainInput;




#pragma endregion

		// table for npda


	public:void assignNpdaSymbolValue(string s, int val)
	{
			   if (npdaSymbol.find(s) == npdaSymbol.end())
			   {
				   npdaSymbol[s] = val;
			   }
	}

	public: void makeCnfTable()
	{
				StreamReader^ reader = File::OpenText("resource/npdaGrammer.txt");
				String^ readString;
				int idx = 1;

				while ((readString = reader->ReadLine()) != nullptr)
				{
					string str = marshal_as<std::string>(readString);

					string leftString;

					int productNo = 1;

					int i = 0;
					while (str[i] != '-')
					{
						leftString.push_back(str[i]);
						i++;
					}

					assignNpdaSymbolValue(leftString, idx++);

					for (++i; i < str.size(); i++)
					{
						string first = "", second = "";
						while ((str[i] != ' ' && str[i] != '|') && i < str.size())
						{
							first.push_back(str[i]);
							i++;
						}

						if (str[i] == '|' || i == str.size())
						{

							if (first.size()) assignNpdaSymbolValue(first, idx++);
							cnfTable[npdaSymbol[leftString]].push_back(first);
							continue;
						}

						i++;
						if (i < str.size())
						while (str[i] != '|' && i < str.size())
						{
							second.push_back(str[i]);
							i++;
						}

						if (first.size()) assignNpdaSymbolValue(first, idx++);
						if (second.size()) assignNpdaSymbolValue(second, idx++);

						cnfTable[npdaSymbol[leftString]].push_back(first + " " + second);
					}


				}


	}

	public: bool npdaAlgorithm(int indx, string current)
	{
				if (grammer[indx] == "$" && current.size() == 0)
				{
					ischeckfinished = true;
					return true;
				}
				if (grammer[indx] == "$" && current.size() != 0)
				{
					return false;
				}

				else if (grammer[indx] != "$" && current.size() == 0)
				{
					return false;
				}

				if (ischeckfinished)
					return true;

				this->lastTextBox->Text += gcnew String(current.c_str()) + "\r\n";

				string term = "";

				// Calculation of dividing the first symbol
				while (current[0] != ' ' &&  current.size() > 0)
				{
					term.push_back(current[0]);
					current.erase(current.begin());
					if (current[0] == ' ')
					{
						current.erase(current.begin());
						break;
					}
				}


				int neumericVal = npdaSymbol[term];


				if (term[0] >= 'A'&&term[0] <= 'Z')
				{

					for (int i = 0; i < cnfTable[neumericVal].size(); i++)
					{
						bool ret = npdaAlgorithm(indx, cnfTable[neumericVal][i] + " " + current);
						if (ret)
						{
							return true;
						}

					}
					return false;

				}
				else
				{


					if (term == grammer[indx])
					{
						bool ret = npdaAlgorithm(indx + 1, current);
						if (!ret)
						{
							return ret;
						}
					}
					else
					{
						return false;
					}

				}

	}

	public:void calculateFirstOfGrammers()
	{
			   for (int i = 0; i < Nonterminal.size(); i++)
			   {
				   int main_idx = noOfSymbol[Nonterminal[i]];

				   queue<string>q;

				   q.push(Nonterminal[i]);

				   while (!q.empty())
				   {

					   string Non = q.front();
					   q.pop();
					   int idx = noOfSymbol[Non];

					   for (int j = 1; j <= totProduction[idx]; j++)
					   {
						   if (splitgrammer[idx][j][0][0] >= 'A'&&splitgrammer[idx][j][0][0] <= 'Z')
							   q.push(splitgrammer[idx][j][0]);
						   else
							   FIRST[main_idx].push_back(splitgrammer[idx][j][0]);
					   }
				   }

			   }
	}

	public: void calculateFollowOfGrammers()
	{
				for (int i = 0; i < Nonterminal.size(); i++)
				{
					int idx = noOfSymbol[Nonterminal[i]];
					if (Nonterminal[i] == "S")
						FOLLOW[idx].push_back("$");

					for (int k = 1; k <= totProduction[idx]; k++)
					{
						vector<string>v;
						for (int j = 0; j < splitgrammer[idx][k].size(); j++)
						{
							v.push_back(splitgrammer[idx][k][j]);
						}

						if (v.size() == 1)
						{
							string tmp1 = v[0];

							if ((tmp1[0] >= 'A'&&tmp1[0] <= 'Z'))
							{
								int idx2 = noOfSymbol[tmp1];
								if (FOLLOW[idx2].size() == 0)
								{
									for (int x = 0; x < FOLLOW[idx].size(); x++)
									{
										FOLLOW[idx2].push_back(FOLLOW[idx][x]);
									}
									FOLLOW[idx2].push_back("$");
								}
							}
						}
						else
						{
							string tmp1, tmp2;
							tmp1 = v[0];
							tmp2 = v[1];
							if ((tmp1[0] >= 'A'&&tmp1[0] <= 'Z') && (tmp2[0] >= 'A'&&tmp2[0] <= 'Z'))
							{
								int idx1 = noOfSymbol[tmp1];
								int idx2 = noOfSymbol[tmp2];
								if (FOLLOW[idx1].size() == 0)
								for (int x = 0; x < FIRST[idx2].size(); x++)
								{
									FOLLOW[idx1].push_back(FIRST[idx2][x]);
								}
							}

							if ((tmp1[0] >= 'a'&&tmp1[0] <= 'z') && (tmp2[0] >= 'A'&&tmp2[0] <= 'Z'))
							{
								int idx2 = noOfSymbol[tmp2];
								if (FOLLOW[idx2].size() == 0)
								for (int x = 0; x < FOLLOW[idx].size(); x++)
								{
									FOLLOW[idx2].push_back(FOLLOW[idx][x]);
								}
							}

							tmp1 = v[v.size() - 1];
							tmp2 = v[v.size() - 2];

							if ((tmp1[0] >= 'A'&&tmp1[0] <= 'Z') && (tmp2[0] >= 'A'&&tmp2[0] <= 'Z'))
							{
								int idx1 = noOfSymbol[tmp1];
								if (FOLLOW[idx1].size() == 0)
									FOLLOW[idx1].push_back("$");
							}
						}
					}
				}
	}

	public: void generateParseTable()
	{
				for (int i = 0; i < Nonterminal.size(); i++)
				{
					int idx = noOfSymbol[Nonterminal[i]];

					for (int j = 1; j <= totProduction[idx]; j++)
					{

						string str = splitgrammer[idx][j][0];

						if (str[0] == '#')
						{
							for (int num = 0; num < FOLLOW[idx].size(); num++)
							{
								int idxTerminal = noOfSymbol[FOLLOW[idx][num]];

								parseTable[idx][idxTerminal].push_back("#");

								if (FOLLOW[idx][num] == "$")
								{
									parseTable[idx][idxTerminal].push_back("#");
								}
							}
						}



						else if (str[0] >= 'A' && str[0] <= 'Z')
						{
							int idxCurrent = noOfSymbol[str];

							for (int num = 0; num < FIRST[idxCurrent].size(); num++)
							{
								int idxTerminal = noOfSymbol[FIRST[idxCurrent][num]];
								for (int k = 0; k < splitgrammer[idx][j].size(); k++)
									parseTable[idx][idxTerminal].push_back(splitgrammer[idx][j][k]);
							}

						}
						else
						{
							int idxTerminal = noOfSymbol[str];

							for (int k = 0; k < splitgrammer[idx][j].size(); k++)
								parseTable[idx][idxTerminal].push_back(splitgrammer[idx][j][k]);
						}
					}

				}
	}

	public: void preprocessingOfParseTable()
	{
				StreamReader^ reader = File::OpenText("resource/ppGrammers.txt");
				String^ readString;
				int idx = 1, idx_term = 1;
				noOfSymbol["$"] = 0;

				while ((readString = reader->ReadLine()) != nullptr)
				{
					string s = marshal_as<std::string>(readString);

					string left = "";
					int i = 0;
					while (s[i] != '-')
					{
						left += s[i];
						i++;
					}

					if (noOfSymbol.find(left) == noOfSymbol.end())
					{
						noOfSymbol[left] = idx++;
						Nonterminal.push_back(left);
					}

					string temp = "";
					int noofProduction = 1;
					for (i = i + 1; s[i]; i++)
					{
						if (s[i] == ' ')
						{
							if (noOfSymbol.find(temp) == noOfSymbol.end())
							{
								if (temp[0] >= 'A'&&temp[0] <= 'Z')
								{
									noOfSymbol[temp] = idx++;
									Nonterminal.push_back(temp);
								}
								else
								{
									noOfSymbol[temp] = idx_term++;
									terminal.push_back(temp);
								}
							}

							splitgrammer[noOfSymbol[left]][noofProduction].push_back(temp);
							temp = "";
						}
						else if (s[i] == '|')
						{
							if (noOfSymbol.find(temp) == noOfSymbol.end())
							{
								if (temp[0] >= 'A'&&temp[0] <= 'Z')
								{
									noOfSymbol[temp] = idx++;
									Nonterminal.push_back(temp);
								}
								else
								{
									noOfSymbol[temp] = idx_term++;
									terminal.push_back(temp);
								}
							}
							splitgrammer[noOfSymbol[left]][noofProduction].push_back(temp);
							temp = "";
							noofProduction++;
						}
						else
							temp += s[i];
					}
					if (noOfSymbol.find(temp) == noOfSymbol.end())
					{
						if (temp[0] >= 'A'&&temp[0] <= 'Z')
						{
							noOfSymbol[temp] = idx++;
							Nonterminal.push_back(temp);
						}
						else
						{
							noOfSymbol[temp] = idx_term++;
							terminal.push_back(temp);
						}
					}

					splitgrammer[noOfSymbol[left]][noofProduction].push_back(temp);

					totProduction[noOfSymbol[left]] = noofProduction;
				}
	}

	public: void genParseTable()
	{
				preprocessingOfParseTable();
				calculateFirstOfGrammers();
				calculateFollowOfGrammers();


				generateParseTable();

	}

	public: bool predictiveParsingAlgorithm()
	{
				stack<string> st;


				st.push("S");
				int idx = 0;

				while (!st.empty())
				{
					string temp = st.top();
					st.pop();

					if (temp[0] >= 'a' && temp[0] <= 'z')
					{

						this->lastTextBox->Text += gcnew String(temp.c_str());
						this->lastTextBox->Text += gcnew String(grammer[idx].c_str()) + "\r\n";
						if (temp != grammer[idx] || idx >= (int)grammer.size())
						{
							return false;
						}
						else
						{
							idx++;
						}

					}
					else if (temp[0] >= 'A' && temp[0] <= 'Z')
					{
						int nonIdx = noOfSymbol[temp];
						int terIdx = noOfSymbol[grammer[idx]];


						if (parseTable[nonIdx][terIdx].size() == 0)//Empty of the parsing table 
						{
							return false;
						}

						for (int i = parseTable[nonIdx][terIdx].size() - 1; i >= 0; i--)
						{
							if (parseTable[nonIdx][terIdx][i] != "#")
							{
								st.push(parseTable[nonIdx][terIdx][i]);
							}
						}
					}
					else
					{

					}

				}
				return true;


	}
	public: Void getGrammer()
	{

				grammer.clear();
				for each(String ^ str in grammerWords)
				{
					if (str == nullptr) break;

					std::string stdString = marshal_as<std::string>(str);

					grammer.push_back(stdString);

				}

				grammer.push_back("$");

	}
	public: string checkWordWithBivokti(wstring index)
	{
				wstring compString = L"";
				for (int i = 0; i < index.size(); i++)
				{
					compString += index[i];

					if (hash.find(compString) != hash.end())
					{
						wstring bivoktiString = L"";

						for (int j = i + 1; j < index.size(); j++)
							bivoktiString += index[j];

						if (bivoktiMap.find(bivoktiString) != bivoktiMap.end())
						{
							return (hash.find(compString)->second).c_str();
						}
					}
				}
				return "";
	}

	public: System::Void xmlReadFunction()  // This function reads data from xml file and save into two txt files
	{


				XmlTextReader ^ xReader = gcnew XmlTextReader("resource/word.xml");
				wstring Index = L"";
				string Key = "";
				int cnt = 0;
				while (xReader->Read())
				{
					switch (xReader->NodeType)
					{
					case XmlNodeType::Element:
					{
												 Index = marshal_as<std::wstring>(xReader->Name);
					}break;
					case XmlNodeType::Text:
					{
											  Key = marshal_as<std::string>(xReader->Value);
					}break;
					case XmlNodeType::EndElement:
					{
													hash[Index] = Key;
					}break;

					default:
						break;
					}

				}

				XmlTextReader ^ xmlReader = gcnew XmlTextReader("temp/generatedXml.xml");
				Index = L"";
				Key = "";
				cnt = 0;
				while (xmlReader->Read())
				{
					switch (xmlReader->NodeType)
					{
					case XmlNodeType::Element:
					{
												 Index = marshal_as<std::wstring>(xmlReader->Name);
					}break;
					case XmlNodeType::Text:
					{
											  Key = marshal_as<std::string>(xmlReader->Value);
					}break;
					case XmlNodeType::EndElement:
					{
													hash[Index] = Key;
					}break;

					default:
						break;
					}

				}

				xmlReader->Close();
				return;


	}

	public:System::Void splitInputText()
	{

			   Array::Clear(grammerWords, 0, grammerWords->Length);

			   for (int i = 0; i <= 100; i++)
			   {
				   Array::Clear(allGrammerWords, 0, allGrammerWords->Length);
			   }


			   String ^ inputText = this->mainTextBox->Text;
			   wstring wInputText = marshal_as<std::wstring>(inputText);

			   String^ lineEndSymbol = "।";

			   /*These are the delimiters
			   */
			   delimiterMarker[L' '] = 1;
			   delimiterMarker[L':'] = 1;
			   delimiterMarker[L','] = 1;
			   delimiterMarker[L';'] = 1;

			   /*these are sentence breaker*/
			   delimiterMarker[L'।'] = 2;
			   delimiterMarker[L'?'] = 2;

			   wstring curString;
			   int indx = 0;
			   totalSentences = 0;


			   for (int i = 0; i < wInputText.size(); i++)
			   {
				   // mainTextBox->Text += gcnew String(wInputText[i].ToString()) +" " + delimiterMarker[wInputText[i]].ToString() + "\t\n";

				   if (delimiterMarker.find(wInputText[i]) == delimiterMarker.end())
				   {
					   //mainTextBox->Text += gcnew String(wInputText[i].ToString()) + "\n";
					   curString.push_back(wInputText[i]);
				   }
				   else if (delimiterMarker[wInputText[i]] == 1)
				   {
					   //mainTextBox->Text += gcnew String(curString.c_str()) + "\t\n";
					   if (curString.size() > 0)
						   allGrammerWords[totalSentences, indx++] = gcnew String(curString.c_str());
					   curString.clear();
				   }
				   else if (delimiterMarker[wInputText[i]] == 2)
				   {
					   if (curString.size())
					   {
						   allGrammerWords[totalSentences, indx++] = gcnew String(curString.c_str());
						   curString.clear();
					   }
					   totalSentences++;
					   indx = 0;
				   }
			   }
			   // if more remains
			   if (curString.size())
			   {
				   allGrammerWords[totalSentences, indx++] = gcnew String(curString.c_str());
				   curString.clear();
			   }
			   if (indx > 0)
			   {
				   totalSentences++;
				   indx = 0;
			   }


			   int i = 0;
			   for (int firstIndex = 0; firstIndex < totalSentences; firstIndex++)
			   {
				   for (int innerIndex = 0;; innerIndex++)
				   {
					   String ^ currentWord = allGrammerWords[firstIndex, innerIndex];

					   if (currentWord == nullptr)
					   {
						   break;
					   }


					   // ager motow kaj

					   wstring index = marshal_as<std::wstring>(currentWord);

					   //this->lastTextBox->Text += " " + gcnew String(index.c_str()) + " ";

					   it = hash.find(index);
					   if (it == hash.end())
					   {
						   if (checkWordWithBivokti(index) != "")
						   {

							   //it = hash.find(compString);
							   // this->lastTextBox->Text += " " + gcnew String((it->second).c_str());
							   // grammerWords[i++] = gcnew String((it->second).c_str());

							   continue;
						   }

						   addingPosForm ^ newForm = gcnew addingPosForm(currentWord);
						   newForm->ShowDialog();

						   string returnStringFromAddingPosForm = marshal_as<std::string>(newForm->comboBox->Text);

						   //newForm->Close();
						   if (returnStringFromAddingPosForm.size() != 0)
						   {

							   //this->lastTextBox->Text += " " + gcnew String(returnStringFromAddingPosForm.c_str());
							   //grammerWords[i++] = gcnew String(returnStringFromAddingPosForm.c_str());

							   hash[index] = returnStringFromAddingPosForm;

							   //lastTextBox->Text += gcnew String( hash[index].c_str()) + " ";

							   continue;
						   }

						   //this->lastTextBox->Text += currentWord + "not found :(" ;

						   notFound = true;
						   //return;

					   }
					   else
					   {
						   //this->lastTextBox->Text += " " + gcnew String((it->second).c_str());
						   //grammerWords[i++] = gcnew String((it->second).c_str());
					   }

				   }
			   }

			   /*
			   for each (String ^ str in words)
			   {
			   if (str == " ") continue;
			   /*string temp = marshal_as<std::string>(str);
			   if (temp== "\u0964")
			   {
			   mainTextBox->Text += " break hoise";
			   tot_word.push_back(i);
			   tot_line++, i = 0;
			   continue;
			   //break;
			   }
			   */

			   // XmlNodeList^ elemList = doc->GetElementsByTagName(str);

			   //mainTextBox->Text += str + " ";
			   /*
				  wstring index = marshal_as<std::wstring>(str);

				  it = hash.find(index);
				  if (it == hash.end())
				  {
				  wstring compString = L"";
				  bool Found = false;

				  for (int i = 0; i < index.size(); i++)
				  {
				  compString += index[i];
				  if (hash.find(compString) != hash.end())
				  {
				  wstring bivoktiString = L"";

				  for (int j = i + 1; j < index.size(); j++)
				  bivoktiString += index[j];

				  if (bivoktiMap.find(bivoktiString) != bivoktiMap.end())
				  {
				  Found = true;
				  break;
				  }
				  }
				  }

				  if (Found)
				  {
				  it = hash.find(compString);
				  this->lastTextBox->Text += " " + gcnew String((it->second).c_str());
				  grammerWords[i++] = gcnew String((it->second).c_str());
				  continue;
				  }

				  addingPosForm ^ newForm = gcnew addingPosForm(str);
				  newForm->ShowDialog();

				  string returnStringFromAddingPosForm = marshal_as<std::string>(newForm->comboBox->Text);

				  //newForm->Close();
				  if (returnStringFromAddingPosForm.size() != 0)
				  {
				  this->lastTextBox->Text += " " + gcnew String(returnStringFromAddingPosForm.c_str());
				  grammerWords[i++] = gcnew String(returnStringFromAddingPosForm.c_str());

				  hash[index] = returnStringFromAddingPosForm;

				  //lastTextBox->Text += gcnew String( hash[index].c_str()) + " ";

				  continue;
				  }

				  this->lastTextBox->Text += str + " not found :( " + "\r\n";

				  notFound = true;
				  //return;

				  }
				  else
				  {
				  this->lastTextBox->Text += " " + gcnew String((it->second).c_str());
				  grammerWords[i++] = gcnew String((it->second).c_str());
				  }


				  }
				  */

			   // getGrammer();
	}

	private: void readBivokti(){
				 StreamReader^ reader = File::OpenText("resource/bivokti.txt");
				 String^ readString;

				 while ((readString = reader->ReadLine()) != nullptr)
				 {
					 wstring index = marshal_as<std::wstring>(readString);

					 bivoktiMap[index] = true;
				 }

				 return;
	}

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 readBivokti();
				 userTimer timer;
				 timer.start();
				 xmlReadFunction();
				 double timeElapsed = timer.elapsedTime();

				 this->boxPreporcessing->Text = "XML Preprocessing Time: " + timeElapsed.ToString()+"sec" + "\r\n";
				 
				 timer.start();
				 genParseTable();
				 timeElapsed = timer.elapsedTime();
				 this->boxPreporcessing->Text += "Parse Table Generation Time: " + timeElapsed.ToString() + "sec" + "\r\n";
				 this->boxPreporcessing->Text += "NPDA Preprocessing Time: " + "0.000" + "sec" + "\r\n";
				 makeCnfTable();
				 

				 this->lastTextBox->Text = timeElapsed.ToString();
	}

	public: bool checkIfRunAlgorithm(int firstIndex)
	{
				Array::Clear(grammerWords, 0, grammerWords->Length);

				showSentence = "";

				for (int innerIndex = 0;; innerIndex++)
				{
					String ^ currentWord = allGrammerWords[firstIndex, innerIndex];

					if (currentWord == nullptr)
					{
						break;
					}
					showSentence = showSentence + " " + currentWord;
					wstring current = marshal_as<std::wstring>(currentWord);
					it = hash.find(current);
					if (it == hash.end())
					{
						string ret = checkWordWithBivokti(current);
						if (ret == "")
						{
							lastTextBox->Text += currentWord + " Not found " + "\r\n";

							return false;
						}
						else
						{
							grammerWords[innerIndex] = gcnew String(ret.c_str());
						}
					}
					else
					{
						grammerWords[innerIndex] = gcnew String((it->second).c_str());
					}
				}

				return true;

	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

				 this->lastTextBox->Text = "";
				 boxExecution->Text = "";
				 grammer.clear();
				 notFound = false;
				 splitInputText();

				 userTimer timer;
				 timer.start();

				 for (int firstIndex = 0; firstIndex < totalSentences; firstIndex++)
				 {
					 bool result;
					 if (checkIfRunAlgorithm(firstIndex))
					 {
						 getGrammer();
						 result = predictiveParsingAlgorithm();
					 }
					 else
					 {
						 result = false;
					 }

					 if (result)
					 {
						 lastTextBox->Text += showSentence + "-->" + "Accepted" + "\r\n";
					 }
					 else
					 {
						 lastTextBox->Text += showSentence + "-->" + "Not Accepted" + "\r\n";
					 }


				 }

				 double timeElapsed = timer.elapsedTime();
				
				 boxExecution->Text += "Predictive parsing time: " + timeElapsed.ToString() + "sec" + "\r\n";
				 /*
				 for (int i = 0; i < totalSentences; i++)
				 {
				 Array::Clear(grammerWords, 0, grammerWords->Length);
				 for (int j = 0; j < tot_word[i]; j++)
				 {
				 //mainTextBox->Text += " " + allGrammerWords[i, j];
				 grammerWords[j] = allGrammerWords[i, j];
				 }
				 getGrammer();
				 predictiveParsingAlgorithm();
				 }
				 if (!notFound)
				 {
				 this->lastTextBox->Text = "";

				 predictiveParsingAlgorithm();
				 }*/

	}
	private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {

				 this->lastTextBox->Text = "";
				 boxExecution->Text = "";
				 splitInputText();
				 /*
				 if (!notFound)
				 {
				 ischeckfinished = false;

				 this->lastTextBox->Text = "";
				 bool ret = npdaAlgorithm(0, "S");

				 if (ischeckfinished)
				 {
				 this->lastTextBox->Text += "Sentence is Accepted";
				 }
				 else
				 this->lastTextBox->Text += "Sentence is not Accepted";
				 }
				 */
				 userTimer timer;
				 timer.start();

				 for (int firstIndex = 0; firstIndex < totalSentences; firstIndex++)
				 {
					 bool result;
					 ischeckfinished = false;

					 if (checkIfRunAlgorithm(firstIndex))
					 {
						 ischeckfinished = false;
						 getGrammer();
						 result = npdaAlgorithm(0, "S");
					 }
					 else
					 {
						 result = false;
					 }

					 if (ischeckfinished)
					 {
						 lastTextBox->Text += showSentence + "-->" + "Accepted" + "\r\n";
					 }
					 else
					 {
						 lastTextBox->Text += showSentence + "-->" + "Not Accepted" + "\r\n";
					 }


				 }

				 double timeElapsed = timer.elapsedTime();

				 boxExecution->Text += "NPDA parsing time: " + timeElapsed.ToString() + "sec" + "\r\n";

	}
	private: System::Void exitButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
	}
	private: System::Void headingLabel_Click(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void openFileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

				 mainTextBox->Text = "";

				 Stream ^ fileStream;

				 OpenFileDialog ^ fileDialog = gcnew OpenFileDialog;
				 fileDialog->ShowHelp = true;

				 if (fileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 if ((fileStream = fileDialog->OpenFile()) != nullptr)
					 {
						 String ^ filename = fileDialog->InitialDirectory + fileDialog->FileName;

						 StreamReader^ reader = File::OpenText(filename);
						 String^ readString;

						 while ((readString = reader->ReadLine()) != nullptr)
						 {
							 mainTextBox->Text += readString;
						 }
						 reader->Close();

						 fileStream->Close();
					 }
				 }
	}
	private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 aboutForm ^ aboutform = gcnew aboutForm();
				 aboutform->Show();
	}
	private: System::Void viewPosButtonFunction(System::Object^  sender, System::EventArgs^  e) {
				 splitInputText();

				 lastTextBox->Text = "";

				 for (int i = 0; i < totalSentences; i++)
				 {
					 for (int inner = 0;; inner++)
					 {
						 String ^ curString = allGrammerWords[i, inner];

						 if (curString == nullptr) break;

						 wstring current = marshal_as<std::wstring>(curString);
						 it = hash.find(current);
						 if (it == hash.end())
						 {
							 lastTextBox->Text += " *";
						 }
						 else
						 {
							 lastTextBox->Text += " " + gcnew String(it->second.c_str());
						 }
					 }

					 lastTextBox->Text += ". ";
				 }
	}
	};

}