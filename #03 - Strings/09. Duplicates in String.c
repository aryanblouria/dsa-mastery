#include<stdio.h>

int max(char* s, int length)
{
    int m = s[0];
    for (int i = 1; i < length; i++)
    {
        if (s[i] > m)
            m = s[i];
    }
    return m;
}

void duplicate1(char s[], int length)
{
    for (int i = 0; i < length; i++)
    {
        int count = 0;
        for(int j = 0; j < length; j++)
            if (s[i] == s[j])
                count++;

        if (count > 1)
            printf("%c has %d duplicates.\n", s[i], count-1);
        else
            printf("%c has no duplicates.\n", s[i]);
    }
}

void duplicate2(char s[], int length)
{
    int hashlength = max(s, length)-97;
    int *t = (int*)malloc(hashlength*sizeof(int));
    for (int i = 0; i <= hashlength; i++)
        t[i] = 0;
    for (int i = 0; i < length; i++)
    {
        int temp = s[i] - 97;
        t[temp]++;
    }
    for (int i = 0; i <= hashlength; i++)
        if (t[i] > 0)
            printf("Count of %c is %d\n", i+97, t[i]);
}

void duplicate3(char s[], int length)
{
    int h = 0;
    for (int i = 0; i < length; i++)
    {
        int b = 1;
        b = b << s[i] - 97;
        if ((b & h) != 0)
            printf("%c is duplicated.", s[i]);
        else
            h = b | h;
    }
}

int main()
{
    char s[] = "abracadabra";
    int l = 0;
    while (s[l] != '\0')
        l++;

    int length = l;
    duplicate1(s, length);
    duplicate2(s, length);
    duplicate3(s, length);

}
