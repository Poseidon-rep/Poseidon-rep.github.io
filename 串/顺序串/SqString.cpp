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
    for (i = 0; cstr[i] != '\0'; ++i)
    {
        s.data[i] = cstr[i];
    }
    s.length = i;
}

SqString Concat(SqString s, SqString t)
{
    SqString str;
    int i;
    str.length = s.length + t.length;
    for (i = 0; s.data[i] != '\0'; ++i)
    {
        str.data[i] = s.data[i];
    }
    for (i = 0; t.data[i] != '\0'; ++i)
    {
        str.data[s.length + i] = t.data[i];
    }
    return str;
}

int Strcmp(SqString s, SqString t)
{
    int i, comlen;
    if (s.length < t.length)
    {
        comlen = s.length;
    }
    else
    {
        comlen = t.length;
    }
    for (int i = 0; i < comlen; ++i)
    {
        if (s.data[i] > t.data[i])
        {
            return 1;
        }
        else if (s.length < t.length)
        {
            return -1;
        }
    }
    if (s.length == t.length)
    {
        return 0;
    }
    else if (s.length > t.length)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int main()
{

    system("pause");

    return 0;
}