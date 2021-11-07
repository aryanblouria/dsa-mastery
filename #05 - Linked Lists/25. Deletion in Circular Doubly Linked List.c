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

void del(struct Node *p, int index)
{
    if (index == 0)
    {
        while (p->next != head)
            p = p->next;
        p->next = head->next;
        head->next->prev = p;
        head = head->next;
    }
    else if (index > 0)
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        p->prev->next = p->next;
        p->next->prev = p->prev;
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
