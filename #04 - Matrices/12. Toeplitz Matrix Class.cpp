#include<iostream>
using namespace std;

class Toeplitz_Matrix
{
private:
    int *arr;
    int dim;
public:
    Toeplitz_Matrix()
    {
        dim = 3;
        arr = new int[dim];
    }

    Toeplitz_Matrix(int d)
    {
        dim = d;
        arr = new int[dim];
    }

    ~Toeplitz_Matrix()
    {
        delete[] arr;
    }

    void toeplitz_display();
    void toeplitz_set(int i, int j, int a);
    int toeplitz_get(int i, int j);
};

void Toeplitz_Matrix::toeplitz_display()
{
   for(int i = 1; i <= dim; i++)
    {
        for(int j = 1; j <= dim; j++)
        {
            int n = dim;
            if (i <= j)
                cout<<arr[j-i]<<" ";
            else
                cout<<arr[n+i-j-1]<<" ";
        }
        cout<<"\n";
    }
}

void Toeplitz_Matrix::toeplitz_set(int i, int j, int a)
{
   int n = dim;
    if (i <= j)
        arr[j-i] = a;
    else
        arr[n+i-j-1] = a;
}

int Toeplitz_Matrix::toeplitz_get(int i, int j)
{
    int n = dim;
    if (i <= j)
        return arr[j-i];
    else
        return arr[n+i-j-1];
}

int main()
{
    Toeplitz_Matrix *d;
    int dim, choice;
    int i, j, a;

    cout<<"Enter dimension: ";
    cin>>dim;

    d = new Toeplitz_Matrix(dim);

    do
    {
       cout<<endl<<"Menu of Operations"<<endl;
       cout<<"=================="<<endl<<endl;
       cout<<"1. Display"<<endl;
       cout<<"2. Set Element"<<endl;
       cout<<"3. Get Element"<<endl;

       cout<<"Enter your choice: ";
       cin>>choice;

       switch(choice)
       {
        case 1:
            d->toeplitz_display();
            break;
        case 2:
            cout<<"Enter row number: ";
            cin>>i;
            cout<<"Enter column number: ";
            cin>>j;
            cout<<"Enter value: ";
            cin>>a;
            d->toeplitz_set(i, j, a);
            break;
        case 3:
            cout<<"Enter row number: ";
            cin>>i;
            cout<<"Enter column number: ";
            cin>>j;
            cout<<d->toeplitz_get(i, j);
       }
    } while (choice > 0 && choice < 4);
}


