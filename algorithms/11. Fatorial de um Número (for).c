/* Algoritmo para calcular e imprimir o fatorial de um número N
(inteiro e positivo, podendo ser 0) */

#include <stdio.h>
#include <stdlib.h>

int i, num, fat=1 ;

main()
{
	printf("Insira o numero para calcular seu fatorial (n!): ");
	scanf("%i", &num);
	
	for(i=num; i>0; i--)
		fat = fat * i ;
	
	if(num >= 0)
		printf("\nResultado (%i!): %i\n\n", num, fat);
	else
		printf("\nERRO! Numero inserido NEGATIVO\n\n");
	
	system("pause");
}
