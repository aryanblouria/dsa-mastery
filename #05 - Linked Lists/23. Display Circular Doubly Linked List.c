#include<stdio.h>

struct Node
{
    struct Node* prev;
    int data;
    struct Node* next;
};

struct Node *head = NULL;

void create(int arr[], int n)
{
    struct Node *temp, *last;
    head = (struct Node*)malloc(sizeof(struct Node));

    head->prev = NULL;
    head->data = arr[0];
    head->next = head;
    last = head;

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
    do
    {
        printf("%d->", p->data);
        p = p->next;
    }
    while (p != head);
    printf("NULL\n");
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    create(arr, 5);
    display(head);
}

