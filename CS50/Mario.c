#include <cs50.h>
#include <stdio.h>

int main(void)
{
      // Get positive integer from user
      int n;
      do
      {
            n = get_int("width: ");
      }
      while (n<1);

      //Print out that many question marks
      for (int i = 0; i < n; i++)
      {
            printf("?");
      }
      printf("\n");
}