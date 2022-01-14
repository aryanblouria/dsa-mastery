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

void recursive_mergesort(int arr[], int l, int h)
{
    int m = 0;
    if (l < h)
    {
        m = (l+h)/2;
        recursive_mergesort(arr, l, m);
        recursive_mergesort(arr, m+1, h);
        merge(arr, l, m, h);
    }
}

int main()
{
    int arr[] = {5, 1, 2, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    recursive_mergesort(arr, 0, n-1);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
