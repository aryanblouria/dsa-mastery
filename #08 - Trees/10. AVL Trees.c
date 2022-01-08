#include<stdio.h>

struct Node
{
    struct Node* left;
    int data;
    int height;
    struct Node* right;
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

int node_height(struct Node* p)
{
    int hl, hr;
    hl = p && p->left ? p->left->height : 0;
    hr = p && p->right ? p->right->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

int balance_factor(struct Node* p)
{
    int hl, hr;
    hl = p && p->left ? p->left->height : 0;
    hr = p && p->right ? p->right->height : 0;

    return hl - hr;
}

struct Node* LLRotate(struct Node* p)
{
    struct Node* pl = p->left;
    struct Node* plr = pl->right;

    pl->right = p;
    pl->left = plr;
    p->height = node_height(p);
    pl->height = node_height(pl);

    if (root == p)
        root = pl;
    return pl;
}

struct Node* LRRotate(struct Node* p)
{
    struct Node* pl = p->left;
    struct Node* plr = pl->right;

    pl->right = plr->right;
    p->left = plr->right;
    plr->left = pl;
    plr->right = p;

    p->height = node_height(p);
    pl->height = node_height(pl);
    plr->height = node_height(plr);

    if (root == p)
        root = plr;
    return plr;
}

struct Node* RRRotate(struct Node* p)
{
    struct Node* pr = p->right;
    struct Node* prl = pr->left;

    pr->left = p;
    p->right = prl;
    p->height = node_height(p);
    pr->height = node_height(pr);

    if (root == p)
        root = pr;
    return pr;
}

struct Node* RLRotate(struct Node* p)
{
    struct Node* pr = p->right;
    struct Node* prl = pr->left;

    pr->left = prl->right;
    p->right = prl->left;
    prl->right = pr;
    prl->left = p;

    p->height = node_height(p);
    pr->height = node_height(pr);
    prl->height = node_height(prl);

    if (root == p)
        root = prl;
    return prl;
}

struct Node *recursive_insert(struct Node *p, int key)
{
    struct Node* t = NULL;
    if (p == NULL)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1;
        t->left = t->right = NULL;
        return t;
    }

    if (key < p->data)
        p->left = recursive_insert(p->left, key);
    else if (key > p->data)
        p->right = recursive_insert(p->right, key);

    p->height = node_height(p);

    if (balance_factor(p) == 2 && balance_factor(p->left) == 1)
        return LLRotate(p);
    else if (balance_factor(p) == 2 && balance_factor(p->left) == -1)
        return LRRotate(p);
    else if (balance_factor(p) == -2 && balance_factor(p->right) == -1)
        return RRRotate(p);
    else if (balance_factor(p) == -2 && balance_factor(p->right) == 1)
        return RLRotate(p);

    return p;
}

int main()
{
    root = recursive_insert(root, 5);
    root = recursive_insert(root, 3);
    root = recursive_insert(root, 2);

    inorder(root);

    return 0;
}
