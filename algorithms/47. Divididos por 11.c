/*
Teste 021
"Divididos por 11"

Faça um programa que verifique e mostre os números entre 1.000 e 2.000 (inclusive)
que, quando divididos por 11 produzam resto igual a 2.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int i ;
float resto ;

main()
{
	for(i=1000; i<2001; i++)
	{
		resto = i % 11 ;
		
		if(resto == 2)
			printf("%i\n", i);
	}
	
	printf("\n");
	
	system("pause");
}
