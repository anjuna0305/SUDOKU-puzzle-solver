#include <iostream>
using namespace std;

#define size 9
int table[size][size] = {4, 0, 0, 0, 0, 0, 1, 0, 8, 0, 0, 0, 0, 8, 3, 0, 0, 0, 0, 0, 0, 0, 9, 0, 5, 0, 7, 0, 6, 2, 4, 0, 0, 0, 0, 0, 3, 0, 9, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 7, 4, 6, 0, 5, 0, 8, 0, 4, 0, 0, 0, 0, 0, 0, 0, 8, 1, 0, 0, 0, 0, 2, 0, 7, 0, 0, 0, 0, 0, 6}; // level 100

// int table[size][size] = {0, 0, 0, 0, 0, 0, 5, 0, 0, 3, 0, 2, 0, 7, 0, 9, 1, 0, 6, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 6, 0, 2, 0, 3, 0, 0, 1, 5, 9, 7, 9, 0, 6, 0, 5, 0, 8, 0, 1, 0, 9, 7, 0, 0, 0, 0, 0, 4, 5, 0, 0, 0, 0, 2, 3, 0, 0, 3, 8, 4, 5, 0, 6, 0, 0}; // level 1
int counter = size * size;
int preCount = 0;

void countCorrecter()
{
    for (int r = 0; r < size; r++)
        for (int c = 0; c < size; c++)
            if (table[r][c] != 0)
                counter = counter - 1;
}

int squareCheck(int x, int y, int lett)
{
    if (x > size - 1 || y > size - 1)
    {
        printf("invalid index!\n");
        return 0;
    }

    int m = (x / 3) * 3;
    int n = (y / 3) * 3;

    for (int i = m; i < m + 3; i++)
        for (int j = n; j < n + 3; j++)
            if (table[i][j] == lett)
                return 0;

    return 1;
}

int rowCheck(int x, int y, int lett)
{
    for (int j = 0; j < size; j++)
        if (j == y)
            continue;
        else if (table[x][j] == lett)
            return 0;

    return 1;
}

int colCheck(int x, int y, int lett)
{
    for (int i = 0; i < size; i++)
        if (i == x)
            continue;
        else if (table[i][y] == lett)
            return 0;

    return 1;
}

void printTable()
{
    for (int i = 0; i < size; i++)
    {
        for (int k = 0; k < size; k++)
            cout << "----";
        cout << endl;
        cout << "| ";
        for (int j = 0; j < 9; j++)
        {
            cout << " " << table[i][j] << " |";
        }
        cout << endl;
    }
    for (int k = 0; k < size; k++)
        cout << "----";
    cout << endl;
}
// 2 5 4
void checker1()
{
    for (int num = 1; num <= 9; num++)
        for (int r = 0; r < size; r++)
            for (int c = 0; c < size; c++)
                if (table[r][c] == 0)
                    if (squareCheck(r, c, num))
                    {
                        int m = (r / 3) * 3; // raws  0
                        int n = (c / 3) * 3; // columns  3

                        int flag = 0;
                        for (int p = m; p < m + 3; p++)
                            for (int q = n; q < n + 3; q++)
                                if (flag == 0 && table[p][q] == 0)
                                    if (p == r && q == c)
                                        continue;
                                    else
                                    {
                                        if (colCheck(p, q, num) && rowCheck(p, q, num))
                                        {
                                            flag = 1;
                                        }
                                    }
                        if (flag == 0)
                        {
                            table[r][c] = num;
                            counter = counter - 1;
                        }
                    }
}

void checker2()
{
    for (int r = 0; r < size; r++)
        for (int c = 0; c < size; c++)
        {
            int tempCount = 0;
            int temp = 0;
            for (int num = 1; num <= 9; num++)
            {
                if (table[r][c] == 0)
                    if (squareCheck(r, c, num) && rowCheck(r, c, num) && colCheck(r, c, num))
                    {
                        tempCount = tempCount + 1;
                        temp = num;
                    }
            }
            if (tempCount == 1)
            {
                table[r][c] = temp;
                counter = counter - 1;
                preCount = preCount + 1;
            }
        }
}

void preValManual()
{
    int r, c, val;
    int flag = 0;
    char temp;

    while (flag == 0)
    {
        cout << "Enter row : ";
        cin >> r;
        cout << "Enter colomn : ";
        cin >> c;
        cout << "Enter val : ";
        cin >> val;

        table[r][c] = val;

        cout << "more inputs(y/n) : ";
        cin >> temp;
        if (temp == 'y' || temp == 'Y')
            flag = 0;
        else if (temp == 'n' || temp == 'N')
            flag = 1;
        else
        {
            cout << "invalind input" << endl;
            return;
        }
    }
}

void preVal()
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            cout << "row[" << r + 1 << "]"
                 << "col[" << c + 1 << "]"
                 << " : ";
            cin >> table[r][c];
        }
    }
}

void sudoku()
{

    while (counter != 0)
    {
        do
        {
            preCount = size * size - counter;
            checker1();
        } while (preCount != size * size - counter);
        do
        {
            preCount = size * size - counter;
            checker2();
        } while (preCount != size * size - counter);
    }

    printTable();
}

int main()
{
    countCorrecter();

    sudoku();
}
