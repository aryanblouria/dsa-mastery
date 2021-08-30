#include<stdio.h>
#include<math.h>

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

int binary_search1(struct Array arr, int value)
{
    int l = 0, h = arr.length-1, mid = 0;
    while (l <= h)
    {
        mid = (l+h)/2;
        if (value == arr.A[mid])
            return mid;
        else if (value > arr.A[mid])
            l = mid + 1;
        else
            h = mid - 1;
    }
    return -1;
}

int binary_search2(struct Array arr, int value, int l, int h)
{
    if (l <= h)
    {
        int mid = (l+h)/2;
        if (value == arr.A[mid])
            return mid;
        else if (value > arr.A[mid])
            l = mid + 1;
        else
            h = mid - 1;
        return binary_search2(arr, value, l, h);
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

    display(arr);
    printf("%d\n", binary_search1(arr, 8));
    printf("%d\n", binary_search2(arr, 8, 0, arr.length-1));
}
