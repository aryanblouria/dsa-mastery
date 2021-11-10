#include<stdio.h>
#include<stdbool.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int* arr;
};

void display(struct Queue q)
{
    for (int i = q.front; i <= q.rear; i++)
        printf("|%d", q.arr[i]);
    printf("\n");
}

bool isEmpty(struct Queue q)
{
    if (q.front > q.rear)
        return true;
    return false;
}

bool isFull(struct Queue q)
{
    if (q.rear == q.size - 1)
        return true;
    return false;
}

int first(struct Queue q)
{
    return q.arr[q.front];
}

int last(struct Queue q)
{
    return q.arr[q.rear];
}

void enqueue(struct Queue *q, int x)
{
    if (!isFull(*q))
    {
        q->rear++;
        q->arr[q->rear] = x;
    }
    else
        printf("Cannot enqueue. Queue overflow.\n");
}

int dequeue(struct Queue *q)
{
    int x = -1;

    if (!isEmpty(*q))
    {
        x = q->arr[q->front];
        q->front++;
    }
    else
        printf("Cannot dequeue. Stack underflow.\n");

    return x;
}

int main()
{
    struct Queue q;
    q.size = 5;
    q.front = 0;
    q.rear = -1;
    q.arr = (int*)malloc(q.size*sizeof(int));

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 6);

    display(q);

    if (isFull(q))
        printf("Queue is full.\n");

    int x = first(q);
    int y = last(q);
    printf("%d and %d are the first and last values respectively.\n", x, y);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    display(q);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    display(q);

    if (isEmpty(q))
        printf("Queue is empty.\n");
}
