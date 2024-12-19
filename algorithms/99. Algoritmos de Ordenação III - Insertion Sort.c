// Algoritmos de Ordenação - Insertion Sort

#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void sortearVetor(int vetor[]);
void imprimirVetor(int vetor[]);
void ordenarVetor(int vetor[]);

int main()
{
	int vetor[TAM];
	
	srand(time(NULL));
	
	sortearVetor(vetor);
	printf("Vetor Original = ");
	imprimirVetor(vetor);
	
	printf("\n\n");
	
	ordenarVetor(vetor);
	printf("Vetor Ordenado por Insertion Sort = ");
	imprimirVetor(vetor);
	
	printf("\n");
	
	return 0;
}

void sortearVetor(int vetor[])
{
	int i;
	
	for(i=0; i<TAM; i++)
	{
		vetor[i] = (rand() % 30) + 1;
	}
}

void imprimirVetor(int vetor[])
{
	int i;
	
	for(i=0; i<TAM; i++)
	{
		if(i == 0)
			printf("[%i, ", vetor[i]);
		else if(i == TAM-1)
			printf("%i]", vetor[i]);
		else
			printf("%i, ", vetor[i]);
		
	}
}

void ordenarVetor(int vetor[])
{
	int i, j, value;
	
	for(i=1; i<TAM; i++)
	{
		value = vetor[i];
		
		for(j=i-1; j>=0 && vetor[j] > value; j--)
		{
			vetor[j+1] = vetor[j];
		}
		
		vetor[j+1] = value;
	}
}
