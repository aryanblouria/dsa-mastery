#include<stdio.h>
#include<stdbool.h>

struct Stack
{
    int size;
    int top;
    int* arr;
};

void display(struct Stack st)
{
    while (st.top != -1)
    {
        printf("|%d|\n", st.arr[st.top]);
        st.top--;
    }
}

bool isEmpty(struct Stack st)
{
    if (st.top == -1)
        return true;
    return false;
}

bool isFull(struct Stack st)
{
    if (st.top == st.size-1)
        return true;
    return false;
}

void push(struct Stack* st, int x)
{
    if (!isFull(*st))
    {
        st->top++;
        st->arr[st->top] = x;
    }
    else
        printf("Cannot push. Stack overflow.\n");
}

int pop(struct Stack* st)
{
    int x = -1;

    if (!isEmpty(*st))
    {
        x = st->arr[st->top];
        st->top--;
    }
    else
        printf("Cannot pop. Stack underflow.\n");

    return x;
}

int peek(struct Stack st, int pos)
{
    int x = -1;

    if (st.top - pos + 1 < 0)
        printf("Invalid position.\n");
    else
        x = st.arr[st.top - pos + 1];

    return x;
}

int main()
{
    struct Stack st;
    st.size = 5;
    st.top = -1;
    st.arr = (int*)malloc(st.size*sizeof(int));

    push(&st, 5);
    push(&st, 4);
    push(&st, 3);
    push(&st, 2);
    push(&st, 1);
    push(&st, 0);

    display(st);

    if (isFull(st))
        printf("Stack is full.\n");

    int x = peek(st, 3);
    int y = peek(st, 6);
    printf("%d was found.\n", x);

    pop(&st);
    pop(&st);
    pop(&st);

    display(st);

    pop(&st);
    pop(&st);
    pop(&st);

    display(st);

    if (isEmpty(st))
        printf("Stack is empty.\n");
}
