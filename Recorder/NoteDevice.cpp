#include "NoteDevice.h"
#include <iostream>


using namespace std;

NoteDevice::NoteDevice(const wstring file, const wstring device_type) {
	this->file = file;
	this->device_type = device_type;

	this->parms.open.lpstrElementName = this->file.c_str();
	this->parms.open.lpstrDeviceType = this->device_type.c_str();

}

void NoteDevice::Play() {
	mciSendCommand(MCI_ALL_DEVICE_ID, MCI_CLOSE, MCI_WAIT, NULL);
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD_PTR)(LPVOID)(&this->parms.open));
	mciSendCommand(this->parms.open.wDeviceID, MCI_PLAY, MCI_NOTIFY, (DWORD_PTR)(LPVOID)(&this->m_parms.play));
}