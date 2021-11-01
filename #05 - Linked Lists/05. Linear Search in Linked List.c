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

struct Node* linear_search(struct Node *p, int value)
{
    while (p != 0)
    {
        if (p->data == value)
            return p;
        p = p->next;
    }
    return 0;
}

struct Node* linear_search_recursion(struct Node *p, int value)
{
    if (p->data == value)
        return p;
    return linear_search_recursion(p->next, value);
};

struct Node* linear_search2(struct Node *p, int value)
{
    struct Node* q = NULL;
    while (p != 0)
    {
        if (p->data == value)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return 0;
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    create(arr, 5);
    display(first);
    display(linear_search(first, 3));
    display(linear_search_recursion(first, 3));
    display(linear_search2(first, 3));
}


