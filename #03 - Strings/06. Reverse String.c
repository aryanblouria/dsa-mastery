#include<stdio.h>

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

char* reverse1(char s[], int length)
{
    char t[length];
    int i = 0;

    while (s[i] != '\0')
    {
        t[i]= s[length - i - 1];
        i++;
    }
    t[length] = '\0';


    i = 0;
    while (t[i] != '\0')
    {
        s[i] = t[i];
        i++;
    }

    return s;
}

void reverse2(char s[], int length)
{
    for (int i = 0, j = length-1; i < j; i++, j--)
        swap(&s[i], &s[j]);
}

int main()
{
    char s[] = "My name is Aryan Blouria";
    int i = 0, length = 0;

    while (s[i] != '\0')
        i++;

    length = i;
    printf("%s\n", reverse1(s, length));
    reverse2(s, length);
    printf("%s\n", s);
}
