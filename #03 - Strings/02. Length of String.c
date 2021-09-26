#include<stdio.h>

int main()
{
    char *s = "Hey Aryan";
    int i = 0, length = 0;

    while (s[i] != '\0')
        i++;

    length = i;

    printf("Length of the string is %d", length);
}
