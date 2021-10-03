#include<stdio.h>

struct Matrix
{
    int arr[10];
    int dim;
};

void utm_rowmajor_display(struct Matrix m)
{
    for(int i = 1; i <= m.dim; i++)
    {
        for(int j = 1; j <= m.dim; j++)
        {
            int index = (m.dim * (i-1) - (i-1)*(i-2)/2) + j - i;
            if (j>=i)
                printf("%d ", m.arr[index]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

void utm_rowmajor_set(struct Matrix *m, int i, int j, int a)
{
    if (j >= i)
    {
        int index = (m->dim * (i-1) - (i-1)*(i-2)/2) + j - i;
        m->arr[index] = a;
    }
}

int utm_rowmajor_get(struct Matrix m, int i, int j)
{
    if (j >= i)
    {
        int index = (m.dim * (i-1) - (i-1)*(i-2)/2) + j - i;
        return m.arr[index];
    }
    return 0;
}

void utm_colmajor_display(struct Matrix m)
{
    for(int i = 1; i <= m.dim; i++)
    {
        for(int j = 1; j <= m.dim; j++)
        {
            int index = (j * (j-1)/2) + i - 1;
            if (j>=i)
                printf("%d ", m.arr[index]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

void utm_colmajor_set(struct Matrix *m, int i, int j, int a)
{
    if (j >= i)
    {
        int index = (j * (j-1)/2) + i - 1;
        m->arr[index] = a;
    }
}

int utm_colmajor_get(struct Matrix m, int i, int j)
{
    if (j >= i)
    {
        int index = (j * (j-1)/2) + i - 1;
        return m.arr[index];
    }
    return 0;
}

int main()
{
    struct Matrix m1, m2;
    m1.dim = 3;
    m2.dim = 3;

    utm_rowmajor_set(&m1, 1, 1, 1);
    utm_rowmajor_set(&m1, 1, 2, 2);
    utm_rowmajor_set(&m1, 2, 2, 3);
    utm_rowmajor_set(&m1, 1, 3, 4);
    utm_rowmajor_set(&m1, 2, 3, 5);
    utm_rowmajor_set(&m1, 3, 3, 6);

    utm_colmajor_set(&m2, 1, 1, 1);
    utm_colmajor_set(&m2, 1, 2, 2);
    utm_colmajor_set(&m2, 2, 2, 3);
    utm_colmajor_set(&m2, 1, 3, 4);
    utm_colmajor_set(&m2, 2, 3, 5);
    utm_colmajor_set(&m2, 3, 3, 6);

    int element1 = utm_rowmajor_get(m1,2,2);
    int element2 = utm_rowmajor_get(m1,1,3);
    int element3 = utm_colmajor_get(m2,2,2);
    int element4 = utm_colmajor_get(m2,1,3);
    printf("%d\n", element1);
    printf("%d\n", element2);
    printf("%d\n", element3);
    printf("%d\n", element4);

    utm_rowmajor_display(m1);
    utm_colmajor_display(m2);
}
