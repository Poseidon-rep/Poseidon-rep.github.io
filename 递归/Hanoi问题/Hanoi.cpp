#include <iostream>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

void Hanoi(int n, char x, char y, char z)
{
    if (n == 1)
    {
        cout << x << "->" << z << endl;
    }
    else
    {
        Hanoi(n - 1, x, z, y);
        cout << x << "->" << z << endl;
        Hanoi(n - 1, y, x, z);
    }
}

int main()
{
    Hanoi(3, 'X', 'Y', 'Z');
    system("pause");

    return 0;
}