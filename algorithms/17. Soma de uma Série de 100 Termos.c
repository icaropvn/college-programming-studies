/*
Atividade 017

Algoritmo para calcaular a soma da seguinte série de 100 termos:

(1 - 1/2) + (1/4 - 1/6) + (1/8 - 1/10) + (1/12 - 1/14) ...
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int i, denominador = 0, mult = 1 ;
float soma = 1.0 ;

main()
{
	setlocale(LC_ALL, "Portuguese");
	
	for(i=2; i<101; i++)
	{
		denominador = denominador + 2 ;
		
		// mult = mult * -1 ;
		
		soma = soma + 1.0/denominador * pow(-1, i-1) ;
	}
	
	printf("A soma dos 100 termos e: %.2f\n\n", soma);
	
	system("pause");
}