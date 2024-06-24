#include <iostream>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

#define MaxSize 50

typedef struct
{
    char data[MaxSize];
    int length;
} SqString;

void StrAssign(SqString &s, char cstr[])
{
    int i;
    for (i = 0; cstr[i] != '\0'; i++)
    {
        s.data[i] = cstr[i];
    }
    s.length = i;
}

void GetNext(SqString t, int next[])
{
    int j, k;
    j = 0, k = -1;
    next[0] = -1;
    while (j < t.length - 1)
    {
        if (k == -1 || t.data[k] == t.data[j])
        {
            k++;
            j++;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
}

int main()
{
    system("pause");

    return 0;
}