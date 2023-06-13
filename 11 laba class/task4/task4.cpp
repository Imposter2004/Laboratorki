


#include "time.h"
#include <iostream>
#include <stack> 
#include <vector>
using namespace std;
typedef stack<Time>St;//стек 
typedef vector<Time>Vec;//вектор
Vec v;
St s;
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
		s.push(v[v.size()-1-i]);//добавить в стек элемент вектора
	}
	return s; //вернуть стек как результат функции
}
void print_stack(St s)
{
	v = copy_stack_to_vector(s);
	for (int i = 0;i < v.size();i++)
	{
		Time temp = v[v.size() - 1 - i];
		cout << temp <<" ";
	}
	cout << endl;
}
Time max(St s)
{
	v = copy_stack_to_vector(s);
	int n = s.size();
	Time m = s.top();
	s.pop();
	while (!s.empty())
	{
		if (m < s.top()) m = s.top();
		s.pop();
	}
	s = copy_vector_to_stack(v);
	return m;
}
Time min(St s)
{
	v = copy_stack_to_vector(s);
	int n = s.size();
	int a = 0;
	Time m = s.top();
	s.pop();
	while (!s.empty())
	{
		if (m > s.top()) 
			m = s.top();
		s.pop();
	}
	s = copy_vector_to_stack(v);
	return m;
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
void add(St& s,Time time)
{
	Vec vv;
	Time t;
	while (!s.empty())//пока стек не пустой
	{	
		t = s.top();
		vv.push_back(t);
		s.pop();
	}
	vv.push_back(time);
	s = copy_vector_to_stack(vv);
}
void del(St& s, Time time)
{
	Time t;
	Vec vv;
	while (!s.empty())//пока стек не пустой
	{
		t = s.top();//получаем элемент из вершины стека
		//если он не равен минимальному, заносим элемент в вектор
		if(!(t==time)) vv.push_back(t);
		s.pop();//удаляем элемент из стека
	}
	s = copy_vector_to_stack(vv);
}
void add_sred(St& s, Time time)
{
	Vec vv;
	Time temp;
	while (!s.empty())
	{
		temp = s.top() + time;
		vv.push_back(temp);
		s.pop();
	}
	s = copy_vector_to_stack(vv);
}
int main()
{
	int n;
	cout << "n?";
	cin >> n;
	s = make_stack(n);//создать стек 
	print_stack(s);//печать стека
	Time temp;
	temp = max(s);
	cout << temp << endl;
	add(s, temp);
	print_stack(s);
	temp = min(s);
	cout << temp << endl;
	del(s, temp);
	print_stack(s);
	temp = sred(s);
	cout << temp << endl;
	add_sred(s, temp);
	print_stack(s);
	return 0;
}