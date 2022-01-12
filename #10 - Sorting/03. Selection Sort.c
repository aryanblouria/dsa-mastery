#include<stdio.h>

void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void selectionnsort(int arr[], int n)
{
    int k = 0;
    for (int i = 0; i < n-1; i++)
    {
        k = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[k] > arr[j])
                k = j;
        }
        swap(&arr[i], &arr[k]);
    }
}

int main()
{
    int arr[] = {5, 1, 2, 9, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    selectionsort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

