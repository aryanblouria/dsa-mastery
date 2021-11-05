#include<stdio.h>
#include<stdbool.h>

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

struct Node* delete_duplicates(struct Node* p)
{
    struct Node* q = (struct Node*)malloc(sizeof(struct Node));
    q = p->next;

    while (q != 0)
    {
        if (p->data == q->data)
        {
            p->next = q->next;
            q = p->next;
        }
        else
        {
            p = q;
            q = q->next;
        }
    }
}

int main()
{
    int arr[] = {1, 2, 4, 4, 5};
    create(arr, 5);
    display(first);
    delete_duplicates(first);
    display(first);
}

