#include<stdio.h>

int main()
{
    char name1[] = {'A', 'r', 'y', 'a', 'n', '\0'};
    printf("%s", name1);

    char name2[] = "Aryan";
    printf("%s", name2);

    char *name3 = "Aryan";
    printf("%s", name3);
}
