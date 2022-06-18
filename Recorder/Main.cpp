#include <iostream>
#include "Xylophone.h"
#include "XylophoneClient.h"
#include "XylophoneServer.h"
#include "UI.h"

using namespace std;

template <typename T>
T question(string msg) {
	T inp;
	cout << msg << endl;
	cin >> inp;

	return inp;
}

int main() {
	__DFstart;
	
	int type;

	type = question<int>("(1) 서버 만들기\n(2) 접속하기");

	if (type == 1) {
		XylophoneServer server("0.0.0.0", question<int>("포트를 입력하세요"), question<int>("최대 인원을 입력하세요"));

		system("cls");

		thread t1([&] {
			server.start();
		});

		thread t2([&] {
			while (true) {
				if (GetAsyncKeyDown(0x41))
					server.play("1");
				if (GetAsyncKeyDown(0x53))
					server.play("2");
				if (GetAsyncKeyDown(0x44))
					server.play("3");
				if (GetAsyncKeyDown(0x46))
					server.play("4");
				//
				if (GetAsyncKeyDown(0x4a))
					server.play("5");
				if (GetAsyncKeyDown(0x4b))
					server.play("6");
				if (GetAsyncKeyDown(0x4c))
					server.play("7");
				if (GetAsyncKeyDown(0xba))
					server.play("8");
			}
		});

		t1.join();
		t2.join();
	}

	else if (type == 2) {
		XylophoneClient client(question<string>("이름을 입력하세요"), question<string>("아이피를 입력하세요"), question<int>("포트를 입력하세요"));

		system("cls");

		thread t1([&] {
			client.start();
		});

		thread t2([&] {
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
		t2.join();
	}
	

	__DFclean;
}