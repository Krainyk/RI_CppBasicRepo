#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

enum Specialty { KN, INF, MATH_ECON, PHYS_INF, LABOR };

string specStr[] = {
    "Комп.науки",
    "Інформатика",
    "Мат+Екон",
    "Фіз+Інф",
    "Трудове"
};

union ThirdMark {
    int programming;
    int numerical;
    int pedagogy;
};

struct Student {
    string prizv;
    int kurs;
    Specialty spec;
    int physics;
    int math;
    ThirdMark third;
};

void Create(Student* s, const int N);
void Print(Student* s, const int N);

void CountExcellent(Student* s, const int N,
    int& phys5, int& math5,
    int& prog5, int& num5, int& ped5);

int CountPhysMath5(Student* s, const int N);

double AvgMark(const Student& s);

void SortStudents(Student* s, int N);
void IndexSort(Student* s, int* idx, int N);

int BinarySearch(Student* s, int* idx, int N,
    string prizv, Specialty spec, double avg);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введіть кількість студентів: ";
    cin >> N;

    Student* s = new Student[N];

    Create(s, N);
    Print(s, N);

    // ---- 5-ки ----
    int phys5, math5, prog5, num5, ped5;
    CountExcellent(s, N, phys5, math5, prog5, num5, ped5);

    cout << "\nКількість оцінок '5':\n";
    cout << "Фізика: " << phys5 << endl;
    cout << "Математика: " << math5 << endl;
    cout << "Програмування: " << prog5 << endl;
    cout << "Чисельні методи: " << num5 << endl;
    cout << "Педагогіка: " << ped5 << endl;

    cout << "\nСтудентів з 5 з фізики і математики: "
        << CountPhysMath5(s, N) << endl;

    SortStudents(s, N);
    cout << "\nПІСЛЯ ФІЗИЧНОГО СОРТУВАННЯ:\n";
    Print(s, N);

    int* idx = new int[N];
    IndexSort(s, idx, N);

    cout << "\nІНДЕКСНЕ СОРТУВАННЯ:\n";
    for (int i = 0; i < N; i++)
        cout << s[idx[i]].prizv << "  " << AvgMark(s[idx[i]]) << endl;

    string findName;
    int sp;
    double avg;

    cout << "\nВведіть прізвище для пошуку: ";
    cin >> findName;

    cout << "Введіть спеціальність (0-4): ";
    cin >> sp;

    cout << "Введіть середній бал: ";
    cin >> avg;

    int pos = BinarySearch(s, idx, N, findName, (Specialty)sp, avg);

    if (pos != -1)
        cout << "Студент знайдений: " << s[pos].prizv << endl;
    else
        cout << "Студента не знайдено\n";

    delete[] s;
    delete[] idx;

    return 0;
}

void Create(Student* s, const int N)
{
    int sp;
    for (int i = 0; i < N; i++)
    {
        cout << "\nСтудент № " << i + 1 << endl;

        cin.get();
        cin.sync();

        cout << " Прізвище: ";
        getline(cin, s[i].prizv);

        cout << " Курс: ";
        cin >> s[i].kurs;

        cout << " Спеціальність (0-КН, 1-Інф, 2-М+Е, 3-Ф+І, 4-Труд): ";
        cin >> sp;
        s[i].spec = (Specialty)sp;

        cout << " Оцінка з фізики: ";
        cin >> s[i].physics;

        cout << " Оцінка з математики: ";
        cin >> s[i].math;

        switch (s[i].spec)
        {
        case KN:
            cout << " Оцінка з програмування: ";
            cin >> s[i].third.programming;
            break;
        case INF:
            cout << " Оцінка з чисельних методів: ";
            cin >> s[i].third.numerical;
            break;
        default:
            cout << " Оцінка з педагогіки: ";
            cin >> s[i].third.pedagogy;
        }
    }
}

