#include<stdio.h>

struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
};

struct Node* root = NULL;

void insert(int key)
{
    struct Node *t = root;
    struct Node *r, *p;

    if (root == NULL)
    {
        p = (struct Node*)malloc(sizeof(struct Node));
        p->data = key;
        p->left = p->right = NULL;
        root = p;
        return;
    }

    while (t != NULL)
    {
        r = t;
        if (key < t->data)
            t = t->left;
        else if (key > t->data)
            t = t->right;
        else
            return;
    }

    p = (struct Node*)malloc(sizeof(struct Node));
    p->data = key;
    p->left = p->right = NULL;

    if (key < r->data)
        r->left = p;
    else
        r->right = p;
}

void inorder(struct Node* p)
{
    if (p)
    {
        inorder(p->left);
        printf("(%d) ", p->data);
        inorder(p->right);
    }
}

struct Node* search(int key)
{
    struct Node* t = root;
    while (t != NULL)
    {
        if (key == t->data)
            return t;
        else if (key < t->data)
            t = t->left;
        else
            t = t->right;
    }
    return NULL;
}

int main()
{
    struct Node* temp = NULL;

    insert(5);
    insert(3);
    insert(7);
    insert(1);
    insert(9);

    inorder(root);

    int n = 6;
    temp = search(n);
    if (temp != NULL)
        printf("\n%d was found", temp->data);
    else
        printf("\n%d was not found", n);

    return 0;
}
