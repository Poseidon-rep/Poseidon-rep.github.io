#include <iostream>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

#define MaxSize 50

typedef char ElemType;

typedef struct
{
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

void CreateQueue(SqQueue *&q, ElemType a[], int n)
{
    q = (SqQueue *)malloc(sizeof(SqQueue));
    q->front = q->rear = -1;
    for (int i = 0; i < n; ++i)
    {
        q->rear++;
        q->data[q->rear] = a[i];
    }
}

void InitQueue(SqQueue *&q)
{
    q = (SqQueue *)malloc(sizeof(SqQueue));
    q->front = q->rear = -1;
}

void DestroyQueue(SqQueue *&q)
{
    free(q);
}

bool QueueEmpty(SqQueue *q)
{
    return q->front == q->rear;
}

bool enQueue(SqQueue *&q, ElemType e)
{
    if (q->rear == MaxSize - 1)
    {
        return false;
    }
    q->rear++;
    q->data[q->rear] = e;
    return true;
}

bool deQueue(SqQueue *&q, ElemType &e)
{
    if (q->front == q->rear)
    {
        return false;
    }
    q->front++;
    e = q->data[q->front];
    return true;
}

void DispQueue(SqQueue *q)
{
    for (int i = q->front + 1; i <= q->rear; ++i)
    {
        cout << q->data[i];
    }
    cout << endl;
}

int main()
{
    ElemType a[MaxSize] = {1, 2, 3, 4, 5, 6};
    SqQueue *q;
    CreateQueue(q, a, 6);
    DispQueue(q);
    system("pause");

    return 0;
}