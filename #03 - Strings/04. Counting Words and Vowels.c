#include <stdio.h>

int main()
{
    char s[] = "My name is Aryan Blouria";
    int words = 1, vowels = 0, consonants = 0, i = 0;

    while (s[i] != '\0')
    {
        if (s[i] == ' ')
        {
            if (s[i-1] != ' ')
                words++;
        }
        else if (s[i] == 'A' || s[i] == 'a' || s[i] == 'E' || s[i] == 'e' || s[i] == 'I' || s[i] == 'i' || s[i] == 'O' || s[i] == 'o' || s[i] == 'U' || s[i] == 'u')
            vowels++;
        else if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
            consonants++;
        i++;
    }

    printf("No. of words: %d\n", words);
    printf("No. of vowels: %d\n", vowels);
    printf("No. of consonants: %d\n", consonants);
}
