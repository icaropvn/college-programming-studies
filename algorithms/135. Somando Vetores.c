// Lista - Exercício 04

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define TAM 5

void preencher(int a[], int b[]);
void somar(int a[], int b[], int c[]);
void imprimir(int vetor[], int tamanho);

int main()
{
	int a[TAM], b[TAM], c[TAM] ;
	
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	printf("Vetores totalmente sorteados:\n\n");
	
	preencher(a, b);
	somar(a, b, c);
	
	printf("Vetor A (pares) = [");
	imprimir(a, TAM);
	
	printf("\nVetor B (ímpares) = [");
	imprimir(b, TAM);
	
	printf("\n\nVetor C (A + B) = [");
	imprimir(c, TAM);
	
	printf("\n");
	
	return 0;
}

void preencher(int a[], int b[])
{
	int i, aux ;
	
	// preenchendo vetor A apenas com PARES
	for(i=0; i<TAM; i++)
	{
		while(1)
		{
			aux = 1 + (rand() % 10);
			a[i] = aux;
			
			if(aux % 2 == 0)
				break;
		}
	}
	
	// preenchendo vetor B apenas com ÍMPARES
	for(i=0; i<TAM; i++)
	{
		while(1)
		{
			aux = 1 + (rand() % 10);
			b[i] = aux;
			
			if(aux % 2 == 1)
				break;
		}
	}
}

void somar(int a[], int b[], int c[])
{
	int i ;
	
	for(i=0; i<TAM; i++)
		c[i] = a[i] + b[i];
}

void imprimir(int vetor[], int tamanho)
{
	int i ;
	
	for(i=0; i<tamanho; i++)
	{
		if(i == tamanho-1)
			printf("%i]", vetor[i]);
		else
			printf("%i, ", vetor[i]);
	}
}
