#include<stdio.h>

void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void max_insert(int arr[], int n)
{
    int temp = arr[n], i = n;
    while (i > 1 && temp > arr[i/2])
    {
        arr[i] = arr[i/2];
        i = i/2;
    }
    arr[i] = temp;
}

void min_insert(int arr[], int n)
{
    int temp = arr[n], i = n;
    while (i > 1 && temp < arr[i/2])
    {
        arr[i] = arr[i/2];
        i = i/2;
    }
    arr[i] = temp;
}

int max_delete(int arr[], int n)
{
    int i = 0, j = 0;

    int z = arr[1];
    arr[1] = arr[n];
    arr[n] = z;
    i = 1; j = 2 * i;

    while (j <= n-1)
    {
        if (j< n-1 && arr[j+1] > arr[j])
            j = j+1;
        if (arr[i] < arr[j])
        {
            swap(&arr[i], &arr[j]);
            i = j;
            j = 2*j;
        }
        else
            break;
    }

    return z;
}

int min_delete(int arr[], int n)
{
    int i = 0, j = 0;

    int z = arr[1];
    arr[1] = arr[n];
    arr[n] = z;
    i = 1; j = 2 * i;

    while (j <= n-1)
    {
        if (arr[j++] < arr[j])
            j = j+1;
        if (arr[i] > arr[j])
        {
            swap(&arr[i], &arr[j]);
            i = j;
            j = 2*j;
        }
        else
            break;
    }

    return z;
}

void display(int arr[], int n)
{
    for (int i = 1; i <= n; i++)
        printf("(%d) ", arr[i]);
    printf("\n");
}

int main()
{
    int arr1[] = {0, 10, 20, 30, 25, 5, 40, 35};
    int arr2[] = {0, 10, 20, 30, 25, 5, 40, 35};

    for (int i = 2; i <= 7; i++)
        max_insert(arr1, i);

    for (int i = 2; i <= 7; i++)
        max_insert(arr2, i);

    display(arr1, 7);
    max_delete(arr1, 7);
    display(arr1, 6);
    max_delete(arr1, 6);
    display(arr1, 5);

    for (int i = 7; i > 1; i--)
        max_delete(arr2, i);

    for (int i = 1; i <= 7; i++)
        printf("(%d) ", arr2[i]);
    printf("\n");

    return 0;
}
