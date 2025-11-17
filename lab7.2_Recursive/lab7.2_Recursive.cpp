#include "RecursiveFunctions.h"
#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
    srand(12345);

    int n;
    cout << "n = ";
    cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    Create(a, n, -6, 31);
    Print(a, n);

    int result;
    if (SearchMaxOfMinOddRows(a, n, result))
        cout << "max odd = " << result << endl;
    else
        cout << "no odd rows found" << endl;

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}