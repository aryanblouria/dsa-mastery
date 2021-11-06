#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
};

class LinkedList
{
    private:
        Node* first;

    public:
        LinkedList()
        {
            first = NULL;
        }

        LinkedList(int arr[], int n)
        {
            Node *temp, *last;
            first = new Node;
            first->data = arr[0];
            first->next = NULL;
            last = first;

            for (int i = 1; i < n; i++)
            {
                temp = new Node;
                temp->data = arr[i];
                temp->next = NULL;
                last->next = temp;
                last = temp;
            }
        }

        ~LinkedList()
        {
            delete first;
        }

        void display();
        int get_length();
        int sum();
        int max();
        int min();
        Node* linear_search(int value);
        void insert(int index, int value);
        void append(int value);
        void del(int index);
        bool check_sorted();
        void delete_duplicates();
        void reverse();
        Node* concatenate(Node *q);
        Node* merge(Node *q);
        void loop_detect();
};

void LinkedList::display()
{
    Node *p = first;
    while (p != 0)
    {
        cout<<p->data<<"->";
        p = p->next;
    }
    cout<<"NULL"<<endl;
}

int LinkedList::get_length()
{
    int length = 0;
    Node *p = first;

    while (p != 0)
    {
        length++;
        p = p->next;
    }
    return length;
}

int LinkedList::sum()
{
    int s = 0;
    Node *p = first;

    while (p != 0)
    {
        s += p->data;
        p = p->next;
    }
    return s;
}

int LinkedList::max()
{
    Node *p = first;
    int m = p->data;

    while (p != 0)
    {
        if (p->data > m)
            m = p->data;
        p = p->next;
    }
    return m;
}

int LinkedList::min()
{
    Node *p = first;
    int m = p->data;

    while (p != 0)
    {
        if (p->data < m)
            m = p->data;
        p = p->next;
    }
    return m;
}

Node* LinkedList::linear_search(int value)
{
    Node *p = first;
    while (p != 0)
    {
        if (p->data == value)
            return p;
        p = p->next;
    }
    return 0;
}

void LinkedList::insert(int index, int value)
{
    Node* q = new Node;
    Node* last = new Node;
    Node *p = first;

    for (int i = 0; i < get_length(); i++)
        p = p->next;
    last = p;

    q->data = value;
    if (index == 0)
    {
        q->next = first;
        first = q;
    }
    else if (index > 0 && index <= get_length())
    {
        p = first;
        for (int i = 0; i < index-1 && p != 0; i++)
            p = p->next;
        q->next = p->next;
        p->next = q;
    }
    else
        cout<<"Insert failed. Please enter valid index."<<endl;
}

void LinkedList::append(int value)
{
    Node* last = new Node;
    Node* q = new Node;

    last = first;
    for (int i = 0; i < get_length() - 1; i++)
        last = last->next;

    q->data = value;
    q->next = NULL;
    last->next = q;
    last = q;
}

void LinkedList::del(int index)
{
    Node* q = new Node;
    Node* prev = new Node;
    Node* p = first;

    if (index == 0)
    {
        q = p->next;
        p->next = NULL;
        first = q;
    }
    else if (index < get_length())
    {
        prev = first;
        p = prev->next;
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
            prev = prev->next;
        }
        prev->next = p->next;
        p->next = NULL;
    }
}

bool LinkedList::check_sorted()
{
    Node *p = first;
    while (p->next != 0)
    {
        int temp = p->data;
        p = p->next;

        if (temp > p->data)
            return false;
    }
    return true;
}

void LinkedList::delete_duplicates()
{
    Node *q = new Node;
    Node *p = first;

    q = p->next;

    while (q != 0)
    {
        if (p->data == q->data)
        {
            p->next = q->next;
            q = p->next;
        }
        else
        {
            p = q;
            q = q->next;
        }
    }
}

void LinkedList::reverse()
{
    Node *q = new Node;
    Node *r = new Node;
    Node *p = first;

    while (p != 0)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

Node* LinkedList::concatenate(Node* q)
{
    Node* p = first;

    while(p->next != 0)
        p = p->next;
    p->next = q;

    p = first;
    return p;
}

Node* LinkedList::merge(Node* q)
{
    Node* f = NULL;
    Node* l = NULL;
    Node* p = first;

    if (p->data < q->data)
    {
        f = p;
        l = p;

        p = p->next;
        l->next = NULL;
    }
    else
    {
        f = q;
        l = q;

        q = q->next;
        l->next = NULL;
    }

    while (p != 0 && q != 0)
    {
        if (p->data < q->data)
        {
            l->next = p;
            l = p;

            p = p->next;
            l->next = NULL;
        }
        else
        {
            l->next = q;
            l = q;

            l->next = NULL;
            q = q->next;
        }
    }

    if (p != 0)
        l->next = p;
    else
        l->next = q;

    return f;
}

void LinkedList::loop_detect()
{
    Node *p = first;
    Node *q = p;

    while (p != 0 && q != 0)
    {
        p = p->next;
        q = q->next;

        if (q != 0)
            q = q->next;
        else
            q = NULL;
    }

    if (p == q)
        cout<<"Loop detected.";
    else
        cout<<"No loop detected.";
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int choice = 0;

    LinkedList ll = LinkedList(arr, 5);

    do
    {
       cout<<endl<<"Menu of Operations"<<endl;
       cout<<"=================="<<endl<<endl;
       cout<<"1. Display"<<endl;
       cout<<"2. Get Length"<<endl;
       cout<<"3. Get Sum"<<endl;
       cout<<"4. Get Max"<<endl;
       cout<<"5. Get Min"<<endl;
       cout<<"6. Linear Search"<<endl;
       cout<<"7. Insert"<<endl;
       cout<<"8. Append"<<endl;
       cout<<"9. Delete"<<endl;
       cout<<"10. Check if Sorted"<<endl;
       cout<<"11. Delete Duplicates"<<endl;
       cout<<"12. Reverse"<<endl;
       cout<<"13. Concatenate"<<endl;
       cout<<"14. Merge"<<endl;
       cout<<"15. Detect Loop"<<endl;


       cout<<endl<<"Enter your choice: ";
       cin>>choice;

       switch(choice)
       {
        //Enter cases here
       }

    } while (choice<16);

    return 0;
}
