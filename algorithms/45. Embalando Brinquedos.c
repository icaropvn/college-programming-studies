/*
Teste 019
"Embalando Brinquedos"

Ler dimensões da caixa, calcular sua diagonal (diâmetro da sua esfera),
e selecionar tipo de esfera a ser utilizada.

Acumular cada tipo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <conio.h>

int e1 = 0, e2 = 0, e3 = 0, e4 = 0, caixa = 0, flag = 0 ;
float a, b, c, d ;
char answer ;

main()
{
	setlocale(LC_ALL, "Portuguese");
	
	do
	{
		caixa++ ;
		
		if(flag == 1)
			printf("\n\n");
		
		printf("Insira a dimensão A da caixa %i: ", caixa);
		scanf("%f", &a);
		
		printf("Insira a dimensão B: ");
		scanf("%f", &b);
		
		printf("Insira a dimensão C: ");
		scanf("%f", &c);
		
		d = sqrt(pow(a, 2) + pow(b, 2) + pow(c, 2)) ;
		
		if(d <= 10)
		{
			e1++ ;
			printf("A esfera a ser utilizada é a 1 (10cm)\n\n");
		}
		else if (d <= 15)
		{
			e2++ ;
			printf("A esfera a ser utilizada é a 2 (15cm)\n\n");
		}
		else if(d <= 20)
		{	
			e3++ ;
			printf("A esfera a ser utilizada é a 3 (20cm)\n\n");
		}
		else if(d <= 25)
		{	
			e4++ ;
			printf("A esfera a ser utilizada é a 4 (25cm)\n\n");
		}
		else
		{
			printf("O brinquedo é grande demais para caber em uma esfera.\n\n");
		}
		
		printf("Deseja continuar calculando? (s/n)\n");
		answer = getche() ;
		
		flag = 1 ;
		
	} while(answer == 'S' || answer == 's');
	
	printf("\n\nQuantidade de esferas a serem utilizadas\n10cm - %i\n15cm - %i\n20cm - %i\n25cm - %i\n\n", e1, e2, e3, e4);

	system("pause");
}
