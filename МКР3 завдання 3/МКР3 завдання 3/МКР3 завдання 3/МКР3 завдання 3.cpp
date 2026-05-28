#include <iostream>
#include <windows.h>
using namespace std;

template <class T>
class Matrix
{
private:
    T** arr;
    int rows;
    int cols;

public:
    Matrix(int r, int c)
    {
        rows = r;
        cols = c;

        arr = new T * [rows];
        for (int i = 0; i < rows; i++)
            arr[i] = new T[cols];
    }

    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
            delete[] arr[i];

        delete[] arr;
    }

    void Input()
    {
        cout << "Введіть елементи масиву:" << endl;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << "arr[" << i << "][" << j << "] = ";
                cin >> arr[i][j];
            }
        }
    }

    void Output()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
                cout << arr[i][j] << "\t";

            cout << endl;
        }
    }

    void CopyByRows()
    {
        cout << "Копіювання за рядками:" << endl;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
                cout << arr[i][j] << "\t";

            cout << endl;
        }
    }

    void CopyByColumns()
    {
        cout << "Копіювання за стовпцями:" << endl;

        for (int j = 0; j < cols; j++)
        {
            for (int i = 0; i < rows; i++)
                cout << arr[i][j] << "\t";

            cout << endl;
        }
    }

    void CopyRow(int row)
    {
        if (row < 0 || row >= rows)
        {
            cout << "Невірний номер рядка!" << endl;
            return;
        }

        cout << "Копія рядка " << row << ":" << endl;

        for (int j = 0; j < cols; j++)
            cout << arr[row][j] << "\t";

        cout << endl;
    }

    void CopyColumn(int col)
    {
        if (col < 0 || col >= cols)
        {
            cout << "Невірний номер стовпця!" << endl;
            return;
        }

        cout << "Копія стовпця " << col << ":" << endl;

        for (int i = 0; i < rows; i++)
            cout << arr[i][col] << endl;
    }

    void CopyMainDiagonal()
    {
        cout << "Копія головної діагоналі:" << endl;

        int n = rows < cols ? rows : cols;

        for (int i = 0; i < n; i++)
            cout << arr[i][i] << "\t";

        cout << endl;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int rows, cols;

    cout << "Введіть кількість рядків: ";
    cin >> rows;

    cout << "Введіть кількість стовпців: ";
    cin >> cols;

    Matrix<int> matrix(rows, cols);

    matrix.Input();

    cout << endl << "Початковий масив:" << endl;
    matrix.Output();

    cout << endl;
    matrix.CopyByRows();

    cout << endl;
    matrix.CopyByColumns();

    cout << endl;
    matrix.CopyRow(1);

    cout << endl;
    matrix.CopyColumn(1);

    cout << endl;
    matrix.CopyMainDiagonal();

    return 0;
}