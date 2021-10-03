#include<stdio.h>

struct Matrix
{
    int arr[10];
    int dim;
};

void symm_ltm_display(struct Matrix m)
{
    for(int i = 1; i <= m.dim; i++)
    {
        for(int j = 1; j <= m.dim; j++)
        {
            if (i >= j)
                printf("%d ", m.arr[(i * (i-1)/2) + j - 1]);
            else
                printf("%d ", m.arr[(j * (j-1)/2) + i - 1]);
        }
        printf("\n");
    }
}

void symm_ltm_set(struct Matrix *m, int i, int j, int a)
{
    m->arr[(i * (i-1)/2) + j - 1] = a;
}

int symm_ltm_get(struct Matrix m, int i, int j)
{
    return m.arr[(i * (i-1)/2) + j - 1];
}

void symm_utm_display(struct Matrix m)
{
    for(int i = 1; i <= m.dim; i++)
    {
        for(int j = 1; j <= m.dim; j++)
        {
            if (j >= i)
                printf("%d ", m.arr[(j * (j-1)/2) + i - 1]);
            else
                printf("%d ", m.arr[(i * (i-1)/2 + j - 1)]);
        }
        printf("\n");
    }
}

void symm_utm_set(struct Matrix *m, int i, int j, int a)
{
    m->arr[(j * (j-1)/2) + i - 1] = a;
}

int symm_utm_get(struct Matrix m, int i, int j)
{
    return m.arr[(j * (j-1)/2) + i - 1];
}

int main()
{
    struct Matrix m1, m2;
    m1.dim = 3;
    m2.dim = 3;

    symm_ltm_set(&m1, 1, 1, 1);
    symm_ltm_set(&m1, 2, 1, 2);
    symm_ltm_set(&m1, 2, 2, 3);
    symm_ltm_set(&m1, 3, 1, 4);
    symm_ltm_set(&m1, 3, 2, 5);
    symm_ltm_set(&m1, 3, 3, 6);

    symm_utm_set(&m2, 1, 1, 1);
    symm_utm_set(&m2, 1, 2, 2);
    symm_utm_set(&m2, 2, 2, 3);
    symm_utm_set(&m2, 1, 3, 4);
    symm_utm_set(&m2, 2, 3, 5);
    symm_utm_set(&m2, 3, 3, 6);

    int element1 = symm_ltm_get(m1,2,2);
    int element2 = symm_ltm_get(m1,3,1);
    int element3 = symm_utm_get(m2,2,2);
    int element4 = symm_utm_get(m2,1,3);
    printf("%d\n", element1);
    printf("%d\n", element2);
    printf("%d\n", element3);
    printf("%d\n", element4);

    symm_ltm_display(m1);
    symm_utm_display(m2);
}

