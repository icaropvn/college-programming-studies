/*
009 - Cubos e Quadrados (referência)

=== Aula 02, Exercício 08 ===

Criar procedimento que calcula e devolva
o quadrado e o cubo de um número.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

void elevar(int *sqr, int *cube);

int main()
{
    int num[3] ;
    
    setlocale(LC_ALL, "Portuguese");
    
    printf("Insira um valor: ");
    scanf("%i", &num[0]);
    
    num[1] = num[0];
    num[2] = num[1];
    
    elevar(&num[1], &num[2]);
    
    printf("\n%i^2 = %i\n%i^3 = %i", num[0], num[1], num[0], num[2]);
    
    return 0;
}

void elevar(int *sqr, int *cube)
{
    *sqr = pow(*sqr, 2);
    *cube = pow(*cube, 3);
}

