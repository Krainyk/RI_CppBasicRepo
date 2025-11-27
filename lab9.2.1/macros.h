#pragma once

#ifndef MACROS1_H
#define MACROS1_H

#include <cmath>
#include <iostream>

// Математичні макроси
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define POW(x, y) (pow((x), (y)))
#define SQRT(x) (sqrt(x))

// Логічні макроси
#define AND &&
#define OR ||

// Виведення
#define PRINT(x) std::cout << x;

#endif