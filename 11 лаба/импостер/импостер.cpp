#include <iostream>
#include <fstream>

// Lab 11. Informational dynamic structures

using namespace std;

//Элемент списка
struct Item {//Содержит:
    int key;//Ключ,
    Item* next;//Ссылку на след. элемент
};

//Создать список, нужна его длина
Item* CreateList(int length)
{
    Item* last, * p;
    last = NULL; //Последний элемент списка, так как будем делать структуру где первый ссылается на последний, начнём с последнего, а так как список может быть пустым, то сразу запишем NULL
    for (int i = length - 1; i >= 0; i--) //Стандартный проход по длинне, только от конца (Если длинна не 0, то условие выполнится и мы точно попадём в цикл, иначе просто вернём наш last как пустой NULL
    {
        p = new Item(); //Раз мы тут, начинаем работать, создаём пустой элемент
        p->key = i; //Записываем "Айдишник"
        p->next = last; //Ссылаемся на последний элемент
        last = p; //И теперь так как являемся самым новым элементом, становимся тоже последним (Последним созданным)
    }
    return last; //Таким образом мы дойдём в итоге до самого первого элемента и возвращаем как раз уже его, начало/вход в список
}

void PrintList(Item* first)
{
    if (first == NULL) { //Если список пустой,
        cout << "List is empty.\n";//выводим сообщение
        return;//и выходим из функции
    }

    cout << "List: "; //Если список был не пустой, то мы окажемся здесь, начинаем выводить список

    Item* p = first;
    while (p != NULL)
    {
        cout << p->key << " -> ";
        p = p->next;
    }
    cout << "NULL\n";
}

void PrintToFile(ofstream* file, Item* first) //Тут вроде всё очевидно? Берём список и точно так же по элементам выводим в файл как в функции выше
{
    Item* p = first;
    while (p != NULL)
    {
        *file << p->key << "\n";
        p = p->next;
    }
    file->close();
}
Item* ReadFromFile(ifstream* file)
{
    int k;
    Item* first = new Item(); //Первый раз нам нужно инициализировать, создаём пустой элемент
    if (*file >> k) //Если в файле что-то есть, то оно запишет это в k
    {
        first->key = k;
        Item* p1 = first; //Запишем в p1 ссылку на первый элемент
        while (*file >> k)//Далее, если в файле есть элементы и дальше, то будет работать цикл
        {
            Item* p = new Item(); //Снова создаём элемент, записываем К
            p->key = k;
            p1->next = p;//Следующий элемент после первого, мы его только что создали
            p1 = p;//А теперь просто смещаем наш p1 с первого элемента, на только что созданный, и тд
        }
        p1->next = NULL;//После того, как в файле не окажется данных, мы должны "закрыть" нашу цепочку
    }
    else
    {
        first = NULL; //Если в файле ничего нет, возвращаем пустой список
    }
    return first;
}
Item* DeleteList(Item* first)
{
    Item* next;
    while (first != NULL)
    {
        next = first->next;//Сохраняем следующий элемент
        delete first;//Удаляем текущий элемент
        first = next;//Текущий становится следующим
    }
    return first;
}

Item* AddItem(Item* first, int key)
{
    Item* p = first;
    if (p == NULL || p->key > key)//Список вообще нулевой, тогда создаём 1 единственный элемент с нужным ключом или если мы должны добавить именно первый элемент
    {
        first = new Item();//cоздаём элемент самым первым
        first->key = key;
        first->next = p;//А после него закрепляем остальной список (это будет правильно даже если остальной список как раз и будет пустым NULL)
    }
    else
    {
        if (p->key == key) return first;
        while (p->next != NULL)
        {
            Item* p2 = p->next;

            if (p2->key > key)
            {
                p->next = new Item();
                p->next->key = key;
                p->next->next = p2;
                return first;
            }
            else if (p2->key == key) return first;

            p = p2;
        }
        p->next = new Item();
        p->next->key = key;
        p->next->next = NULL;
    }
    return first;
}
Item* DeleteItem(Item* first, int key)
{
    if (first == NULL) return first;//Список пуст, нечего удалять

    Item* p = first;

    if (p->key != key) {//Если первый элемент не является искомым
        while (p->next != NULL) //Пока текущий элемент не является последним (у последнего элемента ссылка на следующий = NULL)
        {
            Item* p2 = p->next; //Начинаем проверку следующего элемента (2го, так как первый мы проверили вне цикла)
            if (p2->key == key) {//Если след элемент является тем, который мы должны удалить
                p->next = p2->next;//То получается в предыдущем элементе ссылка должна указывать не на p2(следующий элемент) а на p2.next (следующий следующий элемент)
                delete p2;
                return first;
            }
            else if (p2->key > key)//Если мы прошли до текущего элемента и не нашли до сих пор нужный, а следующий элемент уже больше чем искомый, то все следующие тоже будут больше
            {
                return first;//А значит искомого элемента нет и мы просто покидаем функцию
            }
            else
            {
                p = p2; //Иначе просто смещаем указатель дальше
            }
        }
        return first;
    }
    else //Иначе, первый элемент - тот элемент который надо удалить
    {
        first = p->next; //В p записан первый элемент, в ссылку на сам список (ссылку на первый элемент) записываем ссылку на 2й элемент
        delete p;
        return first;
    }
}
void main()
{
    Item* list = CreateList(5); // 0 > 1 > 2 > 3 > 4 > NULL
    PrintList(list);

    list = AddItem(list, 7); // 0 > 1 > 2 > 3 > 4 > 7 >NULL
    PrintList(list);

    list = DeleteItem(list, 2); // 0 > 1 > 3 > 4 > 7 > NULL
    PrintList(list);

    list = DeleteItem(list, 0); // 1 > 3 > 4 > 7 > NULL
    PrintList(list);

    list = AddItem(list, -1); // -1 > 1 > 3 > 4 > 7 > NULL
    PrintList(list);

    list = AddItem(list, 6); // -1 > 1 > 3 > 4 > 6 > 7 > NULL
    PrintList(list);

    list = AddItem(list, 6); // -1 > 1 > 3 > 4 > 6 > 7 > NULL
    PrintList(list);

    list = DeleteItem(list, 7); // -1 > 1 > 3 > 4 > 6 > NULL
    PrintList(list);

    list = DeleteItem(list, 5); // -1 > 1 > 3 > 4 > 6 > NULL
    PrintList(list);

    ofstream ofs("file.txt");

    PrintToFile(&ofs, list);

    list = DeleteList(list); //NULL
    PrintList(list);

    ifstream ifs("file.txt");
    list = ReadFromFile(&ifs);
    PrintList(list);

    list = DeleteList(list);
}