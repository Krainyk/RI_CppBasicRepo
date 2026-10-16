#include "IterativeFunctions.h"
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int main()
{
    int Low = -6;
    int High = 31;

    int rowCount = 7;
    int colCount = 5;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++) {
        a[i] = new int[colCount];
    }

    srand(12345);
    Create(a, rowCount, colCount, Low, High);
    Print(a, rowCount, colCount);
    Sort(a, rowCount, colCount);
    Print(a, rowCount, colCount);

    int S = 0;
    int k = 0;
    Calc(a, rowCount, colCount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    
    for (int i = 0; i < rowCount; i++) {
        delete[] a[i];
    }
    delete[] a;
}