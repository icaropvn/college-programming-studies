/*
Atividade 016 - Lado B

"Erros de um Programador"
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int problem = 1, week = 1, erros, flagweek = 1;

main()
{
	do
	{
		if(problem % 2 != 0)
		{
			printf("Semana %i\n", week);
			week++ ;
		}
		
		erros = pow(2, flagweek-1);
		
		printf("   Problema %i - %i Erro(s)\n", problem, erros);
		problem++ ;
		flagweek++ ;
		
	} while(problem < 27);
	
	printf("\n");
	system("pause");
}
