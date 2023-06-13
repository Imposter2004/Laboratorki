#include "time.h" 
Time::Time(void)
{
	min = sec = 0;
}
Time::Time(int M, int S)
{
	if (S >= 60)
	{
		min = M + (S / 60);
		sec = S % 60;
	}
	else
	{
		min = M;sec = S;
	}
}
Time::Time(const Time& t)
{
	min = t.min; sec = t.sec;
}
Time& Time::operator =(const Time& t)
{
	min = t.min; sec = t.sec; return*this;
}
ostream& operator<<(ostream& out, const Time& t)
{

	out << t.min << " : " << t.sec; return out;
}
istream& operator>>(istream& in, Time& t)
{
	cout << "\nmin? ";
	in >> t.min;
	cout << "\nsec? ";
	in >> t.sec;
	while (t.sec >= 60) {
		cout << "ќшибка: количество секунд не может быть 60 или больше. ¬ведите значение еще раз: " << endl;
		in >> t.sec;
	}
	return in;
}
bool Time::operator==(const Time& t)
{
	int temp = min * 60 + sec;
	int temp2 = t.min * 60 + t.sec;
	return temp == temp2;
}
Time Time::operator+(Time& t)
{
	Time temp;
	temp.min = ((min + t.min) * 60 + (sec + t.sec)) / 60;
	temp.sec = ((min + t.min) * 60 + (sec + t.sec)) % 60;
	return temp;
}
bool Time::operator>(Time& t)
{
	int temp = min * 60 + sec;
	int temp2 = t.min * 60 + t.sec;
	return temp > temp2;
}
bool Time::operator<(Time& t)
{
	int temp = min * 60 + sec;
	int temp2 = t.min * 60 + t.sec;
	return temp < temp2;
}
Time Time::operator/(const int a)
{
	int temp = min * 60 + sec;
	int res = temp / a;
	Time time;
	time.min = res / 60;
	time.sec = res % 60;
	return time;
}
