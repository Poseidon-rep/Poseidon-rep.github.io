#include <iostream>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

#define MaxSize 50

typedef int ElemType;

typedef struct
{
    ElemType data[MaxSize];
    int top1, top2;
} ShareStack;