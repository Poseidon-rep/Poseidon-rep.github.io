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

void BinInsertSort(RecType R[], int n)
{
    int i, j, low, high, mid;
    RecType tmp;
    for (i = 1; i < n; ++i)
    {
        if (R[i].key < R[i - 1].key)
        {
            low = 0;
            high = i - 1;

            tmp = R[i];
            while (low <= high)
            {
                mid = (low + high) / 2;
                if (tmp.key < R[mid].key)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            for (j = i - 1; j >= high + 1; --j)
            {
                R[j + 1] = R[j];
            }
            R[high + 1] = tmp;
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
    BinInsertSort(R, 10);
    for (int i = 0; i < 10; ++i)
    {
        cout << R[i].key << " ";
    }
    cout << endl;
    system("pause");

    return 0;
}