#include<stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *first = NULL;

void create(int arr[], int n)
{
    struct Node *temp, *last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = arr[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void display(struct Node *p)
{
    while (p != 0)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int sum(struct Node *p)
{
    int s = 0;
    while (p != 0)
    {
        s += p->data;
        p = p->next;
    }
    return s;
}

int sum_recursion(struct Node *p)
{
    if (p != 0)
        return p->data + sum_recursion(p->next);
    else
        return 0;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    create(arr, 5);
    display(first);
    printf("Sum of elements: %d\n", sum(first));
    printf("Sum of elements using Recursion: %d\n", sum_recursion(first));
}


