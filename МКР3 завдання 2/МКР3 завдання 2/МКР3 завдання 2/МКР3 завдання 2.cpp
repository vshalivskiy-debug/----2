#include <iostream>
#include <windows.h>
using namespace std;

// Клас Лічильник
class Counter
{
private:
    int value;
    int minValue;
    int maxValue;

public:
    // Конструктор
    Counter(int minV, int maxV, int start)
    {
        minValue = minV;
        maxValue = maxV;
        value = start;
    }

    // Збільшення на 1
    void Increment()
    {
        value++;

        if (value > maxValue)
        {
            value = minValue;
        }
    }

    // Повернення поточного значення
    int GetValue()
    {
        return value;
    }

    // Встановлення мінімального значення
    void SetMin(int minV)
    {
        minValue = minV;
    }

    // Встановлення максимального значення
    void SetMax(int maxV)
    {
        maxValue = maxV;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Counter counter(0, 5, 0);

    cout << "Робота цифрового лічильника:" << endl;

    for (int i = 0; i < 8; i++)
    {
        cout << "Значення: " << counter.GetValue() << endl;
        counter.Increment();
    }

    return 0;
}