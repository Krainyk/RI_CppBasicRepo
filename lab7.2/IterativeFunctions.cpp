#include "IterativeFunctions.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Create(int** a, const int n, const int Low, const int High) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = Low + rand() % (High - Low + 1);
        }
    }
}

void Print(int** a, const int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

bool SearchMaxOfMinOddRows(int** a, const int n, int& maxOddMin) {
    bool found = false;
    for (int i = 1; i < n; i += 2) { // непарні рядки
        int minInRow = a[i][0];
        for (int j = 1; j < n; j++) {
            if (a[i][j] < minInRow)
                minInRow = a[i][j];
        }
        if (!found || minInRow > maxOddMin) {
            maxOddMin = minInRow;
            found = true;
        }
    }
    return found;
}