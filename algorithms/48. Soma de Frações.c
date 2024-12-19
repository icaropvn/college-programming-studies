/*
Teste 022
"Soma de Frações"

Faça um programa que leia um valor n, inteiro e positivo, calcule e mostre a seguinte soma: S = 1 + 1/2 + 1/3 + 1/4 + … + 1/n.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int i, num ;
float s = 0.0 ;

main()
{
	printf("Insira um valor para N: ");
	scanf("%i", &num);
	
	for(i=1; i<num+1; i++)
	{
		s += 1.0/i ;
	}
	
	printf("S = %f\n\n", s);
	
	system("pause");
}
