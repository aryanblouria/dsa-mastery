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
    Stack st = Stack();
    int choice = 0, x = 0;

    do
    {
       cout<<endl<<"Menu of Operations"<<endl;
       cout<<"=================="<<endl<<endl;
       cout<<"1. Display"<<endl;
       cout<<"2. Check if Full"<<endl;
       cout<<"3. Check if Empty"<<endl;
       cout<<"4. Push Element"<<endl;
       cout<<"5. Pop Element"<<endl;
       cout<<"6. Peek Element"<<endl;

       cout<<endl<<"Enter your choice: ";
       cin>>choice;

       switch(choice)
       {
            case 1:
                st.display();
                break;
            case 2:
                st.isFull() ? cout<<"Full"<<endl : cout<<"Not Full"<<endl;
                break;
            case 3:
                st.isEmpty() ? cout<<"Empty"<<endl : cout<<"Not Empty"<<endl;;
                break;
            case 4:
                cout<<"Enter element: ";
                cin>>x;
                st.push(x);
                break;
            case 5:
                st.pop();
                break;
            case 6:
                cout<<"Enter position: ";
                cin>>x;
                x = st.peek(x);
                cout<<x;
                break;
       }
    } while (choice<7);

    return 0;
}


