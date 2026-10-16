#include "RecursiveFunctions.h"
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int main()
{
    srand(12345);

    int Low = -6;
    int High = 31;

    int rowCount = 7;
    int colCount = 5;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++) {
        a[i] = new int[colCount];
    }

    Create(a, rowCount, colCount, Low, High);
    Print(a, rowCount, colCount);
    SortRec(a, rowCount, colCount);
    Print(a, rowCount, colCount);

    int S = 0;
    int k = 0;
    CalcRec(a, rowCount, colCount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;

    for (int i = 0; i < rowCount; i++) {
        delete[] a[i];
    }
    delete[] a;
}