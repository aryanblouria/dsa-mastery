#include<stdio.h>

int factorial_recursion(int n)
{
    if(n<=1)
        return n;
    else
        return n * factorial_recursion(n-1);
}

int ncr_recursion1(int n, int r)
{
    if (n < r)
        return -1;
    else if (n==r || r==0)
        return 1;
    else
        return ((double)n/(n-r)) * ncr_recursion1(n-1, r);
}

int ncr_recursion2(int n, int r)
{
    if (n<r)
        return -1;
    else if (n==r || r==0)
        return 1;
    else
        return ncr_recursion2(n-1, r-1) + ncr_recursion2(n-1, r);
}

int ncr(int n, int r)
{
    return factorial_recursion(n)/(factorial_recursion(r) * factorial_recursion(n-r));
}

int main()
{
    int n = 10, r = 3;
    int op1 = ncr_recursion1(n, r);
    int op2 = ncr_recursion2(n, r);
    int op3 = ncr(n, r);

    printf("%d\n", op1);
    printf("%d\n", op2);
    printf("%d\n", op3);
}
