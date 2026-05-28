#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

// 1. Factory Method
class LibraryItem
{
public:
    virtual void Show() = 0;
    virtual ~LibraryItem() {}
};

class Book : public LibraryItem
{
public:
    void Show() override
    {
        cout << "Factory Method: створено книгу" << endl;
    }
};

class Magazine : public LibraryItem
{
public:
    void Show() override
    {
        cout << "Factory Method: створено журнал" << endl;
    }
};

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

// 2. Decorator
class Item
{
public:
    virtual void Info() = 0;
    virtual ~Item() {}
};

class SimpleBook : public Item
{
public:
    void Info() override
    {
        cout << "Decorator: книга" << endl;
    }
};

class EBookDecorator : public Item
{
private:
    Item* item;

public:
    EBookDecorator(Item* i)
    {
        item = i;
    }

    void Info() override
    {
        item->Info();
        cout << "Decorator: додано електронну версію" << endl;
    }
};

// 3. Observer
class Observer
{
public:
    virtual void Update(string message) = 0;
    virtual ~Observer() {}
};

class User : public Observer
{
private:
    string name;

public:
    User(string n)
    {
        name = n;
    }

    void Update(string message) override
    {
        cout << "Observer: " << name << " отримав повідомлення: "
            << message << endl;
    }
};

class Library
{
private:
    vector<Observer*> observers;

public:
    void AddObserver(Observer* o)
    {
        observers.push_back(o);
    }

    void Notify(string message)
    {
        for (Observer* o : observers)
            o->Update(message);
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Приклади патернів проектування" << endl << endl;

    LibraryItem* item = Factory::CreateItem(1);
    item->Show();
    delete item;

    cout << endl;

    Item* book = new SimpleBook();
    Item* ebook = new EBookDecorator(book);
    ebook->Info();
    delete ebook;
    delete book;

    cout << endl;

    Library library;
    User user1("Іван");
    User user2("Олена");

    library.AddObserver(&user1);
    library.AddObserver(&user2);

    library.Notify("з'явилася нова книга");

    return 0;
}