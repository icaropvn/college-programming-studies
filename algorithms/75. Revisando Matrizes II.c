/*
Teste 048
"Revisando Matrizes II"

Escreva um programa em C que leia duas matrizes 3x3 de números
inteiros e realize a multiplicação dessas matrizes. Em seguida,
exiba a matriz resultante na tela.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int i, j, k ;
int a[3][3], b[3][3], c[3][3] ;

main()
{
	setlocale(LC_ALL, "Portuguese");
	
	// Lendo a matriz A
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("Insira o valor de A(%i, %i): ", i+1, j+1);
			scanf("%i", &a[i][j]);
		}
	}
	
	printf("\n");
	
	// Lendo a matriz B
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("Insira o valor de B(%i, %i): ", i+1, j+1);
			scanf("%i", &b[i][j]);
		}
	}
	
	// Realizando a multiplicação
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			for(k=0; k<3; k++)
			{
				c[i][j] += a[i][k] * b[k][j] ;
			}
		}
	}
	
	printf("\nMatriz C (A*B): ");
	
	// Imprimindo a matriz multiplicação C
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{	
			printf("%3.2i ", c[i][j]);
		}
		printf("\n	        ");
	}
	
	printf("\n\n");
	
	system("pause");
}
