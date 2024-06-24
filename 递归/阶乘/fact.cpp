#include <iostream>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

int fact(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * fact(n - 1);
    }
}

int main()
{
    cout <<fact(5)<<endl;
    system("pause");

    return 0;
}