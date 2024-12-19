/*
Teste 026
"Preço de um Carro"

Algoritmo para ler o valor de um carro e mostrar uma tabela com os seguintes dados:
preço final - quantidade de parcelas - valor da parcela.

Considerar o seguinte:

- O preço final para compra à vista tem um desconto de 20%;
- A quantidades de parcelas pode ser: 6, 12, 18, 24, 30, 36, 42, 48, 54 ou 60.

Os percentuais de acréscimo seguem a tabela a seguir:  

Quantidade de parcelas	|	Percentual de acréscimo sobre o preço final
6						|	3%
12						|	6%
18						|	9%
24						|	12%
30						|	15%
36						|	18%
42						|	21%
48						|	24%
54						|	27%
60						|	30%
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float valor, vista, valor_f, acrescimo ;

main()
{
	setlocale(LC_ALL, "Portuguese");
	
	printf("Insira o preço do carro: R$");
	scanf("%f", &valor);
	
	vista = valor * 0.80 ;
	
	printf("\n---------------------------------------");
	printf("\nPreço à vista: R$%.2f\n", vista);
	printf("---------------------------------------\n");
	
	printf("Parcelas    Acréscimo          Valor\n");
	
	for(acrescimo=3; acrescimo<31; acrescimo+=3)
	{
		valor_f = valor * (1 + (acrescimo/100));
		
		printf("  %2.f     -     %2.f%%     -     R$%10.2f\n", acrescimo*2, acrescimo, valor_f);
	}
	
	printf("---------------------------------------\n\n");
	
	system("pause");
}
