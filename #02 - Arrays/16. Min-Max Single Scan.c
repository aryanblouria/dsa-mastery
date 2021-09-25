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

void min_max(struct Array arr)
{
    int min = arr.A[0];
    int max = arr.A[0];

    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
            min = arr.A[i];
        else if (arr.A[i] > max)
            max = arr.A[i];
    }
    printf("%d is the minimum and %d is the maximum", min, max);
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
    min_max(arr);
}
