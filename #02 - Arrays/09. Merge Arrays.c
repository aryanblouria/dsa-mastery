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

struct Array* merge(struct Array arr1, struct Array arr2)
{
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *) malloc (sizeof(struct Array));

    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
            arr3->A[k++] = arr1.A[i++];
        else
            arr3->A[k++] = arr2.A[j++];
    }

    for (; i < arr1.length; i++)
        arr3->A[k++] = arr1.A[i];
    for (; j < arr2.length; j++)
        arr3->A[k++] = arr2.A[j];

    arr3->length = arr1.length + arr2.length;
    arr3->size = arr1.size + arr2.size;

    return arr3;
}

int main()
{
    struct Array arr1, arr2, *arr3;
    int n, m;

    printf("Enter array1 size: ");
    scanf("%d", &arr1.size);

    arr1.A = (int*)malloc(arr1.size*sizeof(int));
    arr1.length = 0;

    printf("Enter no. of elements: ");
    scanf("%d", &n);

    printf("Enter all elements: \n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr1.A[i]);
    arr1.length=n;

    printf("Enter array2 size: ");
    scanf("%d", &arr2.size);

    arr2.A = (int*)malloc(arr2.size*sizeof(int));
    arr2.length = 0;

    printf("Enter no. of elements: ");
    scanf("%d", &m);

    printf("Enter all elements: \n");
    for(int i = 0; i < m; i++)
        scanf("%d", &arr2.A[i]);
    arr2.length=m;

    arr3 = merge(arr1, arr2);
    display(*arr3);
}
