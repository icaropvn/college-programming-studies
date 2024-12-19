/*
Teste 036
"Mercadinho"

Esse programa deve ser capaz de somar o valor unitário de um produto do
comércio recebendo como entrada apenas o código identificador dele.

Para verificar o bom funcionamento da funcionalidade de soma de valor 
através do código você decidiu realizar testes apenas com uma parte dos produtos vendidos, 
para isso criou a seguinte tabela:

100 - Detergente - R$1,59
101 - Esponja - R$4,59
102 - Lã de Aço - R$1,79

Desenvolva o código que será utilizado para a realização dos testes com os três produtos selecionados.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

int code, flag = 0 ;
float soma = 0.0 ;
char answer ;

main()
{
	setlocale(LC_ALL, "Portuguese");
	
	do
	{
		if(flag == 1)
			printf("\n\n");
		
		printf("Insira o código presente na embalagem do produto: ");
		scanf("%i", &code);
		
		switch(code)
		{
			case 100:
				soma += 1.59 ;
				printf("Produto \"Detergente\" Adicionado à Sacola.\n\n");
				break;
			case 101:
				soma += 4.59 ;
				printf("Produto \"Esponja\" Adicionado à Sacola.\n\n");
				break;
			case 102:
				soma += 1.79 ;
				printf("Produto \"Lã de Aço\" Adicionado à Sacola.\n\n");
				break;
			default:
				printf("Código Incorreto. Produto não encontrado.\n\n");
		}
		
		printf("Soma Total: R$%.2f\nInserir mais produtos (s/n)?\nR: ", soma);
		answer = getche() ;
		
		flag = 1 ;
		
	} while(answer == 's' || answer == 'S');
	
	printf("\n\nTotal a Pagar: R$%.2f\n\n", soma);
	
	system("pause");
}
