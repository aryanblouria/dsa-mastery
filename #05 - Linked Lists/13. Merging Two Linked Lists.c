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

struct Node* merge(struct Node *p, struct Node *q)
{
    struct Node* first = NULL;
    struct Node* last = NULL;

    if (p->data < q->data)
    {
        first = p;
        last = p;

        p = p->next;
        last->next = NULL;
    }
    else
    {
        first = q;
        last = q;

        q = q->next;
        last->next = NULL;
    }

    while (p != 0 && q != 0)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;

            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;

            q = q->next;
            last->next = NULL;
        }
    }

    if (p != 0)
        last->next = p;
    else
        last->next = q;

    return first;
}

int main()
{
    int arr1[] = {1, 3, 5, 7, 9};
    create(arr1, 5, &first1);
    display(first1);

    int arr2[] = {2, 4, 6, 8, 10};
    create(arr2, 5, &first2);
    display(first2);

    display(merge(first1, first2));
}
