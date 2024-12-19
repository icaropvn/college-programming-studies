/*
006 - Trocando Valores (referência)

=== Aula 02, Exercício 02 ===

Criar procedimento que troca os valores de duas variáveis.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void trocar(int *a, int *b);

int main()
{
    int num1, num2 ;
    
    setlocale(LC_ALL, "Portuguese");
    
    printf("Insira um valor: ");
    scanf("%i", &num1);
    
    printf("Insira outro valor: ");
    scanf("%i", &num2);
    
    printf("\nValores iniciais:\nValor 01 - %i\nValor 02 - %i", num1, num2);
    
    trocar(&num1, &num2);
    
    printf("\n\nValores trocados:\nValor 01 - %i\nValor 02 - %i\n", num1, num2);
    
    return 0;
}

void trocar(int *a, int *b)
{
    int temp ;
    
    temp = *a ;
    *a = *b ;
    *b = temp ;
}
