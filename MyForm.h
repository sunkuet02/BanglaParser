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

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	map<string, int> noOfSymbol,npdaSymbol;
	vector<string >grammer;
	vector<string> parseTable[10][10],cnfTable[10];
	vector<int>tot_word;
	bool notFound = false;
	bool ischeckfinished;
	int tot_line;

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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// mainTextBox
			// 
			this->mainTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mainTextBox->Location = System::Drawing::Point(12, 43);
			this->mainTextBox->Multiline = true;
			this->mainTextBox->Name = L"mainTextBox";
			this->mainTextBox->Size = System::Drawing::Size(255, 220);
			this->mainTextBox->TabIndex = 0;
			// 
			// lastTextBox
			// 
			this->lastTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lastTextBox->Location = System::Drawing::Point(397, 43);
			this->lastTextBox->Multiline = true;
			this->lastTextBox->Name = L"lastTextBox";
			this->lastTextBox->ReadOnly = true;
			this->lastTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->lastTextBox->Size = System::Drawing::Size(298, 220);
			this->lastTextBox->TabIndex = 1;
			// 
			// sendButton
			// 
			this->sendButton->Location = System::Drawing::Point(273, 80);
			this->sendButton->Name = L"sendButton";
			this->sendButton->Size = System::Drawing::Size(118, 23);
			this->sendButton->TabIndex = 2;
			this->sendButton->Text = L"Predictive Parse";
			this->sendButton->UseVisualStyleBackColor = true;
			this->sendButton->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// exitButton
			// 
			this->exitButton->Location = System::Drawing::Point(299, 286);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(92, 23);
			this->exitButton->TabIndex = 3;
			this->exitButton->Text = L"Exit";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &MyForm::exitButton_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(273, 167);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(122, 23);
			this->button1->TabIndex = 5;
			this->button1->Text = L"NPDA";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(234, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(175, 39);
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(707, 321);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->sendButton);
			this->Controls->Add(this->lastTextBox);
			this->Controls->Add(this->mainTextBox);
			this->Name = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		array<String^>^ words;


		array<String^>^ grammerWords = gcnew array<String^>(50);

		array<String^, 2>^ AllgrammerWords = gcnew array<String^, 2>(50, 50);


		array<String^>^ MainInput;


		
		
