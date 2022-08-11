#include <iostream>
using namespace std;

int table[9][9] = {
    {7, 0, 0, 0, 0, 0, 5, 0, 0},
    {6, 0, 0, 4, 0, 0, 0, 0, 0},
    {0, 4, 5, 0, 1, 0, 0, 9, 0},
    {4, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 3, 8, 1, 0, 0, 6, 0, 0},
    {0, 0, 0, 0, 9, 0, 0, 0, 2},
    {0, 0, 0, 0, 0, 8, 0, 6, 0},
    {0, 0, 7, 0, 0, 0, 0, 0, 0},
    {0, 5, 1, 3, 0, 0, 8, 0, 0},
};

int isPossible(int R, int C, int val)
{
    for (int r = 0; r < 9; r++)
        if (table[r][C] == val)
            return 0;

    for (int c = 0; c < 9; c++)
        if (table[R][c] == val)
            return 0;

    int Ri = (R / 3) * 3;
    int Ci = (C / 3) * 3;

    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            if (table[r + Ri][c + Ci] == val)
                return 0;

    return 1;
}

int solver(int R, int C)
{
    if (C == 9)
        if (R < 8)
        {
            C = 0;
            R++;
        }
        else
            return 1;

    if (table[R][C] != 0)
        return solver(R, C + 1);

    for (int num = 1; num <= 9; num++)
    {
        if (isPossible(R, C, num))
        {
            table[R][C] = num;
            if (solver(R, C + 1))
                return 1;
            table[R][C] = 0;
        }
    }
    return 0;
}

void printTable()
{
    for (int i = 0; i < 9; i++)
    {
        for (int k = 0; k < 9; k++)
            cout << "----";
        cout << endl;
        cout << "| ";
        for (int j = 0; j < 9; j++)
        {
            cout << " " << table[i][j] << " |";
        }
        cout << endl;
    }
    for (int k = 0; k < 9; k++)
        cout << "----";
    cout << endl;
}

int main()
{
    solver(0, 0);
    printTable();
}