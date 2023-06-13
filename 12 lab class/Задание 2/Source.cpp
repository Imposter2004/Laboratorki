#include <iostream>
#include <map>
#include <C:\Users\serge\OneDrive\Документы\GitHub\Tarasov_Sergey_LABS_PSTU_RIS_22_1b\class_laba12\task2\time.h> 
#include <C:\Users\serge\OneDrive\Документы\GitHub\Tarasov_Sergey_LABS_PSTU_RIS_22_1b\class_laba12\task2\time.cpp> 
#include <iostream>
using namespace std;
typedef  std::multimap<int, Time> Tmap;
typedef Tmap::iterator it;//итератор
// Функция для создания и заполнения multimap элементами
Tmap createAndFillMultimap(int n)
{
    Tmap container;
    for (int i = 0; i < n;i++)
    {
        Time a;
        cout << "?";
        cin >> a;
        //создаем пару и добавляем ее в словарь
        container.insert(make_pair(i, a));
    }
    return container;
}
Time srednee(Tmap v)
{
    Time s;
    int n = v.size(); // количество элементов в мультимапе

    // перебор мультимапы с использованием итератора
    for (it it = v.begin(); it != v.end(); ++it)
    {
        s = s + it->second;
    }
    return s / n;
}
int Max(Tmap v)
{
    it i = v.begin();
    int nom = 0; // номер максимального элемента
    int k = 0; // счетчик элементов
    Time m = i->second; // значение первого элемента

    while (i != v.end())
    {
        if (m < i->second)
        {
            m = i->second;
            nom = k;
        }
        ++i; // итератор 
        ++k; // счетчик элементов
    }

    return nom; // номер максимального элемента
}
int Min(Tmap v)
{
    it i = v.begin();
    int nom = 0; // номер максимального элемента
    int k = 0; // счетчик элементов
    Time m = i->second; // значение первого элемента

    while (i != v.end())
    {
        if (m > i->second)
        {
            m = i->second;
            nom = k;
        }
        ++i; // итератор 
        ++k; // счетчик элементов
    }
    return nom; // номер минимального элемента
}
void del(Tmap& container)
{
    int min = Min(container); // Находим номер минимального элемента

    // Ищем элемент с соответствующим номером минимального элемента
    auto it = container.begin();
    std::advance(it, min);

    container.erase(it); // Удаляем элемент из контейнера
}
void add(Tmap& container)
{
    int max = Max(container); // Находим максимальный элемент

    // Находим итератор для максимального элемента
    it maxIterator = container.begin();
    std::advance(maxIterator, max);

    // Копируем максимальный элемент
    auto maxElement = *maxIterator;

    // Вставляем максимальный элемент в начало контейнера
    container.insert(container.begin(), maxElement);
}
void add_sred(Tmap& container)
{
    Time sred = srednee(container);
    for (auto& elem : container)
    {
        elem.second = elem.second + sred;
    }
}
void printMultimap(const Tmap& container)
{
    for (const auto& element : container)
    {
        cout << "Номер: " << element.first << ", Значение: " << element.second << endl;
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cout << " введите кол-во элементов ";
    cin >> n;
    Tmap container = createAndFillMultimap(n);
    printMultimap(container);
    cout << endl;

    add(container);
    printMultimap(container);
    cout << endl;

    del(container);
    printMultimap(container);
    cout << endl;

    add_sred(container);
    printMultimap(container);
    cout << endl;
    return 0;
}