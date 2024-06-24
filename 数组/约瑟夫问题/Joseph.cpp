#include <iostream>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

#define MaxSize 50

void Joseph(int n, int m)
{
    int p[MaxSize];
    for (int i = 1; i <= n; ++i)
    {
        p[i] = i;
    }
    int count = n, number;
    cout << "出列顺序为：";
    while (count != 0)
    {
        number = (number + m) % count;
        if (p[number] != 0)
        {
            p[number] = 0;
            cout << number;
            count--;
        }
        number = (number + 1) % count;
    }
    cout << endl;
}

int main()
{
    Joseph(8, 4);
    system("pause");

    return 0;
}