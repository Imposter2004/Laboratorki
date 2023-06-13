#pragma once
#include <iostream>
using namespace std;
class Time
{
private:
	int min;
	int sec;
public:
	Time(void);
	Time(int, int);
	Time(const Time&);
	Time& operator=(const Time&);
	//перегруженные операции ввода-вывода
	Time operator+(Time&);
	bool operator==(const Time&);
	friend ostream& operator<< (ostream& out, const Time&);
	friend istream& operator>> (istream& in, Time&);
	bool operator>(Time&);
	bool operator<(Time&);
	Time operator/(const int);
};
