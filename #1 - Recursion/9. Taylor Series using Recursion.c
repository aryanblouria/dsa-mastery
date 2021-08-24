#include<stdio.h>

int factorial_recursion(int n)
{
    if (n==0)
        return 1;
    else
        return n * factorial_recursion(n-1);
}

int power_recursion(int m, int n)
{
    if (m == 0)
        return 0;
    else if (n==0)
        return 1;
    else if (n==1)
        return m;
    else if (n%2==0)
        return power_recursion(m*m, n/2);
    else
        return m*power_recursion(m*m, (n-1)/2);
}

double taylor_recursion(int x, int n)
{
    if (n==1)
        return 1.0;
    else
        return taylor_recursion(x, n-1) + (double)power_recursion(x, n-1)/factorial_recursion(n-1);
}

int main()
{
    double t = taylor_recursion(1, 3);
    printf("%f", t);

    return 0;
}
