#include<iostream>
#include<string>
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
    string expression = "{([a+b]*[c-d])/e}";

    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == '(')
            st.push(0);
        else if (expression[i] == '[')
            st.push(1);
        else if (expression[i] == '{')
            st.push(2);
        else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}')
        {
            if (((expression[i] == ')' && st.peek(1) == 0) || (expression[i] == ']' && st.peek(1) == 1) || (expression[i] == '}' && st.peek(1) == 2)) && (!st.isEmpty()))
                st.pop();
            else
            {
                cout<<"The parentheses are not balanced."<<endl;
                return 0;
            }
        }
    }

    if (st.isEmpty())
        cout<<"The parentheses are balanced."<<endl;
    else
        cout<<"The parentheses are not balanced."<<endl;

    return 0;
}
