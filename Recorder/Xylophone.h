#pragma once

#include <string>

enum Note {
	C1 = '1',
	D1 = '2',
	E1 = '3',
	F1 = '4',
	G1 = '5',
	A1 = '6',
	B1 = '7',
	C2 = '8',
};

void xylophone_play(std::string note);
short GetAsyncKeyDown(int Key);


#define __DFstart {\
	WSADATA wsaData;\
	::WSAStartup(MAKEWORD(2, 2), &wsaData);\
}

#define __DFclean {\
	WSACleanup();\
	return 0;\
}


