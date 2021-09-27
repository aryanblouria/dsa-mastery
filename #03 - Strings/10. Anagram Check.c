#include<stdio.h>
#include<stdbool.h>

void anagram_check(char s[], char t[], int length)
{
    char r[26] = {0};
    bool anagram = true;
    for (int i = 0; i < length; i++)
        r[s[i]-97]++;
    for (int i = 0; i < length; i++)
        r[t[i]-97]--;
    for (int i = 0; i < 26; i++)
    {
        if (r[i] != 0)
        {
            printf("Not an anagram");
            anagram = false;
            break;
        }
    }
    if (anagram)
        printf("Anagram");
}

int main()
{
    char s[] = "rodney";
    char t[] = "yonder";

    int l = 0;
    while (s[l] != '\0')
        l++;

    anagram_check(s, t, l);
}
