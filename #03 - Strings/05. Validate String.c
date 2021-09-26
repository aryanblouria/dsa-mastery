#include<stdio.h>
#include<stdbool.h>

int main()
{
    char s[] = "My n@me !$ Ary&n Blo%ria";
    bool valid = true;

    int i = 0;

    while (s[i] != '\0')
    {
        if (!((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57) || s[i] == ' '))
        {
            valid = false;
            break;
        }
        i++;
    }

    if (valid)
        printf("Valid string");
    else
        printf("Invalid string");
}
