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

int get_length(struct Node *p)
{
    int length = 0;
    while (p != 0)
    {
        length++;
        p = p->next;
    }
    return length;
}

struct Node* insert(struct Node* p, int index, int value)
{
    struct Node* q = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = (struct Node*)malloc(sizeof(struct Node));

    p = first;
    for (int i = 0; i < get_length(first); i++)
        p = p->next;
    last = p;

    q->data = value;
    if (index == 0)
    {
        q->next = first;
        first = q;
    }
    else if (index > 0 && index <= get_length(first))
    {
        p = first;
        for (int i = 0; i < index-1 && p != 0; i++)
            p = p->next;
        q->next = p->next;
        p->next = q;
    }
    else
    {
        printf("Insert failed. Please enter valid index.\n");
    }
    return q;
};

struct Node* append(struct Node* p, int value)
{
    struct Node* last = (struct Node*)malloc(sizeof(struct Node));
    struct Node* q = (struct Node*)malloc(sizeof(struct Node));

    last = first;
    for (int i = 0; i < get_length(first) - 1; i++)
        last = last->next;

    q->data = value;
    q->next = NULL;
    last->next = q;
    last = q;
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    create(arr, 5);
    display(first);
    insert(first, 0, 0);
    insert(first, 6, 6);
    display(first);
    append(first, 7);
    display(first);
}


