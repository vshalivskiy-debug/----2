#include <iostream>
#include <windows.h>
using namespace std;

class Author
{
public:
    string GetName()
    {
        return "Тарас Шевченко";
    }
};

class Book
{
private:
    Author author;

public:
    Author& GetAuthor()
    {
        return author;
    }
};

class Library
{
private:
    Book book;

public:
    // Правильний підхід
    string GetBookAuthor()
    {
        return book.GetAuthor().GetName();
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Library lib;

    cout << "Автор книги: "
        << lib.GetBookAuthor()
        << endl;

    return 0;
}