#include<stdio.h>

double taylor_recursion(int x, int n)
{
    static double p = 1;
    if(n==0)
        return p;
    else
        p=1+((double)x/n)*p;
        return taylor_recursion(x, n-1);
}

int main()
{
    double t;
    t = taylor_recursion(1, 2);
    printf("%f", t);
    return 0;
}
