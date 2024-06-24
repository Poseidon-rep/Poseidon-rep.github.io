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

int index(SqString s, SqString t)
{
    for (int i = 0; i <= s.length - t.length; ++i)
    {
        for (int k = i, j = 0; k < s.length && j < t.length && s.data[k] == t.data[j]; ++k, ++j)
        {
            if (j == t.length)
            {
                return i;
            }
        }
    }
    return -1;
}

int BF(SqString s, SqString t)
{
    int i = 0, j = 0;
    while (i < s.length && j < t.length)
    {
        if (s.data[i] == t.data[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j >= t.length)
    {
        return i - t.length;
    }
    else
    {
        return -1;
    }
}

int StrCount1(SqString s, SqString t)
{
    int i = 0, j = 0, count = 0;
    while (i < s.length)
    {
        if (s.data[i] == t.data[j])
        {
            i++;
            j++;
            if (j == t.length)
            {
                count++;
                j = 0;
            }
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    return count;
}

int StrCount2(SqString s, SqString t)
{
    int i = 0, j, k, count = 0;
    while (i < s.length - t.length)
    {
        for (k = i, j = 0; k < s.length && j < t.length && s.data[k] == t.data[j]; ++k, ++j)
            ;
        if (j == t.length)
        {
            count++;
            i = k;
        }
        else
        {
            i++;
        }
    }
    return count;
}

int main()
{
    char cstr1[MaxSize] = "aabacabbaab";
    char cstr2[MaxSize] = "ab";
    SqString s, t;
    StrAssign(s, cstr1);
    StrAssign(t, cstr2);
    cout << StrCount2(s, t) << endl;
    ;
    system("pause");

    return 0;
}