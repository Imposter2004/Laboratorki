
#include <vector>
#include <cstdlib>
#include "time.h"
using namespace std;
typedef vector<Time>Vec;//определяем тип для работы с вектором
Vec make_vector(int n)
{
	Vec v;//пустой вектор
	for (int i = 0;i < n;i++)
	{
		int a = rand() % 50;
		int b = rand() % 60;
		Time temp(a, b);
		v.push_back(temp);//добавляем temp в конец вектора
	}
	return v;//возвращаем вектор как результа работы функции
}
//функция для печати вектора
void print_vector(Vec v)
{
	for (int i = 0;i < v.size();i++) cout << v[i] << " ";
	cout << endl;
}
Time max(Vec v)
{
	Time max = v[0];
	for (int i = 1; i < v.size(); i++)
	{
		if (max < v[i]) max = v[i];
	}
	return max;
}
Vec add(Vec v, Time max)
{
	v.insert(v.begin(), max);
	return v;
}
int min(Vec v)
{
	Time min = v[0];
	int n = 0;
	for (int i = 1; i < v.size(); i++)
	{
		if (min > v[i]) { min = v[i]; n = i; }
	}
	return n;
}
Vec del(Vec v, int n)
{
	v.erase(v.begin() + n);
	return v;
}
Time sred(Vec v)
{
	Time temp;
	for (int i = 0;i < v.size();i++)
	{
		temp = temp + v[i];
	}
	temp = temp / v.size();
	return  temp;
}
Vec add_sred(Vec v, Time temp)
{
	for (int i = 0; i < v.size(); i++)
	{
		v[i] = v[i] + temp;
	}
	return v;
}
void main()
{
	srand(time(NULL));
	vector<Time> v;
	//формирование вектора
	int n;
	cout << "N?";
	cin >> n;
	v = make_vector(n);
	print_vector(v);
	//3
	Time temp = max(v);
	cout << temp << endl;
	v = add(v, temp);
	print_vector(v);
	//4
	int mini = min(v);
	cout << mini << endl;
	v = del(v, mini);
	print_vector(v);
	//5
	Time temp1 = sred(v);
	cout << temp1 << endl;
	v = add_sred(v, temp1);
	print_vector(v);
}
