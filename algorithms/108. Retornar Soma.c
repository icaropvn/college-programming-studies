/*
002 - Retornar Soma

=== Aula 02 - Exercício 01 ===

Criar uma função que recebe dois números inteiros
e retorna a soma deles.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int somar(int num1, int num2)
{
    int soma;
    soma = num1 + num2;
    return soma;
}

int main()
{
    int num1, num2, soma ;
    setlocale(LC_ALL, "Portuguese");
    
    printf("Insira um valor inteiro: ");
    scanf("%i", &num1);
    
    printf("Insira outro: ");
    scanf("%i", &num2);
    
    soma = somar(num1, num2);
    
    printf("\nA soma entre %i e %i é: %i\n", num1, num2, soma);
    
    return 0;
}


