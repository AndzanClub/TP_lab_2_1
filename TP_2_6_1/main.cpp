#include "Worker.h"
#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

void printMenu();
void addObject(Marray<Worker>& workers);
void changeObject(Marray<Worker>& workers);
void deleteObject(Marray<Worker>& workers);
void print(Marray<Worker>& workers);
void searchObjects(Marray<Worker>& workers);


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Marray<Worker> workers;

	bool isExit = false;
	while (!isExit) {
		printMenu();
		int method = safeInput(0, 5);
		switch (method)
		{
		case 1:
			addObject(workers);
			break;
		case 2:
			changeObject(workers);
			break;
		case 3:
			deleteObject(workers);
			break;
		case 4:
			print(workers);
			break;
		case 5:
			searchObjects(workers);
			break;
		case 0:

			isExit = true;
			break;
		}
	}

}

void printMenu() {
	cout << "1. Добавить объект" << endl;
	cout << "2. Изменить объект" << endl;
	cout << "3. Удалить объект" << endl;
	cout << "4. Вывести данные" << endl;
	cout << "5. Вывести фамилии рабочих, чей стаж превышает введенный" << endl;
	cout << "0. Выход" << endl;
	cout << "Выберете пункт меню: ";
}

void addObject(Marray<Worker>& workers) {
	Worker student;
	student.inputFromConsole();
	workers += student;
	workers.sort();
}

void changeObject(Marray<Worker>& workers) {
	if (workers.getSize() > 0) {
		print(workers);
		cout << "Введите номер рабочего для изменения: ";
		workers[safeInput(1, workers.getSize()) - 1].change();
	}
	else
		cout << "Список рабочих пуст. Нечего изменять\n";
	workers.sort();
}

void deleteObject(Marray<Worker>& workers) {
	if (workers.getSize() > 0) {
		print(workers);
		cout << "Введите рабочего студента для удаления: ";
		workers -= safeInput(1, workers.getSize()) - 1;
	}
	else
		cout << "Список рабочих пуст. Нечего удалять\n";
	workers.sort();
}

void print(Marray<Worker>& workers) {
	if (workers.getSize() == 0)
		cout << "Список рабочих пуст.\n";
	else {
		cout << "Список рабочих\n";
		for (int i = 0; i < workers.getSize(); i++) {
			cout << i + 1 << ". Рабочий\n";
			workers[i].printToConsole();
		}
	}
}

void searchObjects(Marray<Worker>& workers) {
	if (workers.getSize() == 0)
		cout << "Список рабочих пуст\n";
	else {
		bool isPrint = false;
		cout << "Введите стаж: ";
		int experience = safeInput(1, INT32_MAX);
		for (int i = 0; i < workers.getSize(); i++) {
			if (workers[i].getExperience() > experience) {
				isPrint = true;
				workers[i].printToConsole();
			}
		}
			
		if (!isPrint)
			cout << "Рабочих с таким стажем нет\n";
	}
}