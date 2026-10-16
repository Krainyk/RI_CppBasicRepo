#include "RecursiveFunctions.h"
#include <iostream>
using namespace std;

void Create(int** a, const int rowCount, const int colCount,
    const int Low, const int High) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            a[i][j] = Low + rand() % (High - Low + 1);
        }
    }
}

void Print(int** a, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }
}

void SortRec(int** a, const int rowCount, const int colCount, int i0, int i1) {
    if (i0 == rowCount - 1) return;

    if (i1 == rowCount - i0 - 1) {
        SortRec(a, rowCount, colCount, i0 + 1, 0);
        return;
    }

    if (a[i1][0] > a[i1 + 1][0] ||
        (a[i1][0] == a[i1 + 1][0] && a[i1][1] < a[i1 + 1][1]) ||
        (a[i1][0] == a[i1 + 1][0] && a[i1][1] == a[i1 + 1][1] && a[i1][2] < a[i1 + 1][2])) {
        Change(a, i1, i1 + 1, colCount);
    }

    SortRec(a, rowCount, colCount, i0, i1 + 1);
}

void Change(int** a, const int row1, const int row2, const int colCount) {
    for (int j = 0; j < colCount; j++) {
        int tmp = a[row1][j];
        a[row1][j] = a[row2][j];
        a[row2][j] = tmp;
    }
}

void CalcRec(int** a, const int rowCount, const int colCount, int& S, int& k, int i, int j) {
    if (i == rowCount) return;
    if (j == colCount) {
        CalcRec(a, rowCount, colCount, S, k, i + 1, 0);
        return;
    }

    if (a[i][j] % 2 == 0 && !(i % 3 == 0 || j % 3 == 0)) {
        S += a[i][j];
        k++;
        a[i][j] = 0;
    }

    CalcRec(a, rowCount, colCount, S, k, i, j + 1);
}