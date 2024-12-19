// Algoritmos de Ordenação - Selection Sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
	printf("Vetor Ordenado por Selection Sort = ");
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
	int i, j;
	int index_menor;
	int aux;
	
	for(i=0; i<TAM; i++)
	{
		// Encontrar o menor número
		
		index_menor = i;
		
		for(j=i+1; j<TAM; j++)
		{
			if(vetor[j] < vetor[index_menor])
				index_menor = j;
		}
		
		// Substituir valor caso o valor atual seja maior que o encontrado anteriormente
		if(vetor[i] > vetor[index_menor])
		{
			aux = vetor[i];
			vetor[i] = vetor[index_menor];
			vetor[index_menor] = aux;
		}
	}
}
