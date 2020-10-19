#include <time.h>
#include <Windows.h> // ����������� ��� SetConsoleCP() � SetConsoleOutputCP()
#include <iostream>
#include <conio.h>
#include <fstream>
#include "init.h"
using namespace std;

std::fstream fout;

int startTime;

// �������� ��������� ����� ��� ������� ��������� � ���
int  getTime() {
	time_t rawtime;
	time(&rawtime); // ������� ���� � ��������
//	std::cout << "������� ����� � ���� � ��������: " << rawtime; // ������� ���� � �������� ��� �������� �����
	return  rawtime;
}


void initSys() {
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "��������� ������������� ��� �������� ����������� � ����������� ����� � ��������� �� ������ ���������" << "\n";
	std::cout << "��� ������� ����� ������� �����. �����, ������ �� �����, � ����������� �� �����������, ��������� ������� � ������ ��������� ������� ������� ����������� " << "\n";
	//std::fstream fout;

}

TKey keyPress() {
	if (_kbhit()) {				//���� ���� ������ �������
		int c = 0, a = 224;
		c = _getch();			//�������� ��� ���� ������
		if (c == a) {			//���� ��� ���� ������ � ����� ������, �� ������ ���������� � ������ ������(����������)
			c = _getch();
		}
		return (TKey)c;
	}
	else
	{
		return NO_KEY;
	}
}


void waitPressEnterKey()
{
	int key=0;
	while ((key = keyPress()) != KEY_ENTER) {
	}
	startTime = getTime();
	//std::cout << "����� �a�� =" << time << "\n";
}

void closeFile()
{
	fout.close();
}

void openFile(string a)
{
	fout.open(a, std::ios_base::app);
	fout << "\n" << "������ ������ � " << startTime << "\n";
	std::cout << "\n" << "������ ������ � " << startTime << "\n";
}

void writeKey(int keyCode, char symbol)
{
	int tempTime, diffTimeSec;
	//tempTime = getTime();
	diffTimeSec = getTime() - startTime;
	std::cout << symbol << " " << diffTimeSec << " sec" <<"\n";
	fout << symbol << " " << diffTimeSec << "\n";
}
