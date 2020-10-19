#include <time.h>
#include <Windows.h> // Обязательно для SetConsoleCP() и SetConsoleOutputCP()
#include <iostream>
#include <conio.h>
#include <fstream>
#include "init.h"
using namespace std;

std::fstream fout;

int startTime;

// Получаем начальное время при страрте программы в сек
int  getTime() {
	time_t rawtime;
	time(&rawtime); // текущая дата в секундах
//	std::cout << "Текущее время и дата в секундах: " << rawtime; // текущая дата в понятной для человека форме
	return  rawtime;
}


void initSys() {
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "Программа предназначена для подсчета направлений с сохранением логов с секундами от старта программы" << "\n";
	std::cout << "При страрте видео нажмите Энтер. Далее, смотря на видео, в зависимосте от направления, нажимайте стрелки в момент покидания машиной предела перекрестка " << "\n";
	//std::fstream fout;

}

TKey keyPress() {
	if (_kbhit()) {				//Если была нажата клавиша
		int c = 0, a = 224;
		c = _getch();			//Получаем что было нажато
		if (c == a) {			//Если был спец символ с двумя чарами, то превый пропускаем и читаем второй(актуальный)
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
	//std::cout << "Старт Тaйм =" << time << "\n";
}

void closeFile()
{
	fout.close();
}

void openFile(string a)
{
	fout.open(a, std::ios_base::app);
	fout << "\n" << "Начало записи в " << startTime << "\n";
	std::cout << "\n" << "Начало записи в " << startTime << "\n";
}

void writeKey(int keyCode, char symbol)
{
	int tempTime, diffTimeSec;
	//tempTime = getTime();
	diffTimeSec = getTime() - startTime;
	std::cout << symbol << " " << diffTimeSec << " sec" <<"\n";
	fout << symbol << " " << diffTimeSec << "\n";
}
