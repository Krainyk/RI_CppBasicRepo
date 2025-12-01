#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

bool has_four_consecutive(const std::string& filename) {
    ifstream in(filename, std::ios::binary);
    if (!in) return false;

    char prev = 0;
    int count = 0;
    char c;
    while (in.get(c)) {
        if (count == 0) {          
            prev = c;
            count = 1;
        }
        else if (c == prev) {   
            ++count;
            if (count >= 4) return true;
        }
        else {                  
            prev = c;
            count = 1;
        }
    }
    return false;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string filename = "t.txt";
    if (has_four_consecutive(filename)) {
        cout << "У файлі є чотири підряд однакові символи.\n";
    }
    else {
        cout << "Чотирьох підряд однакових символів немає.\n";
    }
    return 0;
}
