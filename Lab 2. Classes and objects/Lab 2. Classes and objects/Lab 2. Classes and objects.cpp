#include "Student.h"
#include <iostream>
#include <string>

// Lab 2. Classes and objects

using namespace std;

//функция для возврата объекта как результата
Student MakeStudent()
{
	string n;
	string g;
	float m;
	cout << "Student name: ";
	getline(cin, n);
	cout << "Student group: ";
	getline(cin, g);
	cout << "Marks: ";
	cin >> m;

	return Student(n, g, m);
}

//функция для передачи объекта как параметра
void PrintStudent(Student s)
{
	s.Show();
}

void main()
{
	//конструктор без параметров
	Student s1;
	s1.Show();

	//коструктор с параметрами
	Student s2("Vitalik Loh", "RIS-22-1B", 15000);
	s2.Show();

	//конструктор копирования
	Student s3 = s2;

	s3.SetName("Demid Loh");
	s3.SetGroup("RIS-22-2B");
	s3.SetMarks(0);

	//конструктор копирования 
	PrintStudent(s3);

	//конструктор копирования
	s1 = MakeStudent();
	s1.Show();
}