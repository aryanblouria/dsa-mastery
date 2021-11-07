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

struct Node* del(struct Node *p, int index)
{
    struct Node* q = (struct Node*)malloc(sizeof(struct Node));
    struct Node* prev = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = (struct Node*)malloc(sizeof(struct Node));

    if (index == 0)
    {
        while (p->next != head)
            p = p->next;
        last = p;
        last->next = head->next;
        head = head->next;
    }
    else if (index > 0)
    {
        prev = head;
        p = prev->next;
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
            prev = prev->next;
        }
        prev->next = p->next;
        p->next = NULL;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    create(arr, 5);
    display(head);
    del(head, 3);
    del(head, 0);
    display(head);
}

