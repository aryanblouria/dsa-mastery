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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse1(struct Array *arr)
{
    int* temp = (int*) malloc (sizeof(int) * arr->length);
    for (int i = 0; i < arr->length; i++)
    {
        temp[i] = arr->A[arr->length - i - 1];
    }

    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i] = temp[i];
    }
}

void reverse2(struct Array *arr)
{
    for (int i = 0, j = arr->length-1; i < j; i++, j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}

void lshift(struct Array *arr)
{
    for (int i = 0; i < arr->length-1; i++)
        arr->A[i] = arr->A[i+1];
    arr->A[arr->length-1] = 0;
}

void rshift(struct Array *arr)
{
    for (int i = arr->length-1; i > 0; i--)
        arr->A[i] = arr->A[i-1];
    arr->A[0] = 0;
}

void lrotate(struct Array *arr)
{
    int temp = arr->A[0];
    for (int i = 0; i < arr->length-1; i++)
        arr->A[i] = arr->A[i+1];
    arr->A[arr->length-1] = temp;
}

void rrotate(struct Array *arr)
{
    int temp = arr->A[arr->length-1];
    for (int i = arr->length-1; i > 0; i--)
        arr->A[i] = arr->A[i-1];
    arr->A[0] = temp;
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

    display(arr);
    reverse1(&arr);
    display(arr);
    reverse2(&arr);
    display(arr);
    lshift(&arr);
    display(arr);
    rshift(&arr);
    display(arr);
    lrotate(&arr);
    display(arr);
    rrotate(&arr);
    display(arr);
}

