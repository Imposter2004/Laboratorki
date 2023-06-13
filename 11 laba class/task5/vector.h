#pragma once
#include <iostream>
#include <stack>
#include <vector>
template<class T>
class Vector
{
	stack <T> s;//контейнер
	int len;//размер контейнера
public:
	Vector();//конструктор без параметров
	Vector(int n);//конструктор с параметрами
	Vector(const Vector<T>&);//конструктор копирования
	void Print();
	T Max();
	void Del();
	T Min();
	void Add();
	T Srednee();
	void Add_sred(T);
};
//копирование стека в вектор
template <class T>
vector<T> copy_stack_to_vector(stack<T> s)
{
	vector<T> v;

	while (!s.empty())
	{
		v.push_back(s.top()); s.pop();
	}
	return v;
}
//копирование вектора в стек
template <class T>
stack<T> copy_vector_to_stack(vector<T> v)
{
	stack<T> s;
	for (int i = 0;i < v.size();i++)
	{
		s.push(v[i]);
	}
	return s;
}
//конструктор без параметров
template <class T> 
Vector<T>::Vector()
{
	len = 0;
}
//конструктор с параметром
template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0;i < n;i++)
	{
		cin >> a;
		s.push(a);//добавить в стек элемент а
	}
	len = s.size();
}
//конструктор копирования
template <class T>
Vector<T>::Vector(const Vector<T>& Vec)
{
	len = Vec.len;
	//копируем значения стека Vec.s в вектор v
	vector<T> v=copy_stack_to_vector(Vec.s);
	//копируем вектор v в стек s 
	s=copy_vector_to_stack(v);
}
//печать
template <class T>
void Vector<T>::Print()
{
	//копируем стек в вектор
	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty())//пока стек не пустой
	{
		cout << s.top() << endl;//вывод элемента в вершине стека
		s.pop();//удаляем элемент из вершины
	}
	//копируем вектор в стек
	s=copy_vector_to_stack(v);
}
template <class T>
T Vector<T>::Max()
{
	T m = s.top();//m присвоить значение из вершины стека
	//в вектор скопировать элементы стека
	vector<T> v=copy_stack_to_vector(s);
	while(!s.empty())//пока стек не пустой
	{
		//сравниваем m и элемент в вершине стека
		if(s.top()>m) m=s.top();
		s.pop();//удаляем элемент из вершины стека
	}
	s = copy_vector_to_stack(v);//копируем вектор в стек
	return m;
}
template <class T>
void Vector<T>::Del()
{

	T m = Min();//поиск минимального
	vector<T> v;
	T t;
	while (!s.empty())//пока стек не пустой
	{
		t = s.top();//получить элемент из вершины стека
		//если t не равен минимальному, то добавить его в вектор
		if(!(t==m)) v.push_back(t);
		s.pop();//удалить элемент из стека
	}
	//копируем вектор в стек
	s = copy_vector_to_stack(v);
}
template <class T>
T Vector<T>::Min()
{
	T m = s.top();
	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty())
	{
		if (s.top() < m)m = s.top();
		s.pop();
	}
	s = copy_vector_to_stack(v);
	return m;
}
template <class T>
void Vector<T>::Add()
{
	vector <T>v;//вспомогательный вектор
	T t;
	T el = Max();
	int i = 1;
	v.push_back(el);
	while (!s.empty())//пока стек не пустой
	{
		t = s.top();//получить элемент из вершины стека
		v.push_back(t);//добавляем t в вектор
		s.pop();//удаляем элемент из вершины стека
		i++;
	}
	s = copy_vector_to_stack(v);//копируем вектор в стек
}
template <class T>
T Vector<T>::Srednee()
{
	//копируем стек в вектор
	vector<T> v = copy_stack_to_vector(s);
	int n = 1;//количество элементов в стеке
	T sum = s.top();//начальное значение для суммы
	s.pop();//удаляем элемент из вершины стека

	while (!s.empty())//пока стек не пустой
	{
		sum = sum + s.top();//добавляем в сумму элемент из вершины стека
		s.pop();//удаляем элемент из вершины стека
		n++;//увеличиваем количество элементов
	}
	//копируем вектор в стек
	s=copy_vector_to_stack(v);
	return sum/n;
}
template <class T>
void Vector<T>::Add_sred(T el)
{
	vector <T>v;//вспомогательный вектор
	T t;
	T e;
	int i = 1;
	while (!s.empty())//пока стек не пустой
	{
		t = s.top();//получить элемент из вершины стека
		e = t + el;
		v.push_back(e);//добавляем t в вектор
		s.pop();//удаляем элемент из вершины стека
		i++;
	}
	s = copy_vector_to_stack(v);//копируем вектор в стек
}