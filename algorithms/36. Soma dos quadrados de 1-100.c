/* 
Teste 011
Algoritmo para imprimir a soma dos quadrados dos 100 primeiros números inteiros. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int i, quadrado, end ;
long soma_quadrados = 0 ;

main()
{
	printf("Calcular a soma dos quadrados de 1 ate? ");
	scanf("%i", &end);
	
	for(i=1; i<end+1; i++)
	{
		quadrado = pow(i, 2) ;
		printf("%i^2 = %i\n", i, quadrado);
		soma_quadrados = soma_quadrados + quadrado ;
	}
	
	printf("\nSoma dos quadrados de 1 a %i = %i\n\n", end, soma_quadrados);
	
	system("pause");
}
