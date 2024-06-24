#include <iostream>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

#define MaxSize 50

typedef char ElemType;

typedef struct linknode
{
    ElemType data;
    struct linknode *next;
} LinkStNode;

void InitStack(LinkStNode *&s)
{
    s = (LinkStNode *)malloc(sizeof(LinkStNode));
    s->next = NULL;
}

void DestroyStack(LinkStNode *&s)
{
    LinkStNode *p = s, *q = s->next;
    while (q != NULL)
    {
        free(p);
        p = q;
        q = p->next;
    }
    free(q);
}

bool StackEmpty(LinkStNode *s)
{
    return s->next == NULL;
}

bool Push(LinkStNode *&s, ElemType e)
{
    LinkStNode *p;
    p = (LinkStNode *)malloc(sizeof(LinkStNode));
    p->data = e;
    p->next = s->next;
    s->next = p;
    return true;
}

bool Pop(LinkStNode *&s, ElemType &e)
{
    LinkStNode *p = s->next;
    if (p == NULL)
    {
        return false;
    }
    e = p->data;
    s->next = p->next;
    free(p);
    return true;
}

bool GetTop(LinkStNode *&s, ElemType &e)
{
    if (s->next == NULL)
    {
        return false;
    }
    e = s->next->data;
    return true;
}

// 判断输入的表达式中括号是否配对（假设只含有左、右圆括号）
bool Match(ElemType exp[], int n)
{
    LinkStNode *s;
    InitStack(s);
    int i = 0;
    ElemType e;
    bool match = true;
    while (i < n && match)
    {
        if (exp[i] == '(')
        {
            Push(s, exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (!StackEmpty(s))
            {
                Pop(s, e);
            }
            else
            {
                match = false;
            }
        }
        i++;
    }
    if (!StackEmpty(s))
    {
        match = false;
    }
    DestroyStack(s);
    return match;
}

int main()
{
    ElemType exp[MaxSize] = "(()))";
    cout << Match(exp, 5) << endl;
    system("pause");

    return 0;
}