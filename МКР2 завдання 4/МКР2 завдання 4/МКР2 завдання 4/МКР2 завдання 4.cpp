#include <iostream>
#include <windows.h>
using namespace std;

// Базовий компонент
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
        cout << "Книга" << endl;
    }
};

// Базовий декоратор
class Decorator : public LibraryItem
{
protected:
    LibraryItem* item;

public:
    Decorator(LibraryItem* i)
    {
        item = i;
    }

    void Show() override
    {
        item->Show();
    }
};

// Декоратор електронної книги
class EBookDecorator : public Decorator
{
public:
    EBookDecorator(LibraryItem* i)
        : Decorator(i) {
    }

    void Show() override
    {
        Decorator::Show();
        cout << "+ Електронна версія" << endl;
    }
};

// Декоратор аудіокниги
class AudioDecorator : public Decorator
{
public:
    AudioDecorator(LibraryItem* i)
        : Decorator(i) {
    }

    void Show() override
    {
        Decorator::Show();
        cout << "+ Аудіоверсія" << endl;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    LibraryItem* book = new Book();

    // Рекурсивне декорування
    LibraryItem* ebook =
        new EBookDecorator(book);

    LibraryItem* audioebook =
        new AudioDecorator(ebook);

    audioebook->Show();

    delete audioebook;
    delete ebook;
    delete book;

    return 0;
}