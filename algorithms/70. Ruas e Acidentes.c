/*
Teste 043
"Ruas e Acidentes"

Uma cidade tem 4 ruas leste­oeste e 6 ruas norte­sul. 
4x6 = 24 cruzamentos

Leia uma sequência de pares de ruas que indicam o cruzamento 
onde cada acidente ocorreu. Imprima uma matriz com a 
contagem de acidentes de cada cruzamento.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

int flag = 0 ;
int i, j ;
int cruzamentos[4][6], horizontal, vertical ;
char answer ;

main()
{
	setlocale(LC_ALL, "Portuguese");
	
	do
	{
		if(flag == 1)
			printf("\n\n");
		
		printf("Indique o par de ruas que formam o cruzamento onde ocorreu o acidente: ");
		scanf("%i", &horizontal);
		scanf("%i", &vertical);
	
		cruzamentos[horizontal-1][vertical-1]++ ;
		
		printf("\nInserir mais dados?\n");
		answer = getche();
		
		flag = 1 ;
		
	} while(answer == 'S' || answer == 's');
	
	printf("\n\nNúmero de Acidentes por Cruzamento:\n");
	
	for(i=0; i<4; i++)
	{
		for(j=0; j<6; j++)
			printf("%i ", cruzamentos[i][j]);
		
		printf("\n");
	}
	
	printf("\n\n");
	
	system("pause");
}
