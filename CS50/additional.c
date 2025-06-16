#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt userfor x
int x = get_int("x: ");

// Prompt userfor y
int y = get_int("y: ");

printf("%i\n", x + y);
}