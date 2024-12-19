// Lista - Exercício 05

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define TAM 8

void preencher(int a[], int b[]);
void imprimir(int vetor[]);
void trocar(int a[], int b[]);

int main()
{
	int a[TAM], b[TAM];
	
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	preencher(a, b);
	
	printf("Vetores Sorteados:\n\n");
	
	printf("Vetor A = [");
	imprimir(a);
	
	printf("\nVetor B = [");
	imprimir(b);
	
	trocar(a, b);
	
	printf("\n\nVetores trocados:\n");
	
	printf("Vetor A = [");
	imprimir(a);
	
	printf("\nVetor B = [");
	imprimir(b);
	
	printf("\n");
	
	return 0;
}

void preencher(int a[], int b[])
{
	int i;
	
	for(i=0; i<TAM; i++)
		a[i] = 1 + (rand() % 10);

	for(i=0; i<TAM; i++)
		b[i] = 1 + (rand() % 10);
}

void imprimir(int vetor[])
{
	int i;
	
	for(i=0; i<TAM; i++)
	{
		if(i == TAM-1)
			printf("%2.1i]", vetor[i]);
		else
			printf("%2.1i, ", vetor[i]);
	}
}

void trocar(int a[], int b[])
{
	int vetor_auxiliar[TAM];
	int i;
	
	for(i=0; i<TAM; i++)
	{
		vetor_auxiliar[i] = b[i];
		b[i] = a[i];
		a[i] = vetor_auxiliar[i];
	}
}
