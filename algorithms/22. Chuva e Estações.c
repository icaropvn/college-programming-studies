/*
Atividade 022
"Chuva e Estações"

???
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int i, grupo[5] ;
int chuva ;

main()
{
	setlocale(LC_ALL, "Portuguese");
	
	for(i=1; i<11; i++)
	{
		printf("Insira a quantidade de chuva (em cm) na estação %i: ", i);
		scanf("%i", &chuva);
		
		if(chuva < 10)
			grupo[0]++ ;
		else if(chuva < 20)
			grupo[1]++ ;
		else if(chuva < 30)
			grupo[2]++ ;
		else if(chuva < 40)
			grupo[3]++ ;
		else
			grupo[4]++ ;
	}
	
	printf("\nNúmero de Estações por Grupo:\n");
	
	for(i=0; i<5; i++)
		printf("Grupo %i: %i\n", i+1, grupo[i]);
	
	printf("\n\n");
	
	system("pause");
}
