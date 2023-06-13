//Задача 3
//Параметризированный класс – Вектор(см.лабораторную работу №7)
//Задание 3
//Найти максимальный элемент и добавить его в начало контейнера
//Задание 4
//Найти минимальный элемент и удалить его из  контейнера	
//Задание 5
//К каждому элементу добавить среднее арифметическое контейнера


//Задача 3
//1.	Создать параметризированный класс, используя в качестве контейнера последовательный контейнер.
//2.	Заполнить его элементами.
//3.	Добавить элементы в соответствии с заданием
//4.	Удалить элементы в соответствии с заданием.
//5.	Выполнить задание варианта для полученного контейнера.
//6.	Выполнение всех заданий оформить в виде методов параметризированного класса.

#include <C:\Users\serge\OneDrive\Документы\GitHub\Tarasov_Sergey_LABS_PSTU_RIS_22_1b\class_laba11\task2\time.h>
#include <C:\Users\serge\OneDrive\Документы\GitHub\Tarasov_Sergey_LABS_PSTU_RIS_22_1b\class_laba11\task2\time.cpp>
#include "vector.h"
#include <iostream>
using namespace std;

void main()
{
	Vector<Time>vec(5);//создать вектор из 5 элементов
	vec.Print();//печать вектора
	Time temp;
	temp = vec.max();
	cout << temp << endl;
	vec.add(temp);
	vec.Print();
	int mini;
	mini = vec.min();
	cout << mini << endl;
	vec.del(mini);
	vec.Print();
	vec.sred();
	temp = vec.sred();
	cout << temp << endl;
	vec.add_sred(temp);
	vec.Print();
}
