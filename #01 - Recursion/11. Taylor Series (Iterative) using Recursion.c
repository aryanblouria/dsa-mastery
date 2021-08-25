#include<stdio.h>

double taylor_recursion(int x, int n)
{
    double s = 1;
    int i;
    double num = 1;
    double den = 1;

    for(i=1;i<=n;i++)
    {
        num *= x;
        den *= i;
        s += num/den;
    }
    return s;
}

int main()
{
    double r = taylor_recursion(1, 2);
    printf("%f", r);
}
