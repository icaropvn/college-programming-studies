// Lista - Exercício 10

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define TAM 6

void preencher(int matriz[TAM][TAM]);
void d_principal(int matriz[TAM][TAM]);
void d_secundaria(int matriz[TAM][TAM]);
void imprimir(int matriz[TAM][TAM]);

int main()
{
	int matriz[TAM][TAM] ;
	
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	preencher(matriz);
	
	printf("Matriz Sorteada:\n\n");
	
	imprimir(matriz);
	
	printf("\n");
	
	d_principal(matriz);
	printf("\n");
	d_secundaria(matriz);
	
	printf("\n");
	
	return 0;
}

void preencher(int matriz[TAM][TAM])
{
	int i, j ;
	
	for(i=0; i<TAM; i++)
	{
		for(j=0; j<TAM; j++)
		{
			matriz[i][j] = rand() % 21 ;
		}
	}
}

void d_principal(int matriz[TAM][TAM])
{
	int i, j ;
	
	printf("Diagonal Principal:\t");
	
	for(i=0; i<TAM; i++)
	{
		for(j=0; j<TAM; j++)
		{
			if(i == j)
				printf("%2.1i ", matriz[i][j]);
		}
	}
}

void d_secundaria(int matriz[TAM][TAM])
{
	int i, j ;
	
	printf("Diagonal Secundária:\t");
	
	for(i=0; i<TAM; i++)
	{
		for(j=0; j<TAM; j++)
		{
			if(i + j == TAM-1)
				printf("%2.1i ", matriz[i][j]);
		}
	}
}

void imprimir(int matriz[TAM][TAM])
{
	int i, j ;
	
	for(i=0; i<TAM; i++)
	{
		for(j=0; j<TAM; j++)
		{
			if(j == 0)
				printf("| %2.1i ", matriz[i][j]);
			else if(j == TAM-1)
				printf("%2.1i |", matriz[i][j]);
			else
				printf("%2.1i ", matriz[i][j]);
		}
		printf("\n");
	}
}
