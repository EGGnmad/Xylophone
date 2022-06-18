#include <iostream>
#include "Xylophone.h"
#include "XylophoneClient.h"
#include "XylophoneServer.h"
#include "UI.h"

using namespace std;

int main() {
	__DFstart;
	//XylophoneServer server("0.0.0.0", 8888, 3);
	XylophoneClient client("Lee", "125.132.39.158", 8888);

	thread t1([&] {
		client.start();
	});

	thread t3([&] {
		while (true) {
			if (GetAsyncKeyDown(0x41))
				client.play("1");
			if (GetAsyncKeyDown(0x53))
				client.play("2");
			if (GetAsyncKeyDown(0x44))
				client.play("3");
			if (GetAsyncKeyDown(0x46))
				client.play("4");
			//
			if (GetAsyncKeyDown(0x4a))
				client.play("5");
			if (GetAsyncKeyDown(0x4b))
				client.play("6");
			if (GetAsyncKeyDown(0x4c))
				client.play("7");
			if (GetAsyncKeyDown(0xba))
				client.play("8");
		}
	});



	t1.join();
	//t2.join();
	//t3.join();
	

	__DFclean;
}