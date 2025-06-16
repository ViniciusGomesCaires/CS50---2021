#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float troco;
    float restante;
    int nummoedas = 0;

    do
    {
        troco = get_float("Insira o valor devido: ");
    }while (troco <0);

    restante = troco*100;

    while(restante>0)
    {
        if(restante>=25)
        {
            restante = restante - 25;
            nummoedas++;
        }
        else if(restante>=10)
        {
            restante = restante - 10;
            nummoedas++;
        }
        else if(restante>=5)
        {
        restante = restante -5;
        nummoedas++;
        }
    }
    printf("\n Numero minimo de moedas: %i\n",nummoedas);
}