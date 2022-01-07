#include<stdio.h>

struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
};

struct Node* root = NULL;

void inorder(struct Node* p)
{
    if (p)
    {
        inorder(p->left);
        printf("(%d) ", p->data);
        inorder(p->right);
    }
}

int height(struct Node* p)
{
    int x, y;
    if (p == NULL)
        return 0;
    x = height(p->left);
    y = height(p->right);
    return (x > y) ? (x + 1) : (y + 1);
}

struct Node* pre(struct Node *p)
{
    while (p && p->right != NULL)
        p = p->right;
    return p;
};

struct Node* suc(struct Node *p)
{
    while (p && p->left != NULL)
        p = p->left;
    return p;
};

struct Node *recursive_insert(struct Node *p, int key)
{
    struct Node* t = NULL;
    if (p == NULL)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = key;
        t->left = t->right = NULL;
        return t;
    }

    if (key < p->data)
        p->left = recursive_insert(p->left, key);
    else if (key > p->data)
        p->right = recursive_insert(p->right, key);

    return p;
}

struct Node *recursive_delete(struct Node *p, int key)
{
    struct Node* q = NULL;

    if (p == NULL)
        return NULL;
    if (p->left == NULL && p->right == NULL)
    {
        if (p == root)
            root = NULL;
        free(p);
        return NULL;
    }
    if (key < p->data)
        p->left = recursive_delete(p->left, key);
    else if (key > p->data)
        p->right = recursive_delete(p->right,key);
    else
    {
        if (height(p->left) > height(p->right))
        {
            q = pre(p->left);
            p->data = q->data;
            p->left = recursive_delete(p->left, q->data);
        }
        else
        {
            q = suc(p->right);
            p->data = q->data;
            p->right = recursive_delete(p->right, q->data);
        }
    }
    return p;
}

int main()
{
    struct Node* temp = NULL;

    root = recursive_insert(root, 5);
    recursive_insert(root, 3);
    recursive_insert(root, 7);
    recursive_insert(root, 1);
    recursive_insert(root, 9);

    inorder(root);

    recursive_delete(root, 7);
    recursive_delete(root, 3);

    inorder(root);

    return 0;
}
