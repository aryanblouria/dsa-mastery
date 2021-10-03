#include<stdio.h>

struct Matrix
{
    int arr[10];
    int dim;
};

void toeplitz_display(struct Matrix m)
{
    for(int i = 1; i <= m.dim; i++)
    {
        for(int j = 1; j <= m.dim; j++)
        {
            int n = m.dim;
            if (i <= j)
                printf("%d ", m.arr[j-i]);
            else
                printf("%d ", m.arr[n+i-j-1]);
        }
        printf("\n");
    }
}

void toeplitz_set(struct Matrix *m, int i, int j, int a)
{
    int n = m->dim;
    if (i <= j)
        m->arr[j-i] = a;
    else
        m->arr[n+i-j-1] = a;
}

int toeplitz_get(struct Matrix m, int i, int j)
{
    int n = m.dim;
    if (i <= j)
        return m.arr[j-i];
    else
        return m.arr[n+i-j-1];
}

int main()
{
    struct Matrix m;
    m.dim = 3;

    toeplitz_set(&m, 1, 2, 2);
    toeplitz_set(&m, 1, 3, 1);
    toeplitz_set(&m, 2, 2, 3);
    toeplitz_set(&m, 3, 1, 5);
    toeplitz_set(&m, 3, 2, 4);

    int element1 = toeplitz_get(m,2,2);
    int element2 = toeplitz_get(m,3,1);
    printf("%d\n", element1);
    printf("%d\n", element2);

    toeplitz_display(m);
}
