#include<stdio.h>

int factorial_recursion(int n)
{
    if(n==0)
       return 1;
    else
       return n * factorial_recursion(n - 1);
}

int main()
{
    int factorial = factorial_recursion(5);
    printf("%d", factorial);
    return 0;
}


