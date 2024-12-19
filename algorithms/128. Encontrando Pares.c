/*
022 - Encontrando Pares

Crie um função que receba como parâmetro um vetor
de inteiros de tamanho qualquer e retorne um valor
verdade caso mais de 50% do vetor contenha números pares.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 20

void preencher(int vetor[]);
void imprimir(int vetor[]);
int verificar_pares(int vetor[]);

int main()
{
	int vetor[TAM];
	
	setlocale(LC_ALL, "Portuguese");
	srand((unsigned)time(NULL));
	
	preencher(vetor);
	
	printf("Vetor Sorteado = [");
	imprimir(vetor);
	
	if(verificar_pares(vetor) == 1)
		printf("\n\nO vetor possui mais de 50%% de elementos pares!\n");
	else
		printf("\n\nO vetor é majoritariamente ímpar.\n");
	
	return 0;
}

void preencher(int vetor[])
{
	int i;
	
	for(i=0; i<TAM; i++)
		vetor[i] = 1 + (rand() % 10);
}

void imprimir(int vetor[])
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

int verificar_pares(int vetor[])
{
	int i, contador = 0 ;
	
	for(i=0; i<TAM; i++)
	{
		if(vetor[i] % 2 == 0)
			contador++ ;
		
		if(contador > TAM/2)
			return 1;
	}
	
	return 0;
}
