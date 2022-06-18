#include <iostream>
#include "Xylophone.h"
#include "XylophoneClient.h"


void XylophoneClient::play(string note) {
	send_to(note);
}

void XylophoneClient::start_handler(){}
void XylophoneClient::stop_handler(){}

void XylophoneClient::connect_handler(string name) {
	cout << "서버에 접속하였습니다" << endl;
}

void XylophoneClient::recv_handler(string name, string msg){
	xylophone_play(msg);
}

void XylophoneClient::disconnect_handler(string name) {
	cout << "서버에서 퇴장했습니다" << endl;
}
