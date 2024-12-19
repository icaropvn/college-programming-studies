/*
015 - Calculando Descontos

Escreva uma função que receba um valor de um produto e retorne o
valor com cálculo do desconto seguindo as seguintes regras:

a) valor entre 0 e 1000,00 5%;
b) valor entre 1000,01 e 2000,00, 10%;
c) acima de 2000,00, 15%.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float calcular_desconto(float preco);

int main()
{
	float preco, preco_final ;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Insira o preço do produto: R$");
	scanf("%f", &preco);
	
	preco_final = calcular_desconto(preco);
	
	printf("\nValor a pagar: R$%.2f\n", preco_final);
	
	return 0;
}

float calcular_desconto(float preco)
{
	
	if(preco <= 1000.00)
	{
		printf("\nVocê recebeu 5%% de desconto!");
		return preco * 0.95;
	}
	else if(preco <= 2000.00)
	{
		printf("\nVocê recebeu 10%% de desconto!");
		return preco * 0.90;
	}
	else
	{
		printf("\nVocê recebeu 15%% de desconto!");
		return preco * 0.85;
	}
}
