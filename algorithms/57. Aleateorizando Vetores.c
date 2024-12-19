/*
Teste 031
"Aleateorizando Vetores"

Algoritmo para imprimir 6 valores aleatórios de 0 a 100.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int i, valores[6], answer = 0, flag = 0 ;

main()
{
	setlocale(LC_ALL, "Portuguese");
	
	do
	{	
		if(answer == 1)
			printf("\n");
		
		flag = 0 ;
		
		for(i=0; i<6; i++)
			valores[i] = rand() % 101 ;
	
		printf("Números sorteados: ");
	
		for(i=0; i<6; i++)
		{	
			if(i == 5)
				flag = 1 ;
			
			if(flag == 0)
				printf("%i, ", valores[i]);
			else
				printf("%i", valores[i]);
		}
		
		printf("\nImprimir outra sequência?\n");
		scanf("%i", &answer);
		
	} while(answer == 1);
		
	system("pause");
}
