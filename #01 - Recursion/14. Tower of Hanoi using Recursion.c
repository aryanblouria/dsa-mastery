#include<stdio.h>

int tower_of_hanoi(int n, int a, int b, int c)
{
    if(n>0)
    {
        tower_of_hanoi(n-1, a, c, b);
        printf("Moving disc from %d to %d\n", a, c);
        tower_of_hanoi(n-1, b, a, c);
    }
}

int main()
{
    tower_of_hanoi(3, 1, 2, 3);
}
