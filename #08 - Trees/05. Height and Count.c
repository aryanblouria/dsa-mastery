#include<stdio.h>
#include "Queue.h"

struct Node *root = NULL;

void create_tree()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);

    printf("Enter root value: ");
    scanf("%d", &x);

    root = (struct Node*)malloc(sizeof(struct Node));
    root->data = x;
    root->left = root->right = NULL;
    enqueue(&q, root);

    while(!isEmpty(q))
    {
        p = dequeue(&q);
        printf("Enter left child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data = x;
            t->left = t->right = NULL;
            p->left = t;
            enqueue(&q, t);
        }
        printf("Enter right child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data = x;
            t->left = t->right = NULL;
            p->right = t;
            enqueue(&q, t);
        }
    }
}

int count(struct Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = count(p->left);
        y = count(p->right);
        return x + y + 1;
    }
    return 0;
}

int height(struct Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = height(p->left);
        y = height(p->right);
        if (x > y)
            return x + 1;
        else
            return y + 1;
    }
    return 0;
}

int main()
{
    create_tree();
    printf("\nCount = %d", count(root));
    printf("\nHeight = %d", height(root));
    return 0;
}
