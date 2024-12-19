/*
Atividade 015

Preparar um algoritmo para calcular o número de pontos como 
coordenadas de valor inteiro contidas na elipse:

Os pontos no interior da curva acima são considerados dentro da elipse. 

Os valores das coordenadas estão limitados pelos eixos maior e menor da elipse 
(isto é, - 4 ≤ x ≤ 4  e  - 5 ≤ y ≤ 5)

função da elipse: (x²/16) + (y²/25) = 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int x, y, pontos_int = 0 ; 
float f ;

main()
{
	printf(" x	 y	f\n");
	printf("--------------------\n");
	
	for(x=-4; x<5; x++)
	{
		for(y=-5; y<6; y++)
		{
			f = pow(x, 2)/16 + pow(y, 2)/25 ;
			
			printf("%2.1i	%2.1i	%.2f\n", x, y, f);
			
			if(f < 1)
				pontos_int++ ;
		}
	}
	
	printf("--------------------\n");
	printf("\nPontos Contidos na Elipse: %i\n\n", pontos_int);
	
	system("pause");
}