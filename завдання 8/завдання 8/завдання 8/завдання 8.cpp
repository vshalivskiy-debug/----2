#include <iostream>
#include <windows.h>
using namespace std;

class Book;
class Magazine;
class Newspaper;

// Visitor
class Visitor
{
public:
    virtual void Visit(Book* b) = 0;
    virtual void Visit(Magazine* m) = 0;
    virtual void Visit(Newspaper* n) = 0;
};

// Element
class LibraryItem
{
public:
    virtual void Accept(Visitor* v) = 0;
};

// Book
class Book : public LibraryItem
{
public:
    void Accept(Visitor* v)
    {
        v->Visit(this);
    }
};

// Magazine
class Magazine : public LibraryItem
{
public:
    void Accept(Visitor* v)
    {
        v->Visit(this);
    }
};

// Новий клас Newspaper
class Newspaper : public LibraryItem
{
public:
    void Accept(Visitor* v)
    {
        v->Visit(this);
    }
};

// Concrete Visitor
class InfoVisitor : public Visitor
{
public:
    void Visit(Book* b)
    {
        cout << "Обробка книги" << endl;
    }

    void Visit(Magazine* m)
    {
        cout << "Обробка журналу" << endl;
    }

    void Visit(Newspaper* n)
    {
        cout << "Обробка газети" << endl;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    InfoVisitor visitor;

    Book b;
    Magazine m;
    Newspaper n;

    b.Accept(&visitor);
    m.Accept(&visitor);
    n.Accept(&visitor);

    return 0;
}