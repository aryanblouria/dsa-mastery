#include<iostream>
using namespace std;

class Node
{
  public:
    int data;
    Node* next;
};

class Stack
{
  private:
    Node *top;
  public:
    Stack() {top = NULL;}
    ~Stack() {delete top;}
    void display();
    bool isFull();
    bool isEmpty();
    void push(int x);
    int pop();
    int peek(int pos);
};

void Stack::display()
{
    Node *q = top;
    while (q != 0)
    {
        cout<<"|"<<q->data<<"|"<<endl;
        q = q->next;
    }
}

bool Stack::isFull()
{
    Node *q = new Node;
    if (q == 0)
        return true;
    return false;
}

bool Stack::isEmpty()
{
    if (top == NULL)
        return true;
    return false;
}

void Stack::push(int x)
{
    Node *q = new Node;
    if (q == 0)
        cout<<"Cannot push. Stack overflow."<<endl;
    else
        q->data = x;
        q->next = top;
        top = q;
}

int Stack::pop()
{
    Node *q = new Node;
    int x = -1;
    if (top == NULL)
        cout<<"Cannot pop. Stack underflow."<<endl;
    else
        q = top;
        top = top->next;
        x = q->data;

    return x;
}

int Stack::peek(int pos)
{
    Node *q = top;
    for (int i = 0; i < pos - 1 && q != 0; i++)
        q = q->next;

    if (q != 0)
        return q->data;
    else
        return -1;
}

int main()
{
    Stack s1 = Stack();
    Stack s2 = Stack();

    int choice = 0, element = 0;
    while (choice < 3)
    {
        cout<<"1. Enqueue Element"<<endl;
        cout<<"2. Dequeue Element"<<endl;
        cout<<"You choose: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Enter element: ";
                cin>>element;
                s1.push(element);
                break;
            case 2:
                if (s2.isEmpty())
                {
                    while(!s1.isEmpty())
                        s2.push(s1.pop());
                }
                s2.pop();
                break;
        }

        cout<<"Stack 1: "<<endl;
        s1.display();
        cout<<"Stack 2: "<<endl;
        s2.display();
    }

    return 0;
}

