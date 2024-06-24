#include <iostream>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

#define MaxSize 50

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LinkNode;

// 头插法建表
void CreateList1(LinkNode *&l, ElemType a[], int n)
{
    l = (LinkNode *)malloc(sizeof(LinkNode));
    l->next = NULL;
    LinkNode *s;
    for (int i = 0; i < n; ++i)
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i];
        s->next = l->next;
        l->next = s;
    }
}
// 尾插法建表
void CreateList2(LinkNode *l, ElemType a[], int n)
{
    l = (LinkNode *)malloc(sizeof(LinkNode));
    l->next = NULL;
    LinkNode *s, *t;
    t = l;
    for (int i = 0; i < n; ++i)
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i];
        t->next = s;
        t = s;
    }
    t->next = NULL;
}

void InitList(LinkNode *&l)
{
    l = (LinkNode *)malloc(sizeof(LinkNode));
    l->next = NULL;
}

void DestroyList(LinkNode *&l)
{
    LinkNode *pre, *p;
    pre = l;
    p = l->next;
    while (p != NULL)
    {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
}

bool ListEmpty(LinkNode *l)
{
    return l->next == NULL;
}

int ListLength(LinkNode *l)
{
    LinkNode *p = l;
    int n = 0;
    while (p->next != NULL)
    {
        n++;
        p = p->next;
    }
    return n;
}

void DispList(LinkNode *l)
{
    LinkNode *p = l->next;
    while (p != NULL)
    {
        cout << p->data;
        p = p->next;
    }
    cout << endl;
}

bool GetElem(LinkNode *l, int i, ElemType &e)
{
    int j = 0;
    LinkNode *p = l;
    if (i <= 0)
    {
        return false;
    }
    while (p != NULL && j < i)
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
    {
        return false;
    }
    else
    {
        e = p->data;
        return true;
    }
}

int LocateElem(LinkNode *l, ElemType e)
{
    LinkNode *p = l->next;
    int i = 1;
    while (p != NULL && p->data != e)
    {
        p = p->next;
        i++;
    }
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        return i;
    }
}

bool ListInsert(LinkNode *l, int i, ElemType e)
{
    LinkNode *p = l, *s;
    int j = 0;
    if (i <= 0)
    {
        return false;
    }
    while (p != NULL && j < i - 1)
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
    {
        return false;
    }
    else
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = e;
        s->next = p->next;
        p->next = s;
        return true;
    }
}

bool ListDelete(LinkNode *l, int i, ElemType &e)
{
    LinkNode *p = l, *q;
    int j = 0;
    if (i <= 0)
    {
        return false;
    }
    while (p != NULL && j < i - 1)
    {
        j++;
        p = p->next;
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
        free(q);
        return true;
    }
}

// 将所有结点逆置
// 头插法
void Reverse1(LinkNode *&l)
{
    LinkNode *p = l->next, *q;
    l->next = NULL;
    while (p != NULL)
    {
        q = p->next;
        p->next = l->next;
        l->next = p;
        p = q;
    }
}
// 修改指针域
void Reverse2(LinkNode *&l)
{
    LinkNode *p, *q, *r;
    q = l->next;
    r = q->next;
    q->next = NULL;
    while (r != NULL)
    {
        p = q;
        q = r;
        r = r->next;
        q->next = p;
    }
    l->next = q;
}

// 将单链表L=（a1，b1，a2，b2，…，an，bn）拆分成两个带头结点的单链表L1=（a1，a2，…，an），L2=（bn，bn-1，…，b1）
void split(LinkNode *&l, LinkNode *&l1, LinkNode *&l2)
{
    LinkNode *p, *q, *r;
    l1 = l;
    p = l->next;
    r = l1;
    l2 = (LinkNode *)malloc(sizeof(LinkNode));
    l2->next = NULL;
    while (p != NULL)
    {
        r->next = p;
        r = p;
        p = p->next;
        q = p->next;
        p->next = l2->next;
        l2->next = p;
        p = q;
    }
    r->next = NULL;
}

// 删除一个单链表L中元素值最大的结点（假设最大值结点是唯一的）
void delmaxnode(LinkNode *&l)
{
    LinkNode *pre, *p, *maxpre, *maxp;
    pre = l;
    p = l->next;
    maxpre = pre;
    maxp = p;
    while (p != NULL)
    {
        if (maxp->data < p->data)
        {
            maxpre = pre;
            maxp = p;
        }
        pre = p;
        p = p->next;
    }
    maxpre->next = maxp->next;
    free(maxp);
}

// 带头结点的单链表L（至少有一个数据结点），使其元素递增有序排列
// 直接插入法
void sort(LinkNode *&l)
{
    LinkNode *p, *pre, *q;
    p = l->next->next;
    l->next->next = NULL;
    while (p != NULL)
    {
        q = p->next;
        pre = l;
        while (pre->next != NULL && pre->next->data < p->data)
        {
            pre = pre->next;
        }
        p->next = pre->next;
        pre->next = p;
        p = q;
    }
}

int main()
{
    ElemType a[MaxSize] = {1, 3, 2, 7, 5, 6, 8, 4};
    LinkNode *l;
    CreateList1(l, a, 8);
    DispList(l);
    sort(l);
    DispList(l);
    system("pause");

    return 0;
}