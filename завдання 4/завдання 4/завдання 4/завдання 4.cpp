#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "1. Простота використання cin і cout" << endl;
    int a;
    cout << "Введіть число: ";
    cin >> a;
    cout << "Ви ввели число: " << a << endl << endl;

    cout << "2. Підтримка різних типів даних" << endl;
    int age = 18;
    double mark = 95.5;
    string name = "Ivan";

    cout << "Ім'я: " << name << endl;
    cout << "Вік: " << age << endl;
    cout << "Оцінка: " << mark << endl << endl;

    cin.ignore();

    cout << "3. Зручна робота з рядками" << endl;
    string userName;
    cout << "Введіть ім'я: ";
    getline(cin, userName);
    cout << "Привіт, " << userName << "!" << endl << endl;

    cout << "4. Перевірка помилок введення" << endl;
    int x;
    cout << "Введіть число: ";
    cin >> x;

    if (cin.fail())
        cout << "Помилка введення! Потрібно вводити число." << endl;
    else
        cout << "Введене число: " << x << endl;

    return 0;
}