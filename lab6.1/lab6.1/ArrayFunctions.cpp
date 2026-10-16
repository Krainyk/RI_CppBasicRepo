#include "ArrayFunctions.h" // Підключаємо наш .h файл
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// --- Ітераційні ---
void createArray(int b[], int n, int minVal, int maxVal) {
	for (int i = 0; i < n; i++) {
		b[i] = rand() % (maxVal - minVal + 1) + minVal;
	}
}

void printArray(const int b[], int n) {
	for (int i = 0; i < n; i++) {
		cout << setw(4) << b[i];
	}
	cout << endl;
}

int countPositive(const int b[], int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (b[i] > 0 && b[i] % 2 != 0) {
			count++;
		}
	}
	return count;
}

int sumPositive(const int b[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (b[i] > 0 && b[i] % 2 != 0) {
			sum += b[i];
		}
	}
	return sum;
}

void replaceWithzero(int b[], int n) {
	for (int i = 0; i < n; i++) {
		if (b[i] > 0 && b[i] % 2 != 0) {
			b[i] = 0;
		}
	}
}

// Рекурсивний спосіб
void createArrayRec(int b[], int n, int i, int minVal, int maxVal) {
	if (i == n) return;
	b[i] = minVal + rand() % (maxVal - minVal + 1);
	createArrayRec(b, n, i + 1, minVal, maxVal);
}

void printArrayRec(const int b[], int n, int i) {
	if (i == n) {
		cout << endl;
		return;
	}
	cout << setw(4) << b[i];
	printArrayRec(b, n, i + 1);
}

int countPositiveRec(const int b[], int n, int i) {
	if (i == n) return 0;
	return ((b[i] > 0 && b[i] % 2 != 0) ? 1 : 0) + countPositiveRec(b, n, i + 1);
}

int sumPositiveRec(const int b[], int n, int i) {
	if (i == n) return 0;
	return ((b[i] > 0 && b[i] % 2 != 0) ? b[i] : 0) + sumPositiveRec(b, n, i + 1);
}

void replaceWithzeroRec(int b[], int n, int i) {
	if (i == n) return;
	if (b[i] > 0 && b[i] % 2 != 0) {
		b[i] = 0;
	}
	replaceWithzeroRec(b, n, i + 1);
}