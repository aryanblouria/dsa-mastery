#include<stdio.h>

int power_recursion(int m, int n)
{
    if(m == 0)
        return 0;
    else if (n == 0)
        return 1;
    else if (n == 1)
        return m;
    else if (n%2==0)
        return power_recursion(m * m, n/2);
    else
        return m * power_recursion(m * m, (n-1)/2);
}

int main()
{
    int output = power_recursion(7, 3);
    printf("%d", output);
    return 0;
}

