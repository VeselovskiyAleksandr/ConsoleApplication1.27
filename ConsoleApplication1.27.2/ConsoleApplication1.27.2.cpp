// ConsoleApplication1.27.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 24. Задача 2.Реализация программы напоминания о днях рождения.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <ctime>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

struct birthday {
	string name;
	string day;
};
birthday friends[100];

int main()
{
	setlocale(LC_ALL, "Rus");
	vector<birthday> birthdays;
	vector<string> fr;
	int countFr = 0, nextM = 12, nextD = 0, next = 32, count=0;
	string str = "", str1 = "", str2 = "", str3 = "", strY = "", strM = "", strD = "", birthdayBoy = "", nextBirthday = "";
	ifstream file("C:\\Users\\Александр\\Documents\\text for program\\friendsBirthday.txt");
	if (file.is_open()) {
		cout << "\nThe file is open.";
	}
	else {
		cerr << "\nThe file is not found. ";
		return 1;
	}
	while (!file.eof()) {
		file >> str;

		if (str == ";") {
			countFr++;
		}
		str = "";
	}
	file.close();
	ofstream cfile("C:\\Users\\Александр\\Documents\\text for program\\friendsBirthday.txt", ios::app);
	if (cfile.is_open()) {
		cout << "\nThe file is open.";
	}
	else {
		cerr << "\nThe file is not found. ";
		return 2;
	}
	cout << "\nВведите имя (для завершения ввода введите end) и дату рождения в формате ГГГГ/ММ/ДД.\n";
	do {
		if (countFr == 100) {
			cout << "\nСправочник заполнен полностью.";
			break;
		}
		getline(cin, friends[countFr].name);
		str = friends[countFr].name;
		if (str == "end") {
			friends[countFr].name == "";
			break;
		}
		getline(cin, friends[countFr].day);
		birthdays.push_back(friends[countFr]);
		countFr++;
	} while (str != "end");
	for (int i = 0; i < birthdays.size(); i++) {
		cfile << birthdays[i].name <<" :"<< "     " << birthdays[i].day << " ;\n";
	}
	cfile.close();
	ifstream dfile("C:\\Users\\Александр\\Documents\\text for program\\friendsBirthday.txt", ios::app);
	if (dfile.is_open()) {
		cout << "\nThe file is open.";
	}
	else {
		cerr << "\nThe file is not found. ";
		return 3;
	}
	str = "";
	while (!dfile.eof()) {
		dfile >> str;
		fr.push_back(str);
		str = "";
	}
	int j = 0;
	string str0 = "";
	for (int i = 0; i < fr.size(); i++) {
		if (i > 0) {
				i--;
			}
		while (str != ":") {
			
			str = "";
			str=fr[i];
         if (str == ":") {
	        str = "";
			break;
			}
			str0.append(str);
			str0.append(" ");
			i++;
			if (i >= fr.size()) {
				break;
			}	
}
		if (i >= fr.size()) {
			break;
		}
	   friends[j].name= str0;	 
		str = ""; str0 = "";
		while (str != ";") {		
            str = "";
			str = fr[i];
			str0.append(str);
			str0.append(" ");
			i++;
			if (str == ";") {
				break;
			}
			if (i >= fr.size()) {
				break;
			}
		}
 friends[j].day = str0;
 str0 = "";
		if (str == ";") {
			j++;
		}
		birthdays.push_back(friends[j]);
		if (i >= fr.size()) {
			break;
		}		
	}
	time_t d = time(nullptr);
	tm* loc = localtime(&d);
	str1 = to_string(loc->tm_year + 1900);
	str2 = to_string(loc->tm_mon + 1);
	str3 = to_string(loc->tm_mday);
	for (int i = 0; i < countFr; i++) {
		strY = friends[i].day.substr(2, 4);
		strM = friends[i].day.substr(7, 2);
		strD = friends[i].day.substr(10, 2);
		if (stoi(strM) > stoi(str2) && (stoi(strM) - stoi(str2) < nextM)) {
			nextM = stoi(strM) - stoi(str2);
			nextD = 31 -stoi(strD);
			nextBirthday = friends[i].day;
			birthdayBoy = friends[i].name;
		}
		else if ((stoi(strM) - stoi(str2) == nextM) && (31-stoi(strD) >nextD)) {
			nextD =31- stoi(strD);
			nextBirthday = friends[i].day;
			birthdayBoy = friends[i].name;
		}
		else if (stoi(strM) == stoi(str2) && (stoi(strD)>stoi(str3)) && (stoi(strD) < next)) {
			next = stoi(strD);
			nextBirthday = friends[i].day;
			birthdayBoy = friends[i].name;
		}	
		else if (stoi(strM) == stoi(str2) && (stoi(strD) == stoi(str3))) {      
		cout<<"\nСегодня день рождения у "<< friends[i].name;
		}
	}
	count = 0;
	for (int i = 0; i < countFr; i++) {
		if (nextBirthday.substr(7,5) == friends[i].day.substr(7, 5)) {
			count++;
		}
	}
	cout<<"\nБлижайший день рождения друзей "<< nextBirthday.substr(7, 5) <<" у "<< birthdayBoy;
	if (count > 1) {
		cout << " и ещё у " << count - 1;
	}
	dfile.close();
	return 0;
}



// Запуск программы : CTRL + F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: )F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
