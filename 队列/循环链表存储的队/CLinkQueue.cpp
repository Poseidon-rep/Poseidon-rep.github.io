#include <iostream>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

typedef int ElemType;

typedef struct lnode
{
    ElemType data;
    struct lnode *next;
} LinkNode;

void InitQueue(LinkNode *&rear)
{
    rear = NULL;
}

bool QueueEmpty(LinkNode *rear)
{
    return rear == NULL;
}

bool enQueue(LinkNode *&rear, ElemType e)
{
    LinkNode *p;
    p = (LinkNode *)malloc(sizeof(LinkNode));
    p->data = e;
    if (rear = NULL)
    {
        p->next = p;
        rear = p;
    }
    else
    {
        p->next = rear->next;
        rear->next = p;
        rear = p;
    }
    return true;
}

bool deQueue(LinkNode *&rear, ElemType &e)
{
    LinkNode *p;
    if (rear == NULL)
    {
        return false;
    }
    else if (rear->next = rear)
    {
        e = rear->data;
        free(rear);
        rear = NULL;
    }
    else
    {
        p = rear->next;
        e = p->data;
        rear->next = p->next;
        free(p);
    }
    return true;
}

int main()
{
    system("pause");

    return 0;
}