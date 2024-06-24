#include <iostream>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

typedef int KeyType;

typedef struct
{
    KeyType k;
} RecType;

int QuickSort(RecType r[], int s, int t, KeyType k)
{
    int i = s;
    int j = t;
    while (i < j)
    {
        while (i < j && r[j].k > k)
        {
            j--;
        }
        if (r[j].k == k)
        {
            return j + 1;
        }
        else
        {
            j--;
        }
        while (i < j && r[i].k < k)
        {
            i++;
        }
        if (r[i].k == k)
        {
            return i + 1;
        }
        else
        {
            i++;
        }
    }
    return 0;
}

int main()
{
    KeyType keys[10] = {2, 1, 3, 6, 9, 8, 4, 5, 7, 0};
    RecType r[10];
    KeyType k = 6;
    for (int i = 0; i < 10; ++i)
    {
        r[i].k = keys[i];
    }
    int s = 0, t = 9;
    int index = QuickSort(r, s, t, k);
    if (index == 0)
    {
        cout << "not find" << endl;
    }
    else
    {
        cout << "关键字" << k << "的下标为：" << index << endl;
    }
    system("pause");

    return 0;
}