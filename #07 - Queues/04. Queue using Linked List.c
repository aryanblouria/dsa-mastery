#include<stdio.h>
#include<stdbool.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node *front, *rear = NULL;

void display()
{
    struct Node *q = front;
    while (q != 0)
    {
        printf("%d->", q->data);
        q = q->next;
    }
    printf("\n");
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
    if (front == NULL)
        return true;
    return false;
}

int first()
{
    return front->data;
}

int last()
{
    return rear->data;
}

void enqueue(int x)
{
    struct Node *q = (struct Node*)malloc(sizeof(struct Node));

    if (!isFull())
    {
        q->data = x;
        q->next = NULL;

        if (front == NULL)
            front = rear = q;
        else
        {
            rear->next = q;
            rear = q;
        }
    }
    else
        printf("Cannot enqueue. Queue overflow.\n");
}

int dequeue()
{
    struct Node* q = (struct Node*)malloc(sizeof(struct Node));
    int x = -1;

    if(!isEmpty())
    {
        x = front->data;
        front = front->next;
    }
    else
        printf("Cannot dequeue. Queue underflow.\n");

    return x;
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);

    display();

    if (isFull())
        printf("Queue is full.\n");

    int x = first();
    int y = last();
    printf("%d and %d are the first and last values respectively.\n", x, y);

    dequeue();
    dequeue();
    dequeue();

    display();

    dequeue();
    dequeue();
    dequeue();

    display();

    if (isEmpty())
        printf("Queue is empty.\n");
}
