#include <iostream>
#include <windows.h>
using namespace std;

// Базовий клас
class LibraryItem
{
public:
    virtual void Show() = 0;
    virtual ~LibraryItem() {}
};

// Книга
class Book : public LibraryItem
{
public:
    void Show() override
    {
        cout << "Це книга" << endl;
    }
};

// Журнал
class Magazine : public LibraryItem
{
public:
    void Show() override
    {
        cout << "Це журнал" << endl;
    }
};

// Газета
class Newspaper : public LibraryItem
{
public:
    void Show() override
    {
        cout << "Це газета" << endl;
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
        items[i]->Show();
    }

    for (int i = 0; i < 3; i++)
    {
        delete items[i];
    }

    return 0;
}