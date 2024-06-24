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

void Merge(RecType R[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    RecType *R1;
    R1 = (RecType *)malloc((high - low + 1) * sizeof(RecType));
    while (i <= mid && j <= high)
    {
        if (R[i].key <= R[j].key)
        {
            R1[k] = R[i];
            i++;
            k++;
        }
        else
        {
            R1[k] = R[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        R1[k] = R[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        R1[k] = R[j];
        j++;
        k++;
    }
    for (k = 0, i = low; i <= high; ++i, ++k)
    {
        R[low] = R1[k];
    }
    free(R1);
}

void MergePass(RecType R[], int length, int n)
{
    int i;
    for (i = 0; i + 2 * length - 1 < n; i = i + 2 * length)
    {
        MergeSort(R, i, i + length - 1, i + 2 * length - 1);
    }
    if (i + length - 1 < n - 1)
    {
        MergeSort(R, i, i + length - 1, n - 1);
    }
}

void MergeSort(RecType R[], int n)
{
    int length;
    for (length = 1; length < n; length = length * 2)
    {
        MergePass(R, length, n);
    }
}

void MergeDC(RecType R[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        MergeDC(R, low, mid);
        MergeDC(R, mid + 1, high);
        Merge(R, low, mid, high);
    }
}

void MergeSort1(RecType R[], int n)
{
    MergeDC(R, 0, n - 1);
}

int main()
{

    system("pause");

    return 0;
}