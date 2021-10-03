#include<iostream>
using namespace std;

class Upper_Triangular_Matrix
{
private:
    int *arr;
    int dim;
public:
    Upper_Triangular_Matrix()
    {
        dim = 3;
        arr = new int[dim];
    }

    Upper_Triangular_Matrix(int d)
    {
        dim = d;
        arr = new int[dim];
    }

    ~Upper_Triangular_Matrix()
    {
        delete[] arr;
    }

    void utm_rowmajor_display();
    void utm_colmajor_display();
    void utm_rowmajor_set(int i, int j, int a);
    void utm_colmajor_set(int i, int j, int a);
    int utm_rowmajor_get(int i, int j);
    int utm_colmajor_get(int i, int j);
};

void Upper_Triangular_Matrix::utm_rowmajor_display()
{
    for(int i = 1; i <= dim; i++)
    {
        for(int j = 1; j <= dim; j++)
        {
            int index = (dim * (i-1) - (i-1)*(i-2)/2) + j - i;
            if (j>=i)
                cout<<arr[index]<<" ";
            else
                cout<<"0 ";
        }
        cout<<"\n";
    }
}

void Upper_Triangular_Matrix::utm_rowmajor_set(int i, int j, int a)
{
    if (j >= i)
    {
        int index = (dim * (i-1) - (i-1)*(i-2)/2) + j - i;
        arr[index] = a;
    }
}

int Upper_Triangular_Matrix::utm_rowmajor_get(int i, int j)
{
    if (j >= i)
    {
        int index = (dim * (i-1) - (i-1)*(i-2)/2) + j - i;
        return arr[index];
    }
    return 0;
}

void Upper_Triangular_Matrix::utm_colmajor_display()
{
    for(int i = 1; i <= dim; i++)
    {
        for(int j = 1; j <= dim; j++)
        {
            int index = (j * (j-1)/2) + i - 1;
            if (j>=i)
                cout<<arr[index]<<" ";
            else
                cout<<"0 ";
        }
        cout<<"\n";
    }
}

void Upper_Triangular_Matrix::utm_colmajor_set(int i, int j, int a)
{
    if (j >= i)
    {
        int index = (j * (j-1)/2) + i - 1;
        arr[index] = a;
    }
}

int Upper_Triangular_Matrix::utm_colmajor_get(int i, int j)
{
    if (j >= i)
    {
        int index = (j * (j-1)/2) + i - 1;
        return arr[index];
    }
    return 0;
}

int main()
{
    Upper_Triangular_Matrix *utm1, *utm2;
    int dim, choice;
    int i, j, a;

    cout<<"Enter dimension: ";
    cin>>dim;

    utm1 = new Upper_Triangular_Matrix(dim);
    utm2 = new Upper_Triangular_Matrix(dim);

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
            utm1->utm_rowmajor_display();
            utm2->utm_colmajor_display();
            break;
        case 2:
            cout<<"Enter row number: ";
            cin>>i;
            cout<<"Enter column number: ";
            cin>>j;
            cout<<"Enter value: ";
            cin>>a;
            utm1->utm_rowmajor_set(i, j, a);
            utm2->utm_colmajor_set(i, j, a);
            break;
        case 3:
            cout<<"Enter row number: ";
            cin>>i;
            cout<<"Enter column number: ";
            cin>>j;
            cout<<utm1->utm_rowmajor_get(i, j);
            cout<<utm2->utm_colmajor_get(i, j);
       }
    } while (choice > 0 && choice < 4);
}

