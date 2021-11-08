#include<stdio.h>
#include<stdbool.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node *top = NULL;

void display()
{
    struct Node *q = top;
    while (q != 0)
    {
        printf("|%d|\n", q->data);
        q = q->next;
    }
}

bool isFull()
{
    struct Node *q = (struct Node*)malloc(sizeof(struct Node));
    if (q == 0)
        return true;
    return false;
}

bool isEmpty()
{
    if (top == NULL)
        return true;
    return false;
}

void push(int x)
{
    struct Node *q = (struct Node*)malloc(sizeof(struct Node));
    if (q == 0)
        printf("Cannot push. Stack overflow.\n");
    else
        q->data = x;
        q->next = top;
        top = q;
}

int pop()
{
    struct Node *q = (struct Node*)malloc(sizeof(struct Node));
    int x = -1;
    if (top == NULL)
        printf("Cannot pop. Stack underflow.\n");
    else
        q = top;
        top = top->next;
        x = q->data;

    return x;
}

int peek(int pos)
{
    struct Node *q = top;
    for (int i = 0; i < pos - 1 && q != 0; i++)
        q = q->next;

    if (q != 0)
        return q->data;
    else
        return -1;
}

int main()
{
    push(5);
    push(4);
    push(3);
    push(2);
    push(1);

    display();

    if (isFull())
        printf("Stack is full.\n");

    int x = peek(3);
    int y = peek(6);
    printf("%d was found.\n", x);

    pop();
    pop();
    pop();

    display();

    pop();
    pop();

    display();

    if (isEmpty())
        printf("Stack is empty.\n");
}
