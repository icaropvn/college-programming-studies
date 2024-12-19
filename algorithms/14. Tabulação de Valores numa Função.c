/*
Atividade 014
Algoritmo para calcular e tabular:

x = 2, 4, 6, 8
y = 6, 9, 12, 15, 18, 21

f(x,y) = (x² - y²) / (x² + Y²)

*A função pow() sempre retorna um valor real*

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int x, y ;
float funcao ;

main()
{
	printf(" x  |   y  |   f(x,y)\n");
	printf("---------------------\n");
	
	for(x=2; x<9; x = x + 2)
	{
		for(y=6; y<22; y = y + 3)
		{
			funcao = (pow(x, 2) - pow(y, 2)) / (pow(x, 2) + pow(y, 2)) ;
			printf(" %i  |  %2.i  |  %6.2f\n", x, y, funcao);
		}
	}
	
	printf("---------------------\n");
	
	system("pause");
}