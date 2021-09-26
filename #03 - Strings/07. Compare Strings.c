#include<stdio.h>
#include<stdbool.h>

int main()
{
    char s1[] = "Aryan";
    char s2[] = "Arjan";
    bool equal = true;

    for (int i = 0; (s1[i] != '\0') && (s2[i] != '\0'); i++)
        if (s1[i] != s2[i])
        {
            equal = false;
            if (s1[i] < s2[i])
                printf("S1 smaller than S2");
            else
                printf("S1 greater than S2");
            break;
        }

    if (equal)
        printf("S1 equal to S2");
}

