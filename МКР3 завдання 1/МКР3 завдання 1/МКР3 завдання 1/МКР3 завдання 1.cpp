#include <iostream>
#include <windows.h>
using namespace std;

// Абстрактний клас
class Figure
{
protected:
    double x, y;
    double angle;
    double scale;

public:
    Figure(double x0, double y0, double a, double s)
    {
        x = x0;
        y = y0;
        angle = a;
        scale = s;
    }

    // Чисто віртуальна функція
    virtual void Draw() = 0;

    // Зробити невидимою
    virtual void Hide()
    {
        cout << "Фігура стала невидимою" << endl;
    }

    // Поворот
    void Rotate(double a)
    {
        angle += a;
        cout << "Поворот на " << a << " градусів" << endl;
    }

    // Переміщення
    void Move(double dx, double dy)
    {
        x += dx;
        y += dy;
        cout << "Переміщено у точку (" << x << "; " << y << ")" << endl;
    }

    virtual ~Figure() {}
};

// Трикутник
class Triangle : public Figure
{
public:
    Triangle(double x, double y, double a, double s)
        : Figure(x, y, a, s)
    {
    }

    void Draw() override
    {
        cout << "Трикутник" << endl;
    }
};

// Чотирикутник
class Quadrilateral : public Figure
{
public:
    Quadrilateral(double x, double y, double a, double s)
        : Figure(x, y, a, s)
    {
    }

    void Draw() override
    {
        cout << "Чотирикутник" << endl;
    }
};

// Многокутник
class Many : public Figure
{
public:
    Many(double x, double y, double a, double s)
        : Figure(x, y, a, s)
    {
    }

    void Draw() override
    {
        cout << "Многокутник" << endl;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Triangle triangle(1, 2, 0, 1);
    Quadrilateral quadrilateral(3, 4, 10, 1.5);
    Many many(5, 6, 20, 2);

    Figure* figures[3];

    figures[0] = &triangle;
    figures[1] = &quadrilateral;
    figures[2] = &many;

    for (int i = 0; i < 3; i++)
    {
        figures[i]->Draw();
        figures[i]->Rotate(45);
        figures[i]->Move(2, 3);
        figures[i]->Hide();
        cout << endl;
    }

    return 0;
}