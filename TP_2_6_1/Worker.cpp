#include "Worker.h"

Worker::Worker() : FIO("Не задано"), status("Не задано"), year(0)
{
	cout << "Вызван конструктор Worker" << endl;
}

Worker::Worker(string FIO, string status, int year) :
	FIO(FIO), status(status), year(year)
{
	cout << "Вызван конструктор Worker" << endl;
}

Worker::Worker(const Worker& worker) : FIO(worker.FIO), status(worker.status), year(worker.year)
{
	cout << "Вызван конструктор копирования Worker" << endl;
}

Worker::~Worker()
{
	cout << "Вызван деструктор Worker" << endl;
}

void Worker::inputFromConsole()
{
	cout << "Введите ФИО: ";
	getline(cin, FIO);
	cout << "Введите должность: ";
	getline(cin, status);
	cout << "Введите год поступления на работу: ";
	year = safeInput(1, 1900 + getCurrentTime()->tm_year);
}

void Worker::printToConsole()
{
	cout << "ФИО: " << FIO << endl;
	cout << "Должность: " << status << endl;
	cout << "Год поступления на работу: " << year << endl;
}

void Worker::change()
{
	cout << "Введите новое ФИО: ";
	getline(cin, FIO);
	cout << "Введите новую должность: ";
	getline(cin, status);
	cout << "Введите новый год поступления на работу: ";
	year = safeInput(1, 1900 + getCurrentTime()->tm_year);
}

int Worker::getExperience() {
	return 1900 + getCurrentTime()->tm_year - year;
}

Worker& Worker::operator=(const Worker& worker) {
	if (this == &worker)
		return *this;
	FIO = worker.FIO;
	status = worker.status;
	year = worker.year;
	return *this;
}

bool Worker::operator>(Worker& worker) {
	return FIO > worker.FIO;
}

tm* Worker::getCurrentTime() {
	time_t seconds = time(0);
	tm* ltm = new tm();
	gmtime_s(ltm, &seconds);
	return ltm;
}