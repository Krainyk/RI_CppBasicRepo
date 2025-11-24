#define _CRT_SECURE_NO_WARNINGS
#include "Functions.h"
#include <string>
using namespace std;

int CountStr(const string& s)
{
    if (s.length() < 4)
        return 0;

    int k = 0;
    int count = 1;

    for (size_t i = 1; i < s.length(); i++)
    {
        if (s[i] == s[i - 1])
        {
            count++;
            if (count == 4)
                k++;
        }
        else
        {
            count = 1;
        }
    }

    return k;
}

void ChangeStr(char* str)
{
    size_t len = strlen(str);
    if (len < 4)
        return;

    char tmp[201];
    int t = 0;

    for (int i = 0; i < len;)
    {
        // рахуємо довжину групи однакових символів
        int j = i + 1;
        while (j < len && str[j] == str[i])
            j++;

        int groupLen = j - i;

        if (groupLen >= 4)
        {
            // замість будь-якої кількості >=4 записуємо "**"
            tmp[t++] = '*';
            tmp[t++] = '*';
        }
        else
        {
            // копіюємо оригінальні символи
            for (int k = 0; k < groupLen; k++)
                tmp[t++] = str[i];
        }

        i = j;
    }

    tmp[t] = '\0';
    strcpy(str, tmp);
}
