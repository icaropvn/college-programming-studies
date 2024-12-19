// Lista - Exercício 11

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define TAM 6

void preencher(int matriz[TAM][TAM]);
void imprimir(int matriz[TAM][TAM]);
void escolha(int matriz[TAM][TAM]);
void trocar(int matriz[TAM][TAM]);

int main()
{
	int matriz[TAM][TAM] ;
	
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	preencher(matriz);
	
	printf("Matriz Sorteada:\n\n");
	
	imprimir(matriz);
	
	printf("\n");
	
	escolha(matriz);
	
	return 0;
}

void preencher(int matriz[TAM][TAM])
{
	int i, j ;
	
	for(i=0; i<TAM; i++)
	{
		for(j=0; j<TAM; j++)
		{
			matriz[i][j] = rand() % 10 ;
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
				printf("| %i ", matriz[i][j]);
			else if(j == TAM-1)
				printf("%i |", matriz[i][j]);
			else
				printf("%i ", matriz[i][j]);
		}
		printf("\n");
	}
}

void escolha(int matriz[TAM][TAM])
{
	char answer;
	
	printf("Deseja trocar as diagonais da matriz entre si?\nR: ");
	scanf(" %c", &answer);
	
	if(answer == 's' || answer == 'S')
	{
		trocar(matriz);
		
		printf("\nDiagonais Trocadas!\n\n");
		imprimir(matriz);
	}
	else
		printf("\nCerto. Até mais!\n");
}

void trocar(int matriz[TAM][TAM])
{
	int i, j;
	int diagonal_principal[TAM], diagonal_secundaria[TAM];
	
	for(i=0; i<TAM; i++)
	{
		for(j=0; j<TAM; j++)
		{
			if(i == j)
				diagonal_principal[i] = matriz[i][j];
			else if(i + j == TAM-1)
				diagonal_secundaria[i] = matriz[i][j];
		}
	}
	
	for(i=0; i<TAM; i++)
	{
		for(j=0; j<TAM; j++)
		{
			if(i == j)
				matriz[i][j] = diagonal_secundaria[i];
			else if(i + j == TAM-1)
				matriz[i][j] = diagonal_principal[i];
		}
	}
}
