#include<stdio.h>
#include "Queue.h"
#include "Stack.h"

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

void it_preorder(struct Node *p)
{
    struct Stack st;
    create_stack(&st, 100);

    while (p || !isStackEmpty(st))
    {
        if (p)
        {
            printf("(%d) ", p->data);
            push(&st, p);
            p = p->left;
        }
        else
        {
            p = pop(&st);
            p = p->right;
        }
    }
}

void it_inorder(struct Node *p)
{
    struct Stack st;
    create_stack(&st, 100);

    while (p || !isStackEmpty(st))
    {
        if (p)
        {
            push(&st, p);
            p = p->left;
        }
        else
        {
            p = pop(&st);
            printf("(%d) ", p->data);
            p = p->right;
        }
    }
}

void it_postorder(struct Node *p)
{
    struct Stack st;
    create_stack(&st, 100);
    long int temp = 0;

    while (p || !isStackEmpty(st))
    {
        if (p)
        {
            push(&st, p);
            p = p->left;
        }
        else
        {
            temp = pop(&st);
            if (temp > 0)
            {
                push(&st, -temp);
                p = ((struct Node*)temp)->right;
            }
            else
            {
                printf("(%d) ", ((struct Node*)-temp)->data);
                p = NULL;
            }
        }
    }
}

int main()
{
    create_tree();
    printf("\nPreorder Traversal: \n");
    it_preorder(root);
    printf("\nInorder Traversal: \n");
    it_inorder(root);
    printf("\nPostorder Traversal: \n");
    it_postorder(root);

    return 0;
}

