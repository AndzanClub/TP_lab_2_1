#pragma once
#include "helper.h"
#include "Marray.h"
#include <ctime>
using namespace std;

class Worker
{
private:
	string FIO, status;
	int year;

	tm* getCurrentTime();
public:
	Worker();
	Worker(string FIO, string status, int year);
	Worker(const Worker& worker);
	~Worker();

	void inputFromConsole();
	void printToConsole();
	void change();

	string getFIO() { return FIO; }
	void setFIO(string FIO) { this->FIO = FIO; }

	string getStatus() { return status; }
	void setStatus(string status) { this->status = status; }

	int getYear() { return year; }
	void setYear(int year) { this->year = year; }

	int getExperience();

	Worker& operator=(const Worker& worker);
	bool operator>(Worker& worker);
};

