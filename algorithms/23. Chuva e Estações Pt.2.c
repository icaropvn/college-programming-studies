/*
Atividade 023
"Chuva e Estações Pt. 2"

Grupos de acordo com mm de chuva por estação
1. 0-9
2. 10-19
3. 20-29
4. 30-39
5. 40-49
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int i, grupo[5], chuva, indice ;

main()
{
	setlocale(LC_ALL, "Portuguese");
	
	for(i=1; i<11; i++)
	{
		printf("Insira a quantidade de chuva (em cm) na estação %i: ", i);
		scanf("%i", &chuva);
		
		grupo[chuva / 10]++ ;
	}
	
	printf("\nNúmero de Estações por Grupo:\n");
	
	for(i=0; i<5; i++)
		printf("Grupo %i: %i\n", i+1, grupo[i]);
	
	printf("\n\n");
	
	system("pause");
}