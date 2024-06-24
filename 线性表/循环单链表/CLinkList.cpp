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
} CLinkNode;

void CreateList(CLinkNode *&cl, ElemType a[], int n)
{
    cl = (CLinkNode *)malloc(sizeof(CLinkNode));
    cl->next = NULL;
    CLinkNode *p, *t = cl;

    for (int i = 0; i < n; ++i)
    {
        p = (CLinkNode *)malloc(sizeof(CLinkNode));
        p->data = a[i];
        t->next = p;
        t = p;
    }
    t->next = cl;
}

void DispList(CLinkNode *&cl)
{
    CLinkNode *p = cl->next;
    while (p != cl)
    {
        cout << p->data;
        p = p->next;
    }
    cout << endl;
}

// 一个带头结点的循环单链表L，统计其data域值为x的结点个数
int count(CLinkNode *cl, ElemType x)
{
    int cnt = 0;
    CLinkNode *p = cl->next;
    while (p != cl)
    {
        if (p->data == x)
        {
            cnt++;
        }
        p = p->next;
    }
    return cnt;
}

int main()
{
    ElemType a[MaxSize] = {2, 3, 2, 4, 5, 2, 2, 2};
    CLinkNode *cl;
    CreateList(cl, a, 8);
    DispList(cl);
    cout << count(cl, 2);
    cout << endl;
    system("pause");

    return 0;
}