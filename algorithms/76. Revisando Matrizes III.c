/*
Teste 049
"Revisando Matrizes III"

Escreva um programa em C que leia uma matriz quadrada de tamanho N
(onde N é um número inteiro lido do usuário) e verifique se essa matriz
é simétrica. Uma matriz é considerada simétrica se ela é igual à sua transposta.
Exiba na tela se a matriz é simétrica ou não.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int i, j ;
int num ;
int flag = 0 ;

main()
{		
	setlocale(LC_ALL, "Portuguese");
	
	printf("Insira o tamanho da matriz quadrada: ");
	scanf("%i", &num);
	
	int a[num][num] ;
	int at[num][num] ;
	
	printf("\n");
	
	for(i=0; i<num; i++)
	{
		for(j=0; j<num; j++)
		{
			printf("Insira o valor de A(%i, %i): ", i+1, j+1);
			scanf("%i", &a[i][j]);
			
			at[j][i] = a[i][j] ;
		}
	}
	
	printf("\nMatriz A:\n");
	
	for(i=0; i<num; i++)
	{
		for(j=0; j<num; j++)
		{
			printf(" %2.i", a[i][j]);
		}
		printf("\n");
	}
	
	printf("\nMatriz At:\n");
	
	for(i=0; i<num; i++)
	{
		for(j=0; j<num; j++)
		{
			printf(" %2.i", at[i][j]);
		}
		printf("\n");
	}
	
	for(i=0; i<num; i++)
	{
		for(j=0; j<num; j++)
		{
			if(at[i][j] != a[i][j])
				flag = 1 ;
		}
	}
	
	if(flag == 1)
		printf("\nA matriz não é simétrica.\n\n");
	else
		printf("\nA matriz é simétrica!\n\n");
	
	printf("\n");
	
	system("pause");
}
