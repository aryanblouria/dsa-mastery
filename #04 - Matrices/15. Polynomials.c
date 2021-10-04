#include<stdio.h>
#include<math.h>

struct Term
{
    int coeff;
    int exp;
};

struct Polynomial
{
    int n;
    struct Term *terms;
};

void create(struct Polynomial *p)
{
    printf("Enter no. of terms: ");
    scanf("%d", &p->n);

    printf("Enter the terms: \n");
    p->terms = (struct Term*)malloc(p->n*sizeof(struct Term*));
    for (int i = 0; i < p->n; i++)
        scanf("%d %d", &p->terms[i].coeff, &p->terms[i].exp);
}

void display(struct Polynomial p)
{
    for (int i = 0; i < p.n; i++)
    {
        if (i == p.n-1)
            printf("%dx^%d", p.terms[i].coeff, p.terms[i].exp);
        else
            printf("%dx^%d + ", p.terms[i].coeff, p.terms[i].exp);
    }
    printf("\n");
}

struct Polynomial *add(struct Polynomial *p1, struct Polynomial *p2)
{
    struct Polynomial *sum;
    int max_size = p1->n + p2->n;
    sum = (struct Polynomial*)malloc(sizeof(struct Polynomial));
    sum->terms = (struct Term*)malloc(max_size * sizeof(struct Term));

    int i = 0, j = 0, k = 0;
    while (i < p1->n && j < p2->n)
    {
        if (p1->terms[i].exp > p2->terms[j].exp)
            sum->terms[k++] = p1->terms[i++];
        else if (p1->terms[i].exp < p2->terms[j].exp)
            sum->terms[k++] = p1->terms[j++];
        else
        {
            sum->terms[k].exp = p1->terms[i].exp;
            sum->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff;
        }
    }

    for (; i < p1->n; i++)
        sum->terms[k++] = p1->terms[i];
    for (; j < p2->n; j++)
        sum->terms[k++] = p2->terms[j];

    sum->n = k;
    return sum;
}

int evaluate(struct Polynomial p, int x)
{
    int sum = 0;
    for (int i = 0; i < p.n; i++)
        sum += p.terms[i].coeff * pow(x, p.terms[i].exp);
    return sum;
}

int main()
{
    struct Polynomial p1, p2, *p3;
    int value = 0;

    create(&p1);
    create(&p2);

    p3 = add(&p1, &p2);
    display(*p3);

    value = evaluate(*p3, 1);
    printf("%d", value);
}
