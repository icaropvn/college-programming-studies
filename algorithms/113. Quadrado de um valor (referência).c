/*
007 - Quadrado de um valor (referência)

=== Aula 02, Exercício 03 ===

Criar procedimento que modifica o valor de um número para seu quadrado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

void elevar(int *num);

int main()
{
    int num, original_num ;
    
    setlocale(LC_ALL, "Portuguese");
    
    printf("Insira um número para calcular seu quadrado: ");
    scanf("%i", &num);
    
    original_num = num ;
    elevar(&num);
    
    printf("\n%i ao quadrado é: %i", original_num, num);
    
    return 0;
}

void elevar(int *num)
{
    *num = pow(*num, 2) ;
}

