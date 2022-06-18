#pragma comment(lib, "ws2_32")
#pragma  warning(disable:4996)
#include <iostream>
#include <thread>
#include <WinSock2.h>

#define PORT 8888
#define PACKET_SIZE 256

using namespace std;

int main() {
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET hListen;
	hListen = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN tListenAddr = {};
	tListenAddr.sin_family = AF_INET;
	tListenAddr.sin_port = htons(PORT);
	tListenAddr.sin_addr.s_addr = inet_addr("0.0.0.0");

	bind(hListen, (SOCKADDR*)&tListenAddr, sizeof(tListenAddr));
	listen(hListen, SOMAXCONN);


	SOCKET hClient = accept(hListen, NULL, NULL);
	cout << "accepted!\n";

	char cBuffer[PACKET_SIZE] = {};
	recv(hClient, cBuffer, PACKET_SIZE, 0);
	printf("Server Recv: %s\n", cBuffer);

	char cMsg[] = "Server send";
	send(hClient, cMsg, strlen(cMsg), 0);

	closesocket(hClient);
	closesocket(hListen);

	WSACleanup();
	return 0;
}
