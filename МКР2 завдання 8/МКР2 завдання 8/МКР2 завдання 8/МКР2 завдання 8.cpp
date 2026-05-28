#include <iostream>
#include <windows.h>
using namespace std;

// Функціонально-процедурний підхід
int Sum(int a, int b)
{
    return a + b;
}

// Об'єктно-орієнтований підхід
class Calculator
{
private:
    int a, b;

public:
    Calculator(int x, int y)
    {
        a = x;
        b = y;
    }

    int GetSum()
    {
        return a + b;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int result1 = Sum(5, 3);

    cout << "Функціонально-процедурний підхід:" << endl;
    cout << "Сума = " << result1 << endl << endl;

    Calculator calc(5, 3);

    cout << "Об'єктно-орієнтований підхід:" << endl;
    cout << "Сума = " << calc.GetSum() << endl;

    return 0;
}