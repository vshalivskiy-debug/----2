#include <iostream>
#include <windows.h>
using namespace std;

// Інтерфейс принтера
class Printer
{
public:
    virtual void Print() = 0;
    virtual ~Printer() {}
};

// Лазерний принтер
class LaserPrinter : public Printer
{
public:
    void Print() override
    {
        cout << "Друк через лазерний принтер" << endl;
    }
};

// Струменевий принтер
class InkPrinter : public Printer
{
public:
    void Print() override
    {
        cout << "Друк через струменевий принтер" << endl;
    }
};

// Клас документа
class Document
{
private:
    Printer* printer;

public:
    Document(Printer* p)
    {
        printer = p;
    }

    void PrintDocument()
    {
        printer->Print();
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    LaserPrinter lp;
    InkPrinter ip;

    Document doc1(&lp);
    Document doc2(&ip);

    doc1.PrintDocument();
    doc2.PrintDocument();

    return 0;
}