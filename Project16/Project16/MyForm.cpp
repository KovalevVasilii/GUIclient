#include "MyForm.h"
#include "MyForm1.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Project16::MyForm form; //WinFormsTest - имя вашего проекта
	Project16::MyForm1 form1;
	//Client client(get)
	Application::Run(%form);

}
