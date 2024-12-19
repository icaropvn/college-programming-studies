#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "FuncoesOrdenacao.h"

void printVetor(int vetor[]);

int main()
{
	int i;
	
	// Vetores para Teste
	int random[30];
	int sorted[30] = {1, 2, 4, 6, 7, 9, 12, 13, 16, 18, 24, 26, 29, 31, 34, 37, 38, 40, 42, 43, 48, 54, 57, 61, 65, 69, 77, 81, 99, 112};
	int inversed[30] = {112, 99, 81, 77, 69, 65, 61, 57, 54, 48, 43, 42, 40, 38, 37, 34, 31, 29, 26, 24, 18, 16, 13, 12, 9, 7, 6, 4, 2, 1};
	int repeated[30] = {3, 3, 3, 3, 5, 6, 6, 6, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 5, 5, 5, 8, 8, 10, 71, 71, 71, 10, 10, 8};
	
	// Rand Seed
	srand(time(NULL));
	
	// Alimentando Vetor "random"
	for(i=0; i<30; i++)
	{
		random[i] = rand() % 101;
	}
	
	// Testando Bubble Sort
	bubbleSort(repeated, 30);
	printVetor(repeated);
	printf("\n");
	
	// Testando Selection Sort
	selectionSort(inversed, 30);
	printVetor(inversed);
	printf("\n");
	
	// Testando Insertion Sort
	insertionSort(random, 30);
	printVetor(random);
	printf("\n");
	
	return 0;
}

void printVetor(int vetor[])
{
	int i;
	
	for(i=0; i<30; i++)
	{
		if(i == 0)
			printf("[%i, ", vetor[i]);
		else if(i == 30-1)
			printf("%i]", vetor[i]);
		else
			printf("%i, ", vetor[i]);
	}
}
