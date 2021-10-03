#include<iostream>
using namespace std;

class Symmetric_Matrix
{
private:
    int *arr;
    int dim;
public:
    Symmetric_Matrix()
    {
        dim = 3;
        arr = new int[dim];
    }

    Symmetric_Matrix(int d)
    {
        dim = d;
        arr = new int[dim];
    }

    ~Symmetric_Matrix()
    {
        delete[] arr;
    }

    void symm_ltm_display();
    void symm_utm_display();
    void symm_ltm_set(int i, int j, int a);
    void symm_utm_set(int i, int j, int a);
    int symm_ltm_get(int i, int j);
    int symm_utm_get(int i, int j);
};

void Symmetric_Matrix::symm_ltm_display()
{
    for(int i = 1; i <= dim; i++)
    {
        for(int j = 1; j <= dim; j++)
        {
            if (i >= j)
                printf("%d ", arr[(i * (i-1)/2) + j - 1]);
            else
                printf("%d ", arr[(j * (j-1)/2) + i - 1]);
        }
        printf("\n");
    }
}

void Symmetric_Matrix::symm_ltm_set(int i, int j, int a)
{
    arr[(i * (i-1)/2) + j - 1] = a;
}

int Symmetric_Matrix::symm_ltm_get(int i, int j)
{
    return arr[(i * (i-1)/2) + j - 1];
}

void Symmetric_Matrix::symm_utm_display()
{
    for(int i = 1; i <= dim; i++)
    {
        for(int j = 1; j <= dim; j++)
        {
            if (j >= i)
                printf("%d ", arr[(j * (j-1)/2) + i - 1]);
            else
                printf("%d ", arr[(i * (i-1)/2 + j - 1)]);
        }
        printf("\n");
    }
}

void Symmetric_Matrix::symm_utm_set(int i, int j, int a)
{
    arr[(j * (j-1)/2) + i - 1] = a;
}

int Symmetric_Matrix::symm_utm_get(int i, int j)
{
    return arr[(j * (j-1)/2) + i - 1];
}

int main()
{
    Symmetric_Matrix *symm1, *symm2;
    int dim, choice;
    int i, j, a;

    printf("Enter dimension: ");
    scanf("%d", &dim);

    symm1 = new Symmetric_Matrix(dim);
    symm2 = new Symmetric_Matrix(dim);

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
            symm1->symm_ltm_display();
            symm2->symm_utm_display();
            break;
        case 2:
            printf("Enter row number: ");
            scanf("%d", &i);
            printf("Enter column number: ");
            scanf("%d", &j);
            printf("Enter value: ");
            scanf("%d", &a);
            symm1->symm_ltm_set(i, j, a);
            symm2->symm_utm_set(j, i, a);
            break;
        case 3:
            printf("Enter row number: ");
            scanf("%d", &i);
            printf("Enter column number: ");
            scanf("%d", &j);
            printf("%d\n", symm1->symm_ltm_get(i, j));
            printf("%d\n", symm2->symm_utm_get(i, j));
       }
    } while (choice > 0 && choice < 4);
}

