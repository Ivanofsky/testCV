#pragma once

enum TKey {
NO_KEY = 0,
KEY_ENTER = 13,
KEY_ESC = 27,
KEY_UP = 72,
KEY_DOWN = 80,
KEY_LEFT = 75,
KEY_RIGHT = 77
};


void initSys();
int getTime();
TKey keyPress();
void waitPressEnterKey();
void closeFile();
void openFile(std::string a);
void writeKey(int keyCode, char symbol);