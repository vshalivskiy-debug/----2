#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // 1. setw()
    cout << "1. setw() - ширина поля" << endl;
    cout << setw(10) << 25 << endl << endl;

    // 2. setprecision() + fixed
    cout << "2. setprecision() i fixed" << endl;
    double x = 3.1415926;
    cout << fixed << setprecision(2) << x << endl << endl;

    // 3. fixed
    cout << "3. fixed - фіксований формат" << endl;
    double a = 12.34567;
    cout << fixed << setprecision(3) << a << endl << endl;

    // 4. left i right
    cout << "4. left i right - вирівнювання" << endl;
    cout << left << setw(10) << "Іван" << "|" << endl;
    cout << right << setw(10) << "Іван" << "|" << endl;

    return 0;
}