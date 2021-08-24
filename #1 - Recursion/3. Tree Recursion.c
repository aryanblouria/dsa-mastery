#include<stdio.h>

void tree_recursion(int n)
{
    if(n>0)
    {
        printf("%d", n);
        tree_recursion(n-1);
        tree_recursion(n-1);
    }
}

int main()
{
    tree_recursion(3);
    return 0;
}

