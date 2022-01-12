#include<stdio.h>

void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int partition(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l, j = h;

    do
    {
        do {i++;} while (arr[i] <= pivot);
        do {j--;} while (arr[j] > pivot);
        if (i < j) swap(&arr[i], &arr[j]);
    } while (i < j);

    swap(&arr[l], &arr[j]);
    return j;
}

void quicksort(int arr[], int l, int h)
{
    int j;

    if (l < h)
    {
        j = partition(arr, l, h);
        quicksort(arr, l, j);
        quicksort(arr, j+1, h);
    }
}

int main()
{
    int arr[] = {5, 1, 2, 9, 7, 65535};
    int n = sizeof(arr)/sizeof(arr[0]);

    quicksort(arr, 0, 5);

    for (int i = 0; i < n-1; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}


