#include <iostream>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;
typedef set<int> Set;
// Функция для замены максимального элемента на заданное значение
void replaceMax(Set& container, int newValue)
{
    if (!container.empty()) {
        // Находим максимальный элемент
        int maxElement = *max_element(container.begin(), container.end());

        // Удаляем максимальный элемент
        container.erase(maxElement);

        // Вставляем новое значение
        container.insert(newValue);
    }
}

// Функция для нахождения минимального элемента и его удаления
void removeMin(Set& container)
{
    if (!container.empty()) {
        // Находим минимальный элемент
        int minElement = *container.begin();

        // Удаляем минимальный элемент
        container.erase(minElement);
    }
}

// Функция для добавления среднего арифметического ко всем элементам
void addAverage(Set& container)
{
    if (!container.empty()) {
        // Вычисляем среднее арифметическое
        int sum = 0;
        for (int num : container) {
            sum += num;
        }
        int average = sum / container.size();

        // Создаем временный контейнер для хранения измененных значений
        std::set<int> tempContainer;

        // Добавляем среднее арифметическое к каждому элементу
        for (int num : container) {
            tempContainer.insert(num + average);
        }

        // Заменяем исходный контейнер измененными значениями
        container = std::move(tempContainer);
    }
}
void print_set(Set container)
{
    for (int num : container) {
        cout << num << " ";
    }
    cout << endl;
}
Set make_set(int n)
{
    Set temp;
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        temp.insert(a);
    }
    return temp;
}
int main()
{
    int n;
    cout << "n? " << endl;
    cin >> n;
    Set container = make_set(n);
    print_set(container);

    cout << "replace? " << endl;
    cin >> n;
    replaceMax(container, n);
    print_set(container);
    // Нахождение минимального элемента и его удаление

    removeMin(container);
    print_set(container);

    // Добавление среднего арифметического ко всем элементам
    addAverage(container);
    print_set(container);

    return 0;
}