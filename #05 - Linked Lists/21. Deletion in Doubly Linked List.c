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

void del(struct Node *p, int index)
{
    if (index == 0)
    {
        first = first->next;
        first->prev = NULL;
    }
    else if (index < get_length(first))
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
    display(first);
    del(first, 3);
    del(first, 0);
    display(first);
}
