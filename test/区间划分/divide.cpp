#include <iostream>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

#define MaxSize 50

typedef char KeyType;

typedef struct
{
    KeyType k;
} RecType;

// r--红色   w--白色    b--蓝色
void devide(RecType r[], int n)
{
    int i, j, k;
    i = -1;
    j = n;
    RecType t;
    while (r[k].k != '\0')
    {
        switch (r[k].k)
        {
        case 'r':
        {
            i++;
            t = r[k];
            r[k] = r[i];
            r[i] = t;
            k++;
            break;
        }
        case 'b':
        {
            if (k < j)
            {
                j--;
                t = r[k];
                r[k] = r[j];
                r[j] = t;
                break;
            }
        }
        default:
        {
            k++;
            break;
        }
        }
    }
}

int main()
{
    RecType r[MaxSize];
    cout << "输入砾石个数：";
    int n;
    cin >> n;
    cout << "输入砾石排列：";
    for (int i = 0; i < n; ++i)
    {
        cin >> r[i].k;
    }
    cout << "调整后的砾石排列为：";
    devide(r, n);
    for (int i = 0; i < n; ++i)
    {
        cout << r[i].k;
    }
    cout << endl;
    system("pause");

    return 0;
}