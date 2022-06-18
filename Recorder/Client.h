#pragma once
#pragma comment(lib, "ws2_32")
#pragma warning(disable:4996)

#define BUFFER_SIZE 128
#define NAME_SIZE 26

#include <WinSock2.h>
#include <thread>
#include <vector>
#include <string>
#include "ISocket.h"


using namespace std;

class Client : public ISocket{
private:
	SOCKET sock;
	SOCKADDR_IN addr;

	string name;
	char buffer[BUFFER_SIZE];

protected:
	//handler
	virtual void start_handler() = 0;
	virtual void stop_handler() = 0;
	virtual void connect_handler(string name) = 0;
	virtual void recv_handler(string name, string msg) = 0;
	virtual void disconnect_handler(string name) = 0;

public:
	Client(string name, string ip, int port);

	void start();
	void stop();

	void send_to(string msg);
};