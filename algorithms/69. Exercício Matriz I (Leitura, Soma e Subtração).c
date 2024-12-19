/*
Teste 042
"Exercício Matriz I"

Algoritmo para ler duas matrizes 2x2
e imprimí-las. Mostrar também a matriz soma e
a matriz subtração.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int i, j ;
int a[2][2], b[2][2] ;
int soma[2][2], sub[2][2] ;

main()
{
	setlocale(LC_ALL, "Portuguese");
	
	for(i=0; i<2; i++)
	{
		for(j=0; j<2; j++)
		{
			printf("Insira o elemento A[%i,%i]: ", i+1, j+1);
			scanf("%i", &a[i][j]);
		}
	}
	
	for(i=0; i<2; i++)
	{
		for(j=0; j<2; j++)
		{
			printf("Insira o elemento B[%i,%i]: ", i+1, j+1);
			scanf("%i", &b[i][j]);
		}
	}
	
	for(i=0; i<2; i++)
	{
		for(j=0; j<2; j++)
		{
			soma[i][j] = a[i][j] + b[i][j] ;
			sub[i][j] = a[i][j] - b[i][j] ;
		}
	}
	
	printf("\nMatriz A+B:\n");
	
	for(i=0; i<2; i++)
	{
		for(j=0; j<2; j++)
			printf("%3.i ", soma[i][j]);
		
		printf("\n");
	}
	
	printf("\nMatriz A-B:\n");
	
	for(i=0; i<2; i++)
	{
		for(j=0; j<2; j++)
			printf("%3.i ", sub[i][j]);
		
		printf("\n");
	}
	
	printf("\n\n");
	
	system("pause");
}
