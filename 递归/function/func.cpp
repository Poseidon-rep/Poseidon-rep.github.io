#include <iostream>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

void func(int a[], int n, int k)
{
    int i;
    if (k == n - 1)
    {
        for (i = 0; i < n; ++i)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    else
    {
        for (i = k; i < n; ++i)
        {
            a[i] = a[i] + i * i;
        }
        func(a, n, k + 1);
    }
}

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    func(a, 5, 0);
    system("pause");

    return 0;
}