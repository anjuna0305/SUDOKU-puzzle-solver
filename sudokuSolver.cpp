#include <iostream>

int COUNT = 0;

void printMesh(int mesh[9][9])
{
    std::cout << "+---------+---------+---------+" << std::endl;
    for (int r = 0; r < 9; r++)
    {
        for (int c = 0; c < 9; c++)
        {
            if (c == 0)
                std::cout << "|";
            std::cout << " " << mesh[r][c] << " ";
            if (c == 2 || c == 5 || c == 8)
                std::cout << "|";
        }
        std::cout << std::endl;
        if (r == 2 || r == 5 || r == 8)
            std::cout << "+---------+---------+---------+" << std::endl;
    }
    std::cout << std::endl;
}

bool isPresentRow(int mesh[9][9], int row, int val)
{
    for (int col = 0; col < 9; col++)
    {
        if (mesh[row][col] == val)
            return true;
    }
    return false;
}

bool isPresentCol(int mesh[9][9], int col, int val)
{
    for (int row = 0; row < 9; row++)
    {
        if (mesh[row][col] == val)
            return true;
    }
    return false;
}

bool isPresentSquare(int mesh[9][9], int row, int col, int val)
{
    int sqRow = (row / 3) * 3;
    int sqCol = (col / 3) * 3;

    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
            if (mesh[sqRow + r][sqCol + c] == val)
                return true;
    }
    return false;
}

bool isSafe(int mesh[9][9], int row, int col, int num)
{
    if (!isPresentCol(mesh, col, num) && !isPresentRow(mesh, row, num) && !isPresentSquare(mesh, row, col, num))
        return true;
    return false;
}

void solver(int mesh[9][9], int row, int col)
{
    if (col == 9)
    {
        if (row == 8)
        {
            COUNT++;
            printMesh(mesh);
        }
        else
        {
            col = 0;
            row++;
        }
    }
    if (mesh[row][col] != 0)
    {
        solver(mesh, row, col + 1);
        return;
    }

    for (int num = 1; num < 10; num++)
    {
        if (isSafe(mesh, row, col, num))
        {
            mesh[row][col] = num;
            solver(mesh, row, col + 1);
            mesh[row][col] = 0;
        }
    }
}

int main()
{
    int mesh[9][9] = {
        {9, 0, 6, 0, 7, 0, 4, 0, 3},
        {0, 0, 0, 4, 0, 0, 2, 0, 0},
        {0, 7, 0, 0, 2, 3, 0, 1, 0},
        {5, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 4, 0, 2, 0, 8, 0, 6, 0},
        {0, 0, 3, 0, 9, 0, 0, 0, 5},
        {0, 3, 0, 7, 0, 0, 0, 5, 0},
        {0, 0, 7, 0, 0, 5, 0, 0, 0},
        {4, 0, 5, 0, 1, 0, 7, 0, 8}};
    // printMesh(mesh);
    solver(mesh, 0, 0);

    if (COUNT == 0)
        std::cout << "There are no solutions" << std::endl;
    else
        std::cout << "There are " << COUNT << " solutions." << std::endl;
}