/*
Teste 025
"Tabelando Descontos"

Uma loja tem tem uma política de descontos de acordo com o valor da compra do cliente.
Os descontos começam acima dos R$500.
A cada 100 reais acima dos R$500,00 o cliente ganha 1% de desconto cumulativo até 25%. 

Por exemplo: R$500 = 1% || R$600,00 = 2% … etc…

Alogritmo para exibir essa tabela de descontos no formato:  

Valor da compra – porcentagem de desconto – valor final
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int valor_i = 400 ;
float desconto, valor_f ;

main()
{
	printf("----------------------------\nCompra   Desconto  A Pagar\n----------------------------\n");
	
	for(desconto=1; desconto<26; desconto++)
	{
		valor_i += 100 ;
		valor_f = valor_i*(1 - (desconto/100)) ;
		
		printf("R$%4.i  -  %2.f%%  -  R$%7.2f\n", valor_i, desconto, valor_f);
	}
	
	printf("----------------------------\n\n");
	
	system("pause");
}
