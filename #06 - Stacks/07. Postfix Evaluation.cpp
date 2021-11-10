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
    {
        q = top;
        top = top->next;
        x = q->data;
    }
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
    Stack st = Stack();
    string postfix = "35*62/+4-";
    int eval = 0;

    for (int i = 0; i < postfix.length(); i++)
    {
        if (postfix[i] - 48 >= 0 && postfix[i] - 48 <= 9)
            st.push(postfix[i] - 48);
        else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
        {
            int a = st.pop();
            int b = st.pop();
            if (postfix[i] == '+')
                st.push(a+b);
            else if (postfix[i] == '-')
                st.push(b-a);
            else if (postfix[i] == '*')
                st.push(a*b);
            else
                st.push(b/a);
        }
    }

    eval = st.pop();
    cout<<"Value: "<<eval;
}
