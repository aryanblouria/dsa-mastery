#include<stdio.h>
#include<stdlib.h>

int fibonacci_recursion(int n)
{
    if(n==0)
        return 0;
    else if (n==1)
        return 1;
    else
        return fibonacci_recursion(n-1) + fibonacci_recursion(n-2);
}

int fibonacci_loop(int n)
{
    int first = 0;
    int second = 1;
    int sum = 0;

    for(int i = 0; i < n-1; i++)
    {
        sum = first + second;
        first = second;
        second = sum;
    }
    return sum;
}

int fibonacci_memoization(int n)
{
    int fib[n];
    for(int i = 0; i < n; i++)
        fib[i] = -1;

    if (n<=1)
    {
        fib[n] = n;
        return n;
    }
    else
    {
        if (fib[n-2] == -1)
            fib[n-2] = fibonacci_memoization(n-2);
        if (fib[n-1] == -1)
            fib[n-1] = fibonacci_memoization(n-1);
        return fib[n-2] + fib[n-1];
    }
}

int main()
{
    int n = 10;
    int f1 = fibonacci_recursion(n);
    int f2 = fibonacci_loop(n);
    int f3 = fibonacci_memoization(n);

    printf("%d\n", f1);
    printf("%d\n", f2);
    printf("%d\n", f3);
}
