#pragma once

void Create(int** a, int n, int Low, int High, int i = 0, int j = 0);

void Print(int** a, int n, int i = 0, int j = 0);

int RowMin(int** a, int row, int n, int col = 0);

bool SearchMaxOfMinOddRows(int** a, int n, int& maxOddMin, int row = 1);