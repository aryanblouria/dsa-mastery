#include<stdio.h>

int z = 0;

int static_recursive(int n)
{
    static int x = 0;
    if (n>0)
    {
        x++;
        return static_recursive(n-1) + x;
    }
    return 0;
}

int global_recursive(int n)
{
    if (n>0)
    {
        z++;
        return global_recursive(n-1) + z;
    }
    return 0;
}

int main()
{
    int r1, r2;

    r1 = static_recursive(5);
    r2 = global_recursive(5);

    printf("%d", r1);
    printf("%d", r2);

    return 0;
}
