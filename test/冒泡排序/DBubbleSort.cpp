#include <iostream>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

#define MaxSize 50

typedef int KeyType;

typedef struct dlnode
{
    KeyType k;
    struct dlnode *prior;
    struct dlnode *next;
} DLinkNode;

void CreateList(DLinkNode *&dl, KeyType a[], int n)
{
    dl = (DLinkNode *)malloc(sizeof(DLinkNode));
    dl->prior = dl->next = NULL;
    DLinkNode *p, *q;
    p = dl;
    for (int i = 0; i < n; ++i)
    {
        q = (DLinkNode *)malloc(sizeof(DLinkNode));
        q->k = a[i];
        p->next = q;
        q->prior = p;
        p = q;
    }
    p->next = NULL;
}

void DispList(DLinkNode *dl)
{
    DLinkNode *p = dl->next;
    while (p != NULL)
    {
        cout << p->k;
        p = p->next;
    }
    cout << endl;
}

void DBubblesort(DLinkNode *&dl, int n)
{
    KeyType k;
    DLinkNode *p = dl->next;
    bool exchange;
    for (int i = 0; i < n / 2; ++i)
    {
        exchange = false;
        while (p->next != NULL)
        {
            if (p->k > p->next->k)
            {
                k = p->k;
                p->k = p->next->k;
                p->next->k = k;
                exchange = true;
            }
            p = p->next;
        }
        if (!exchange)
        {
            return;
        }
        exchange = false;
        p = p->prior;
        while (p->prior != dl)
        {
            if (p->k < p->prior->k)
            {
                k = p->k;
                p->k = p->prior->k;
                p->prior->k = k;
                exchange = true;
            }
            p = p->prior;
        }
        if (!exchange)
        {
            return;
        }
        p = p->next;
    }
}

int main()
{
    KeyType a[MaxSize] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    DLinkNode *dl;
    CreateList(dl, a, 9);
    DispList(dl);
    DBubblesort(dl, 9);
    DispList(dl);

    system("pause");
    return 0;
}