/*
Teste 012

Na matemática, a seguinte propriedade é mantida: sqrt(x) <= sqrt(y) quando x <= y
Preparar um algoritmo para verificar se esta propriedade se mantém para a função embutida SQRT para os valores inteiros de x e y no intervalo de 0 a 100. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int x = 0, y = 0, flag, testeint ;
float testef ;

main()
{
	setlocale(LC_ALL, "Portuguese");
	
	/*
	=== RESOLUÇÃO 1 ===
	
	for(x=0; x<101; x++)
	{
		for(y=0; y<101; y++)
		{
			printf("|  %3.1i  |  %3.1i  |  %5.2f  |  %5.2f  |\n", x, y, sqrt(x), sqrt(y));
		
			if(sqrt(x) <= sqrt(y) && x <= y || sqrt(x) >= sqrt(y) && x >= y)
				flag = 0 ;
			else
				flag = 1 ;
		}
	}
	*/
		
	do
	{
		y = 0;
		
		do
		{
			printf("|  %3.1i  |  %3.1i  |  %5.2f  |  %5.2f  |\n", x, y, sqrt(x), sqrt(y));
		
			if(sqrt(x) <= sqrt(y) && x <= y || sqrt(x) >= sqrt(y) && x >= y)
				flag = 0 ;
			else
				flag = 1 ;
			
			y++ ;
		} while(y < 101);
		
		x++ ;
	} while(x < 101);

	printf("---------------------------------\n|   x   |   y   |  raiz x |  raiz y |\n");
	
	if(flag == 1)	
		printf("\nA afirmação é falsa.\n\n");
	else
		printf("\nA afirmação é verdadeira.\n\n");
	
	system("pause");
}
