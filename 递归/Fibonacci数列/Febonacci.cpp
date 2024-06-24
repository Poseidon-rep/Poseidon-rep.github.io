#include <iostream>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

int Fib1(int n){
    if(n == 1 || n == 2){
        return 1;
    }
    else{
        return Fib1(n-1)+Fib1(n-2);
    }
}

int main(){
    cout <<Fib1(6)<<endl;
    system("pause");

    return 0;
}