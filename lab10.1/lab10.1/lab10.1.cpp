#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

enum Specialty { KN, INF, MATH_ECON, PHYS_INF, LABOR };
string specStr[] = {
    "Комп. науки",
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

    int phys5, math5, prog5, num5, ped5;

    CountExcellent(s, N, phys5, math5, prog5, num5, ped5);

    cout << "\nКількість оцінок '5':\n";
    cout << "Фізика: " << phys5 << endl;
    cout << "Математика: " << math5 << endl;
    cout << "Програмування: " << prog5 << endl;
    cout << "Чисельні методи: " << num5 << endl;
    cout << "Педагогіка: " << ped5 << endl;

    int k = CountPhysMath5(s, N);
    cout << "\nКількість студентів з '5' з фізики і математики: " << k << endl;

    delete[] s;
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

void CountExcellent(Student* s, const int N,
    int& phys5, int& math5,
    int& prog5, int& num5, int& ped5)
{
    phys5 = math5 = prog5 = num5 = ped5 = 0;

    for (int i = 0; i < N; i++)
    {
        if (s[i].physics == 5) phys5++;
        if (s[i].math == 5)    math5++;

        switch (s[i].spec)
        {
        case KN:
            if (s[i].third.programming == 5) prog5++;
            break;
        case INF:
            if (s[i].third.numerical == 5) num5++;
            break;
        default:
            if (s[i].third.pedagogy == 5) ped5++;
        }
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
