// Busca Binária de forma Recursiva

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define TAM 10

void sortearVetor(int vetor[]);
void imprimirVetor(int vetor[]);
void ordenarVetor(int vetor[]);
int buscarVetor(int chave, int vetor[], int inicio, int fim);

int main()
{
	int vetor[TAM];
	int chave;
	int busca;
	
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	sortearVetor(vetor);
	
	ordenarVetor(vetor);
	printf("Vetor = [");
	imprimirVetor(vetor);
	
	printf("\n\nInsira um número para buscar no vetor: ");
	scanf("%i", &chave);
	
	busca = buscarVetor(chave, vetor, 0, TAM);
	
	if(busca == -1)
		printf("\nO elemento não se encontra no vetor.\n");
	else
		printf("\nO elemento está no índice %i do vetor.\n", busca);
	
	return 0;
}

void sortearVetor(int vetor[])
{
	int i;
	
	for(i=0; i<TAM; i++)
		vetor[i] = (rand() % 30) + 1;
}

void imprimirVetor(int vetor[])
{
	int i;
	
	for(i=0; i<TAM; i++)
	{
		if(i == 0)
			printf("%i, ", vetor[i]);
		else if(i == TAM-1)
			printf("%i]", vetor[i]);
		else
			printf("%i, ", vetor[i]);
	}
}

void ordenarVetor(int vetor[])
{
	int i, j;
	int aux;
	
	for(i=0; i<TAM; i++)
	{
		for(j=i+1; j<TAM; j++)
		{
			if(vetor[j] < vetor[i])
			{
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}
		}
	}
}

int buscarVetor(int chave, int vetor[], int inicio, int fim)
{
	int meio;
	
	if(inicio <= fim)
	{
		meio = (inicio + fim) / 2;
		
		if(chave == vetor[meio])
			return meio;
		else
		{
			if(chave < vetor[meio])
				return buscarVetor(chave, vetor, inicio, meio - 1);
			else
				return buscarVetor(chave, vetor, meio + 1, fim);
		}
	}
	else
		return -1;
}
