#include "RecursiveFunctions.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Input(int** a, const int n, int i, int j) {
    if (i == n) return;
    if (j < n) {
        cout << "a[" << i << "][" << j << "] = ";
        cin >> a[i][j];
        Input(a, n, i, j + 1);
    }
    else {
        Input(a, n, i + 1, 0);
    }
}

void Print(int** a, const int n, int i, int j) {
    if (i == n) return;
    if (j < n) {
        cout << setw(6) << a[i][j];
        Print(a, n, i, j + 1);
    }
    else {
        cout << endl;
        Print(a, n, i + 1, 0);
    }
}

void SmoothMatrix(int** a, int** b, const int n, int i, int j) {
    if (i == n) return;
    if (j < n) {
        b[i][j] = SmoothElement(a, n, i, j);
        SmoothMatrix(a, b, n, i, j + 1);
    }
    else {
        SmoothMatrix(a, b, n, i + 1, 0);
    }
}

int SmoothElement(int** a, const int n, int i, int j) {
    int sum = 0, count = 0;
    for (int k = i - 1; k <= i + 1; k++) {
        for (int l = j - 1; l <= j + 1; l++) {
            if (k >= 0 && k < n && l >= 0 && l < n) {
                sum += a[k][l];
                count++;
            }
        }
    }
    return sum / count;
}

int Abs(int x) {
    return (x >= 0) ? x : -x;
}

int SumBelowDiagonal(int** a, const int n, int i, int j) {
    if (i == n) return 0;
    if (j < i) {
        return Abs(a[i][j]) + SumBelowDiagonal(a, n, i, j + 1);
    }
    else {
        return SumBelowDiagonal(a, n, i + 1, 0);
    }
}