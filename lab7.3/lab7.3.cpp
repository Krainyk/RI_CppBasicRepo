#include "IterativeFunctions.h"
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;


int main() {
    srand((unsigned)time(NULL));
    int n;
    cout << "Enter the matrix size n: ";
    cin >> n;

    // Виділення пам'яті під матриці
    int** a = new int* [n];
    int** b = new int* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
        b[i] = new int[n];
    }

    Input(a, n);
    cout << "Initial matrix:" << endl;
    Print(a, n);

    SmoothMatrix(a, b, n);
    cout << "Smoothed matrix:" << endl;
    Print(b, n);

    int sum = SumBelowDiagonal(b, n);
    cout << "Sum of the moduli of the elements below the main diagonal: " << sum << endl;

    // Звільнення пам'яті
    for (int i = 0; i < n; i++) {
        delete[] a[i];
        delete[] b[i];
    }
    delete[] a;
    delete[] b;

    return 0;
}