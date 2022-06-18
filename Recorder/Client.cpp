#include <iostream>
#include "Client.h"

Client::Client(const string name, const string ip, const int port) {

	this->name = name;
	memset(this->buffer, 0, sizeof(this->buffer));

	//allocating client socket
	this->sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (this->sock == INVALID_SOCKET) throw "socket::allocating ERROr!";

	//setting info of socket
	this->addr.sin_family = AF_INET;
	this->addr.sin_port = htons(port);
	this->addr.sin_addr.s_addr = inet_addr(ip.c_str());
}

void Client::start() {
	start_handler();

	if (connect(this->sock, (SOCKADDR*)&this->addr, sizeof(this->addr)) == SOCKET_ERROR) cout << "no";
	send(this->sock, this->name.c_str(), strlen("Test"), 0);
	connect_handler(this->name);


	thread([&] {
		while (true) {
			recv(this->sock, this->buffer, BUFFER_SIZE, 0);
			this->recv_handler(this->name, this->buffer);

			memset(this->buffer, 0, sizeof(this->buffer));
		}

		disconnect_handler(this->name);
		closesocket(this->sock);
		}).join();
}

void Client::send_to(string msg) {
	thread([&] {
		send(sock, msg.c_str(), msg.length(), 0);
		}).join();
}

void Client::stop() {
	stop_handler();
	exit(1);
}