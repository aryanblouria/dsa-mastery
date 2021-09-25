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

void sorted_duplicate(struct Array arr)
{
    for (int i = 0; i < arr.length-1; i++)
    {
        if (arr.A[i+1] == arr.A[i])
        {
            printf("%d is duplicate.\n", arr.A[i]);
            while (arr.A[i+1] == arr.A[i])
                i++;
        }
    }
}

void unsorted_duplicate(struct Array arr)
{
    for (int i = 0; i < arr.length-1; i++)
    {
        int count = 1;
        for (int j = i+1; j < arr.length; j++)
        {
            if (arr.A[j] == arr.A[i])
                count++;
        }
        if (count > 1)
            printf("%d is duplicate.\n", arr.A[i]);
    }
}

void hash_duplicate(struct Array arr)
{
    struct Array arr2;\
    int temp = 0;
    arr2.A = (int*)malloc(max(arr)*sizeof(int));
    arr2.size = max(arr);
    arr2.length = max(arr);

    for (int i = 0; i < arr2.length; i++)
        arr2.A[i] = 0;

    for (int i = 0; i < arr.length; i++)
    {
        temp = arr.A[i] - 1;
        if (arr2.A[temp] == 0)
            arr2.A[temp] = 1;
        else if (arr2.A[temp] == 1)
        {
            printf("%d is duplicate.\n", arr.A[i]);
            arr2.A[temp]++;
        }
    }
}

int main()
{
    struct Array arr;
    int n, choice;

    printf("Press 1 for Sorted Array: \n");
    printf("Press 2 for Unsorted Array: \n");
    printf("Press 3 for Hash Method: \n");
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
            sorted_duplicate(arr);
            break;
        case 2:
            unsorted_duplicate(arr);
            break;
        case 3:
            hash_duplicate(arr);
            break;
    }
}

