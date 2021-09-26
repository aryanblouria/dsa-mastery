#include<stdio.h>
#include<stdbool.h>

int main()
{
    char s1[] = "Aryan";
    char s2[] = "Arjan";
    bool equal = true;

    for (int i = 0, j = 0; (s1[i] != '\0') && (s2[j] != '\0'); i++, j++)
        if (s1[i] != s2[j])
        {
            equal = false;
            if (s1[i] < s2[j])
                printf("S1 smaller than S2");
            else
                printf("S1 greater than S2");
            break;
        }

    if (equal)
        printf("S1 equal to S2");
}

