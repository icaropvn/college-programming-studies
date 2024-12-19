/*
Teste 046
"Triângulo de Pascal"

Escreva um programa que leia um numero inteiro positivo n e em seguida imprima n
linhas do chamado Triângulo de Pascal:

1  -  -  -  -  -
1  1  -  -  -  -
1  2  1  -  -  -
1  3  3  1  -  -
1  4  6  4  1  -
1  5 10 10  5  1
...

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	int i, j ;
	int n ;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Insira o número de linhas desejadas do Triâgulo de Pascal: ");
	scanf("%i", &n);
	
	int pascal[n][n];
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<=i; j++)
		{
			pascal[i][j] = 1 ;
		}
	}
	
	printf("\n");
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<=i; j++)
		{
			pascal[i+2][j+1] = pascal[i+1][j+1] + pascal[i+1][j];
			
			printf(" %3.i ", pascal[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\n");
	
	return 0;
}
