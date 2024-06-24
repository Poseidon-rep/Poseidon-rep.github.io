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

void shellSort(RecType R[], int n)
{
    int i, j, d;
    RecType tmp;
    d = n / 2;
    while (d > 0)
    {
        for (i = d; i < n; i++)
        {
            tmp = R[i];
            j = i - d;
            while (j >= 0 && R[j].key > tmp.key)
            {
                R[j + d] = R[j];
                j = j - d;
            }
            R[j + d] = tmp;
        }
        d = d / 2;
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
    shellSort(R, 10);
    for (int i = 0; i < 10; ++i)
    {
        cout << R[i].key << " ";
    }
    cout << endl;
    system("pause");

    return 0;
}