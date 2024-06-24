#include <iostream>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

#define MaxSize 50

typedef int KeyType;

typedef char InfoType;

typedef struct
{
    KeyType key;
    InfoType data;
} RecType;

int partition(RecType R[], int s, int t)
{
    int i = s, j = t;
    RecType base = R[i];
    while (i < j)
    {
        while (i < j && R[j].key >= base.key)
        {
            j--;
        }
        if (i < j)
        {
            R[i] = R[j];
        }
        while (i < j && R[i].key <= base.key)
        {
            i++;
        }
        if (i < j)
        {
            R[j] = R[i];
        }
    }
    R[i] = base;
    return i;
}

void QuickSort(RecType R[], int s, int t)
{
    int i;
    if (s < t)
    {
        i = partition(R, s, t);
        QuickSort(R, s, i - 1);
        QuickSort(R, i + 1, t);
    }
}

void QuickSort1(RecType R[], int s, int t)
{
    int i, base;
    RecType tmp;
    base = (s + t) / 2;
    if (s < t)
    {
        if (base != s)
        {
            R[base] = tmp;
            R[s] = R[base];
            R[base] = tmp;
        }
        i = partition(R, s, t);
        QuickSort(R, s, i - 1);
        QuickSort(R, i + 1, t);
    }
}

int main()
{
    RecType R[MaxSize];
    for (int i = 0; i < 10; ++i)
    {
        R[i].key = 10 - i;
    }
    for (int i = 0; i < 10; ++i)
    {
        cout << R[i].key << " ";
    }
    cout << endl;
    QuickSort(R, 0, 9);
    for (int i = 0; i < 10; ++i)
    {
        cout << R[i].key << " ";
    }
    cout << endl;
    system("pause");

    return 0;
}