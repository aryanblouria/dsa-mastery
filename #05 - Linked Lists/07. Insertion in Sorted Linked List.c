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

struct Node* insert_sorted(struct Node* p, int value)
{
    struct Node* q = (struct Node*)malloc(sizeof(struct Node));
    struct Node* prev = (struct Node*)malloc(sizeof(struct Node));
    q->data = value;

    prev = first;
    p = prev->next;

    while (p != 0)
    {
        if (p->data < value)
        {
            if (p->next == 0)
            {
                append(first, value);
                return;
            }
            p = p->next;
            prev = prev->next;
        }
        else
        {
            prev->next = q;
            q->next = p;
            return q;
        }
    }
}

int main()
{
    int arr[] = {1, 5, 6, 8, 9};
    create(arr, 5);
    display(first);
    insert_sorted(first, 7);
    display(first);
}


