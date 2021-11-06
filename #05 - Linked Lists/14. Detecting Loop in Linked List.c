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

void loop_detect(struct Node *p)
{
    struct Node *q = p;
    while (p != 0 && q != 0)
    {
        p = p->next;
        q = q->next;

        if (q != 0)
            q = q->next;
        else
            q = NULL;
    }

    if (p == q)
        printf("Loop detected.");
    else
        printf("No loop detected.");
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    create(arr, 5);
    display(first);
    loop_detect(first);
}


