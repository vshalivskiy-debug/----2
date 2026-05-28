#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try
    {
        int age;
        cout << "Введіть вік: ";
        cin >> age;

        if (age < 18)
            throw age;

        cout << "Доступ дозволено." << endl;
    }
    catch (int x)
    {
        cout << "Помилка! Вік " << x
            << " років. Доступ заборонено." << endl;
    }

    return 0;
}