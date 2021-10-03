#include<iostream>
using namespace std;

class Tri_Band_Matrix
{
private:
    int *arr;
    int dim;
public:
    Tri_Band_Matrix()
    {
        dim = 3;
        arr = new int[dim];
    }

    Tri_Band_Matrix(int d)
    {
        dim = d;
        arr = new int[dim];
    }

    ~Tri_Band_Matrix()
    {
        delete[] arr;
    }

    void triband_display();
    void triband_set(int i, int j, int a);
    int triband_get(int i, int j);
};

void Tri_Band_Matrix::triband_display()
{
    for(int i = 1; i <= dim; i++)
    {
        for(int j = 1; j <= dim; j++)
        {
            int n = dim;
            if (i - j == 1)
                cout<<arr[i-2]<<" ";
            else if (i - j == 0)
                cout<<arr[n - 1 + i - 1]<<" ";
            else if (i - j == -1)
                cout<<arr[n - 1 + n + i - 1]<<" ";
            else
                cout<<"0 ";
        }
        cout<<"\n";
    }
}

void Tri_Band_Matrix::triband_set(int i, int j, int a)
{
   int n = dim;
    if (i - j == 1)
        arr[i-2] = a;
    else if (i - j == 0)
        arr[n - 1 + i - 1] = a;
    else if (i - j == -1)
        arr[n - 1 + n + i - 1] = a;
}

int Tri_Band_Matrix::triband_get(int i, int j)
{
    int n = dim;
    if (i - j == 1)
        return arr[i-2];
    else if (i - j == 0)
        return arr[n-1+i-1];
    else if (i - j == -1)
        return arr[n-1+n+i-1];
    else
        return 0;
}

int main()
{
    Tri_Band_Matrix *d;
    int dim, choice;
    int i, j, a;

    cout<<"Enter dimension: ";
    cin>>dim;

    d = new Tri_Band_Matrix(dim);

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
            d->triband_display();
            break;
        case 2:
            cout<<"Enter row number: ";
            cin>>i;
            cout<<"Enter column number: ";
            cin>>j;
            cout<<"Enter value: ";
            cin>>a;
            d->triband_set(i, j, a);
            break;
        case 3:
            cout<<"Enter row number: ";
            cin>>i;
            cout<<"Enter column number: ";
            cin>>j;
            cout<<d->triband_get(i, j);
       }
    } while (choice > 0 && choice < 4);
}


