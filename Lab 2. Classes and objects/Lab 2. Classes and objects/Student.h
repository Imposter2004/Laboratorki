#include <iostream>
#include <string>

using namespace std;

class Student
{
	private:
		string name;
		string group;
		float marks;

	public:
		Student();//конструктор без параметров
		Student(string, string, float);//конструктор с параметрами
		Student(const Student&);//конструктор копирования
		~Student();//деструктор

		string GetName();//Getter
		void SetName(string);//Setter

		string GetGroup();//селектор
		void SetGroup(string); //модификатор

		float GetMarks();//селектор
		void SetMarks(float); //модификатор

		void Show();//просмотр атрибутов
};