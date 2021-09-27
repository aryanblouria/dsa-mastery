#include<stdio.h>

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permutations1(char s[], int k)
{
    static int r[4] = {0};
    static char p[4];

    if (s[k] == '\0')
    {
        p[k] = '\0';
        for (int i = 0; p[i] != '\0'; i++)
            printf("%c", p[i]);
        printf("\n");
    }
    else
    {
        for (int i = 0; s[i] != '\0'; i++)
        {
            if (r[i]==0)
            {
                p[k] = s[i];
                r[i]++;
                permutations1(s, k+1);
                r[i]--;
            }
        }
    }
}

void permutations2(char s[], int l, int h)
{
    if (l == h)
    {
        for (int i = 0; s[i] != '\0'; i++)
            printf("%c", s[i]);
        printf("\n");
    }
    else
    {
        for (int i = l; i <= h; i++)
        {
            swap(&s[l],&s[i]);
            permutations2(s, l+1, h);
            swap(&s[l], &s[i]);
        }
    }
}

int main()
{
    char s[] = "BLO";
    int k = 0;
    permutations1(s,k);
    printf("\n\n");
    permutations2(s, 0, 2);
}
