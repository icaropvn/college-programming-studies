// Lista - Exercício 08

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIN 6
#define COL 10

void sortear(int matriz[LIN][COL]);

int main()
{
	int i, j;
	int matriz[LIN][COL];
	
	srand(time(NULL));
	
	sortear(matriz);
	
	printf("Matriz Sorteada (%i x %i):\n\n", LIN, COL);
	
	for(i=0; i<LIN; i++)
	{
		for(j=0; j<COL; j++)
		{
			if(j == 0)
				printf("| %2.1i ", matriz[i][j]);
			else if(j == 9)
				printf("%2.1i |", matriz[i][j]);
			else
				printf("%2.1i ", matriz[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

void sortear(int matriz[LIN][COL])
{
	int i, j;
	
	for(i=0; i<LIN; i++)
	{
		for(j=0; j<COL; j++)
		{
			matriz[i][j] = rand() % 21 ;
		}
	}
}
