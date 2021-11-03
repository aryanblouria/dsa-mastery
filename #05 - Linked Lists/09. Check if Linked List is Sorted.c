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

bool check_sorted(struct Node* p)
{
    while (p->next != 0)
    {
        int temp = p->data;
        p = p->next;

        if (temp > p->data)
            return false;
    }
    return true;
}


int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    create(arr, 5);
    display(first);

    if (check_sorted(first))
        printf("\nThe linked list is sorted.");
    else
        printf("\nThe linked list is not sorted.");
}
