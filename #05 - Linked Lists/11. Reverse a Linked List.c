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

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void elements_reverse(struct Node *p)
{
    int n = get_length(p);
    int* arr = (int*)malloc(n*sizeof(int));

    for (int i = 0; i < n; i++)
    {
        arr[i] = p->data;
        p = p->next;
    }

    p = first;
    for (int i = n - 1; i >= 0; i--)
    {
        p->data = arr[i];
        p = p->next;
    }
}

void links_reverse(struct Node *p)
{
    struct Node *q, *r = NULL;
    while (p != 0)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void recursive_reverse(struct Node* p, struct Node* q)
{
    if (p != 0)
    {
        recursive_reverse(p->next, p);
        p->next = q;
    }
    else
        first = q;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    create(arr, 5);
    display(first);
    elements_reverse(first);
    display(first);
    links_reverse(first);
    display(first);
    recursive_reverse(first, NULL);
    display(first);
}

