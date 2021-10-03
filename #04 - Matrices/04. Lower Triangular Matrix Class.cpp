#include<iostream>
using namespace std;

class Lower_Triangular_Matrix
{
private:
    int *arr;
    int dim;
public:
    Lower_Triangular_Matrix()
    {
        dim = 3;
        arr = new int[dim];
    }

    Lower_Triangular_Matrix(int d)
    {
        dim = d;
        arr = new int[dim];
    }

    ~Lower_Triangular_Matrix()
    {
        delete[] arr;
    }

    void ltm_rowmajor_display();
    void ltm_colmajor_display();
    void ltm_rowmajor_set(int i, int j, int a);
    void ltm_colmajor_set(int i, int j, int a);
    int ltm_rowmajor_get(int i, int j);
    int ltm_colmajor_get(int i, int j);
};

void Lower_Triangular_Matrix::ltm_rowmajor_display()
{
    for(int i = 1; i <= dim; i++)
    {
        for(int j = 1; j <= dim; j++)
        {
            int index = (i * (i-1)/2) + j - 1;
            if (i>=j)
                cout<<arr[index]<<" ";
            else
                cout<<"0 ";
        }
        cout<<"\n";
    }
}

void Lower_Triangular_Matrix::ltm_rowmajor_set(int i, int j, int a)
{
    if (i >= j)
    {
        int index = (i * (i-1)/2) + j - 1;
        arr[index] = a;
    }
}

int Lower_Triangular_Matrix::ltm_rowmajor_get(int i, int j)
{
    if (i >= j)
    {
        int index = (i * (i-1)/2) + j - 1;
        return arr[index];
    }
    return 0;
}

void Lower_Triangular_Matrix::ltm_colmajor_display()
{
    for(int i = 1; i <= dim; i++)
    {
        for(int j = 1; j <= dim; j++)
        {
            int index = (dim * (j-1) - (j-1)*(j-2)/2) + i - j;
            if (i>=j)
                cout<<arr[index]<<" ";
            else
                cout<<"0 ";
        }
        cout<<"\n";
    }
}

void Lower_Triangular_Matrix::ltm_colmajor_set(int i, int j, int a)
{
    if (i >= j)
    {
        int index = (dim * (j-1) - (j-1)*(j-2)/2) + i - j;
        arr[index] = a;
    }
}

int Lower_Triangular_Matrix::ltm_colmajor_get(int i, int j)
{
    if (i >= j)
    {
        int index = (dim * (j-1) - (j-1)*(j-2)/2) + i - j;
        return arr[index];
    }
    return 0;
}

int main()
{
    Lower_Triangular_Matrix *ltm1, *ltm2;
    int dim, choice;
    int i, j, a;

    cout<<"Enter dimension: ";
    cin>>dim;

    ltm1 = new Lower_Triangular_Matrix(dim);
    ltm2 = new Lower_Triangular_Matrix(dim);

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
            ltm1->ltm_rowmajor_display();
            ltm2->ltm_colmajor_display();
            break;
        case 2:
            cout<<"Enter row number: ";
            cin>>i;
            cout<<"Enter column number: ";
            cin>>j;
            cout<<"Enter value: ";
            cin>>a;
            ltm1->ltm_rowmajor_set(i, j, a);
            ltm2->ltm_colmajor_set(i, j, a);
            break;
        case 3:
            cout<<"Enter row number: ";
            cin>>i;
            cout<<"Enter column number: ";
            cin>>j;
            cout<<ltm1->ltm_rowmajor_get(i, j);
            cout<<ltm2->ltm_colmajor_get(i, j);
       }
    } while (choice > 0 && choice < 4);
}

