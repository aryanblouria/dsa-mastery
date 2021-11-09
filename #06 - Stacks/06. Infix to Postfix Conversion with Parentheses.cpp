#include<iostream>
using namespace std;

class Node
{
  public:
    char data;
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
    void push(char x);
    char pop();
    char peek(int pos);
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

void Stack::push(char x)
{
    Node *q = new Node;
    if (q == 0)
        cout<<"Cannot push. Stack overflow."<<endl;
    else
        q->data = x;
        q->next = top;
        top = q;
}

char Stack::pop()
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

char Stack::peek(int pos)
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
    string infix = "((a+b)*c)-d^e^f";
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] >= 97 && infix[i] <= 122)
            postfix.push_back(infix[i]);
        else if (infix[i] == '(')
            st.push(infix[i]);
        else if (infix[i] == '+' || infix[i] == '-')
        {
            if (st.isEmpty() || st.peek(1) == '(')
                st.push(infix[i]);
            else
            {
                while (!st.isEmpty() || !st.peek(1) == '(')
                    postfix.push_back(st.pop());
                st.push(infix[i]);
            }
        }
        else if (infix[i] == '*' || infix[i] == '/')
        {
            if (st.isEmpty() || st.peek(1) == '+' || st.peek(1) == '-' || st.peek(1) == '(')
                st.push(infix[i]);
            else
            {
                while (!(st.peek(1) == '+' && !st.peek(1) == '-'))
                    postfix.push_back(st.pop());
                st.push(infix[i]);
            }
        }
        else if (infix[i] == '^')
            st.push(infix[i]);
        else if (infix[i] == ')')
        {
            while (st.peek(1) != '(')
                postfix.push_back(st.pop());
            st.pop();
        }
    }

    while (!st.isEmpty())
        postfix.push_back(st.pop());

    cout<<"Postfix expression: "<<postfix;
}
