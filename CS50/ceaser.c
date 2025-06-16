#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main (int argc, string argv[])
{
    if (argc != 2 )
    {
        printf("Usage: ./caesar key");
        return 1;
    }

    string key = argv[1];
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isdigit(key[i]))
        {
            printf ("Usage: ./caesar key");
            return 1;
        }
    }

    int k = atoi(key);

    string plaintext = get_string("plaintext:");
    int length = strlen(plaintext);
    char ciphertext[length + 1];
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {
            char caractere = isupper(plaintext[i]) ? 'A' : 'a' ;
            ciphertext[i] = (plaintext[i] - caractere + k ) % 26 + caractere;
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[length] = '\0';
    printf("ciphertext:%s\n", ciphertext);
    return 0;
}