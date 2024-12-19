/*
Teste ???
"Ordem Inversa"

*INTRODUÇÃO A VETORES*
Vetor é uma forma de acumular inúmeras variáveis numa única.

Ler 5 números e imprimir em ordem inversa.
*/

#include <stdio.h>
#include <stdlib.h>

int i, vetor[5] ;

main()
{
	for(i=0; i<5; i++)
	{
		printf("Informe o numero %i: ", i+1);
		scanf("%i", &vetor[i]);
	}
	
	printf("\n");
	
	for(i=4; i>-1; i--)
		printf("%i ", vetor[i]);
	
	printf("\n\n");
	
	system("pause");
}
