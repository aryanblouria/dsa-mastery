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

int find_middle1(struct Node* p, int mid)
{
    for (int i = 0; i < mid; i++)
        p = p->next;
    return p->data;
}

int find_middle2(struct Node* p)
{
    struct Node* q = first;
    while (q != 0)
    {
        q = q->next;
        if (q != 0)
            q = q->next;
        if (q != 0)
            p = p->next;
    }
    return p->data;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    create(arr, 5);
    display(first);

    int mid = get_length(first)/2;
    int middle1 = find_middle1(first, mid);
    int middle2 = find_middle2(first);

    printf("Middle Node 1: %d\n", middle1);
    printf("Middle Node 2: %d\n", middle2);
}

