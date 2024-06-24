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
} CDLinkNode;

// 尾插法
void CreateList(CDLinkNode *&cdl, ElemType a[], int n)
{
    cdl = (CDLinkNode *)malloc(sizeof(CDLinkNode));
    cdl->prior = cdl->next = NULL;
    CDLinkNode *p = cdl, *q;
    for (int i = 0; i < n; i++)
    {
        q = (CDLinkNode *)malloc(sizeof(CDLinkNode));
        q->data = a[i];
        p->next = q;
        q->prior = p;
        p = q;
    }
    p->next = cdl;
    cdl->prior = p;
}

void DispList(CDLinkNode *cdl)
{
    CDLinkNode *p = cdl->next;
    while (p != cdl)
    {
        cout << p->data;
        p = p->next;
    }
    cout << endl;
}

// 一个带头结点的循环双链表L，删除第一个data域值为x的结点
bool delelem(CDLinkNode *&cdl, ElemType x)
{
    CDLinkNode *p = cdl->next;
    while (p != NULL && p->data != x)
    {
        p = p->next;
    }
    if (p != NULL)
    {
        p->prior->next = p->next;
        if (p->next != NULL)
        {
            p->next->prior = p->prior;
        }
        free(p);
        return true;
    }
    else
    {
        return false;
    }
}

// 判断带头结点的循环双链表（含两个以上的结点）是否对称(symmetry)相等
bool symmetry(CDLinkNode *cdl)
{
    bool same = true;
    CDLinkNode *p, *q;
    p = cdl->next;
    q = cdl->prior;
    while (same)
    {
        if (p->data != q->data)
        {
            same = false;
        }
        else
        {
            if (p == q || p == q->prior)
            {
                break;
            }
            p = p->next;
            q = q->prior;
        }
    }
    return same;
}

int main()
{
    CDLinkNode *cdl;
    ElemType a[MaxSize] = {1, 3, 2, 5, 5, 2, 3, 1};
    CreateList(cdl, a, 8);
    DispList(cdl);
    // delelem(cdl, 1);
    // DispList(cdl);
    cout << symmetry(cdl) << endl;
    system("pause");

    return 0;
}