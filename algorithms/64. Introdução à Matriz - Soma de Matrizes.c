/*
Teste 037
"Introdução à Matriz - Soma de Matrizes"

Algoritmo para ler e somar duas matrizes 2x2.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// ! Para manipular colunas, o índice universal é 'j', como o 'i' é para linhas !
int i, j, a[2][2], b[2][2], soma[2][2] ;

main()
{
	setlocale(LC_ALL, "Portuguese");
	
	// Lendo a matriz A
	for(i=0; i<2; i++)
	{
		for(j=0; j<2; j++)
		{
			printf("Insira o valor da posição A[%i,%i]: ", i+1, j+1);
			scanf("%i", &a[i][j]);
		}
	}
	
	printf("\n");
	
	// Lendo a matriz B
	for(i=0; i<2; i++)
	{
		for(j=0; j<2; j++)
		{
			printf("Insira o valor da posição B[%i,%i]: ", i+1, j+1);
			scanf("%i", &b[i][j]);
		}
	}
	
	// Somando as matrizes A e B
	for(i=0; i<2; i++)
	{
		for(j=0; j<2; j++)
			soma[i][j] = a[i][j] + b[i][j] ;
	}
	
	printf("\nA+B = ");
	
	// Imprimindo a matriz soma (A+B)
	for(i=0; i<2; i++)
	{
		for(j=0; j<2; j++)
		{
			printf(" %2.i ", soma[i][j]);
		}
		printf("\n      ");
	}
	
	printf("\n\n");
	
	system("pause");
}
