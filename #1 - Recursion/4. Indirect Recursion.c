#include<stdio.h>
void B(int n);

void A(int n)
{
    if(n>0)
    {
        printf("%d", n);
        B(n-1);
    }
}

void B(int n)
{
    if(n>0)
    {
        printf("%d", n);
        A(n/2);
    }
}

int main()
{
    A(20);
    return 0;
}
