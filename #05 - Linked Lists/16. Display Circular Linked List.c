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

void recursive_display(struct Node *p)
{
    static int flag = 0;
    if (p != head || flag == 0)
    {
        flag = 1;
        printf("%d->", p->data);
        recursive_display(p->next);
    }
    flag = 0;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    create(arr, 5);
    display(head);
    recursive_display(head);
    printf("NULL\n");
}

