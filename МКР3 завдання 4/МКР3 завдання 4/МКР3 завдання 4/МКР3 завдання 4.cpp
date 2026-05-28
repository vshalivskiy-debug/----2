#include <iostream>
#include <windows.h>
#include <cstdarg>
using namespace std;

// а) Перевантаження функцій (через посилання)
void Sum(int& result, int a, int b)
{
    result = a + b;
}

void Sum(int& result, int a, int b, int c)
{
    result = a + b + c;
}

// б) Параметри за замовчуванням (через вказівник)
void SumDefault(int* result, int a, int b = 0, int c = 0)
{
    *result = a + b + c;
}

// в) Змінна кількість параметрів
void SumVar(int& result, int count, ...)
{
    result = 0;

    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++)
    {
        result += va_arg(args, int);
    }

    va_end(args);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int result1, result2, result3, result4;

    // Перевантаження
    Sum(result1, 5, 7);
    Sum(result2, 1, 2, 3);

    // Параметри за замовчуванням
    SumDefault(&result3, 10, 20);

    // Змінна кількість параметрів
    SumVar(result4, 4, 1, 2, 3, 4);

    cout << "Перевантаження (2 числа): " << result1 << endl;
    cout << "Перевантаження (3 числа): " << result2 << endl;
    cout << "Параметри за замовчуванням: " << result3 << endl;
    cout << "Змінна кількість параметрів: " << result4 << endl;

    return 0;
}