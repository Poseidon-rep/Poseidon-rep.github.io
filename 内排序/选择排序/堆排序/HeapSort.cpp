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

void sift(RecType R[], int low, int high)
{
    int i = low, j = 2 * i;
    RecType tmp = R[i];
    while (j <= high)
    {
        if (j < high && R[j].key < R[j + 1].key)
        {
            j++;
        }
        if (tmp.key < R[j].key)
        {
            R[i] = R[j];
            i = j;
            j = 2 * i;
        }
        else
        {
            break;
        }
    }
    R[i] = tmp;
}

void HeapSort(RecType R[], int n)
{
    int i;
    RecType tmp;
    for (i = n / 2; i >= 1; --i)
    {
        sift(R, i, n);
    }
    for (i = n; i >= 2; --i)
    {
        tmp = R[1];
        R[1] = R[i];
        R[i] = tmp;
        sift(R, 1, i - 1);
    }
}

int main()
{
    RecType R[MaxSize];
    for (int i = 1; i <= 10; ++i)
    {
        R[i].key = 11-i;
    }
    for (int i = 1; i <= 10; ++i)
    {
        cout << R[i].key << " ";
    }
    cout << endl;
    HeapSort(R, 10);
    for (int i = 1; i <= 10; ++i)
    {
        cout << R[i].key << " ";
    }
    cout << endl;
    system("pause");

    return 0;
}