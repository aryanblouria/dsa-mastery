#include<stdio.h>
#include<stdlib.h>

int max(int arr[], int n)
{
    int m = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > m)
            m = arr[i];
    }
    return m;
}

void countsort(int arr[], int n)
{
    int m = 0;
    int *c;

    m = max(arr, n);
    c = (int*)malloc(sizeof(int)*(m+1))  ;

    for (int i = 0; i < m +1; i++)
        c[i] = 0;

    for (int i = 0; i < n; i++)
        c[arr[i]]++;

    int i = 0, j = 0;
    while (j < m + 1)
    {
        if (c[j] > 0)
        {
            arr[i++] = j;
            c[j]--;
        }
        else
            j++;
    }
}

int main()
{
    int arr[] = {5, 1, 2, 9, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    countsort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
