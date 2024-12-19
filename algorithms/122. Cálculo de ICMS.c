/*
016 - Cálculo de ICMS

Escreva uma função que receba um valor de venda de algum
produto e retorne o novo valor com o cálculo do ICMS (considere 18%).
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float calcular_icms(float preco_produto);

int main()
{
	float preco_produto, valor_icms ;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Insira o preço cobrado pelo produto: R$");
	scanf("%f", &preco_produto);
	
	valor_icms = calcular_icms(preco_produto);
	
	printf("Valor do ICMS embutido: R$%.2f\n", valor_icms);
	
	return 0;
}

float calcular_icms(float preco_produto)
{
	return preco_produto * 0.18 ;
}
