#include<stdio.h>

void head(int n)
{
    if(n>0)
    {
        head(n-1);
        printf("%d", n);
    }
}

void tail(int n)
{
    if(n>0)
    {
        printf("%d", n);
        tail(n-1);
    }
}

int main()
{
    int x=3;

    head(x);
    tail(x);

    return 0;
}
