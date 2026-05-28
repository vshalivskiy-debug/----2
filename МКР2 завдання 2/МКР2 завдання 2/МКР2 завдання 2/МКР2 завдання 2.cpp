#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

// Інтерфейс спостерігача
class Observer
{
public:
    virtual void Update(string book) = 0;
};

// Користувач
class User : public Observer
{
private:
    string name;

public:
    User(string n)
    {
        name = n;
    }

    void Update(string book) override
    {
        cout << name
            << " отримав повідомлення про нову книгу: "
            << book << endl;
    }
};

// Subject
class Library
{
private:
    vector<Observer*> observers;

public:
    void AddObserver(Observer* o)
    {
        observers.push_back(o);
    }

    void Notify(string book)
    {
        for (Observer* o : observers)
            o->Update(book);
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Library lib;

    User u1("Іван");
    User u2("Олена");

    lib.AddObserver(&u1);
    lib.AddObserver(&u2);

    lib.Notify("C++ для початківців");

    return 0;
}