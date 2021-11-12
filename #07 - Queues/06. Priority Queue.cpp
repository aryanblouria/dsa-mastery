#include<iostream>
using namespace std;

class Queue
{
    private:
        int size;
        int front;
        int rear;
        char *arr;
    public:
        Queue() {size = 5; front = 0; rear = -1; arr = new char[size];}
        ~Queue() {delete[] arr;}
        void display();
        bool isFull();
        bool isEmpty();
        char first();
        char last();
        void enqueue(char x);
        char dequeue();
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

char Queue::first()
{
    return arr[front];
}

char Queue::last()
{
    return arr[rear];
}

void Queue::enqueue(char x)
{
    if (!isFull())
    {
        rear++;
        arr[rear] = x;
    }
    else
        cout<<"Cannot enqueue. Queue overflow."<<endl;
}

char Queue::dequeue()
{
    char x = ' ';

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
    char elements[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int priorities[] = {1, 1, 2, 3, 2, 1, 2, 3};

    Queue q1 = Queue();
    Queue q2 = Queue();
    Queue q3 = Queue();

    for (int i = 0; i < 8; i++)
    {
        if (priorities[i] == 1)
            q1.enqueue(elements[i]);
        else if (priorities[i] == 2)
            q2.enqueue(elements[i]);
        else
            q3.enqueue(elements[i]);
    }

    q1.display();
    q2.display();
    q3.display();

    char del = 'y', input;
    int queue_no = 0;

    while (del == 'y')
    {
        cout<<"Enter element to delete: ";
        cin>>input;

        input = toupper(input);

        for (int i = 0; i < 8; i++)
        {
            if (elements[i] == input)
                queue_no = priorities[i];
        }

        switch(queue_no)
        {
            case 1:
                while (q1.first() != input)
                    q1.dequeue();
                q1.dequeue();
                break;
            case 2:
                while (!q1.isEmpty())
                    q1.dequeue();
                while (q2.first() != input)
                    q2.dequeue();
                q2.dequeue();
                break;
            case 3:
                while (!q1.isEmpty())
                    q1.dequeue();
                while (!q2.isEmpty())
                    q2.dequeue();
                while (q3.first() != input)
                    q3.dequeue();
                q3.dequeue();
                break;
        }

        q1.display();
        q2.display();
        q3.display();

        cout<<"Would you like to continue? (y/n): ";
        cin>>del;
    }

}

