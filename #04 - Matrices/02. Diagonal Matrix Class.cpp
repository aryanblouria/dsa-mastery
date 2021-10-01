#include<iostream>
using namespace std;

class Diagonal_Matrix
{
private:
    int *arr;
    int dim;
public:
    Diagonal_Matrix()
    {
        dim = 3;
        arr = new int[dim];
    }

    Diagonal_Matrix(int d)
    {
        dim = d;
        arr = new int[dim];
    }

    ~Diagonal_Matrix()
    {
        delete[] arr;
    }

    void diag_display();
    void diag_set(int i, int j, int a);
    int diag_get(int i, int j);
};

void Diagonal_Matrix::diag_display()
{
    for(int i = 0; i < dim; i++)
    {
        for(int j = 0; j < dim; j++)
        {
            if (i==j)
                printf("%d ", arr[i]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

void Diagonal_Matrix::diag_set(int i, int j, int a)
{
    if (i == j)
        arr[i-1] = a;
}

int Diagonal_Matrix::diag_get(int i, int j)
{
    if (i == j)
        return arr[i-1];
    return 0;
}

int main()
{
    Diagonal_Matrix *d;
    int dim, choice;
    int i, j, a;

    printf("Enter dimension: ");
    scanf("%d", &dim);

    d = new Diagonal_Matrix(dim);

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
            d->diag_display();
            break;
        case 2:
            printf("Enter row number: ");
            scanf("%d", &i);
            printf("Enter column number: ");
            scanf("%d", &j);
            printf("Enter value: ");
            scanf("%d", &a);
            d->diag_set(i, j, a);
            break;
        case 3:
            printf("Enter row number: ");
            scanf("%d", &i);
            printf("Enter column number: ");
            scanf("%d", &j);
            printf("%d", d->diag_get(i, j));
       }
    } while (choice > 0 && choice < 4);
}


