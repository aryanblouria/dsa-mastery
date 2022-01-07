#include<stdio.h>
#include "Queue.h"
#include "Stack.h"

struct Node* root = NULL;

void create_tree(int pre[], int n)
{
    struct Stack st;
    struct Node* t = NULL;
    struct Node* p = NULL;

    int i = 0;
    root = (struct Node*)malloc(sizeof(struct Node));
    root->data = pre[i++];
    root->left = root->right = NULL;

    p = root;
    while (i < n)
    {
        if (pre[i] < p->data)
        {
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data = pre[i++];
            t->left = t->right = NULL;
            p->left = t;
            push(&st, p);
            p = t;
        }
        else
        {
            if (pre[i] > p->data && pre[i] < st.top)
            {
                t = (struct Node*)malloc(sizeof(struct Node));
                t->left = t->right = NULL;
                p->right = t;
                p = t;
            }
            else
                p = pop(&st);
        }
    }
}

int main()
{
    int pre[5] = {5, 1, 9, 3, 7};
    create_tree(pre, 5);

    return 0;
}

