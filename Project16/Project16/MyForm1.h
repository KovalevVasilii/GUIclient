#pragma once
#include "constants.h"
namespace Project16 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// —водка дл€ MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  toSomeone;
	protected:
		Thread ^ thread;
	private: System::Windows::Forms::TextBox^  chat;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  yourMassege;
	private: System::Windows::Forms::Button^  check;
	private: System::Windows::Forms::Label^  chat_label;
	private: System::Windows::Forms::Button^  getListUs;







	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->toSomeone = (gcnew System::Windows::Forms::TextBox());
			this->chat = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->yourMassege = (gcnew System::Windows::Forms::TextBox());
			this->check = (gcnew System::Windows::Forms::Button());
			this->chat_label = (gcnew System::Windows::Forms::Label());
			this->getListUs = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// toSomeone
			// 
			this->toSomeone->Location = System::Drawing::Point(33, 245);
			this->toSomeone->Multiline = true;
			this->toSomeone->Name = L"toSomeone";
			this->toSomeone->Size = System::Drawing::Size(70, 23);
			this->toSomeone->TabIndex = 0;
			this->toSomeone->TextChanged += gcnew System::EventHandler(this, &MyForm1::textBox1_TextChanged);
			// 
			// chat
			// 
			this->chat->Location = System::Drawing::Point(33, 31);
			this->chat->Multiline = true;
			this->chat->Name = L"chat";
			this->chat->ReadOnly = true;
			this->chat->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->chat->Size = System::Drawing::Size(312, 196);
			this->chat->TabIndex = 1;
			this->chat->TextChanged += gcnew System::EventHandler(this, &MyForm1::textBox2_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(190, 245);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"send";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// yourMassege
			// 
			this->yourMassege->Location = System::Drawing::Point(33, 288);
			this->yourMassege->Multiline = true;
			this->yourMassege->Name = L"yourMassege";
			this->yourMassege->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->yourMassege->Size = System::Drawing::Size(312, 166);
			this->yourMassege->TabIndex = 3;
			// 
			// check
			// 
			this->check->Location = System::Drawing::Point(109, 245);
			this->check->Name = L"check";
			this->check->Size = System::Drawing::Size(75, 23);
			this->check->TabIndex = 4;
			this->check->Text = L"start";
			this->check->UseVisualStyleBackColor = true;
			this->check->Click += gcnew System::EventHandler(this, &MyForm1::check_Click);
			// 
			// chat_label
			// 
			this->chat_label->AutoSize = true;
			this->chat_label->Location = System::Drawing::Point(30, 9);
			this->chat_label->Name = L"chat_label";
			this->chat_label->Size = System::Drawing::Size(29, 13);
			this->chat_label->TabIndex = 5;
			this->chat_label->Text = L"Chat";
			this->chat_label->Click += gcnew System::EventHandler(this, &MyForm1::label1_Click_1);
			// 
			// getListUs
			// 
			this->getListUs->Location = System::Drawing::Point(270, 245);
			this->getListUs->Name = L"getListUs";
			this->getListUs->Size = System::Drawing::Size(75, 23);
			this->getListUs->TabIndex = 6;
			this->getListUs->Text = L"list of users";
			this->getListUs->UseVisualStyleBackColor = true;
			this->getListUs->Click += gcnew System::EventHandler(this, &MyForm1::getListUs_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(382, 487);
			this->Controls->Add(this->getListUs);
			this->Controls->Add(this->chat_label);
			this->Controls->Add(this->check);
			this->Controls->Add(this->yourMassege);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->chat);
			this->Controls->Add(this->toSomeone);
			this->Name = L"MyForm1";
			this->Text = L"user";
			this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();
			thread = gcnew Thread(gcnew ThreadStart(this, &MyForm1::printTexts));
		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void MyForm1_Load(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	///
	//Thread listening = new Thread(new ThreadStart(client->listen()));


	///	!!!!!!thread = gcnew Thread(gcnew ThreadStart(this, &MyForm1::printTexts));!!!!!!!!!!!

	if (toSomeone->Text->Length != 0 && yourMassege->Text->Length)
	{
		for (int i = 0; i < toSomeone->Text->Length; i++) {
			toName += System::Convert::ToChar(toSomeone->Text[i]);
		}
		for (int i = 0; i < yourMassege->Text->Length; i++) {
			msg += System::Convert::ToChar(yourMassege->Text[i]);
		}
		client->process(toName, msg);
		texts.clear();
		texts += login;
		texts += ": ";
		texts += msg;
		texts += "\r\n";
		for (int i = 0; i < texts.length(); i++) {
			chat->Text += System::Convert::ToChar(texts[i]);
		}
		//chat->Text = "";
		//texts += "\r\n";
		/*texts += login;
		texts += ": ";
		texts +=msg;
		texts += "\r\n";
		client->process(toName, msg);
		for (int i = 0; i < texts.length(); i++) {
			chat->Text += System::Convert::ToChar(texts[i]);
		}


	}
	texts.clear();*/
		msg.clear();
		toName.clear();
	}
}
	//private: delegate System::Void  printText();
	private:  System::Void  SetChat(String^ str) {
		String^ Str;

		for (int i = 0; i < textsFrom.length(); i++) {
			Str += System::Convert::ToChar(textsFrom[i]);
		}
		if (str != Str) {
			//textsFrom.clear();
			//textsFrom = str;
			textsFrom.clear();
			for (int i = 0; i < str->Length; i++) {
				textsFrom += System::Convert::ToChar(str[i]);
			}
			textsFrom += "\r\n";
			if (textsFrom.length() != 0) {
				for (int i = 0; i < textsFrom.length(); i++) {
					chat->Text += System::Convert::ToChar(textsFrom[i]);
				}
			}

			textsFrom.clear();
		}
	}
	private:  System::Void  printTexts() {
		//TimerCallback tm
		//client->listen();
		while (true) {
			std::string str = client->listenStr(textsFrom);
			//textsFrom += str;
			String^ Str;
			try {
			for (int i = 0; i < str.length(); i++) {
				Str += System::Convert::ToChar(str[i]);
			}
				this->Invoke(gcnew Action<String^>(this, &MyForm1::SetChat), Str);
			}
			catch (...) {
				exit(1);
			}
		}
		//str = client->listen();

	}
private: System::Void check_Click(System::Object^  sender, System::EventArgs^  e) {
	try {
		thread->IsBackground = true;
		thread->Start();
	}
	catch(...){}
	/*std::string str=client->listenStr();
	textsFrom += str;

	if (str != "-1") {
		if (textsFrom.length() != 0) {
			for (int i = 0; i < textsFrom.length(); i++) {
				chat->Text += System::Convert::ToChar(textsFrom[i]);
			}
		}


		textsFrom.clear();
	}*/
}
private: System::Void label1_Click_1(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void getListUs_Click(System::Object^  sender, System::EventArgs^  e) {
	client->getUsers();
}
};
}
