#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
typedef vector<double>Vec;//определяем тип для работы с вектором
//функция для формирования вектора
Vec make_vector(int n)
{
	Vec v;//пустой вектор
	for (int i = 0;i < n;i++)
	{
		double a = rand() % 100 - 50;
		v.push_back(a);//добавляем а в конец вектора
	}
	return v;//возвращаем вектор как результа работы функции
}
//функция для печати вектора
void print_vector(Vec v)
{
	for (int i = 0;i < v.size();i++) cout << v[i] << " ";
	cout << endl;
}
int max(Vec v)
{
	int m = v[0];
	for (int i = 0; i < v.size();i++)
	{
		if (v[i] > m)
		{
			m = v[i];
		}
	}
	return m;
}
Vec add(Vec v, int m)
{
	v.insert(v.begin(), m);
	return v;
}
int min(Vec v)
{
	int m = v[0];
	int n = 0;
	for (int i = 0; i < v.size();i++)
	{
		if (v[i] < m)
		{
			m = v[i]; n = i;
		}
	}
	return n;
}
Vec  del(Vec v, int n)
{
	v.erase(v.begin() + n);
	return v;
}
double srednee(Vec v)
{
	double sum = 0;
	for (int i = 0; i < v.size();i++)
	{
		sum += v[i];
	}
	sum /= v.size();
	return sum;
}
Vec add_srednee(Vec v, double sred)
{
	for (int i = 0; i < v.size();i++)
	{
		v[i] += sred;
	}
	return v;
}

void main()
{
	vector<double> v;
	vector<double>::iterator vi = v.begin();
	//формирование вектора
	int n;
	cout << "N?";
	cin >> n;
	v = make_vector(n);
	print_vector(v);
	//3
	int maxi = max(v);
	cout << maxi << endl;
	v = add(v, maxi);
	print_vector(v);
	//4
	int mini = min(v);

	cout << mini << endl;
	v = del(v, mini);
	print_vector(v);
	//5
	double sredn = srednee(v);
	cout << sredn << endl;
	v = add_srednee(v, sredn);
	print_vector(v);
}