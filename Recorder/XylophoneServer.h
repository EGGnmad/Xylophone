#pragma once
#pragma comment(lib, "winmm.lib")

#include "Server.h"
#include "Xylophone.h"
#include <mmsystem.h>
#include <conio.h>

class XylophoneServer : public Server{

protected:
	virtual void start_handler();
	virtual void stop_handler();
	virtual void connect_handler(string name);
	virtual void recv_handler(string name, string msg);
	virtual void disconnect_handler(string name);

public:
	void play(string note);
	XylophoneServer(string ip, int port, int max_player_size) : Server(ip, port, max_player_size) {}
};