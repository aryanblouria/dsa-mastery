#include<stdio.h>

struct Matrix
{
    int arr[10];
    int dim;
};

void ltm_rowmajor_display(struct Matrix m)
{
    for(int i = 1; i <= m.dim; i++)
    {
        for(int j = 1; j <= m.dim; j++)
        {
            int index = (i * (i-1)/2) + j - 1;
            if (i>=j)
                printf("%d ", m.arr[index]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

void ltm_rowmajor_set(struct Matrix *m, int i, int j, int a)
{
    if (i >= j)
    {
        int index = (i * (i-1)/2) + j - 1;
        m->arr[index] = a;
    }
}

int ltm_rowmajor_get(struct Matrix m, int i, int j)
{
    if (i >= j)
    {
        int index = (i * (i-1)/2) + j - 1;
        return m.arr[index];
    }
    return 0;
}

void ltm_colmajor_display(struct Matrix m)
{
    for(int i = 1; i <= m.dim; i++)
    {
        for(int j = 1; j <= m.dim; j++)
        {
            int index = (m.dim * (j-1) - (j-1)*(j-2)/2) + i - j;
            if (i>=j)
                printf("%d ", m.arr[index]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

void ltm_colmajor_set(struct Matrix *m, int i, int j, int a)
{
    if (i >= j)
    {
        int index = (m->dim * (j-1) - (j-1)*(j-2)/2) + i - j;
        m->arr[index] = a;
    }
}

int ltm_colmajor_get(struct Matrix m, int i, int j)
{
    if (i >= j)
    {
        int index = (m.dim * (j-1) - (j-1)*(j-2)/2) + i - j;
        return m.arr[index];
    }
    return 0;
}

int main()
{
    struct Matrix m1, m2;
    m1.dim = 3;
    m2.dim = 3;

    ltm_rowmajor_set(&m1, 1, 1, 1);
    ltm_rowmajor_set(&m1, 2, 1, 2);
    ltm_rowmajor_set(&m1, 2, 2, 3);
    ltm_rowmajor_set(&m1, 3, 1, 4);
    ltm_rowmajor_set(&m1, 3, 2, 5);
    ltm_rowmajor_set(&m1, 3, 3, 6);

    ltm_colmajor_set(&m2, 1, 1, 1);
    ltm_colmajor_set(&m2, 2, 1, 2);
    ltm_colmajor_set(&m2, 2, 2, 3);
    ltm_colmajor_set(&m2, 3, 1, 4);
    ltm_colmajor_set(&m2, 3, 2, 5);
    ltm_colmajor_set(&m2, 3, 3, 6);

    int element1 = ltm_rowmajor_get(m1,2,2);
    int element2 = ltm_rowmajor_get(m1,3,1);
    int element3 = ltm_colmajor_get(m2,2,2);
    int element4 = ltm_colmajor_get(m2,3,1);
    printf("%d\n", element1);
    printf("%d\n", element2);
    printf("%d\n", element3);
    printf("%d\n", element4);

    ltm_rowmajor_display(m1);
    ltm_colmajor_display(m2);
}

