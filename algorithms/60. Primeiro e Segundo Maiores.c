/*
Teste 033
"Primeiro e Segundo Maiores"

Algoritmo para ler 5 valores para um vetor e imprimir o PRIMEIRO e SEGUNDO maiores
elementos dele.

Algorithm for reading 5 values in a vector and print its FIRST and SECOND biggest
numbers.
*/

#include <stdio.h>
#include <stdlib.h>

int i, vector[6] ;
int biggest1, biggest2 ;

main()
{
	for(i=0; i<6; i++)
	{
		printf("Insert the value in the position %i: ", i+1);
		scanf("%i", &vector[i]);
		
		if(i == 0)
			biggest1 = vector[i] ;
		
		if(vector[i] > biggest1)
			biggest1 = vector[i] ;
	}
	
	if(vector[0] == biggest1)	
		biggest2 = vector[1] ;
	else
		biggest2 = vector[0] ;
	
	for(i=1; i<6; i++)
	{
		if(vector[i] > biggest2 && vector[i] < biggest1)
			biggest2 = vector[i] ;
	}
	
	printf("\nFirst biggest number: %i\nSecond biggest number: %i\n\n", biggest1, biggest2);

	system("pause");
}
