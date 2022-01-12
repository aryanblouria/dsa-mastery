#include<stdio.h>

void insertionsort(int arr[], int n)
{
    int x = 0, j = 0;
    for (int i = 1; i < n; i++)
    {
        j = i - 1;
        x = arr[i];

        while (j > -1 && arr[j] > x)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = x;
    }
}

int main()
{
    int arr[] = {5, 2, 1, 9, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    insertionsort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

