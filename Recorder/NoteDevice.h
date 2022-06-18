#pragma once

#include <string>
#include <windows.h>
#include <mmsystem.h>
#include <digitalv.h>
#pragma comment(lib, "winmm.lib")


typedef struct {
	MCI_OPEN_PARMS open;
	MCI_PLAY_PARMS play;
} mciParms;

class NoteDevice
{
private:
	mciParms parms, m_parms;

	std::wstring file;
	std::wstring device_type;

public:
	NoteDevice(std::wstring file, std::wstring device_type = L"mpegvideo");
	void Play();
};


