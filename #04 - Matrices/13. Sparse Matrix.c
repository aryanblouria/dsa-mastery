#include<stdio.h>

struct Element
{
    int i;
    int j;
    int x;
};

struct Sparse
{
    int rows;
    int columns;
    int n;
    struct Element *e;
};

 void create(struct Sparse *s)
 {
     printf("Enter dimensions: ");
     scanf("%d %d", &s->rows, &s->columns);

     printf("Enter no. of non-zero elements: ");
     scanf("%d", &s->n);

     s->e = (struct Element*)malloc(s->n * sizeof(struct Element));

     printf("Enter all elements: \n");
     for (int i = 0; i < s->n; i++)
        scanf("%d %d %d", &s->e[i].i, &s->e[i].j, &s->e[i].x);
 }

 void display(struct Sparse s)
 {
    int k = 0;
    for (int i = 0; i < s.rows; i++)
    {
        for (int j = 0; j < s.columns; j++)
        {
            if (i == s.e[k].i && j == s.e[k].j)
                printf("%d ", s.e[k++].x);
            else
                printf("0 ");
        }
        printf("\n");
    }
 }

 struct Sparse *add(struct Sparse *s1, struct Sparse *s2)
 {
     if (s1->rows == s2->rows && s1->columns == s2->columns)
     {
         int max_size = s1->n + s2->n;
         struct Sparse *s3 = (struct Sparse*)malloc(sizeof(struct Sparse));
         s3->e = (struct Element*)malloc(max_size * sizeof(struct Element));

         int i = 0, j = 0, k = 0;
         while (i < s1->n && j < s2->n)
            {
                if (s1->e[i].i < s2->e[j].i)
                    s3->e[k++] = s1->e[i++];
                else if (s1->e[i].i > s2->e[j].i)
                    s3->e[k++] = s2->e[j++];
                else
                {
                    if (s1->e[i].j < s2->e[j].j)
                        s3->e[k++] = s1->e[i++];
                    else if (s1->e[i].j > s2->e[j].j)
                        s3->e[k++] = s2->e[j++];
                    else
                    {
                        s3->e[k] = s1->e[i];
                        s3->e[k++].x = s1->e[i++].x + s2->e[j++].x;
                    }
                }
            }
         for(; i < s1->n; i++)
            s3->e[k++] = s1->e[i];
         for(; j < s2->n; j++)
            s3->e[k++] = s2->e[j];
         s3->rows = s1->rows;
         s3->columns = s1->columns;
         s3->n = k;
         return s3;
      }
 }

 int main()
{
    struct Sparse s1, s2, *s3;
    create(&s1);
    create(&s2);
    s3 = add(&s1, &s2);

    printf("S1: \n");
    display(s1);
    printf("S2: \n");
    display(s2);
    printf("S3: \n");
    display(*s3);
}

