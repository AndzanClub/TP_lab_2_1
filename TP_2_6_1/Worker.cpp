#include "Worker.h"

Worker::Worker() : FIO("�� ������"), status("�� ������"), year(0)
{
	cout << "������ ����������� Worker" << endl;
}

Worker::Worker(string FIO, string status, int year) :
	FIO(FIO), status(status), year(year)
{
	cout << "������ ����������� Worker" << endl;
}

Worker::Worker(const Worker& worker) : FIO(worker.FIO), status(worker.status), year(worker.year)
{
	cout << "������ ����������� ����������� Worker" << endl;
}

Worker::~Worker()
{
	cout << "������ ���������� Worker" << endl;
}

void Worker::inputFromConsole()
{
	cout << "������� ���: ";
	getline(cin, FIO);
	cout << "������� ���������: ";
	getline(cin, status);
	cout << "������� ��� ����������� �� ������: ";
	year = safeInput(1, 1900 + getCurrentTime()->tm_year);
}

void Worker::printToConsole()
{
	cout << "���: " << FIO << endl;
	cout << "���������: " << status << endl;
	cout << "��� ����������� �� ������: " << year << endl;
}

void Worker::change()
{
	cout << "������� ����� ���: ";
	getline(cin, FIO);
	cout << "������� ����� ���������: ";
	getline(cin, status);
	cout << "������� ����� ��� ����������� �� ������: ";
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