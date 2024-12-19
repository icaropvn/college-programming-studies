/*
008 - Oposto de um número (referência)

=== Aula 02, Exercício 07 ===

Criar procedimento que troque o sinal de um número.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void negativar(int *num);

int main()
{
    int num ;
    
    setlocale(LC_ALL, "Portuguese");
    
    printf("Insira um valor para obter seu oposto: ");
    scanf("%i", &num);
    
    printf("\nO oposto de %i é ", num);
    
    negativar(&num);
    
    printf("%i", num);
    
    return 0;
}

void negativar(int *num)
{
    *num = *num * -1 ;
}

