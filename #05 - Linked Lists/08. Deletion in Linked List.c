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

struct Node* del(struct Node *p, int index)
{
    struct Node* q = (struct Node*)malloc(sizeof(struct Node));
    struct Node* prev = (struct Node*)malloc(sizeof(struct Node));

    if (index == 0)
    {
        q = p->next;
        p->next = NULL;
        first = q;
    }
    else if (index < get_length(first))
    {
        prev = first;
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
    display(first);
    del(first, 3);
    display(first);
}

