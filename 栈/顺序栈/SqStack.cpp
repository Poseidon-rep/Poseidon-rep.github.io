#include <iostream>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

#define MaxSize 50

typedef char ElemType;

typedef struct
{
    ElemType data[MaxSize];
    int top;
} SqStack;

void CreateStack(SqStack *&s, ElemType a[], int n)
{
    s = (SqStack *)malloc(sizeof(SqStack));
    s->top = -1;
    for (int i = 0; i < n; ++i)
    {
        s->top++;
        s->data[s->top] = a[i];
    }
}

void InitStack(SqStack *&s)
{
    s = (SqStack *)malloc(sizeof(SqStack));
    s->top = -1;
}

void DestroyStack(SqStack *&s)
{
    free(s);
}

bool StackEmpty(SqStack *s)
{
    return s->top == -1;
}

void DispStack(SqStack *s)
{
    int i = 0;
    while (i <= s->top)
    {
        cout << s->data[i];
        ++i;
    }
    cout << endl;
}

bool Push(SqStack *&s, ElemType e)
{
    if (s->top == MaxSize - 1)
    {
        return false;
    }
    s->top++;
    s->data[s->top] = e;
    return true;
}

bool Pop(SqStack *&s, ElemType &e)
{
    if (s->top == -1)
    {
        return false;
    }
    e = s->data[s->top];
    s->top--;
    return true;
}

bool GetTop(SqStack *s, ElemType &e)
{
    if (s->top == -1)
    {
        return false;
    }
    e = s->data[s->top];
    return true;
}

// 利用顺序栈判断一个字符串是否是对称串。所谓对称串是指从左向右读和从右向左读的序列相同
bool symmetry(ElemType str[])
{
    int i;
    ElemType e;
    SqStack *s;
    InitStack(s);
    for (i = 0; str[i] != '\0'; ++i)
    {
        Push(s, str[i]);
    }
    for (i = 0; str[i] != '\0'; ++i)
    {
        Pop(s, e);
        if (str[i] != e)
        {
            DestroyStack(s);
            return false;
        }
    }
    DestroyStack(s);
    return true;
}

// 利用栈将一个正十进制整数转换为二进制数并输出
void transform(int n)
{
    SqStack *s;
    InitStack(s);
    ElemType e;
    while (n > 0)
    {
        Push(s, n % 2);
        n = n / 2;
    }
    while (!StackEmpty(s))
    {
        Pop(s, e);
        cout << e;
    }
    cout << endl;
    DestroyStack(s);
}

// 输入序列是1、2、…、n。判断a[0..n-1]（为1、2、…、n的某个排列）是不是出栈序列
bool validseq(ElemType a[], int n)
{
    SqStack *s;
    InitStack(s);
    bool flag;
    ElemType e;
    int i, k = 0;
    for (i = 1; i <= n; ++i)
    {
        Push(s, i);
        while (!StackEmpty(s))
        {
            GetTop(s, e);
            if (e == a[k])
            {
                Pop(s, e);
                k++;
            }
            else
            {
                break;
            }
        }
    }
    flag = StackEmpty(s);
    DestroyStack(s);
    return flag;
}

int main()
{
    ElemType e;
    SqStack *st;
    InitStack(st);
    cout << "栈st为空：" << StackEmpty(st) << endl;
    Push(st, 'a');
    Push(st, 'b');
    Push(st, 'c');
    cout << "栈st为空：" << StackEmpty(st) << endl;
    cout << "出栈顺序：";
    while (!StackEmpty(st))
    {
        Pop(st, e);
        cout << e;
    }
    cout << endl;
    DestroyStack(st);
    system("pause");

    return 0;
}