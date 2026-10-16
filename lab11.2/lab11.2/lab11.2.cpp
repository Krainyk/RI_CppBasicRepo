#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream file("t.txt");
    if (!file) {
        cerr << "Не вдалося відкрити файл!" << endl;
        return 1;
    }

    string word;
    int count = 0;

    while (file >> word) {
        if (!word.empty() && word.front() == word.back()) {
            count++;
        }
    }

    cout << "Кількість слів, де перший і останній символ однакові: " << count << endl;

    file.close();
    return 0;
}
