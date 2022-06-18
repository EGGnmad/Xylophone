#include <iostream>
#include "XylophoneServer.h"

void XylophoneServer::play(string note) {
	xylophone_play(note);
	send_to(note);
}

void XylophoneServer::start_handler() {
	cout << "!! Server started" << endl;
}

void XylophoneServer::stop_handler() {
	cout << "!! Server stopped" << endl;
}

void XylophoneServer::connect_handler(string name) {
	cout << name << "+" << endl;
}

void XylophoneServer::disconnect_handler(string name) {
	cout << name << "-" << endl;
}

void XylophoneServer::recv_handler(string name, string msg) {
	cout << name << " : ";
	xylophone_play(msg);
	send_to(msg);
}