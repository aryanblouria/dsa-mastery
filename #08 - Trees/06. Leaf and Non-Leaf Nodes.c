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

int leaf(struct Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = count(p->left);
        y = count(p->right);
        if (p->left == NULL && p->right == NULL)
            return x + y + 1;
        else
            return x + y;
    }
    return 0;
}

int nonleaf(struct Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = count(p->left);
        y = count(p->right);
        if (p->left != NULL || p->right != NULL)
            return x + y + 1;
        else
            return x + y;
    }
    return 0;
}

int deg2(struct Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = count(p->left);
        y = count(p->right);
        if (p->left != NULL && p->right != NULL)
            return x + y + 1;
        else
            return x + y;
    }
    return 0;
}

int deg1(struct Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = count(p->left);
        y = count(p->right);
        if ((p->left != NULL && p->right == NULL)||(p->left == NULL && p->right == NULL))
            return x + y + 1;
        else
            return x + y;
    }
    return 0;
}

int main()
{
    create_tree();
    printf("\nCount = %d", count(root));
    printf("\nLeaf Count = %d", leaf(root));
    printf("\nNon-Leaf Count = %d", nonleaf(root));
    printf("\nDegree Two Count = %d", deg2(root));
    printf("\nDegree One Count = %d", deg1(root));
    return 0;
}
