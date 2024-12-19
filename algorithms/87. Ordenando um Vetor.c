/* Ordenando um vetor

Conceitos da aula
- Teste em Mesa
- "Técnica da Bolha"
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define MAX 10

void preencher(int vetor[]);
void imprimir(int vetor[]);
void ordenar(int vetor[]);
void trocar(int *num1, int *num2);

int main()
{
	int vetor[MAX];
	
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	preencher(vetor);
	printf("Vetor = [");
	imprimir(vetor);
	
	printf("\n\n");
	
	ordenar(vetor);
	printf("Vetor Ordenado = [");
	imprimir(vetor);
	
	printf("\n");
	
	return 0;
}

void preencher(int vetor[])
{
	int i;
	
	for(i=0; i<MAX; i++)
	{
		vetor[i] = rand() % 31 ;
	}
}

void imprimir(int vetor[])
{
	int i;
	
	for(i=0; i<MAX; i++)
	{
		if(i == MAX - 1)
			printf("%i]", vetor[i]);
		else
			printf("%i, ", vetor[i]);
	}
}

void ordenar(int vetor[])
{
	int i, j;
	
	for(i=0; i<MAX; i++)
	{
		for(j=i+1; j<MAX; j++)
		{
			if(vetor[i] > vetor[j])
				trocar(&vetor[i], &vetor[j]);
		}
	}
}

void trocar(int *num1, int *num2)
{
	int temp;
	
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
