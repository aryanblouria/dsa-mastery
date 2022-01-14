#include<stdio.h>

void merge(int arr[], int l, int m, int h)
{
    int i = l, j = m+1, k = l;
    int temp[100];

    while (i <= m && j <= h)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    for (; i <= m; i++)
        temp[k++] = arr[i];
    for (; j <= h; j++)
        temp[k++] = arr[j];

    for (int i = l; i <= h; i++)
        arr[i] = temp[i];
}

void iterative_mergesort(int arr[], int n)
{
    int p, l, h, m, i;

    for (p = 2; p <= n; p = p*2)
    {
        for (i = 0; i+p-1 <= n; i = i+p)
        {
            l = i;
            h = i+p-1;
            m = (l+h)/2;
            merge(arr, l, m, h);
        }
    }

    if (p/2 < n)
        merge(arr, 0, p/2 - 1, n-1);
}

int main()
{
    int arr[] = {5, 1, 2, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    iterative_mergesort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}



