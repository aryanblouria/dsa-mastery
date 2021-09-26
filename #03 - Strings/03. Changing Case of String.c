#include<stdio.h>

int main()
{
    char s[] = "Aryan Blouria";
    int i = 0;

    while (s[i] != '\0')
    {
        if (s[i] <= 90 && s[i] >= 65)
            s[i] += 32;
        else if (s[i] <= 122 && s[i] >= 97)
            s[i] -= 32;
        i++;
    }

    printf("%s", s);
}
