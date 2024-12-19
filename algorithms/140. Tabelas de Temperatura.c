// Lista - Exercício 09

#include <stdio.h>
#include <stdlib.h>
#define LIN 600
#define COL 700

void preencher(float f[LIN][COL]);
void converter(float f[LIN][COL], float c[LIN][COL]);
void imprimir(float matriz[LIN][COL]);

int main()
{
	int i, j ;
	float fahrenheit[LIN][COL];
	float celsius[LIN][COL];
	
	preencher(fahrenheit);
	
	printf("Tabela em Fahrenheit:\n\n");
	imprimir(fahrenheit);
	
	converter(fahrenheit, celsius);
	
	printf("\n");
	
	printf("Tabela em Celsius:\n\n");
	imprimir(celsius);
	
	return 0;
}

void preencher(float f[LIN][COL])
{
	int i, j;
	
	f[0][0] = 32 ;
	
	for(i=0; i<LIN; i++)
	{
		for(j=0; j<COL; j++)
		{
			f[i][j+1] = f[i][j] + 1 ;
		}
	}
}

void converter(float f[LIN][COL], float c[LIN][COL])
{
	int i, j;
	
	for(i=0; i<LIN; i++)
	{
		for(j=0; j<COL; j++)
		{
			c[i][j] = (f[i][j] - 32) * 5/9 ;
		}
	}
}

void imprimir(float matriz[LIN][COL])
{
	int i, j ;
	
	for(i=0; i<LIN; i++)
	{
		for(j=0; j<COL; j++)
		{
			if(j == COL-1)
				printf("| %7.1f |", matriz[j][i]);
			else
				printf("| %7.1f ", matriz[j][i]);
		}
		printf("\n");
	}
}
