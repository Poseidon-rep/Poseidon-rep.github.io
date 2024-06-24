#include <iostream>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

typedef struct snode
{
    char data;
    struct snode *next;
} LinkStrNode;

void StrAssign(LinkStrNode *&s, char cstr[])
{
    s = (LinkStrNode *)malloc(sizeof(LinkStrNode));
    LinkStrNode *r, *p;
    r = s;
    for (int i = 0; cstr[i] != '\0'; ++i)
    {
        p = (LinkStrNode *)malloc(sizeof(LinkStrNode));
        p->data = cstr[i];
        r->next = p;
        r = p;
    }
    r->next = NULL;
}

void DestroyStr(LinkStrNode *&s)
{
    LinkStrNode *pre, *p;
    pre = s;
    p = s->next;
    while (p != NULL)
    {
        free(pre);
        pre = p;
        p = pre->next;
    }
    free(pre);
}

LinkStrNode *Concat(LinkStrNode *s, LinkStrNode *t)
{
    LinkStrNode *str, *p, *q, *r;
    str = (LinkStrNode *)malloc(sizeof(LinkStrNode));
    p = s->next;
    r = str;
    while (p != NULL)
    {
        q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }
    p = t->next;
    while (p != NULL)
    {
        q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }
    r->next = NULL;
    return str;
}

void Repl(LinkStrNode *s)
{
    LinkStrNode *p, *q;
    p = s->next;
    int find = 0;
    while (p->next != NULL && find == 0)
    {
        if (p->data == 'a' && p->next->data == 'b')
        {
            p->data = 'x';
            p->next->data = 'z';
            q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
            q->data = 'y';
            q->next = p->next;
            p->next = q;
            find = 1;
        }
        else
        {
            p = p->next;
        }
    }
}

int main()
{

    system("pause");

    return 0;
}