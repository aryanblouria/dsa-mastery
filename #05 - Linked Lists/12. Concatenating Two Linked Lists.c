#include<stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *first1, *first2 = NULL;

void create(int arr[], int n, struct Node** first)
{
    struct Node *temp, *last;
    *first = (struct Node*)malloc(sizeof(struct Node));

    (*first)->data = arr[0];
    (*first)->next = NULL;
    last = *first;

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

struct Node* concatenate(struct Node *p, struct Node *q)
{
    struct Node* first = p;

    while(p->next != 0)
        p = p->next;
    p->next = q;

    p = first;
    return p;
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    create(arr1, 5, &first1);
    display(first1);

    int arr2[] = {6, 7, 8, 9, 10};
    create(arr2, 5, &first2);
    display(first2);

    display(concatenate(first1, first2));
}


