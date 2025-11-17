#include "IterativeFunctions.h"
#include <iostream>
#include <iomanip>
using namespace std;


void Input(int** a, const int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
}

void Print(int** a, const int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(6) << a[i][j];
        cout << endl;
    }
}

void SmoothMatrix(int** a, int** b, const int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            int count = 0;
            // Обхід сусідів
            for (int k = i - 1; k <= i + 1; k++) {
                for (int l = j - 1; l <= j + 1; l++) {
                    if (k >= 0 && k < n && l >= 0 && l < n) {
                        sum += a[k][l];
                        count++;
                    }
                }
            }
            b[i][j] = sum / count; // середнє арифметичне
        }
    }
}

int Abs(int x) {
    return (x >= 0) ? x : -x;
}

// Сума модулів нижче головної діагоналі
int SumBelowDiagonal(int** a, const int n) {
    int sum = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            sum += Abs(a[i][j]);
        }
    }
    return sum;
}