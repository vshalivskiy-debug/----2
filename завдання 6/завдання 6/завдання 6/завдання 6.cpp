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

// Клас Книга
class Book : public LibraryItem
{
public:
    void Show() override
    {
        cout << "Створено об'єкт: Книга" << endl;
    }
};

// Клас Журнал
class Magazine : public LibraryItem
{
public:
    void Show() override
    {
        cout << "Створено об'єкт: Журнал" << endl;
    }
};

// Фабрика
class Factory
{
public:
    static LibraryItem* CreateItem(int type)
    {
        if (type == 1)
            return new Book();
        else
            return new Magazine();
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;

    cout << "1 - Книга" << endl;
    cout << "2 - Журнал" << endl;
    cout << "Ваш вибір: ";
    cin >> choice;

    LibraryItem* item = Factory::CreateItem(choice);

    item->Show();

    delete item;

    return 0;
}