#include <iostream>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

#define NULLKEY -1

typedef int KeyType;

typedef struct
{
    KeyType key;
    int count;
} HashTable;

void InsertHT(HashTable ha[], int &n, int m, int p, KeyType k)
{
    int adr, cnt;
    adr = k % p;
    if (ha[adr].key == NULLKEY)
    {
        ha[adr].key = k;
        ha[adr].count = 1;
    }
    else
    {
        cnt = 1;
        do
        {
            adr = (adr + 1) % m;
            cnt++;
        } while (ha[adr].key != NULLKEY);
        ha[adr].key = k;
        ha[adr].count = cnt;
    }
    n++;
}

void CreateHT(HashTable ha[], int &n, int m, int p, KeyType keys[], int total)
{
    for (int i = 0; i < m; ++i)
    {
        ha[i].key = NULLKEY;
        ha[i].count = 0;
    }
    n = 0;
    for (int i = 0; i < total; ++i)
    {
        InsertHT(ha, n, m, p, keys[i]);
    }
}

void DispHT(HashTable ha[], int m)
{
    for (int i = 0; i < m; ++i)
    {
        cout << "ha[" << i << "}：" << ha[i].key << "\t" << ha[i].count << endl;
    }
}

int main()
{
    HashTable ha[13];
    KeyType keys[11] = {16, 74, 60, 43, 54, 90, 46, 31, 29, 88, 77};
    int m = 13, n, p = 13;
    CreateHT(ha, n, m, p, keys, 11);
    DispHT(ha, m);
    system("pause");

    return 0;
}
