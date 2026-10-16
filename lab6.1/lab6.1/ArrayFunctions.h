#pragma once // Захист від подвійного включення

// --- Ітераційні ---
void createArray(int b[], int n, int minVal, int maxVal);
void printArray(const int b[], int n);
int countPositive(const int b[], int n);
int sumPositive(const int b[], int n);
void replaceWithzero(int b[], int n);

// --- Рекурсивні ---
void createArrayRec(int b[], int n, int i, int minVal, int maxVal);
void printArrayRec(const int b[], int n, int i);
int countPositiveRec(const int b[], int n, int i);
int sumPositiveRec(const int b[], int n, int i);
void replaceWithzeroRec(int b[], int n, int i);