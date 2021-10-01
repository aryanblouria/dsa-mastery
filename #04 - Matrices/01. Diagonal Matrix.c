#include<stdio.h>

struct Matrix
{
    int arr[10];
    int dim;
};

void diag_display(struct Matrix m)
{
    for(int i = 0; i < m.dim; i++)
    {
        for(int j = 0; j < m.dim; j++)
        {
            if (i==j)
                printf("%d ", m.arr[i]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

void diag_set(struct Matrix *m, int i, int j, int a)
{
    if (i == j)
        m->arr[i-1] = a;
}

int diag_get(struct Matrix m, int i, int j)
{
    if (i == j)
        return m.arr[i-1];
    return 0;
}

int main()
{
    struct Matrix m;
    m.dim = 3;

    diag_set(&m, 1, 1, 3);
    diag_set(&m, 2, 2, 5);
    diag_set(&m, 3, 3, 7);

    int element1 = diag_get(m,2,2);
    int element2 = diag_get(m,3,1);
    printf("%d\n", element1);
    printf("%d\n", element2);

    diag_display(m);
}
