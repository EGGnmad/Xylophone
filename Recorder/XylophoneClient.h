#pragma once

#include "Client.h"
#include "Xylophone.h"
#include "UI.h"

class XylophoneClient : public Client {
private:
	//UI ui;

protected:
	virtual void start_handler();
	virtual void stop_handler();
	virtual void connect_handler(string name);
	virtual void recv_handler(string name, string msg);
	virtual void disconnect_handler(string name);

public:
	void play(string note);
	XylophoneClient(string name, string ip, int port) : Client(name, ip, port) {}
};