// Algoritmos de Ordenação - Bubble Sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void sortear_vetor(int vetor[]);
void imprimir(int vetor[]);
void ordenar_vetor(int vetor[]);

int main()
{
	int vetor[10];
	
	srand(time(NULL));
	
	printf("Vetor Sorteado = [");
	sortear_vetor(vetor);
	imprimir(vetor);
	
	printf("\n\n");
	
	printf("Vetor Ordenado = [");
	ordenar_vetor(vetor);
	imprimir(vetor);
	
	printf("\n");
	
	return 0;
}

void sortear_vetor(int vetor[])
{
	int i;
	
	for(i=0; i<10; i++)
	{
		vetor[i] = (rand() % 15) + 1;
	}
}

void imprimir(int vetor[])
{
	int i;
	
	for(i=0; i<10; i++)
	{
		if(i == 0)
			printf("%i, ", vetor[i]);
		else if(i == 9)
			printf("%i]", vetor[i]);
		else
			printf("%i, ", vetor[i]);
	}
}

void ordenar_vetor(int vetor[])
{
	int i, j;
	int aux;
	
	for(j=0; j<9; j++)
	{
		for(i=0; i<9; i++)
		{	
			if(vetor[i] > vetor[i+1])
			{
				aux = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = aux;
			}
		}
	}
}
