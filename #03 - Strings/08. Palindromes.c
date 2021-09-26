#include<stdio.h>
#include<stdbool.h>

void palindrome1(char s[], int length)
{
    bool palindrome = true;
    for (int i = 0, j = length-1; i < j; i++, j--)
        if (s[i]!= s[j])
        {
            printf("Not palindrome.\n");
            palindrome = false;
            break;
        }

    if (palindrome)
        printf("Palindrome.\n");
}

void palindrome2(char s[], int length)
{
    char t[length];
    bool palindrome = true;
    for (int i = 0; i < length; i++)
        t[i] = s[length - i - 1];
    for (int i = 0; s[i] != '\0' && t[i] != '\0'; i++)
        if (s[i] != t[i])
        {
            printf("Not palindrome.\n");
            palindrome = false;
            break;
        }

    if (palindrome)
        printf("Palindrome.\n");
}


int main()
{
    char s[] = "wasitacaroracatisaw";

    int l = 0;
    while (s[l] != '\0')
        l++;

    int length = l;
    palindrome1(s, length);
    palindrome2(s, length);
}
