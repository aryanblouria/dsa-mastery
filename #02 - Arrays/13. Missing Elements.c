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


void find_missing_inc(struct Array arr)
{
    int diff = arr.A[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i]-i != diff)
        {
            while (diff < arr.A[i]- i)
            {
                printf("%d is missing.\n", i + diff);
                diff++;
            }
        }
    }
}

void find_missing_dec(struct Array arr)
{
    int sum = arr.A[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i]+i != sum)
        {
            while (arr.A[i] + i < sum)
            {
                printf("%d is missing.\n", sum - i);
                sum--;
            }
        }
    }
}

void missing_unsorted(struct Array arr)
{

    struct Array arr2;
    int temp = 0;
    arr2.A = (int*)malloc((max(arr)+1)*sizeof(int));
    arr2.size = max(arr)+1;
    arr2.length = max(arr)+1;

    for (int i = 0; i < arr.length; i++)
    {
        temp = arr.A[i];
        arr2.A[temp] = 1;
    }

    for (int i = 0; i < arr2.length; i++)
    {
        if (arr2.A[i] != 1 && i > min(arr))
            printf("%d is missing.\n", i);
    }
}

int main()
{
    struct Array arr;
    int n, choice;

    printf("Press 1 for Increasing Order Sorted Array: \n");
    printf("Press 2 for Decreasing Order Sorted Array: \n");
    printf("Press 3 for Unsorted Array: \n");
    printf("You choose: ");
    scanf("%d", &choice);

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

    switch(choice)
    {
        case 1:
            find_missing_inc(arr);
            break;
        case 2:
            find_missing_dec(arr);
            break;
        case 3:
            missing_unsorted(arr);
            break;
    }
}
