/*
Teste 053
"Interação de Vetores"

Algoritmo para ler dois vetores de 7 elementos
númericos cada um e mostrar um vetor de 14 elementos
resultante da interação desses dois (utilizando for).
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	int i ;
	int v1[7], v2[7], vresult[14] ;
	int aux = 0 ;
	
	setlocale(LC_ALL, "Portuguese");
	
	for(i=0; i<7; i++)
	{
		printf("Insira o elemento %i do vetor 1: ", i+1);
		scanf("%i", &v1[i]);
	}
	
	printf("\n");
	
	for(i=0; i<7; i++)
	{
		printf("Insira o elemento %i do vetor 2: ", i+1);
		scanf("%i", &v2[i]);
	}
	
	for(i=0; i<14; i++)
	{
		if(i%2 == 0)	
			vresult[i] = v1[aux];
		else
		{	
			vresult[i] = v2[aux];
			aux++ ;
		}
	}
	
	printf("\nVetor Interação: [");
	
	for(i=0; i<14; i++)
	{
		if(i == 13)
			printf("%i]", vresult[i]);
		else	
			printf("%i, ", vresult[i]);
	}
	
	printf("\n");
	
	return 0;
}
