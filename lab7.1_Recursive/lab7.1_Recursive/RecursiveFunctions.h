#pragma
#include <iomanip>
#include <time.h>

void Create(int** a, const int rowCount, const int colCount,
    const int Low, const int High);

void Print(int** a, const int rowCount, const int colCount);

void SortRec(int** a, const int rowCount, const int colCount, int i0 = 0, int i1 = 0);

void Change(int** a, const int row1, const int row2, const int colCount);

void CalcRec(int** a, const int rowCount, const int colCount, int& S, int& k, int i = 0, int j = 0);