#include <iostream>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

#define MaxSize 50

typedef int ElemType;

typedef struct
{
    ElemType data[MaxSize];
    int front, rear;
} CQueue;

void InitQueue(CQueue *&q)
{
    q = (CQueue *)malloc(sizeof(CQueue));
    q->front = q->rear = 0;
}

void DestroyQueue(CQueue *&q)
{
    free(q);
}

bool QueueEmpty(CQueue *q)
{
    return q->front == q->rear;
}

bool enQueue(CQueue *&q, ElemType e)
{
    if (q->front == (q->rear + 1) % MaxSize)
    {
        return false;
    }
    q->rear = (q->rear + 1) % MaxSize;
    q->data[q->rear] = e;
    return true;
}

bool deQueue(CQueue *&q, ElemType &e)
{
    if (q->front == q->rear)
    {
        return false;
    }
    q->front = (q->front + 1) % MaxSize;
    e = q->data[q->front];
    return true;
}

void number(int n)
{
    int i;
    ElemType e;
    CQueue *q;
    InitQueue(q);
    for (int i = 1; i <= n; ++i)
    {
        enQueue(q, i);
    }
    cout << "报数出列顺序：";
    while (!QueueEmpty(q))
    {
        deQueue(q, e);
        cout << e << "\t";
        if (!QueueEmpty(q))
        {
            deQueue(q, e);
            enQueue(q, e);
        }
    }
    cout << endl;
    DestroyQueue(q);
}

int main()
{
    int n;
    cout << "请输入队列人数：";
    cin >> n;
    cout << "初始序列为：";
    for (int i = 1; i <= n; ++i)
    {
        cout << i << "\t";
    }
    cout << endl;
    number(n);
    system("pause");

    return 0;
}