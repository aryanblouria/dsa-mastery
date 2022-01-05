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

void levelorder(struct Node *p)
{
    struct Queue q;
    create(&q, 100);

    printf("(%d) ", p->data);
    enqueue(&q, p);

    while(!isEmpty(q))
    {
        p = dequeue(&q);
        if (p->left)
        {
            printf("(%d) ", root->left->data);
            enqueue(&q, root->left);
        }
        if (p->right)
        {
            printf("(%d) ", root->right->data);
            enqueue(&q, root->right);
        }
    }
}

int main()
{
    create_tree();
    printf("Level Order Traversal: \n");
    levelorder(root);
    return 0;
}

