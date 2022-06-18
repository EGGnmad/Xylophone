#pragma once

#include <vector>
#include <string>

#define UI_SIZE_WIDTH 250
#define UI_SIZE_HEIGHT 200

using namespace std;

class UI {
private:
	vector<string> ui;
	
public:
	UI(vector<string> ui);
	void show();
};