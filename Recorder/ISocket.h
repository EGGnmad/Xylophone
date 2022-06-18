#pragma once

#include <string>

using namespace std;

class ISocket
{
	virtual void start() = 0;
	virtual void stop() = 0;

	virtual void start_handler() = 0;
	virtual void stop_handler() = 0;
	virtual void connect_handler(string name) = 0;
	virtual void recv_handler(string name, string msg) = 0;
	virtual void disconnect_handler(string name) = 0;


	virtual void send_to(string msg) = 0;
};