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

void enqueue_front(struct Queue *q, int x)
{
    if (!isFull(*q))
    {
        q->front--;
        q->arr[q->front] = x;
    }
    else
        printf("Cannot enqueue. Queue overflow.\n");
}

void enqueue_rear(struct Queue *q, int x)
{
    if (!isFull(*q))
    {
        q->rear++;
        q->arr[q->rear] = x;
    }
    else
        printf("Cannot enqueue. Queue overflow.\n");
}

int dequeue_front(struct Queue *q)
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

int dequeue_rear(struct Queue *q)
{
    int x = -1;

    if (!isEmpty(*q))
    {
        x = q->arr[q->rear];
        q->rear--;
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

    enqueue_rear(&q, 1);
    enqueue_rear(&q, 2);
    enqueue_rear(&q, 3);
    dequeue_front(&q);
    dequeue_front(&q);

    display(q);

    if (isFull(q))
        printf("Queue is full.\n");

    int x = first(q);
    int y = last(q);
    printf("%d and %d are the first and last values respectively.\n", x, y);

    enqueue_front(&q, 2);
    enqueue_front(&q, 1);

    display(q);

    dequeue_rear(&q);
    dequeue_rear(&q);

    display(q);

    if (isEmpty(q))
        printf("Queue is empty.\n");
}
