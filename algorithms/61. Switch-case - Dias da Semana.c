/*
Teste 034
"Switch-case: Dias da Semana"

Desenvolva um programa que receba como entrada um número inteiro que
represente um dos 7 dias da semana e imprima na tela se esse dia é útil, 
final de semana ou inválido.

Considere que Domingo é o dia 1 e Sábado o dia 7.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int dia, flag = 0 ;

main()
{
	setlocale(LC_ALL, "Portuguese");
	
	do
	{
		flag = 0;
		
		printf("Insira um número: ");
		scanf("%i", &dia);
	
		switch (dia)
		{
			case 1:
				printf("Domingo!\n\n");
				break;
			case 2:
				printf("Segunda!\n\n");
				break;
			case 3:
				printf("Terça!\n\n");
				break;
			case 4:
				printf("Quarta!\n\n");
				break;
			case 5:
				printf("Quinta!\n\n");
				break;
			case 6:
				printf("Sexta!\n\n");
				break;
			case 7:
				printf("Sábado!\n\n");
				break;
			default:
				flag = 1;
				printf("Número inválido, insira outro valor.\n\n");
				break;
		}
	} while(flag == 1);
	
	system("pause");
}
