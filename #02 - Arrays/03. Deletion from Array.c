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

void del1(struct Array *arr, int index)
{
    for(int i = index; i < arr->length-1; i++)
    {
        arr->A[i] = arr->A[i+1];
    }
    arr->length--;
}

void del2(struct Array *arr, int value)
{
    int index = 0;
    for(int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == value)
            index = i;
    }
    for(int i = index; i < arr->length-1; i++)
    {
        arr->A[i] = arr->A[i+1];
    }
    arr->length--;
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

    del1(&arr, 2);
    del2(&arr, 1);
    display(arr);
}
