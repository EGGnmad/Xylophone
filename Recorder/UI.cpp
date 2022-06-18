#include <iostream>
#include <Windows.h>
#include "UI.h"


UI::UI(vector<string> ui) {
	this->ui = ui;


	CONSOLE_SCREEN_BUFFER_INFOEX csbi{ sizeof csbi };
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfoEx(hOutput, &csbi);

	SetConsoleScreenBufferInfoEx(hOutput, &csbi);
}

void UI::show() {

	for (auto & i : this->ui) {
		cout << i << endl;
	}
}