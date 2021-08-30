#include<stdio.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void display(struct Array arr)
{
    printf("The elements of the array are: ");
    for(int i = 0; i < arr.length; i++)
        printf("%d", arr.A[i]);
    printf("\n");
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int linear_search1(struct Array arr, int value)
{
    for(int i = 0; i < arr.length; i++)
        if (arr.A[i] == value)
        {
            return i;
        }
    return -1;
}

int linear_search2(struct Array *arr, int value)
{
    for(int i = 0; i < arr->length; i++)
        if (arr->A[i] == value)
        {
            swap(&arr->A[i], &arr->A[i-1]);
            return i - 1;
        }
    return -1;
}

int linear_search3(struct Array *arr, int value)
{
    for(int i = 0; i < arr->length; i++)
        if (arr->A[i] == value)
        {
            swap(&arr->A[i], &arr->A[0]);
            return 0;
        }
    return -1;
}

int main()
{
    struct Array arr;
    int n;

    printf("Enter array size: ");
    scanf("%d", &arr.size);

    arr.A = (int*)malloc(arr.size*sizeof(int));
    arr.length = 0;

    printf("Enter no. of elements: ");
    scanf("%d", &n);

    printf("Enter all elements: \n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr.A[i]);
    arr.length=n;

    printf("Found at index: %d\n", linear_search1(arr, 3));
    display(arr);

    printf("Found at index: %d\n", linear_search2(&arr, 3));
    display(arr);

    printf("Found at index: %d\n", linear_search3(&arr, 3));
    display(arr);
}
