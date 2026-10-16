#include "RecursiveFunctions.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Create(int** a, int n, int Low, int High, int i, int j) {
    if (i == n) return;
    a[i][j] = Low + rand() % (High - Low + 1);

    if (j + 1 < n)
        Create(a, n, Low, High, i, j + 1);
    else
        Create(a, n, Low, High, i + 1, 0);
}

void Print(int** a, int n, int i, int j) {
    if (i == n) return;

    cout << setw(4) << a[i][j];

    if (j + 1 < n)
        Print(a, n, i, j + 1);
    else
    {
        cout << endl;
        Print(a, n, i + 1, 0);
    }
}

// рекурсивний мінімум по рядку
int RowMin(int** a, int row, int n, int col) {
    if (col == n - 1) return a[row][col];

    int nextMin = RowMin(a, row, n, col + 1);
    return (a[row][col] < nextMin ? a[row][col] : nextMin);
}

// рекурсивний пошук максимального серед мінімальних непарних рядків
bool SearchMaxOfMinOddRows(int** a, int n, int& maxOddMin, int row) {
    if (row >= n) return false;

    int rowMin = RowMin(a, row, n);

    bool nextFound = SearchMaxOfMinOddRows(a, n, maxOddMin, row + 2);

    if (!nextFound || rowMin > maxOddMin)
        maxOddMin = rowMin;

    return true;
}