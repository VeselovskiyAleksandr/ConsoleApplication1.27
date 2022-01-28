// ConsoleApplication1.27.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 24. Задача 3. Реализация программы таймера.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <iomanip>
#include <windows.h> 
#include <locale.h>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int interim=0, intermediate = 0, interval=0;
	string strTime = "",strM = "", strS = "";
	cout << "Установите таймер в формате: ММ:СС.\n";
	cin >> strTime;
	strM = strTime.substr(0, 2);
	strS = strTime.substr(3, 2);
	interim = stoi(strM) * 60 + stoi(strS);
	time_t t = time(0);
	time_t completion = t + (time_t)interim;
	intermediate =(double) interim;
	do {
		time_t  start = time(nullptr);
		interval = difftime(completion, start);
		if (intermediate != interval) {
			cout << "\n";
			if ((int)interval / 60 > 9) {
				cout << (int)interval / 60 << ":";
			}
			else {
				cout << "0" << (int)interval / 60 << ":";
			}
			if ((int)interval % 60 > 9) {
				cout << (int)interval % 60;
			}
			else {
				cout << "0" << (int)interval % 60;
			}
		}
		if (completion == start) {
			Beep(750, 2250);
			cin.get();
			break;
		}
		intermediate = interval;
	} while (completion > t);
	return 0;
}




// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
