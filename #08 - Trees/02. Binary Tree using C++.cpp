#include <iostream>
using namespace std;

class Node
{
    public:
        Node* left;
        int data;
        Node* right;
};

class Queue
{
    private:
        int size;
        int front;
        int rear;
        Node** Q;
    public:
        Queue(int size);
        ~Queue();
        bool isFull();
        bool isEmpty();
        void enqueue(Node* x);
        Node* dequeue();
};

Queue::Queue(int size)
{
    this->size = size;
    front = -1;
    rear = -1;
    Q = new Node*[size];
}

Queue::~Queue()
{
    delete[] Q;
}

bool Queue::isEmpty()
{
    if (front == rear)
        return true;
    return false;
}

bool Queue::isFull()
{
    if (rear == size-1)
        return true;
    return false;
}

void Queue::enqueue(Node* x)
{
    if (isFull())
        cout << "Queue Overflow";
    else
    {
        rear++;
        Q[rear] = x;
    }
}

Node* Queue::dequeue()
{
    Node* x = nullptr;
    if (isEmpty())
        cout << "Queue Underflow";
    else
    {
        front++;
        x = Q[front];
    }
    return x;
}

Node* root = new Node;

void create_tree()
{
    Node* p;
    Node* t;
    int x;
    Queue q(10);

    cout << "Enter root element: ";
    cin >> x;
    root->data = x;
    root->left = nullptr;
    root->right = nullptr;
    q.enqueue(root);

    while (!q.isEmpty())
    {
        p = q.dequeue();
        cout << "Enter left child element of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->left = nullptr;
            t->right = nullptr;
            p->left = t;
            q.enqueue(t);
        }

        cout << "Enter right child element of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->left = nullptr;
            t->right = nullptr;
            p->right = t;
            q.enqueue(t);
        }
    }
}

void preorder(Node* p)
{
    if (p)
    {
        cout << "(" << p->data << ") ";
        preorder(p->left);
        preorder(p->right);
    }
}

void inorder(Node* p)
{
    if (p)
    {
        inorder(p->left);
        cout << "(" << p->data << ") ";
        inorder(p->right);
    }
}

void postorder(Node* p)
{
    if (p)
    {
        postorder(p->left);
        postorder(p->right);
        cout << "(" << p->data << ") ";
    }
}


int main()
{
    create_tree();

    preorder(root);
    cout << endl;

    inorder(root);
    cout << endl;

    postorder(root);
    cout << endl;

    return 0;
}
