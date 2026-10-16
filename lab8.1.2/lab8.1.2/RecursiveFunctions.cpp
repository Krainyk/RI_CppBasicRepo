#include "RecursiveFunctions.h"
#define _CRT_SECURE_NO_WARNINGS
#include <string>
using namespace std;

int CountRec(char* str, int i, int count, int k)
{
    if (str[i] == '\0')
        return k;

    if (str[i] == str[i - 1])
    {
        int newCount = count + 1;

        if (newCount == 4)
            k++;

        return CountRec(str, i + 1, newCount, k);
    }
    else
    {
        return CountRec(str, i + 1, 1, k);
    }
}

void ChangeRecHelper(char* str, char* out, int i, int& pos)
{
    if (str[i] == '\0')
    {
        out[pos] = '\0';
        return;
    }
    int j = i + 1;
    while (str[j] != '\0' && str[j] == str[i])
        j++;

    int groupLen = j - i;

    if (groupLen >= 4)
    {
        int groups = groupLen / 4;

        for (int g = 0; g < groups; g++)
        {
            out[pos++] = '*';
            out[pos++] = '*';
        }

        int rem = groupLen % 4;
        for (int r = 0; r < rem; r++)
            out[pos++] = str[i];

        ChangeRecHelper(str, out, j, pos);
    }
    else
    {
        for (int r = 0; r < groupLen; r++)
            out[pos++] = str[i];
        ChangeRecHelper(str, out, j, pos);
    }
}

char* ChangeRec(char* str)
{
    size_t len = strlen(str);
    char* out = new char[len * 2 + 1];
    int pos = 0;

    ChangeRecHelper(str, out, 0, pos);
    out[pos] = '\0';

    strcpy(str, out);
    return out;
}