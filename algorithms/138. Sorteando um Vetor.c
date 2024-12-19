// Lista - Exercício 07

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10

void sortear(int vetor[]);

int main()
{
	int i;
	int vetor[TAM];
	
	srand(time(NULL));
	
	sortear(vetor);
	
	printf("Vetor Sorteado:\n[");
	
	for(i=0; i<TAM; i++)
	{
		if(i == TAM-1)
			printf("%i]\n", vetor[i]);
		else
			printf("%i, ", vetor[i]);
	}
	
	return 0;
}

void sortear(int vetor[])
{
	int i ;
	
	for(i=0; i<TAM; i++)
	{
		vetor[i] = rand() % 21 ;
	}
}
