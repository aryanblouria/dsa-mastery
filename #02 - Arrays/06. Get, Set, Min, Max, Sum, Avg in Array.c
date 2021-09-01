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

int get(struct Array arr, int index)
{
    if (index>=0 && index<arr.length)
        return arr.A[index];
}

void set(struct Array *arr, int index, int value)
{
    if (index>=0 && index<arr->length)
        arr->A[index] = value;
}

int max(struct Array arr)
{
    int m = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > m)
            m = arr.A[i];
    }
    return m;
}

int min(struct Array arr)
{
    int m = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < m)
            m = arr.A[i];
    }
    return m;
}

int sum(struct Array arr)
{
    int s = 0;
    for (int i = 0; i < arr.length; i++)
        s+=arr.A[i];
    return s;
}

double avg(struct Array arr)
{
    double s = 0;
    for (int i = 0; i < arr.length; i++)
        s+=arr.A[i];
    return s/arr.length;
}

int main()
{
    struct Array arr;
    int n = 0;

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
    printf("%d\n", get(arr, 1));
    set(&arr, 2, 5);
    display(arr);
    printf("%d\n", max(arr));
    printf("%d\n", min(arr));
    printf("%d\n", sum(arr));
    printf("%.2f\n", avg(arr));
}


