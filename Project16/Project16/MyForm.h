#pragma once
#include <iostream>
#include <string>
#include "client.h"
#include "MyForm1.h"
#include "constants.h"
std::string getPassword() {
	return password;
}
std::string getLogin() {
	return login;
}
namespace Project16 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: 
	System::Windows::Forms::Button^  logIn;
	

	protected:

	private: System::Windows::Forms::TextBox^  loginField;






	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;

	private: System::Windows::Forms::TextBox^  passwordField;
	private: System::Windows::Forms::Button^  create;
	private: System::Windows::Forms::Label^  result;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;


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
			this->logIn = (gcnew System::Windows::Forms::Button());
			this->loginField = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->passwordField = (gcnew System::Windows::Forms::TextBox());
			this->create = (gcnew System::Windows::Forms::Button());
			this->result = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->SuspendLayout();
			// 
			// logIn
			// 
			this->logIn->Location = System::Drawing::Point(21, 129);
			this->logIn->Name = L"logIn";
			this->logIn->Size = System::Drawing::Size(75, 23);
			this->logIn->TabIndex = 0;
			this->logIn->Text = L"log in";
			this->logIn->UseVisualStyleBackColor = true;
			this->logIn->Click += gcnew System::EventHandler(this, &MyForm::logIn_Click);
			// 
			// loginField
			// 
			this->loginField->Location = System::Drawing::Point(21, 38);
			this->loginField->Name = L"loginField";
			this->loginField->Size = System::Drawing::Size(210, 20);
			this->loginField->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(112, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(33, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Login";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(102, 66);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Password";
			// 
			// passwordField
			// 
			this->passwordField->Location = System::Drawing::Point(21, 82);
			this->passwordField->Name = L"passwordField";
			this->passwordField->Size = System::Drawing::Size(210, 20);
			this->passwordField->TabIndex = 2;
			this->passwordField->TextChanged += gcnew System::EventHandler(this, &MyForm::passwordField_TextChanged);
			// 
			// create
			// 
			this->create->Location = System::Drawing::Point(156, 129);
			this->create->Name = L"create";
			this->create->Size = System::Drawing::Size(75, 23);
			this->create->TabIndex = 3;
			this->create->Text = L"create";
			this->create->UseVisualStyleBackColor = true;
			this->create->Click += gcnew System::EventHandler(this, &MyForm::create_Click);
			// 
			// result
			// 
			this->result->AutoSize = true;
			this->result->Location = System::Drawing::Point(110, 177);
			this->result->Name = L"result";
			this->result->Size = System::Drawing::Size(0, 13);
			this->result->TabIndex = 6;
			this->result->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(261, 217);
			this->Controls->Add(this->result);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->create);
			this->Controls->Add(this->passwordField);
			this->Controls->Add(this->loginField);
			this->Controls->Add(this->logIn);
			this->Name = L"MyForm";
			this->Text = L"Chat";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void logIn_Click(System::Object^  sender, System::EventArgs^  e) {
		//std::string login;

		if (loginField->Text->Length != 0 && passwordField->Text->Length != 0) {
			for (int i = 0; i < loginField->Text->Length; i++) {
				login += System::Convert::ToChar(loginField->Text[i]);
			}

			for (int i = 0; i < passwordField->Text->Length; i++) {
				password += System::Convert::ToChar(loginField->Text[i]);
			}
			client = new Client(login, password);
			if (client->start(false)) {
				result->Text = "Succsesfull";
				//Sleep(2000);
				this->Hide();
				Project16::MyForm1 form1;
				form1.ShowDialog();
				delete client;
				exit(0);
			}
			else {
				result->Text = "Unsuccsesfull";
				//Sleep(2000);
				delete client;
			}
		}
		login.clear();
		password.clear();
		//std::cout << s << std::endl;
		

	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void create_Click(System::Object^  sender, System::EventArgs^  e) {
	//std::string login;
	if (loginField->Text->Length != 0 && passwordField->Text->Length != 0) {
		for (int i = 0; i < loginField->Text->Length; i++) {
			login += System::Convert::ToChar(loginField->Text[i]);
		}

		for (int i = 0; i < passwordField->Text->Length; i++) {
			password += System::Convert::ToChar(loginField->Text[i]);
		}
		client = new Client(login, password);
		if (client->start(true)) {
			result->Text = "Succsesfull";
			//Sleep(5000);
			this->Hide();
			Project16::MyForm1 form1;
			form1.ShowDialog();
			delete client;
			exit(0);
		}
		else {
			result->Text = "Unsuccsesfull";
			Sleep(2000);
			delete client;
		}
	}
	login.clear();
	password.clear();
}
private: System::Void passwordField_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
