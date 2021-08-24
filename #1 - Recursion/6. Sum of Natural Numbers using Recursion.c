#include<stdio.h>

int sum_recursion(int n)
{
    if(n>0)
    {
       return sum_recursion(n-1) + n;
    }
}

int main()
{
    int sum = sum_recursion(10);
    printf("%d", sum);
    return 0;
}
