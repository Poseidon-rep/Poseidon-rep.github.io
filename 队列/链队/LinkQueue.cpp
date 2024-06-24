#include <iostream>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

typedef int ElemType;

typedef struct qnode
{
    ElemType data;
    struct qnode *next;
} DataNode;

typedef struct
{
    DataNode *front;
    DataNode *rear;
} LinkQuNode;

void InitQueue(LinkQuNode *&qu)
{
    qu = (LinkQuNode *)malloc(sizeof(LinkQuNode));
    qu->front = qu->rear = NULL;
}

void DestroyQueue(LinkQuNode *&qu)
{
    DataNode *pre = qu->front, *p;
    if (pre != NULL)
    {
        p = pre->next;
        while (p != NULL)
        {
            free(pre);
            pre = p;
            p = pre->next;
        }
    }
    free(pre);
    free(qu);
}

bool QueueEmpty(LinkQuNode *qu)
{
    return qu->rear == NULL;
}

bool enQueue(LinkQuNode *&qu, ElemType e)
{
    DataNode *p;
    p = (DataNode *)malloc(sizeof(DataNode));
    p->data = e;
    p->next = NULL;
    if (qu->rear == NULL)
    {
        qu->front = qu->rear = p;
    }
    else
    {
        qu->rear->next = p;
        qu->rear = p;
    }
    return true;
}

bool deQueue(LinkQuNode *&qu, ElemType &e)
{
    DataNode *p;
    if (qu->rear == NULL)
    {
        return false;
    }
    p = qu->front;
    e = p->data;
    if (qu->front == qu->rear)
    {
        qu->front = qu->rear = NULL;
    }
    else
    {
        qu->front = qu->front->next;
    }
    free(p);
    return true;
}

int main()
{
    LinkQuNode *qu;
    InitQueue(qu);
    DataNode *p;
    for (int i = 0; i < 5; ++i)
    {
        p = (DataNode *)malloc(sizeof(DataNode));
        p->data = i;
        p->next = qu->front;
        qu->front = p;
    }
    DestroyQueue(qu);
    cout << qu->front->data;
    system("pause");

    return 0;
}