/*
Teste 045
"Cálculos Diagonais"

Leia uma matriz de 3 x 3 elementos. Calcule a soma dos elementos que estão acima,
abaixo e dentro da diagonal principal.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int i, j ;
int a[3][3] ;
int soma[3] ;

main()
{
	setlocale(LC_ALL, "Portuguese");
	
	srand((unsigned)time(NULL));
	
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			a[i][j] = rand() % 10;
		}
	}
	
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			if(i > j)
				soma[2] += a[i][j] ;
			else if(i == j)
				soma[1] += a[i][j] ;
			else
				soma[0] += a[i][j] ;
		}
	}
	
	printf("Matriz:\n");
	
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("%2.1i ", a[i][j]);
		}
		printf("\n");
	}
	
	printf("\nSomas:\nAcima da Diagonal: %i\n", soma[0]);
	printf("Elementos da Diagonal: %i\n", soma[1]);
	printf("Abaixo da Diagonal: %i\n\n", soma[2]);
	
	system("pause");
}
