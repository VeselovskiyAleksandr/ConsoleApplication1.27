// ConsoleApplication1.27.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 24. Задача 1. Реализация программы учёта времени.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <iomanip>
#include <locale.h>
#include <string>
#include <vector>

using namespace std;

struct tests {
	string title;
	string elapsTime;
};
tests test[20];

int main()
{	
	setlocale(LC_ALL, "Rus");
	string commandStr="", solutionTime="";
	int countdown = 0, interim = 0, count=0, tH=0, tM=0, tS=0;
	cout << "\nДля начала отслеживания задачи введите: begin ";
	cin>> commandStr;
	do {
		if (count >= 20) {
			cout << "\n<Большее количество задач програма отслеживать не может.";
			cout << "\nДля просмотра состояния введите status ";
			cin >> commandStr;
			if (commandStr == "status") {
					for (int i = 0; i < count;i++){
						cout << "\n" << test[i].title << "  " << test[i].elapsTime;
			}
		};
				return 0;
		}
            count++;
			cout << "\nВведите название задачи.";
			cin >> test[count-1].title;			
            commandStr == "";
			time_t d = time(0);
			interim = countdown;
			do {           
				cout << "\nДля окончания отслеживания введите: end, для начала отслеживания новой задачи введите : begin";
				cout << "\nДля просмотра состояния введите status ";
				cin >> commandStr;
				solutionTime = "";
					time_t t = time(0);
					countdown = (int)difftime(t, d);
					tS=countdown % 60;
					tM= countdown / 60;
					tH= countdown / 3600;
					solutionTime.append(to_string(tH));
					solutionTime.append(" hour ");
					solutionTime.append(to_string(tM));
					solutionTime.append(" minutes ");
					solutionTime.append(to_string(tS));
					solutionTime.append(" seconds ");
					test[count-1].elapsTime = solutionTime;
					break;
			} while (commandStr == "begin");
			if (commandStr == "end") {
				break;
			}
			 if (commandStr == "status") {
				for (int i = 0; i < count; i++) {
					cout << "\n" << test[i].title << "  " << test[i].elapsTime;
				}
				cout << "\nДля окончания отслеживания введите: end, для начала отслеживания новой задачи введите : begin ";
				cin >> commandStr;
		}
	}while (commandStr != "end");

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
