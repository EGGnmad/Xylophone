#include <iostream>
#include "Server.h"

Server::Server(const string ip, const int port, const int max_player_size) {

	this->ip = ip;
	this->port = port;
	this->max_client_size = max_player_size;
	

	//allocating server socket
	this->sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (this->sock == INVALID_SOCKET) throw "socket::allocating ERROr!";

	//setting info of socket
	this->addr.sin_family = AF_INET;
	this->addr.sin_port = htons(port);
	this->addr.sin_addr.s_addr = inet_addr(ip.c_str());


	//binding info to server socket 
	if (bind(this->sock, (SOCKADDR*)&this->addr, sizeof(this->addr)) == SOCKET_ERROR) throw "socket::binding ERROr!";
	//listen client connections
	if (listen(this->sock, SOMAXCONN) == SOCKET_ERROR) throw "socket::listening ERROr!";
}

void Server::start() {
	this->start_handler();
	for (unsigned int i = 0; i < this->max_client_size; i++) {
		this->clients_thread.emplace_back([&] {
			SOCKET hClient = accept(sock, NULL, NULL);
			string name = connect_action(hClient);

			connect_handler(name);

			int recv_size; 
			char cBuffer[BUFFER_SIZE];
			memset(cBuffer, 0, sizeof(cBuffer)); //버퍼 초기화

			while (true) {
				recv_size = recv(hClient, cBuffer, BUFFER_SIZE, 0);
				if (recv_size <= 0) break;
				recv_handler(name, cBuffer); //전송받은 데이터를 관리하기 위해 함수에 전송
				memset(cBuffer, 0, sizeof(cBuffer)); //버퍼 초기화
			}

			disconnect_handler(name);

			thread([&] {
				disconnect_action();
			}).join();
			closesocket(hClient);
		});
	}

	for (auto& t : this->clients_thread) {
		t.join();
	}
}

void Server::stop() {
	this->stop_handler();
	exit(1);
}


string Server::connect_action(SOCKET& sock) {
	char name[NAME_SIZE] = { 0 };
	recv(sock, name, NAME_SIZE, 0);
	this->clients_socket.push_back(sock);

	return name;
}

void Server::disconnect_action() {
	thread([&] {

		SOCKET hClient = accept(sock, NULL, NULL);

		string name = connect_action(hClient);

		connect_handler(name);

		int recv_size;
		char cBuffer[BUFFER_SIZE];
		memset(cBuffer, 0, sizeof(cBuffer)); //버퍼 초기화

		while (true) {
			recv_size = recv(hClient, cBuffer, BUFFER_SIZE, 0);
			if (recv_size <= 0) break;
			recv_handler(name, cBuffer); //전송받은 데이터를 관리하기 위해 함수에 전송
			memset(cBuffer, 0, sizeof(cBuffer)); //버퍼 초기화
		}

		disconnect_handler(name);

		thread([&] {
			disconnect_action();
		}).join();
		closesocket(hClient);
	}).join();
}


void Server::send_to(string msg) {
	for (auto& i : this->clients_socket) {
		send(i, msg.c_str(), msg.length(), 0);
	}
}