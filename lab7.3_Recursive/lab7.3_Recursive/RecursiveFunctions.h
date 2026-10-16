#pragma once

void Input(int** a, const int n, int i = 0, int j = 0);

void Print(int** a, const int n, int i = 0, int j = 0);

void SmoothMatrix(int** a, int** b, const int n, int i = 0, int j = 0);

int SmoothElement(int** a, const int n, int i, int j);

int Abs(int x);

int SumBelowDiagonal(int** a, const int n, int i = 1, int j = 0);