#include "time.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
typedef stack<Time>St;//стек 
typedef vector<Time>Vec;//вектор
Vec v;
St s;
//копирует стек в вектор
Vec copy_stack_to_vector(St s)
{
	Vec v;
	while (!s.empty())//пока стек не пустой
	{
		//добавить в вектор элемент из вершиы стека
		v.push_back(s.top());
		s.pop();
	}
	return v; //вернуть вектор как результат функции
}
//копирует вектор в стек
St copy_vector_to_stack(Vec v)
{
	St s;
	for (int i = 0;i < v.size();i++)
	{
		s.push(v[v.size() - 1 - i]);//добавить в стек элемент вектора
	}
	return s; //вернуть стек как результат функции
}
void print_stack(St s)
{
	v = copy_stack_to_vector(s);
	for (int i = 0;i < v.size();i++)
	{
		Time temp = v[v.size() - 1 - i];
		cout << temp << " ";
	}
	cout << endl;
}
St make_stack(int n)
{
	St s;
	Time t;
	for (int i = 0;i < n;i++)
	{
		cin >> t;//ввод переменной
		s.push(t);//добавление ее в стек
	}
	return s;//вернуть стек как результат функции
}
Time sred(St s)
{
	v = copy_stack_to_vector(s);
	int n = s.size();
	Time m = s.top();
	s.pop();
	while (!s.empty())
	{
		m = m + s.top();
		s.pop();
	}
	m = m / n;
	s = copy_vector_to_stack(v);
	return m;
}
void add(Time& t, Time& average)
{
	t = t + average;
}
void replaceMaxElement(St& s, const Time& newValue)
{
	Vec v = copy_stack_to_vector(s);
	auto maxElementIter = max_element(v.begin(), v.end());
	if (maxElementIter != v.end()) {
		replace(v.begin(), v.end(), *maxElementIter, newValue);
		s = copy_vector_to_stack(v);
	}
}
void eraseMinElement(St& s)
{
	Vec v = copy_stack_to_vector(s);
	auto minElementIter = min_element(v.begin(), v.end());
	Time min = *minElementIter;
	minElementIter = remove(v.begin(), v.end(), min);
	v.erase(minElementIter, v.end());
	s = copy_vector_to_stack(v);
}
void for_each_add(St& s)
{
	Vec v = copy_stack_to_vector(s);
	Time sredn = sred(s);
	for_each(v.begin(), v.end(), [&](Time& t) {
		add(t, sredn);
		});
	s = copy_vector_to_stack(v);
}
int main()
{
	int n;
	cout << "N? ";
	cin >> n;
	St v;
	v = make_stack(n);
	print_stack(v);
	Time a;
	cin >> a;
	replaceMaxElement(v, a);
	print_stack(v);
	cout << endl;
	eraseMinElement(v);
	print_stack(v);
	cout << endl;
	for_each_add(v);
	print_stack(v);
	return 0;
}