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

void BubbleSort(RecType R[], int n)
{
    int i, j;
    RecType tmp;
    for (i = 0; i < n - 1; ++i)
    {
        for (j = n - 1; j > i; j--)
        {
            if (R[j].key < R[j - 1].key)
            {
                tmp = R[j];
                R[j] = R[j - 1];
                R[j - 1] = tmp;
            }
        }
    }
}

// 改进，减少比较和交换的次数
void BubbleSort1(RecType R[], int n)
{
    int i, j;
    RecType tmp;
    bool exchange;
    for (i = 0; i < n - 1; ++i)
    {
        exchange = false;
        for (j = n - 1; j > i; --j)
        {
            if (R[j].key < R[j - 1].key)
            {
                tmp = R[j];
                R[j] = R[j - 1];
                R[j - 1] = tmp;
                exchange = true;
            }
        }
        if (!exchange)
        {
            break;
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
    BubbleSort1(R, 10);
    for (int i = 0; i < 10; ++i)
    {
        cout << R[i].key << " ";
    }
    cout << endl;
    system("pause");

    return 0;
}