#pragma once
#pragma comment(lib, "ws2_32")
#pragma warning(disable:4996)

#define BUFFER_SIZE 128
#define NAME_SIZE 26


#include "ISocket.h"
#include <WinSock2.h>
#include <thread>
#include <vector>

using namespace std;

class Server : public ISocket{
private:
	SOCKET sock;
	SOCKADDR_IN addr;

	unsigned int max_client_size;
	string ip;
	unsigned int port;

	vector<SOCKET> clients_socket;
	vector<thread> clients_thread;

	string connect_action(SOCKET& sock);
	void disconnect_action();

protected:
	//handler
	virtual void start_handler() = 0;
	virtual void stop_handler() = 0;
	virtual void connect_handler(string name) = 0;
	virtual void recv_handler(string name, string msg) = 0;
	virtual void disconnect_handler(string name) = 0;

public:
	Server(string ip, int port, int max_player_size);

	void start();
	void stop();

	void send_to(string msg);

	~Server() {};
};