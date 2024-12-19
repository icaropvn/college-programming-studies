/*
Teste 040
"Ordenando Vetores I"

Ordenando um vetor de forma crescente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int i, j, vetor[5], oldvector[5], temp ;

main()
{
	setlocale(LC_ALL, "Portuguese");
	
	for(i=0; i<5; i++)
	{
		printf("Insira o valor %i: ", i+1);
		scanf("%i", &vetor[i]);
		
		oldvector[i] = vetor[i] ;
	}
	
	for(i=0; i<5; i++)
	{
		for(j=i+1; j<5; j++)
		{
			if(vetor[j] < vetor[i])
			{
				temp = vetor[i] ;
				vetor[i] = vetor[j] ;
				vetor[j] = temp ;
			}
		}
	}
	
	printf("\nVetor Original: [");
	
	for(i=0; i<5; i++)
	{
		if(i == 4)
			printf("%i]", oldvector[i]);
		else
			printf("%i, ", oldvector[i]);
	}
		
	printf("\nVetor Ordenado (crescente): [");
	
	for(i=0; i<5; i++)
	{
		if(i == 4)
			printf("%i]", vetor[i]);
		else
			printf("%i, ", vetor[i]);
	}
		
	printf("\n\n");
	
	system("pause");
}
