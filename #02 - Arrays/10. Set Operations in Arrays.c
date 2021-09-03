#include<stdio.h>
#include<stdbool.h>

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

bool found(struct Array arr, int value)
{
    for (int i = 0; i < arr.length; i++)
        if (value == arr.A[i])
            return true;
    return false;
}

struct Array* unsorted_union(struct Array arr1, struct Array arr2)
{
    int k = 0;
    struct Array* arr3 = (struct Array *) malloc (sizeof(struct Array));

    for (int i = 0; i < arr1.length; i++)
        arr3->A[k++] = arr1.A[i];

    arr3->length = arr1.length;
    for (int j = 0; j < arr2.length; j++)
        if (!found(*arr3, arr2.A[j]))
            arr3->A[k++] = arr2.A[j];

    arr3->length = k;
    arr3->size = k;
    return arr3;
};

struct Array* sorted_union(struct Array arr1, struct Array arr2)
{
    int i = 0, j = 0, k = 0;
    struct Array *arr4 = (struct Array *) malloc (sizeof(struct Array));

    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
            arr4->A[k++] = arr1.A[i++];
        else if (arr2.A[j] < arr1.A[i])
            arr4->A[k++] = arr2.A[j++];
        else
        {
            arr4->A[k++] = arr1.A[i++];
            j++;
        }
    }

    for (; i < arr1.length; i++)
        arr4->A[k++] = arr1.A[i];
    for (; j < arr2.length; j++)
        arr4->A[k++] = arr2.A[j];

    arr4->length = k;
    arr4->size = arr1.size + arr2.size;

    return arr4;
}

struct Array* unsorted_intersection(struct Array arr1, struct Array arr2)
{
    int k = 0;
    struct Array *arr3 = (struct Array *) malloc (sizeof(struct Array));

    for (int i = 0; i < arr1.length; i++)
        if (found(arr2, arr1.A[i]))
            arr3->A[k++] = arr1.A[i];

    arr3->length = k;
    arr3->size = k;
    return arr3;
};

struct Array* sorted_intersection(struct Array arr1, struct Array arr2)
{

    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *) malloc (sizeof(struct Array));

    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
            i++;
        else if (arr2.A[j] < arr1.A[i])
            j++;
        else
        {
            arr3->A[k++] = arr1.A[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = k;

    return arr3;
};

struct Array* unsorted_difference(struct Array arr1, struct Array arr2)
{
    int k = 0;
    struct Array *arr3 = (struct Array *) malloc (sizeof(struct Array));

    for (int i = 0; i < arr1.length; i++)
        if (!found(arr2, arr1.A[i]))
            arr3->A[k++] = arr1.A[i];

    arr3->length = k;
    arr3->size = k;
    return arr3;
};

struct Array* sorted_difference(struct Array arr1, struct Array arr2)
{
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *) malloc (sizeof(struct Array));

    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
            arr3->A[k++] = arr1.A[i++];
        else if (arr2.A[j] < arr1.A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }

    for (; i < arr1.length; i++)
        arr3->A[k++] = arr1.A[i];
    arr3->length = k;
    arr3->size = k;

    return arr3;
};


int main()
{
    struct Array arr1, arr2;
    struct Array *arr3;
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

    arr3 = unsorted_union(arr1, arr2);
    display(*arr3);

    arr3 = sorted_union(arr1, arr2);
    display(*arr3);

    arr3 = unsorted_intersection(arr1, arr2);
    display(*arr3);

    arr3 = sorted_intersection(arr1, arr2);
    display(*arr3);

    arr3 = unsorted_difference(arr1, arr2);
    display(*arr3);

    arr3 = sorted_difference(arr1, arr2);
    display(*arr3);
}
