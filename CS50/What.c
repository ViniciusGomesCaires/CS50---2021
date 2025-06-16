#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string answer = get_string("Qual é o seu nome? ");
    printf("Olá, %s\n", answer);
}