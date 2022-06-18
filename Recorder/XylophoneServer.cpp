#include <iostream>
#include "XylophoneServer.h"

void XylophoneServer::play(string note) {
	xylophone_play(note);
	send_to(note);
}

void XylophoneServer::start_handler() {
	cout << "서버가 시작되었습니다" << endl;
}

void XylophoneServer::stop_handler() {
	cout << "서버가 종료되었습니다" << endl;
}

void XylophoneServer::connect_handler(string name) {
	cout << name << "이/가 접속했습니다." << endl;
}

void XylophoneServer::disconnect_handler(string name) {
	cout << name << "이/가 퇴장했습니다." << endl;
}

void XylophoneServer::recv_handler(string name, string msg) {
	cout << name << " : ";
	xylophone_play(msg);
	send_to(msg);
}