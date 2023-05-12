#include <iostream>
#include <fstream>

using namespace std;

struct Item {
    int key;
    Item* next;
    Item* prev;
};

Item* CreateList(int length)
{
    Item* last, * p;
    last = NULL; 
    for (int i = length - 1; i >= 0; i--) 
    {
        p = new Item(); 
        p->key = i; 
        p->next = last; 
        last->prev = p;
        last = p; 
    }
    last->prev = NULL;
    return last; 
}

void PrintList(Item* first)
{
    if (first == NULL) {
        cout << "List is empty.\n";
        return;
    }

    cout << "List: "; 

    Item* p = first;
    while (p != NULL)
    {
        cout << p->key << " -> ";
        p = p->next;
    }
    cout << "NULL\n";
}

void PrintToFile(ofstream* file, Item* first) 
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
    Item* first = new Item(); 
    if (*file >> k) 
    {
        first->key = k;
        Item* p1 = first; 
        while (*file >> k)
        {
            Item* p = new Item();
            p->key = k;
            p1->next = p;
            p1 = p;
        }
        p1->next = NULL;
    }
    else
    {
        first = NULL; 
    }
    return first;
}
Item* DeleteList(Item* first)
{
    Item* next;
    while (first != NULL)
    {
        next = first->next;
        delete first;
        first = next;
    }
    return first;
}

Item* AddItem(Item* first, int key)
{
    Item* p = first;
    if (p == NULL || p->key > key)
    {
        first = new Item();
        first->key = key;
        first->next = p;
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
    if (first == NULL) return first;

    Item* p = first;

    if (p->key != key) {
        while (p->next != NULL) 
        {
            Item* p2 = p->next; 
            if (p2->key == key) {
                p->next = p2->next;
                delete p2;
                return first;
            }
            else if (p2->key > key)
            {
                return first;
            }
            else
            {
                p = p2; 
            }
        }
        return first;
    }
    else
    {
        first = p->next; 
        delete p;
        return first;
    }
}
void main()
{
    Item* list = CreateList(5); 
    PrintList(list);

    list = AddItem(list, 7); 
    PrintList(list);

    list = DeleteItem(list, 2); 
    PrintList(list);

    list = DeleteItem(list, 0); 
    PrintList(list);

    list = AddItem(list, -1); 
    PrintList(list);

    list = AddItem(list, 6); 
    PrintList(list);

    list = AddItem(list, 6); 
    PrintList(list);

    list = DeleteItem(list, 7); 
    PrintList(list);

    list = DeleteItem(list, 5); 
    PrintList(list);

    ofstream ofs("file.txt");

    PrintToFile(&ofs, list);

    list = DeleteList(list); 
    PrintList(list);

    ifstream ifs("file.txt");
    list = ReadFromFile(&ifs);
    PrintList(list);

    list = DeleteList(list);
}