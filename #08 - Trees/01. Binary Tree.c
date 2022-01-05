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

void preorder(struct Node *p)
{
    if (p)
    {
        printf("(%d) ", p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

void inorder(struct Node *p)
{
    if (p)
    {
        inorder(p->left);
        printf("(%d) ", p->data);
        inorder(p->right);
    }
}

void postorder(struct Node *p)
{
    if (p)
    {
        postorder(p->left);
        postorder(p->right);
        printf("(%d) ", p->data);
    }
}

int main()
{
    create_tree();
    printf("\nPreorder Traversal: \n");
    preorder(root);
    printf("\nInorder Traversal: \n");
    inorder(root);
    printf("\nPostorder Traversal: \n");
    postorder(root);

    return 0;
}
