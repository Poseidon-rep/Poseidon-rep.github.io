#include <iostream>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

#define MaxSize 50

typedef int ElemType;

typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;

void CreateList(SqList *&l, ElemType a[], int n)
{
    int i = 0, k = 0;
    l = (SqList *)malloc(sizeof(SqList));
    while (i < n)
    {
        l->data[k] = a[i];
        i++;
        k++;
    }
    l->length = k;
}

void InitList(SqList *&l)
{
    l = (SqList *)malloc(sizeof(SqList));
    l->length = 0;
}

void DestroyList(SqList *&l)
{
    free(l);
}

bool ListEmpty(SqList *l)
{
    return l->length == 0;
}

int ListLength(SqList *l)
{
    return l->length;
}

void DispList(SqList *l)
{
    if (ListEmpty(l))
    {
        return;
    }
    for (int i = 0; i < l->length; ++i)
    {
        cout << l->data[i];
    }
    cout << endl;
}

bool GetElem(SqList *l, int i, ElemType &e)
{
    if (i < 1 || i > l->length)
    {
        return false;
    }
    e = l->data[i + 1];
    return true;
}

int LocateElem(SqList *l, ElemType e)
{
    int i = 0;
    while (i < l->length && l->data[i] != e)
    {
        i++;
    }
    if (i >= l->length)
    {
        return 0;
    }
    else
    {
        return i + 1;
    }
}

bool ListInsert(SqList *&l, int i, ElemType e)
{
    if (i < 1 || i > l->length + 1)
    {
        return false;
    }
    i--;
    for (int j = l->length; j > i; --j)
    {
        l->data[j] = l->data[j - 1];
    }
    l->data[i] = e;
    l->length++;
    return true;
}

bool ListDestroy(SqList *&l, int i, ElemType &e)
{
    if (i < 1 || i > l->length)
    {
        return false;
    }
    i--;
    e = l->data[i];
    for (int j = i; j < l->length - 1; ++j)
    {
        l->data[j] = l->data[j + 1];
    }
    l->length--;
    return true;
}

void unionList(SqList *LA, SqList *LB, SqList *&LC)
{
    InitList(LC);
    ElemType e;
    for (int i = 0; i < LA->length; ++i)
    {
        LC->data[i] = LA->data[i];
    }
    LC->length = LA->length;
    int lena = LC->length;
    for (int i = 1; i <= LB->length; ++i)
    {
        if (!LocateElem(LC, LB->data[i]))
        {
            GetElem(LB, i, e);
            ListInsert(LC, lena, e);
            lena++;
        }
    }
}

// 删除顺序表中所有值等于x的元素
// 整体建表法
void delnode1(SqList *&l, ElemType x)
{
    int k = 0;
    for (int i = 0; i < l->length; ++i)
    {
        if (l->data[i] != x)
        {
            l->data[k] = l->data[i];
            k++;
        }
    }
    l->length = k;
}
// 元素移动法
void delnode2(SqList *&l, ElemType x)
{
    int i = 0, k = 0;
    while (i < l->length)
    {
        if (l->data[i] == x)
        {
            k++;
        }
        else
        {
            l->data[i - k] = l->data[i];
        }
        i++;
    }
    l->length -= k;
}
// 区间划分法
void delnode3(SqList *&l, ElemType x)
{
    int i = -1, j = 0;
    ElemType t;
    while (j < l->length)
    {
        if (l->data[j] != x)
        {
            i++;
            t = l->data[i];
            l->data[i] = l->data[j];
            l->data[j] = t;
        }
        j++;
    }
    l->length = i + 1;
}

// 以第一个元素为分界线（基准），将所有小于或等于它的元素移动到该基准的前面，将所有大于它的元素移动到该基准的后面
// 元素交换法
void move1(SqList *&l)
{
    int i = 0, j = l->length - 1;
    ElemType base = l->data[0], t;
    while (i < j)
    {
        while (i < j && l->data[j] > base)
        {
            j--;
        }
        while (i < j && l->data[i] <= base)
        {
            i++;
        }
        if (i < j)
        {
            t = l->data[j];
            l->data[j] = l->data[i];
            l->data[i] = t;
        }
    }
    l->data[0] = l->data[i];
    l->data[i] = base;
}
// 前后移动法
void move2(SqList *&l)
{
    int i = 0, j = l->length - 1;
    ElemType base = l->data[0];
    while (i < j)
    {
        while (i < j && l->data[j] > base)
        {
            j--;
        }
        l->data[i] = l->data[j];
        while (i < j && l->data[i] <= base)
        {
            i++;
        }
        l->data[j] = l->data[i];
    }
    l->data[i] = base;
}

// 将所有奇数移动到偶数的前面
// 元素交换法
void move_1(SqList *&l)
{
    int i = 0, j = l->length - 1;
    ElemType t;
    while (i < j)
    {
        while (i < j && (l->data[j] % 2 == 0))
        {
            j--;
        }
        while (i < j && (l->data[i] % 2 == 1))
        {
            i++;
        }
        if (i < j)
        {
            t = l->data[i];
            l->data[i] = l->data[j];
            l->data[j] = t;
        }
    }
}
// 区间划分法
void move_2(SqList *&l)
{
    int i = -1;
    ElemType t;
    for (int j = 0; j < l->length; ++j)
        if (l->data[j] % 2 == 1)
        {
            i++;
            t = l->data[i];
            l->data[i] = l->data[j];
            l->data[j] = t;
        }
}

int main()
{
    ElemType arr[MaxSize] = {4, 1, 3, 7, 6, 8, 5};
    SqList *l;
    CreateList(l, arr, 7);
    DispList(l);
    move1(l);
    DispList(l);
    move_1(l);
    DispList(l);
    system("pause");

    return 0;
}