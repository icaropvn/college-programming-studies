/*
004 - Procedimentos e Vetores

=== Aula 02, Exercício 05 ===

Criar um rocedimento que adiciona um valor a cada elemento
de um vetor, e outro para imprimir esee vetor.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 10

int menu()
{
    int answer ;
    printf("O que deseja fazer?\n1 - Adicionar\n2 - Imprimir\n3 - Sair\n");
    scanf("%i", &answer);
    
    return answer ;
}

void adicionar(int vetor[MAX], int contador)
{
    printf("\nValor para adicionar: ");
    scanf("%i", &vetor[contador]);
    printf("\n");
}

void imprimir(int vetor[10], int contador)
{
    int i;
    
	for(i=0; i<contador; i++)
    {
        if(i == contador-1)
            printf("%i", vetor[i]);
        else
            printf("%i, ", vetor[i]);
    }
}

int main()
{
    int vetor[10], contador = 0, answer ;
    setlocale(LC_ALL, "Portuguese");
    
    printf("MANIPULANDO UM VETOR\n\n");
    
    do
    {
        answer = menu();
        
        if(answer == 1)
        {
            adicionar(vetor, contador);
            contador++ ;
        }
        else if(answer == 2)
        {
            printf("\nVetor = [");
            imprimir(vetor, contador);
            printf("]\n\n");
        }
        else if(answer == 3)
            break ;
    } while(1);
    
    printf("\nAté mais!");
    
    return 0;
}
