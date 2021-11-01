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

int max(struct Node *p)
{
    int m = p->data;
    while (p != 0)
    {
        if (p->data > m)
            m = p->data;
        p = p->next;
    }
    return m;
}

int min(struct Node *p)
{
    int m = p->data;
    while (p != 0)
    {
        if (p->data < m)
            m = p->data;
        p = p->next;
    }
    return m;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    create(arr, 5);
    display(first);
    printf("Max of Linked List: %d\n", max(first));
    printf("Min of Linked List: %d\n", min(first));
}


