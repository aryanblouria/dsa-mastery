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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool check(struct Array arr)
{
    int i = 1;
    while (i!=arr.length)
    {
        if (arr.A[i] < arr.A[i-1])
            return false;
        i++;
    }
    return true;
}

void insert1(struct Array *arr, int value)
{
   for (int i = 0; i < arr->length; i++)
        if (arr->A[i] > value)
        {
            for (int j = arr->length-1; j >= i; j--)
                arr->A[j+1] = arr->A[j];
            arr->A[i] = value;
            arr->length++;
            return;
        }
   arr->A[arr->length++] = value;
}

void insert2(struct Array *arr, int value)
{
    int i = arr->length-1;
    while (arr->A[i] > value)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = value;
    arr->length++;
}

void negative_shift1(struct Array *arr)
{
    int index = 0;
    for (int i = 0; i < arr->length; i++)
        if (arr->A[index] > 0)
        {
            int temp = arr->A[index];
            for (int j = index; j < arr->length-1; j++)
                arr->A[j] = arr->A[j+1];
            arr->A[arr->length-1] = temp;
        }
        else
            index++;
}

void negative_shift2(struct Array *arr)
{
   int i = 0, j = arr->length-1;
   while(i < j)
   {
       while (arr->A[i] < 0)
            i++;
       while (arr->A[j] >= 0)
            j--;
       if (i < j)
           swap(&arr->A[i], &arr->A[j]);
   }
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
    insert1(&arr, 5);
    insert2(&arr, 5);
    display(arr);

    if (check(arr))
        printf("Sorted");
    else
        printf("Unsorted");

    negative_shift1(&arr);
    negative_shift2(&arr);
    display(arr);
}
