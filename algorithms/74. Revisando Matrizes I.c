/*
Teste 047
"Revisando Matrizes I"

Escreva um programa em C que leia uma matriz 3x3 de números inteiros
e calcule a soma de todos os elementos da matriz. Em seguida, exiba
o resultado na tela.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int i, j ;
int matriz[3][3] ;
int soma = 0 ;

main()
{
	setlocale(LC_ALL, "Portuguese");
	
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("Insira o elemento %i,%i da matriz: ", i+1, j+1);
			scanf("%i", &matriz[i][j]);
		}
	}
	
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
			soma += matriz[i][j] ;
	}
	
	printf("\n");
	
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
			printf(" %3.i", matriz[i][j]);
		printf("\n");
	}
	
	printf("\nA soma dos elementos da matriz é: %i\n\n", soma);
	
	system("pause");
}

