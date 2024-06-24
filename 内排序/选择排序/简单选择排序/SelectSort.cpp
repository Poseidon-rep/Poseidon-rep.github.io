#include <iostream>
#include <malloc.h>
#include <stdlib.h>
using namespace std;

#define MaxSize 50

typedef int KeyType;

typedef char InfoType;

typedef struct
{
    KeyType key;
    InfoType data;
} RecType;

void SelectSort(RecType R[], int n)
{
    int i, j, k;
    RecType tmp;
    for (i = 0; i < n - 1; ++i)
    {
        k = i;
        for (j = i + 1; j < n; ++j)
        {
            if (R[j].key < R[k].key)
            {
                k = j;
            }
        }
        if (k != i)
        {
            tmp = R[i];
            R[i] = R[k];
            R[k] = tmp;
        }
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
    SelectSort(R, 10);
    for (int i = 0; i < 10; ++i)
    {
        cout << R[i].key << " ";
    }
    cout << endl;
    system("pause");

    return 0;
}