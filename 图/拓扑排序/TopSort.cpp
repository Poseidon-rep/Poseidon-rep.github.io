#include <iostream>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

#define INF 32767

#define MAXV 50

typedef struct
{
    int data[MAXV];
    int top;
} SqStack;

void InitStack(SqStack *&s)
{
    s = (SqStack *)malloc(sizeof(SqStack));
    s->top = -1;
}

bool StackEmpty(SqStack *s)
{
    return s->top == -1;
}

bool Push(SqStack *&s, int e)
{
    if (s->top == MAXV - 1)
    {
        return false;
    }
    s->top++;
    s->data[s->top] = e;
    return true;
}

bool Pop(SqStack *&s, int &e)
{
    if (s->top == -1)
    {
        return false;
    }
    e = s->data[s->top];
    s->top--;
    return true;
}

typedef char InfoType;

typedef struct ANode
{
    int adjvex;
    struct ANode *nextarc;
    int weight;
} ArcNode;

typedef struct VNode
{
    InfoType info;
    ANode *firstarc;
} VNode;

typedef struct
{
    VNode adjlist[MAXV];
    int n, e;
} AdjGraph;

void CreateAdj(AdjGraph *&G, int A[MAXV][MAXV], int n, int e)
{
    G = (AdjGraph *)malloc(sizeof(AdjGraph));
    ArcNode *p;
    for (int i = 0; i < n; ++i)
    {
        G->adjlist[i].firstarc = NULL;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = n - 1; j >= 0; --j)
        {
            if (A[i][j] != 0 && A[i][j] != INF)
            {
                p = (ArcNode *)malloc(sizeof(ArcNode));
                p->adjvex = j;
                p->weight = A[i][j];
                p->nextarc = G->adjlist[i].firstarc;
                G->adjlist[i].firstarc = p;
            }
        }
    }
    G->n = n;
    G->e = e;
}

void TopSort(AdjGraph *G)
{
    SqStack *S;
    InitStack(S);  // 栈S初始化
    int count = 0; // 累加器count初始化
    int indegree[MAXV];
    for (int i = 0; i < G->n; ++i)
    {
        indegree[i] = 0;
    }
    for (int i = 0; i < G->n; ++i)
    {
        ArcNode *p = G->adjlist[i].firstarc;
        while (p != NULL)
        {
            int w = p->adjvex;
            indegree[w]++;
            p = p->nextarc;
        }
    }
    for (int i = 0; i < G->n; ++i)
    {
        if (indegree[i] == 0)
        {
            Push(S, i); // 扫描顶点表，将没有前驱（即入度为0）的顶点压栈
        }
    }
    int v;
    while (!StackEmpty(S)) // 当栈S非空时循环
    {
        Pop(S, v); // v=退出栈顶元素
        cout << v; // 输出v
        count++;   // 累加器加1
        ArcNode *p = G->adjlist[v].firstarc;
        while (p != NULL)
        {
            int w = p->adjvex;
            indegree[w]--; // 将顶点vj的各个邻接点的入度减1
            if (indegree[w] == 0)
            {
                Push(S, w); // 将新的入度为0的顶点入栈
            }
            p = p->nextarc;
        }
    }
    cout << endl;
    if (count < G->n)
    {
        cout << "图中有回路";
    }
    else
    {
        cout << "图中无回路";
    }
    cout << endl;
}

int main()
{
    int A[MAXV][MAXV] = {
        {0, 1, INF, INF, INF, INF},
        {INF, 0, 1, INF, INF, INF},
        {INF, INF, 0, 1, INF, INF},
        {INF, INF, INF, 0, INF, INF},
        {INF, 1, INF, INF, 0, 1},
        {INF, INF, INF, 1, INF, 0},
    };
    AdjGraph *G;
    CreateAdj(G, A, 6, 6);
    TopSort(G);
    system("pause");

    return 0;
}