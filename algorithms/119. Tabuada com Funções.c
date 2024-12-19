/*
013 - Tabuada com Funções

Escreva um procedimento que exiba na tela a tabuada do número
passado por parâmetro.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void imprimir_tabuada(int num);

int main()
{
    int num ;
    
    setlocale(LC_ALL, "Portuguese");
    
    printf("Insira um número: ");
    scanf("%i", &num);
    
    imprimir_tabuada(num);
    
    printf("\n");
    
    return 0;
}

void imprimir_tabuada(int num)
{
    int i ;

    for(i=1; i<=10; i++)
    {
        printf("\n%2.i * %2.i = %2.i", num, i, num*i);
    }
}
