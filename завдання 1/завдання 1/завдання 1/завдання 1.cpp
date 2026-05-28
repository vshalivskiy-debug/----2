#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try
    {
        int a = 10;
        int b = 0;

        if (b == 0)
            throw "Ділення на нуль!";

        cout << a / b << endl;
    }
    catch (const char* error)
    {
        cout << "Помилка: " << error << endl;
    }

    return 0;
}