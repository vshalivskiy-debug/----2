#include <iostream>
#include <windows.h>
using namespace std;

void CheckNumber(int n)
{
    if (n < 0)
        throw "Число не може бути від’ємним!";
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try
    {
        CheckNumber(-5);
    }
    catch (const char* error)
    {
        cout << "Помилка: " << error << endl;
    }

    return 0;
}