#include <iostream>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

#define MaxSize 50

typedef int ElemType;

typedef struct
{
    ElemType data[MaxSize];
    int front;
    int count;
} QuType;

void InitQueue(QuType *&qu)
{
    qu = (QuType *)malloc(sizeof(QuType));
    qu->front = 0;
    qu->count = 0;
}

bool enQueue(QuType *&qu, ElemType e)
{
    int rear;
    if (qu->count == MaxSize)
    {
        return false;
    }
    else
    {
        rear = (qu->front + qu->count) % MaxSize;
        rear = (rear + 1) % MaxSize;
        qu->data[rear] = e;
        qu->count++;
        return true;
    }
}

bool deQueue(QuType *&qu, ElemType &e)
{
    if (qu->count == 0)
    {
        return false;
    }
    else
    {
        qu->front = (qu->front + 1) % MaxSize;
        e = qu->data[qu->front];
        qu->count--;
        return true;
    }
}

bool QueueEmpty(QuType *&qu)
{
    return qu->count == 0;
}

int main()
{
    system("pause");

    return 0;
}