void Print(Student* s, const int N)
{
    cout << "\n====================================================================================\n";
    cout << "| № | Прізвище | Курс | Спеціальність | Фіз | Мат | Прог | ЧисМ | Пед |\n";
    cout << "------------------------------------------------------------------------------------\n";

    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(2) << right << i + 1 << " ";
        cout << "| " << setw(9) << left << s[i].prizv;
        cout << "| " << setw(4) << right << s[i].kurs;
        cout << "| " << setw(13) << left << specStr[s[i].spec];
        cout << "| " << setw(3) << right << s[i].physics;
        cout << "| " << setw(3) << right << s[i].math;

        switch (s[i].spec)
        {
        case KN:
            cout << "| " << setw(4) << s[i].third.programming
                << "|   -  |   -  |";
            break;
        case INF:
            cout << "|   -  | " << setw(4) << s[i].third.numerical
                << " |   -  |";
            break;
        default:
            cout << "|   -  |   -  | " << setw(4) << s[i].third.pedagogy << " |";
        }

        cout << endl;
    }

    cout << "====================================================================================\n";
}

double AvgMark(const Student& s)
{
    double third;

    if (s.spec == KN)
        third = s.third.programming;
    else if (s.spec == INF)
        third = s.third.numerical;
    else
        third = s.third.pedagogy;

    return (s.physics + s.math + third) / 3.0;
}

void CountExcellent(Student* s, const int N,
    int& phys5, int& math5,
    int& prog5, int& num5, int& ped5)
{
    phys5 = math5 = prog5 = num5 = ped5 = 0;

    for (int i = 0; i < N; i++)
    {
        if (s[i].physics == 5) phys5++;
        if (s[i].math == 5) math5++;

        if (s[i].spec == KN && s[i].third.programming == 5) prog5++;
        else if (s[i].spec == INF && s[i].third.numerical == 5) num5++;
        else if (s[i].third.pedagogy == 5) ped5++;
    }
}

int CountPhysMath5(Student* s, const int N)
{
    int k = 0;
    for (int i = 0; i < N; i++)
        if (s[i].physics == 5 && s[i].math == 5)
            k++;
    return k;
}

void SortStudents(Student* s, int N)
{
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N - i - 1; j++)
            if (AvgMark(s[j]) > AvgMark(s[j + 1]) ||
                (AvgMark(s[j]) == AvgMark(s[j + 1]) && s[j].spec > s[j + 1].spec) ||
                (AvgMark(s[j]) == AvgMark(s[j + 1]) && s[j].spec == s[j + 1].spec &&
                    s[j].prizv > s[j + 1].prizv))
                swap(s[j], s[j + 1]);
}

void IndexSort(Student* s, int* idx, int N)
{
    for (int i = 0; i < N; i++)
        idx[i] = i;

    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N - i - 1; j++)
        {
            int a = idx[j], b = idx[j + 1];

            if (AvgMark(s[a]) > AvgMark(s[b]) ||
                (AvgMark(s[a]) == AvgMark(s[b]) && s[a].spec > s[b].spec) ||
                (AvgMark(s[a]) == AvgMark(s[b]) && s[a].spec == s[b].spec &&
                    s[a].prizv > s[b].prizv))
                swap(idx[j], idx[j + 1]);
        }
}

int BinarySearch(Student* s, int* idx, int N,
    string prizv, Specialty spec, double avg)
{
    int L = 0, R = N - 1;

    while (L <= R)
    {
        int m = (L + R) / 2;
        int i = idx[m];

        if (s[i].prizv == prizv && s[i].spec == spec && AvgMark(s[i]) == avg)
            return i;

        if (AvgMark(s[i]) < avg ||
            (AvgMark(s[i]) == avg && s[i].spec < spec) ||
            (AvgMark(s[i]) == avg && s[i].spec == spec && s[i].prizv < prizv))
            L = m + 1;
        else
            R = m - 1;
    }
    return -1;
}
