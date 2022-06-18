#include <iostream>
#include "XylophoneServer.h"

void XylophoneServer::play(string note) {
	xylophone_play(note);
	send_to(note);
}

void XylophoneServer::start_handler() {
	cout << "������ ���۵Ǿ����ϴ�" << endl;
}

void XylophoneServer::stop_handler() {
	cout << "������ ����Ǿ����ϴ�" << endl;
}

void XylophoneServer::connect_handler(string name) {
	cout << name << "��/�� �����߽��ϴ�." << endl;
}

void XylophoneServer::disconnect_handler(string name) {
	cout << name << "��/�� �����߽��ϴ�." << endl;
}

void XylophoneServer::recv_handler(string name, string msg) {
	cout << name << " : ";
	xylophone_play(msg);
	send_to(msg);
}