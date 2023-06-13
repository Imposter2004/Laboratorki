#include "time.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<Time> TVector;

//формирование вектора
TVector make_vector(int n)
{
	Time a;
	TVector v;
	for (int i = 0;i < n;i++)
	{
		cin >> a; v.push_back(a);
	}
	return v;
}
//печать вектора
void print_vector(TVector v)
{
	for (int i = 0;i < v.size();i++)

		cout << v[i] << endl; cout << endl;
}
Time srednee(TVector v)
{
	Time s = v[0];
	//перебор вектора
	for (int i = 1;i < v.size();i++) s = s + v[i];
	int n = v.size();//количество элементов в векторе
	return s/n;
}
void add(Time& t, Time& average)
{
	t = t + average;
}
void main()
{
	int n; cout << "n? ";
	cin >> n;
	TVector v;
	v = make_vector(n);
	print_vector(v);

	TVector::iterator i;
	//поставили итератор i на максимальный элемент

	cout << endl;

	i=max_element(v.begin(),v.end());
	Time m = *(i);
	Time a;
	cin >> a;
	cout << endl;
	replace(v.begin(), v.end(), m, a);
	print_vector(v);

	cout << endl;

	i = min_element(v.begin(), v.end());
	m = *(i);
	i = remove(v.begin(), v.end(), m);
	v.erase(i, v.end());
	print_vector(v);

	cout << endl;

	Time s;
	s = srednee(v);//нашли среднее арифметическое вектора
	for_each(v.begin(), v.end(), [&](Time& t) {
		add(t, s);
		});
	print_vector(v);
}
