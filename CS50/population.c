#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int pop_inicial;
    int pop_final;
    do{
         pop_inicial = get_int("Start Size:");
    }while(pop_inicial < 9);



    do{
         pop_final = get_int("End Size:");
    }while(pop_final < pop_inicial);




    int cont = 0;
    for(cont = 0; pop_inicial < pop_final ; cont++){
        int pop_nascida = pop_inicial / 3;
        int pop_morta = pop_inicial / 4;

        pop_inicial += pop_nascida;
        pop_inicial -= pop_morta;
    }
    printf("Years: %i",cont);
}