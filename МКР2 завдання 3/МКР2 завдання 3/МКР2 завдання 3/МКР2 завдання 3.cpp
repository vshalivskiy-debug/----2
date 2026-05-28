#include <iostream>
#include <windows.h>
using namespace std;

// Базовий клас
class LibraryItem
{
public:
    virtual void ShowInfo() = 0;
    virtual ~LibraryItem() {}
};

// Похідний клас Книга
class Book : public LibraryItem
{
public:
    void ShowInfo() override
    {
        cout << "Тип: Книга" << endl;
    }
};

// Похідний клас Журнал
class Magazine : public LibraryItem
{
public:
    void ShowInfo() override
    {
        cout << "Тип: Журнал" << endl;
    }
};

// Новий тип - Газета
class Newspaper : public LibraryItem
{
public:
    void ShowInfo() override
    {
        cout << "Тип: Газета" << endl;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    LibraryItem* items[3];

    items[0] = new Book();
    items[1] = new Magazine();
    items[2] = new Newspaper();

    for (int i = 0; i < 3; i++)
    {
        items[i]->ShowInfo();
    }

    for (int i = 0; i < 3; i++)
    {
        delete items[i];
    }

    return 0;
}