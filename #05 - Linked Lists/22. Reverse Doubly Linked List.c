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

void swap(struct Node* a, struct Node* b)
{
    struct Node *temp = a;
    a = b;
    b = temp;
}

void reverse(struct Node *p)
{
    while (p != 0)
    {
        struct Node* temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;

        if (p != 0 && p->next == NULL)
            first = p;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    create(arr, 5);
    display(first);
    reverse(first);
    display(first);
}


