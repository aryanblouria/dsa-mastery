#include<stdio.h>

int nested_recursion(int n)
{
    if(n>100)
        return n - 10;
    else
        return nested_recursion(nested_recursion(n + 11));
}

int main()
{
    int r;
    r = nested_recursion(95);
    printf("%d", r);
    return 0;
}

