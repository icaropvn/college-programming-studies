/*
012 - Somatória

Escreva uma função que receba um número inteiro positivo e retorne o
somatório dos números entre 0 e o número passado. Exemplo: Caso o
parâmetro seja 3, o resultado deverá ser a soma de 0 + 1 + 2 + 3 = 6.
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int somar(int num);

int main()
{
    int num, somatoria ;
    
    setlocale(LC_ALL, "Portuguese");
    
    printf("Insira um valor: ");
    scanf("%i", &num);
    
    printf("\n");
    
    somatoria = somar(num);
    
    printf(" = %i", somatoria);
    
    return 0;
}

int somar(int num)
{
    int i, soma = 0;
    
    for(i=0; i<=num; i++)
    {
        soma = soma + i;
        if(i == num)
            printf("%i", i);
        else
            printf("%i + ", i);
    }
    
    return soma;
}
