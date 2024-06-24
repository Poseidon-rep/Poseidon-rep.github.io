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

void InsertSort(RecType R[], int n)
{
    int i, j;
    RecType tmp;
    for (i = 1; i < n; ++i)
    {
        if (R[i].key < R[i - 1].key)
        {
            tmp = R[i];
            j = i - 1;
            do
            {
                R[j + 1] = R[j];
                j--;
            } while (j >= 0 && R[j].key > tmp.key);
            R[j + 1] = tmp;
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
    InsertSort(R, 10);
    for (int i = 0; i < 10; ++i)
    {
        cout << R[i].key << " ";
    }
    cout << endl;
    system("pause");

    return 0;
}