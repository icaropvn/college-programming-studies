/*
Teste 054
"Centralizando"

Algoritmo para preencher um matriz 15x11 automaticamente, e
em seguida mostrar a soma dos valores na linha e coluna centrais.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
{
	int i, j ;
	int matriz[15][11];
	int somaline = 0, somacolumn = 0 ;
	
	setlocale(LC_ALL, "Portuguese");
	srand((unsigned)time(NULL));
	
	for(i=0; i<15; i++)
	{
		for(j=0; j<11; j++)
		{
			matriz[i][j] = rand() % 10 ;
		}
	}
	
	for(i=0; i<15; i++)
	{
		for(j=0; j<11; j++)
		{
			if(i == 7)
				somaline += matriz[i][j] ;
			if(j == 5)
				somacolumn += matriz[i][j] ;
		}
	}
	
	for(i=0; i<15; i++)
	{
		for(j=0; j<11; j++)
		{
			printf(" %i ", matriz[i][j]);
		}
		printf("\n");
	}
	
	printf("\nSoma da Linha central: %i\nSoma da Coluna central: %i\n", somaline, somacolumn);
	
	return 0;
}
