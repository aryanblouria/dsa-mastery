#include<stdio.h>

struct Node
{
    struct Node* prev;
    int data;
    struct Node* next;
};

struct Node *first = NULL;

void create(int arr[], int n)
{
    struct Node *temp, *last;
    first = (struct Node*)malloc(sizeof(struct Node));

    first->prev = NULL;
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->prev = last;
        temp->data = arr[i];
        temp->next = last->next;
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

    q->data = value;
    if (index == 0)
    {
        q->prev = NULL;
        q->next = first;
        first->prev = q;
        first = q;
    }
    else if (index > 0 && index <= get_length(first))
    {
        for (int i = 0; i < index-1 && p != 0; i++)
            p = p->next;
        q->next = p->next;
        q->prev = p;
        if (p->next != 0)
            p->next->prev = q;
        p->next = q;
    }
    else
        printf("Insert failed. Please enter valid index.\n");
    return q;
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    create(arr, 5);
    display(first);
    insert(first, 5, 6);
    insert(first, 0, 0);
    display(first);
}

