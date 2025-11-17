#include "IterativeFunctions.h"
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int main()
{
    srand(12345);
    int Low = -6;
    int High = 31;

    int n;
    cout << "n = ";
    cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
    }


    Create(a, n, Low, High);
    Print(a, n);

    int MaxOddMin;
    if (SearchMaxOfMinOddRows(a, n, MaxOddMin))
        cout << "max odd = " << MaxOddMin << endl;
    else
        cout << "there are no odd elements" << endl;

    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;

}