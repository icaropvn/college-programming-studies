/*
020 - Multiplicação Escalar x Vetor

Crie um procedimento que faça a multiplicação
de um escalar qualquer em um vetor de inteiros.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define TAM 10

void preencher_vetor_random(int vetor[], int vet_original[]);
void multiplicar_vetor(int vetor[], int escalar);
void imprimir_vetor(int vetor[]);

int main()
{
	int vetor[TAM], vet_original[TAM] ;
	int escalar ;
	
	setlocale(LC_ALL, "Portuguese");
	srand((unsigned)time(NULL));
	
	preencher_vetor_random(vetor, vet_original);
	
	printf("Insira um número para multiplicar o vetor por: ");
	scanf("%i", &escalar);
	
	multiplicar_vetor(vetor, escalar);
	
	printf("\nVetor Original = [");
	imprimir_vetor(vet_original);
	
	printf("\nVetor Multiplicado = [");
	imprimir_vetor(vetor);
	
	printf("\n");
	
	return 0;
}

void preencher_vetor_random(int vetor[], int vet_original[])
{
	int i;
	
	for(i=0; i<TAM; i++)
	{
		vetor[i] = 1 + (rand() % 10) ;
		vet_original[i] = vetor[i] ;
	}
}

void multiplicar_vetor(int vetor[], int escalar)
{
	int i ;
	
	for(i=0; i<TAM; i++)
		vetor[i] = escalar * vetor[i] ;
}

void imprimir_vetor(int vetor[])
{
	int i;
	
	for(i=0; i<TAM; i++)
	{
		if(i == TAM-1)
			printf("%i]", vetor[i]);
		else
			printf("%i, ", vetor[i]);
	}
}
