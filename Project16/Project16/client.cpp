#include "client.h"
//#include <thread>
#include <iostream>
//#include "constants.h"
Client::Client(std::string Login, std::string Password)
{
	isFirst = true;
	password = Password;
	username = Login;
	firstName = Login;
	lastName = Login;
	setlocale(LC_ALL, "RUS");
	std::cout<<"TCP DEMO CLIENT"<<std::endl;
	if (WSAStartup(0x202, (WSADATA *)&buff[0]))
	{
		std::cout << "WSAStart error "<< WSAGetLastError() << std::endl;
		return ;
	}
	my_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (my_sock < 0)
	{
		std::cout << "Socket() error"<<WSAGetLastError() << std::endl;
		return;
	}
	dest_addr.sin_family = AF_INET;
	dest_addr.sin_port = htons(MY_PORT);
	HOSTENT *hst;

	if (inet_addr(SERVERADDR) != INADDR_NONE)
	{
		dest_addr.sin_addr.s_addr = inet_addr(SERVERADDR);
	}
	else
	{
		if (hst = gethostbyname(SERVERADDR))
		{
			((unsigned long *)&dest_addr.sin_addr)[0] =((unsigned long **)hst->h_addr_list)[0][0];
		}
		else
		{
			std::cout << "Invalid address"<<SERVERADDR << std::endl;
			closesocket(my_sock);
			WSACleanup();
			return ;
		}

	}
	if (connect(my_sock, (sockaddr *)&dest_addr,sizeof(dest_addr)))
	{
		std::cout << "Connect error. The server is currently offline!"<< WSAGetLastError() << std::endl;
		return ;
	}

	std::cout << "Successful connection with "<< SERVERADDR << std::endl;
	//start();
}


Client::~Client()
{
	char buf[1024];
	std::string loginStr = client_quitConversation(username);
	send(my_sock, loginStr.c_str(), loginStr.length(), 0);
	int bytesReceived;
	bytesReceived = recv(my_sock, buf, sizeof(buf), 0);
	buf[bytesReceived] = '\0';
	//std::cout << "\n" << buf;
	//Sleep(2000);
	//exit(0);
}

void Client::process(std::string toName, std::string msg) {
	//std::cout << "Enter your message to send\n"
		//<< "\t\or \\connect to connect with other user\n" << "\tor \\quit to quit" << std::endl;
	//while (true) {
	if (isFirst) {
		std::string sendMess = client_connect(username, toName);
		send(my_sock, sendMess.c_str(), sendMess.length(), 0);
		To = toName;
		isFirst = false;
		}
	if (To == toName) {
		std::string sendMess = client_sendMessage(username, msg);
		send(my_sock, sendMess.c_str(), sendMess.length(), 0);
	}
	else {
		std::string sendMess = client_connect(username, toName);
		send(my_sock, sendMess.c_str(), sendMess.length(), 0);
		To = toName;

		sendMess = client_sendMessage(username, msg);
		send(my_sock, sendMess.c_str(), sendMess.length(), 0);
	}

		/*std::string answer;
		char buf[1024];
		std::cout << username << ": ";
		std::getline(std::cin, answer);
		if (answer == "\\connect") {
			std::cout << "Username: " << std::endl;
			std::string name;
			std::getline(std::cin, name);
			std::string sendMess = client_connect(username, name);
			send(my_sock, sendMess.c_str(), sendMess.length(), 0);
		}
		else if (answer == "\\quit") {
			//std::string To ="0";
			
			std::string loginStr = client_quitConversation(username);
			send(my_sock, loginStr.c_str(), loginStr.length(), 0);
			int bytesReceived;
			bytesReceived = recv(my_sock, buf, sizeof(buf), 0);
			buf[bytesReceived] = '\0';
			std::cout << "\n" << buf;
			Sleep(2000);
			exit(0);
			//return;
		
		}
		else
		{
			std::string sendMess = client_sendMessage(username, answer);
			send(my_sock, sendMess.c_str(), sendMess.length(), 0);
		}
	//}*/
}
void Client::listen() {
	if (this != nullptr) {
		char buf[1024];
		int bytesReceived;
		bytesReceived = recv(my_sock, buf, sizeof(buf), 0);
		buf[bytesReceived] = '\0';
		//System::Console::WriteLine(buf);
		//textsFrom += buf;
		//textsFrom += "\r\n";
	}
	//std::cout << "\n"<<buf;
}
void Client::getUsers() {
	std::string loginStr = client_list_users();
	send(my_sock, loginStr.c_str(), loginStr.length(), 0);

}
std::string Client::listenStr(std::string str) {
	if (this != nullptr) {
		//std::fstream
		if (undelMsg.length() != 0) {
			std::string st = undelMsg;
			undelMsg.clear();
			return str + st;
			
		}
		char buf[1024];
		int bytesReceived;
		bytesReceived = recv(my_sock, buf, sizeof(buf), 0);
		if (bytesReceived == 1) {
			return str;
		}
		buf[bytesReceived] = '\0';
		//System::Console::WriteLine(buf);
		return str + buf;// +"\r\n";
		
	}
	else {
		return str;
	}
	//std::cout << "\n"<<buf;
}
bool Client::start(bool create) {
	//system("clear");

	//std::string answer;
	//std::cout << "Welcome to the chat client!\n" << std::endl;
	//std::cout << "Type\t\\create to create a new account or enter in your credentials to log in.\n\n";
	bool flag = true;
		if(create==true){
			createAccount();
		}

		std::string loginStr = client_login(username, password);
		send(my_sock, loginStr.c_str(), loginStr.length(), 0);


		int bytesReceived;
		char buf[1024];
		while (true) {
			bytesReceived = recv(my_sock, buf, sizeof(buf), 0);
			buf[bytesReceived] = '\0';
			if (std::string(buf) == "end")
			{
				break;
			}
			else {
				undelMsg += buf;
				undelMsg += "\r\n";
			}
			
			//std::cout << "\n" << buf;
		}

		char response;
		recv(my_sock, &response, sizeof(response), 0);

		if (response == ERROR_ACCOUNT_DOES_NOT_EXIST || response == ERROR_INCORRECT_PASSWORD) {
			return false;
		}
		else {
			return true;
		}
}





void Client::createAccount() {
	/*std::cout << "Enter your desired username: ";
	std::getline(std::cin, username);
	std::cout << "Enter a password: ";

	//setPasswordInput(true);
	std::getline(std::cin, password);
	//setPasswordInput(false);

	std::cout << "\n";

	std::cout << "Enter your first name: ";
	std::getline(std::cin, firstName);
	std::cout << "Enter your last name: ";
	std::getline(std::cin, lastName);*/

	std::string create = client_createAccount(username, password, firstName, lastName);
	send(my_sock, create.c_str(), create.length(), 0);

	char response;
	recv(my_sock, &response, sizeof(response), 0);

	//if (response == CREATE_ACCOUNT_SUCCESS) {}

}
