/*
Teste 041
"Multiplicando Matrizes"

Algoritmo para ler duas matrizes e multiplicá-las.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int a[3][3], b[3][3], ab[3][3] ;
int i, j, k ;

main()
{
	setlocale(LC_ALL, "Portuguese");
	
	// Lendo a matriz A
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("Insira o elemento A[%i,%i]: ", i+1, j+1);
			scanf("%i", &a[i][j]);
		}
	}
	
	printf("\n");
	
	// Lendo a matriz B
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("Insira o elemento B[%i,%i]: ", i+1, j+1);
			scanf("%i", &b[i][j]);
		}
	}
	
	printf("\n\nMatriz AxB: \n\n");
	
	// Multiplicando as matrizes
	// ! a variável "k" serve para simplificar o algoritmo e representa as linhas (ou) colunas das matrizes A e B !
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			for(k=0; k<3; k++)
				ab[i][j] = ab[i][j] + a[i][k] * b[k][j] ;
		}
	}
	
	// Print da matriz AxB
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("%i ", ab[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\n");
	
	system("pause");
}
