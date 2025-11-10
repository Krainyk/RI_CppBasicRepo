#include <iostream>
#include <cmath>
using namespace std;

// 1️ Рекурсивне введення елементів
void inputArray(double* p, int n, int i = 0) {
    if (i == n) return;
    cout << "p[" << i << "] = ";
    cin >> p[i];
    inputArray(p, n, i + 1);
}

// 2️ Рекурсивний пошук найбільшого за модулем елемента
double findMaxAbs(double* p, int n, int i = 1, double currentMax = 0) {
    if (i == 1) currentMax = abs(p[0]);
    if (i == n) return currentMax;
    if (abs(p[i]) > currentMax) currentMax = abs(p[i]);
    return findMaxAbs(p, n, i + 1, currentMax);
}

// 3️ Рекурсивний пошук індексів першого і другого додатних елементів
void findTwoPositives(double* p, int n, int i, int& firstPos, int& secondPos) {
    if (i == n) return;
    if (p[i] > 0) {
        if (firstPos == -1) firstPos = i;
        else if (secondPos == -1) {
            secondPos = i;
            return;
        }
    }
    findTwoPositives(p, n, i + 1, firstPos, secondPos);
}

// 4️ Рекурсивне обчислення суми між двома індексами
double sumBetween(double* p, int start, int end) {
    if (start >= end - 1) return 0;
    return p[start + 1] + sumBetween(p, start + 1, end);
}

// 5️ Рекурсивне створення нового масиву без нулів (з нулями в кінці)
void moveZeros(double* src, double* dst, int n, int i = 0, int index = 0) {
    if (i == n) {
        for (int j = index; j < n; j++)
            dst[j] = 0;
        return;
    }
    if (src[i] != 0) {
        dst[index] = src[i];
        moveZeros(src, dst, n, i + 1, index + 1);
    }
    else {
        moveZeros(src, dst, n, i + 1, index);
    }
}

// 6️ Рекурсивний вивід масиву
void printArray(double* p, int n, int i = 0) {
    if (i == n) return;
    cout << p[i] << " ";
    printArray(p, n, i + 1);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    double* p = new double[n];
    inputArray(p, n);

    // Знаходимо найбільше за модулем значення
    double maxAbs = findMaxAbs(p, n);
    cout << "The biggest element in abs: " << maxAbs << endl;

    // Знаходимо перший і другий додатні елементи
    int firstPos = -1, secondPos = -1;
    findTwoPositives(p, n, 0, firstPos, secondPos);

    if (firstPos != -1 && secondPos != -1 && secondPos - firstPos > 1) {
        double sum = sumBetween(p, firstPos, secondPos);
        cout << "Sum between first and second positive elements: " << sum << endl;
    }
    else {
        cout << "There are no two positive elements or nothing between them." << endl;
    }

    // Переносимо нулі в кінець
    double* result = new double[n];
    moveZeros(p, result, n);

    cout << "Transformed Array: ";
    printArray(result, n);
    cout << endl;

    delete[] p;
    delete[] result;
    return 0;
}