#pragma endregion

		// table for npda

		public: void makeCnfTable()
		{
					cnfTable[1].push_back("NP VP");
					cnfTable[2].push_back("pron");
					cnfTable[2].push_back("A NP1");
					cnfTable[2].push_back("noun");
					cnfTable[2].push_back("NP1 NP2");
					cnfTable[3].push_back("noun");
					cnfTable[4].push_back("P1 VP1");
					cnfTable[4].push_back("verb");
					cnfTable[4].push_back("VP2 VP3");
					cnfTable[4].push_back("B NP1");
					cnfTable[5].push_back("verb");
					cnfTable[6].push_back("pron");
					cnfTable[6].push_back("noun");
					cnfTable[7].push_back("adv");
					cnfTable[8].push_back("C NP1");
					cnfTable[9].push_back("NP1 VP1");
					cnfTable[10].push_back("VP1");
					cnfTable[11].push_back("conj");
					cnfTable[12].push_back("adj");

		}

		public: void assignNpdaSymbols()
		{
					//Non-terminal
					npdaSymbol["S"] = 1;
					npdaSymbol["NP"] = 2;
					npdaSymbol["NP1"] = 3;
					npdaSymbol["VP"] = 4;
					npdaSymbol["VP1"] = 5;
					npdaSymbol["P1"] = 6;
					npdaSymbol["A"] = 7;
					npdaSymbol["NP2"] = 8;
					npdaSymbol["VP2"] = 9;
					npdaSymbol["VP3"] = 10;
					npdaSymbol["C"] = 11;
					npdaSymbol["B"] = 12;



					//terminal
					npdaSymbol["noun"] = 101;
					npdaSymbol["pron"] = 102;
					npdaSymbol["verb"] = 103;
					npdaSymbol["adv"] = 104;
					npdaSymbol["adj"] = 105;
					npdaSymbol["conj"] = 106;

					makeCnfTable();

		}


		bool npdaAlgorithm(int indx, string current)
		{
			if (grammer[indx] == "$" && current.size() == 0)
			{
				ischeckfinished = true;
				return true;
			}

			else if (grammer[indx] != "$" && current.size() == 0)
			{
				return false;
			}

			//if (indx == 3)
					//{
						//lastTextBox->Text = "-" + gcnew String(current.c_str()) + "-" + current.size() + "    ";
					//}
			//lastTextBox->Text += gcnew String(current.c_str()) + "-"+ indx + "    ";
			if (ischeckfinished)
				return true;
			//lastTextBox->Text += "Call hoiche";

			//int neumericVal = npdaSymbol[current];

			lastTextBox->Text += "  " + gcnew String(current.c_str())+"\r\n";
			//lastTextBox->Text +=" "+ neumericVal;
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
					/*if (term == "NP")
					{
						//lastTextBox->Text +=    "   "   + cnfTable[npdaSymbol["NP"]].size() + "   "  + ret + "   " + i + "  "  ;
					}*/
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












			/*

			for (int j = 0; j < cnfTable[neumericVal].size(); j++)
			{
				//lastTextBox->Text += "  " + gcnew String(cnfTable[neumericVal][j].c_str());
				//terminal
				if (cnfTable[neumericVal][j][0] >= 'a'&&cnfTable[neumericVal][j][0] <= 'z')
				{
					if (cnfTable[neumericVal][j] == grammer[idx_npda])
					{
						idx_npda++;
						//lastTextBox->Text += " " + idx_npda;
						lastTextBox->Text += " " + gcnew String(grammer[idx_npda-1].c_str());
						if (idx_npda+1 == grammer.size())
						{
							lastTextBox->Text += "Sentence is  accepted";
							return;
						}
					}
					else
					{
						//rejected
						lastTextBox->Text +=" "+ "Sentence is not accepted";
						return;
					}
				}
				//non-terminal
				else
				{
					npdaAlgorithm(cnfTable[neumericVal][j]);
				}
				
			}
			*/
			//lastTextBox->Text += " "+grammer.size();
			//if (idx_npda >= grammer.size())
			//lastTextBox->Text += "Sentence is  accepted";
		}

		public: void assignNumToSymbol()
		{
			noOfSymbol["S"] = 1;
			noOfSymbol["NP"] = 2;
			noOfSymbol["NP1"] = 3;
			noOfSymbol["NP2"] = 4;
			noOfSymbol["AP"] = 5;
			noOfSymbol["AP1"] = 6;
			noOfSymbol["AP2"] = 7;
			noOfSymbol["VP"] = 8;
			noOfSymbol["VP1"] = 9;
			noOfSymbol["VP2"] = 10;
			noOfSymbol["VP3"] = 11;
			noOfSymbol["VP4"] = 12;
			noOfSymbol["VP5"] = 13;
			noOfSymbol["noun"] = 1;
			noOfSymbol["pron"] = 2;
			noOfSymbol["adv"] = 3;
			noOfSymbol["adj"] = 4;
			noOfSymbol["conj"] = 5;
			noOfSymbol["verb"] = 6;
			noOfSymbol["$"] = 7;
		}

		void genParseTable()
		{
			assignNumToSymbol();

			parseTable[1][1].push_back("NP");
			parseTable[1][1].push_back("VP");
			parseTable[1][2].push_back("NP");
			parseTable[1][2].push_back("VP");
			parseTable[1][3].push_back("NP");
			parseTable[1][3].push_back("VP");
			parseTable[1][4].push_back("NP");
			parseTable[1][4].push_back("VP");

			parseTable[2][1].push_back("noun");
			parseTable[2][1].push_back("NP1");
			parseTable[2][2].push_back("pron");
			parseTable[2][2].push_back("NP2");
			parseTable[2][3].push_back("adv");
			parseTable[2][3].push_back("noun");
			parseTable[2][4].push_back("AP");

			parseTable[3][1].push_back("#");//# means epsilon
			parseTable[3][2].push_back("#");
			parseTable[3][4].push_back("#");
			parseTable[3][5].push_back("conj");
			parseTable[3][5].push_back("noun");
			parseTable[3][6].push_back("#");

			parseTable[4][1].push_back("#");//# means epsilon
			parseTable[4][2].push_back("#");
			parseTable[4][4].push_back("#");
			parseTable[4][5].push_back("conj");
			parseTable[4][5].push_back("pron");
			parseTable[4][6].push_back("#");

			parseTable[5][4].push_back("adj");
			parseTable[5][4].push_back("AP1");
			parseTable[5][6].push_back("#");

			parseTable[6][1].push_back("noun");
			parseTable[6][2].push_back("pron");
			parseTable[6][4].push_back("adj");
			parseTable[6][4].push_back("AP2");
			parseTable[6][5].push_back("conj");
			parseTable[6][5].push_back("AP");
			parseTable[6][7].push_back("#");

			parseTable[7][1].push_back("#");
			parseTable[7][2].push_back("#");
			parseTable[7][4].push_back("#");
			parseTable[7][6].push_back("verb");
			parseTable[7][7].push_back("#");

			parseTable[8][1].push_back("noun");
			parseTable[8][1].push_back("VP1");
			parseTable[8][2].push_back("pron");
			parseTable[8][2].push_back("AP");
			parseTable[8][2].push_back("verb");
			parseTable[8][4].push_back("AP");
			parseTable[8][4].push_back("VP3");
			parseTable[8][6].push_back("verb");
			//parseTable[8][6].push_back("verb");
			parseTable[8][6].push_back("VP2");

			parseTable[9][4].push_back("adj");
			parseTable[9][4].push_back("noun");
			parseTable[9][6].push_back("verb");
			parseTable[9][6].push_back("VP4");

			parseTable[10][6].push_back("verb");
			parseTable[10][7].push_back("#");

			parseTable[11][1].push_back("noun");
			parseTable[11][4].push_back("adj");
			parseTable[11][4].push_back("VP5");
			parseTable[11][6].push_back("verb");
			parseTable[11][7].push_back("#");

			parseTable[12][6].push_back("verb");
			parseTable[12][7].push_back("#");

			parseTable[13][4].push_back("adj");
			parseTable[13][4].push_back("verb");

			parseTable[13][6].push_back("verb");

		}

		void parseAlgorithm()
		{
			//lastTextBox->Text="";
			//lastTextBox->Text +=mainTextBox->Text;
			//lastTextBox->Text +=" "+ "kaj hoise mone hoy ";

			

			stack<string> st;

			//st.push("$");
			st.push("S");
			int idx = 0;

			while (!st.empty())
			{
				string temp = st.top();
				st.pop();
				//lastTextBox->Text += "  " + gcnew String(temp.c_str());
				if (temp[0] >= 'a' && temp[0] <= 'z')
				{
					
					lastTextBox->Text +=  gcnew String(temp.c_str());
					lastTextBox->Text +=  gcnew String(grammer[idx].c_str())+"\r\n";
					if (temp != grammer[idx] || idx >= (int)grammer.size())
					{
						
						lastTextBox->Text += "  "+"Sentence is not Accepted";
						return;
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
					//lastTextBox->Text += "  "+nonIdx;
					//lastTextBox->Text += "  " + terIdx;

					if (parseTable[nonIdx][terIdx].size() == 0)//Empty of the parsing table 
					{
						lastTextBox->Text +="  "+ "Sentence is not Accepted";
						return;
					}

					for (int i = parseTable[nonIdx][terIdx].size() - 1; i >= 0; i--)
					{
						if (parseTable[nonIdx][terIdx][i] != "#")
						{
							st.push(parseTable[nonIdx][terIdx][i]);
							//mainTextBox->Text += "  " + gcnew String(parseTable[nonIdx][terIdx][i].c_str());
							//mainTextBox->Text += "  " + i;
						}
					}
				}
				else
				{

				}
				//lastTextBox->Text += "  " + idx;
			}
			lastTextBox->Text+= " Sentence is Accepted!";
			
			
		}

		public:System::Void printMsg(string str)
		{
				   mainTextBox->Text = gcnew String(str.c_str());
		}

		public: Void getGrammer()
		{
			//vector<string> gram;
			grammer.clear();
			for each(String ^ str in grammerWords)
			{
				if (str == nullptr) break;

				std::string stdString = marshal_as<std::string>(str);

				grammer.push_back(stdString);

				//mainTextBox->Text += " "+(str) ;
			}

			grammer.push_back("$");
			
			//return gram;

		}

	public: System::Void xmlReadFunction()
	{
				String ^ inputText = mainTextBox->Text;

				String^ delimStr = " ,.:\t";

				array<Char>^ delimiter = delimStr->ToCharArray();



				words = inputText->Split(delimiter);

				XmlTextReader ^ xReader = gcnew XmlTextReader("word.xml");

				while (xReader->Read())
				{
					switch (xReader->NodeType)
					{
					case XmlNodeType::Element:
					{
												 mainTextBox->Text += (xReader->Name);
					}break;
					case XmlNodeType::Text:
					{
											  lastTextBox->Text += (" " + xReader->Value + "\n");

					}break;

					default:
						break;
					}

				}






	}

	public:System::Void splitInputText()
	{
			  // lastTextBox->Text += " "+"kire vai";

			   Array::Clear(grammerWords, 0, grammerWords->Length);

			   //grammerWords->Clear;
			   words->Clear;

			   String ^ inputText = mainTextBox->Text;

			   String^ lineEndSymbol = "।";
			  
			   //MainInput=mainTextBox->Text;

			  
			  // lastTextBox->Text += mainTextBox->Text;

			   String^ delimStr = ", .:\t\n";

			   array<Char>^ delimiter = delimStr->ToCharArray();



			   words = inputText->Split(delimiter);


			   XmlDocument^ doc = gcnew XmlDocument;
			   doc->Load("word.xml");

			   //Display all the book titles.
			   int i = 0;
			   //lastTextBox->Text += "";
			   for each (String ^ str in words)
			   {
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

				   XmlNodeList^ elemList = doc->GetElementsByTagName(str);

				   //mainTextBox->Text += str + " ";
				   

				   if (elemList->Count == 0)
				   {
					   lastTextBox->Text += str + " not found :( ";
					   notFound = true; 
					   //return;

				   }
				   else
				   grammerWords[i++] = ((elemList[0]->InnerXml));
				   //AllgrammerWords[tot_line,i++] = ((elemList[0]->InnerXml));

			   }

			  getGrammer();
	}



	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 genParseTable();
				 assignNpdaSymbols();
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

				 tot_line = 0;
				 grammer.clear();
				 notFound = false;
				 splitInputText();
				/*for (int i = 0; i < tot_line; i++)
				 {
					Array::Clear(grammerWords, 0, grammerWords->Length);
					for (int j = 0; j < tot_word[i]; j++)
					{
						//mainTextBox->Text += " " + AllgrammerWords[i, j];
						grammerWords[j] = AllgrammerWords[i, j];
					}
					 getGrammer();
					 parseAlgorithm();
				 }*/
				 if (!notFound)
				 {
					 lastTextBox->Text = "";
					 //genParseTable();
					 parseAlgorithm();
				 }
	}
	private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
				 grammer.clear();
				 notFound = false;


				 splitInputText();
				 if (!notFound)
				 {
					 ischeckfinished = false;
					 //genParseTable();
					 //parseAlgorithm();
					 lastTextBox->Text = "";
					 bool ret = npdaAlgorithm(0, "S");

					 if (ischeckfinished)
					 {
						 lastTextBox->Text += "Sentence is Accepted";
					 }
					 else
						 lastTextBox->Text += "Sentence is not Accepted";
				 }
	}
	private: System::Void exitButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
	}
	private: System::Void headingLabel_Click(System::Object^  sender, System::EventArgs^  e) {
	}

};

	
	

	
}