#include<stdio.h>
#include<math.h>

struct Matrix
{
    int arr[10];
    int dim;
};

void triband_display(struct Matrix m)
{
    for(int i = 1; i <= m.dim; i++)
    {
        for(int j = 1; j <= m.dim; j++)
        {
            int n = m.dim;
            if (i - j == 1)
                printf("%d ", m.arr[i-2]);
            else if (i - j == 0)
                printf("%d ", m.arr[n - 1 + i - 1]);
            else if (i - j == -1)
                printf("%d ", m.arr[n - 1 + n + i - 1]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

void triband_set(struct Matrix *m, int i, int j, int a)
{
    int n = m->dim;
    if (i - j == 1)
        m->arr[i-2] = a;
    else if (i - j == 0)
        m->arr[n - 1 + i - 1] = a;
    else if (i - j == -1)
        m->arr[n - 1 + n + i - 1] = a;
}

int triband_get(struct Matrix m, int i, int j)
{
    int n = m.dim;
    if (i - j == 1)
        return m.arr[i-2];
    else if (i - j == 0)
        return m.arr[n-1+i-1];
    else if (i - j == -1)
        return m.arr[n-1+n+i-1];
    else
        return 0;
}

int main()
{
    struct Matrix m;
    m.dim = 3;

    triband_set(&m, 1, 1, 3);
    triband_set(&m, 2, 2, 5);
    triband_set(&m, 3, 3, 7);
    triband_set(&m, 2, 1, 2);
    triband_set(&m, 3, 2, 4);
    triband_set(&m, 1, 2, 2);
    triband_set(&m, 2, 3, 4);

    int element1 = triband_get(m,2,2);
    int element2 = triband_get(m,3,1);
    printf("%d\n", element1);
    printf("%d\n", element2);

    triband_display(m);
}
