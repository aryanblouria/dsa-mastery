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

void target_sum1(struct Array arr, int target)
{
    for (int i = 0; i < arr.length; i++)
    {
        for (int j = i+1; j < arr.length; j++)
        {
            if (arr.A[i] + arr.A[j] == target)
                printf("%d and %d add up to %d\n", arr.A[i], arr.A[j], target);
        }
    }
}

void target_sum2(struct Array arr, int target)
{
    struct Array arr2;
    int temp = 0;
    arr2.A = (int*)malloc(max(arr)*sizeof(int));
    arr2.size = max(arr)+1;
    arr2.length = max(arr)+1;

    for (int i = 0; i < arr2.length; i++)
        arr2.A[i] = 0;

    for (int i = 0; i < arr.length; i++)
    {
        temp = arr.A[i];
        if (arr2.A[temp] == 0)
        {
            arr2.A[temp] = 1;
            if (arr2.A[target-temp] == 1)
                printf("%d and %d add up to %d\n", temp, target-temp, target);
        }
    }
}

void target_sum_sorted(struct Array arr, int target)
{
    int l = 0, h = arr.length - 1, sum = 0;
    while (l < h)
    {
        sum = arr.A[l] + arr.A[h];
        if (sum < target)
            l++;
        else if (sum > target)
            h--;
        else
        {
            printf("%d and %d add up to to %d\n", arr.A[l], arr.A[h], target);
            l++;
            h--;
        }
    }
}

int main()
{
    struct Array arr;
    int n, target, choice;

    printf("Press 1 for Brute Force Method: \n");
    printf("Press 2 for Hash Method: \n");
    printf("Press 3 for Two Pointer Method: \n");
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

    printf("Enter target: ");
    scanf("%d", &target);

     switch(choice)
    {
        case 1:
            target_sum1(arr, target);
            break;
        case 2:
            target_sum2(arr, target);
            break;
        case 3:
            target_sum_sorted(arr, target);
            break;
    }
}
