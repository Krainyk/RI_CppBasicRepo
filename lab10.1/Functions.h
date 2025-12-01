#pragma once
enum Specialty { KN, INF, MATH_ECON, PHYS_INF, LABOR };
union ThirdMark;
struct Student;

void Create(Student* s, const int N);

void Print(Student* s, const int N);

void CountExcellent(Student* s, const int N,
    int& phys5, int& math5,
    int& prog5, int& num5, int& ped5);
int CountPhysMath5(Student* s, const int N);