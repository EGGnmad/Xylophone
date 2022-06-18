#pragma once

#include <string>

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


