#include "Student.h"
#include <iostream>
#include <string>

using namespace std;

//конструктор без параметров 
Student::Student()
{
	name = "Unnamed";
	group = "Ungrouped";
	marks = 0;
	cout << "Without parametrs " << this << endl;
}

//конструктор с параметрами
Student::Student(string N, string G, float M)
{
	name = N;
	group = G;
	marks = M;
	cout << "With parametrs " << this << endl;
}
//конструктор копирования
Student::Student(const Student &t)
{
	name = t.name;
	group = t.group;
	marks = t.marks;

	cout << "Copy " << this << endl;
}

//деструктор
Student::~Student()
{
	cout << "Just destruct " << this << endl;
}
//селекторы
string Student::GetName()
{
	return name;
}
string Student::GetGroup()
{
	return group;
}
float Student::GetMarks()
{
	return marks;
}

//модификаторы
void Student::SetName(string N)
{
	name = N;
}
void Student::SetGroup(string G)
{
	group = G;
}
void Student::SetMarks(float M)
{
	marks = M;
}

//метод для просмотра атрибутов
void Student::Show()
{
	cout << "name :" << name << endl;
	cout << "group :" << group << endl;
	cout << "marks :" << marks << endl;
}