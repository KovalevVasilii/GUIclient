
#ifndef CLIENT_H
#define CLIENT_H

#include "helper.h"
#include <WinSock2.h>
#include <winsock.h>

class Client
{
public:
	Client(std::string Login,std::string Password);
	~Client();
	void handle();
	void process(std::string toName, std::string msg);
	void listen();
	std::string listenStr(std::string str);
	//int makeSock();

	//void makeConnection();

	//void conversation();

	//void listenForMessages();

	bool start(bool createOrNot);

	void createAccount();
	void getUsers();
	/*void login();
	void mainMenu();*/
private:
	SOCKET my_sock;
	SOCKADDR_IN dest_addr;
	char buff[1024];
	struct sockaddr_in serverinfo;
	//int sock;
	int connection;
	char buffer[1024];
	long sendAttempt;
	long receiveAttempt;
	std::string username;
	std::string password;
	std::string firstName;
	std::string lastName;
	std::string recipient;
	bool talking;
	bool isFirst;
	std::string To;
	std::string undelMsg;

};

#endif