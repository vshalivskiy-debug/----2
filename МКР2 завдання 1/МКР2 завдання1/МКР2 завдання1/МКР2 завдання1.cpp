#include <iostream>
#include <windows.h>
using namespace std;

// Інтерфейс друку
class IPrint
{
public:
    virtual void Print() = 0;
};

// Інтерфейс сканування
class IScan
{
public:
    virtual void Scan() = 0;
};

// Принтер
class Printer : public IPrint
{
public:
    void Print() override
    {
        cout << "Друк документа" << endl;
    }
};

// Сканер
class Scanner : public IScan
{
public:
    void Scan() override
    {
        cout << "Сканування документа" << endl;
    }
};

// Багатофункціональний пристрій
class MFP : public IPrint, public IScan
{
public:
    void Print() override
    {
        cout << "MFP друкує документ" << endl;
    }

    void Scan() override
    {
        cout << "MFP сканує документ" << endl;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Printer p;
    Scanner s;
    MFP m;

    p.Print();
    s.Scan();
    m.Print();
    m.Scan();

    return 0;
}