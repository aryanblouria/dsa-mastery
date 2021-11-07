#include<stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create(int arr[], int n)
{
    struct Node *temp, *last;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = arr[0];
    head->next = head;
    last = head;

    for (int i = 1; i < n; i++)
    {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = arr[i];
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

void display(struct Node *p)
{
    do
    {
        printf("%d->", p->data);
        p = p->next;
    }
    while (p != head);
    printf("NULL\n");
}

void insert(struct Node* p, int index, int value)
{
    struct Node* q = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = (struct Node*)malloc(sizeof(struct Node));
    q->data = value;

    while (p->next != head)
        p = p->next;
    last = p;
    p = head;

    if (index == 0)
    {
        last->next = q;
        q->next = head;
        head = q;
    }
    else if (index > 0)
    {
        for (int i = 0; i < index-1; i++)
            p = p->next;
        q->next = p->next;
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
    display(head);
    insert(head, 5, 6);
    insert(head, 0, 0);
    display(head);
}

