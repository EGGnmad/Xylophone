#include "Xylophone.h"

#include <iostream>
#include <string>
#include <Windows.h>
#include "NoteDevice.h"
#include <thread>

#pragma comment(lib, "winmm.lib")

using namespace std;

short KeyState[256] = { 0 };
string note_string[8] = { "C1", "D1", "E1", "F1", "G1", "A1", "B1", "C2" };

void xylophone_play(string note) {
	cout << "Play " << note_string[atoi(note.c_str()) -1] << endl;

	wstring a;
	a.assign(note.begin(), note.end());

	wstring dir = L"./Sound/" + a + L".wav";
	thread([&] {
		NoteDevice d(dir);
		d.Play();
	}).join();
}

short GetAsyncKeyDown(int Key) {
	if (KeyState[Key] == 0 && GetAsyncKeyState(Key)) KeyState[Key] = 1;
	else if (KeyState[Key] == 1 && GetAsyncKeyState(Key)) KeyState[Key] = 2;
	else if (KeyState[Key] == 1 && GetAsyncKeyState(Key) == 0) KeyState[Key] = 0;
	else if (KeyState[Key] == 2 && GetAsyncKeyState(Key) == 0) KeyState[Key] = 0;
	return KeyState[Key] == 1 ? true : false;
}