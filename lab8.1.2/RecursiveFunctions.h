#pragma once

int CountRec(char* str, int i = 1, int count = 1, int k = 0);

void ChangeRecHelper(char* str, char* out, int i, int& pos);

char* ChangeRec(char* str);