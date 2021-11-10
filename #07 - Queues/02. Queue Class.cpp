#include<iostream>
using namespace std;

class Queue
{
    private:
        int size;
        int front;
        int rear;
        int *arr;
    public:
        Queue() {size = 5; front = 0; rear = -1; arr = new int[size];}
        ~Queue() {delete[] arr;}
        void display();
        bool isFull();
        bool isEmpty();
        int first();
        int last();
        void enqueue(int x);
        int dequeue();
};

void Queue::display()
{
    for (int i = front; i <= rear; i++)
        cout<<"|"<<arr[i];
    cout<<endl;
}

bool Queue::isFull()
{
    if (rear == size - 1)
        return true;
    return false;
}

bool Queue::isEmpty()
{
    if (front > rear)
        return true;
    return false;
}

int Queue::first()
{
    return arr[front];
}

int Queue::last()
{
    return arr[rear];
}

void Queue::enqueue(int x)
{
    if (!isFull())
    {
        rear++;
        arr[rear] = x;
    }
    else
        cout<<"Cannot enqueue. Queue overflow."<<endl;
}

int Queue::dequeue()
{
    int x = -1;

    if (!isEmpty())
    {
        x = arr[front];
        front++;
    }
    else
        cout<<"Cannot dequeue. Stack underflow."<<endl;

    return x;
}

int main()
{
    Queue q = Queue();
    int choice = 0, x = 0;

    do
    {
       cout<<endl<<"Menu of Operations"<<endl;
       cout<<"=================="<<endl<<endl;
       cout<<"1. Display"<<endl;
       cout<<"2. Check if Full"<<endl;
       cout<<"3. Check if Empty"<<endl;
       cout<<"4. Get First"<<endl;
       cout<<"5. Get Last"<<endl;
       cout<<"6. Enqueue Element"<<endl;
       cout<<"7. Dequeue Element"<<endl;

       cout<<endl<<"Enter your choice: ";
       cin>>choice;

       switch(choice)
       {
            case 1:
                q.display();
                break;
            case 2:
                q.isFull() ? cout<<"Full"<<endl : cout<<"Not Full"<<endl;
                break;
            case 3:
                q.isEmpty() ? cout<<"Empty"<<endl : cout<<"Not Empty"<<endl;;
                break;
            case 4:
                cout<<"First Element: "<<q.first()<<endl;
                break;
            case 5:
                cout<<"Last Element: "<<q.last()<<endl;
                break;
            case 6:
                cout<<"Enter element: ";
                cin>>x;
                q.enqueue(x);
                break;
            case 7:
                q.dequeue();
                break;
       }
    } while (choice<8);

    return 0;
}
