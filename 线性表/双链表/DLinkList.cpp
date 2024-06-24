#include <iostream>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

#define MaxSize 50

typedef int ElemType;

typedef struct DNode
{
    ElemType data;
    struct DNode *prior;
    struct DNode *next;
} DLinkNode;

void CreateList1(DLinkNode *&dl, ElemType a[], int n)
{
    DLinkNode *p;
    dl = (DLinkNode *)malloc(sizeof(DLinkNode));
    dl->prior = dl->next = NULL;
    for (int i = 0; i < n; ++i)
    {
        p = (DLinkNode *)malloc(sizeof(DLinkNode));
        p->data = a[i];
        p->next = dl->next;
        if (dl->next != NULL)
        {
            dl->next->prior = p;
        }
        p->prior = dl;
        dl->next = p;
    }
}

void CreateList2(DLinkNode *&dl, ElemType a[], int n)
{
    DLinkNode *p, *t;
    dl = (DLinkNode *)malloc(sizeof(DLinkNode));
    dl->prior = dl->next = NULL;
    p = dl;
    for (int i = 0; i < n; ++i)
    {
        t = (DLinkNode *)malloc(sizeof(DLinkNode));
        t->data = a[i];
        t->prior = p;
        p->next = t;
        p = t;
    }
    p->next = NULL;
}

void DispList(DLinkNode *dl)
{
    DLinkNode *p = dl->next;
    while (p != NULL)
    {
        cout << p->data;
        p = p->next;
    }
    cout << endl;
}

bool ListInsert1(DLinkNode *&dl, int i, ElemType e)
{
    DLinkNode *p, *t;
    p = dl;
    int j = 0;
    if (i <= 0)
    {
        return false;
    }
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    if (p == NULL)
    {
        return false;
    }
    t = (DLinkNode *)malloc(sizeof(DLinkNode));
    t->data = e;
    t->next = p->next;
    if (p->next != NULL)
    {
        p->next->prior = t;
    }
    t->prior = p;
    p->next = t;
    return true;
}

bool ListInsert2(DLinkNode *&dl, int i, ElemType e)
{
    DLinkNode *p = dl, *t;
    int j = 0;
    if (i <= 0)
    {
        return false;
    }
    while (p != NULL & j < i)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
    {
        return false;
    }
    t = (DLinkNode *)malloc(sizeof(DLinkNode));
    t->data = e;
    t->prior = p->prior;
    p->prior->next = t;
    p->prior = t;
    t->next = p;
    return true;
}

bool ListDelete1(DLinkNode *&dl, int i, ElemType &e)
{
    DLinkNode *p, *q;
    int j = 0;
    p = dl;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
    {
        return false;
    }
    else
    {
        q = p->next;
        if (q == NULL)
        {
            return false;
        }
        e = q->data;
        p->next = q->next;
        if (q->next != NULL)
        {
            q->next->prior = p;
        }
        free(q);
        return true;
    }
}

bool ListDelete(DLinkNode *&dl, int i, ElemType &e)
{
    DLinkNode *p, *q;
    q = dl;
    int j = 0;
    while (j < i && q != NULL)
    {
        q = q->next;
        j++;
    }
    if (q == NULL)
    {
        return false;
    }
    else
    {
        p = q->prior;
        e = q->data;
        p->prior->next = q;
        q->prior = p->prior;
        return true;
    }
}

// 一个带头结点的双链表L，将其所有元素逆置，即第1个元素变为最后一个元素，第2个元素变为倒数第2个元素，…，最后一个元素变为第1个元素
// 头插法建表
void reverse(DLinkNode *&dl)
{
    DLinkNode *p = dl->next, *q;
    dl->next = NULL;
    while (p != NULL)
    {
        q = p->next;
        p->next = dl->next;
        if (dl->next != NULL)
        {
            dl->next->prior = p;
        }
        p->prior = dl;
        dl->next = p;
        p = q;
    }
}

// 个带头结点的双链表L（至少有一个数据结点），使其元素递增有序排列
void sort(DLinkNode *&dl)
{
    DLinkNode *p = dl->next->next, *pre, *q;
    dl->next->next = NULL;
    while (p != NULL)
    {
        q = p->next;
        pre = dl;
        while (pre->next != NULL && pre->next->data < p->data)
        {
            pre = pre->next;
        }
        p->next = pre->next;
        if (pre->next != NULL)
        {
            pre->next->prior = p;
        }
        p->prior = pre;
        pre->next = p;
        p = q;
    }
}

int main()
{
    DLinkNode *dl;
    ElemType a[MaxSize] = {1, 3, 7, 5, 4, 6, 8, 2};
    CreateList2(dl, a, 8);
    DispList(dl);
    reverse(dl);
    DispList(dl);
    sort(dl);
    DispList(dl);
    system("pause");

    return 0;
}