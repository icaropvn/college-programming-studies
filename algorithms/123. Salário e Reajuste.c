/*
017 - Salário e Reajuste

Crie um procedimento que receba 3 parâmetros de ponto
flutante positivos, sendo os dois primeiros por valor
e o terceiro por referência. A primeira variável se refere
ao salario atual, a segunda a porcentagem de reajuste e
por fim a terceira receberá o novo valor reajustado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void calcular_salario(float salario, float porcentagem, float *novo_salario);

int main()
{
	float salario, porcentagem, novo_salario ;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Insira o salário atual: R$");
	scanf("%f", &salario);
	
	printf("Insira a porcentagem de reajuste (%%): ");
	scanf("%f", &porcentagem);
	
	calcular_salario(salario, porcentagem, &novo_salario);
	
	printf("\nO novo salário é: R$%.2f\n", novo_salario);
	
	return 0;
}

void calcular_salario(float salario, float porcentagem, float *novo_salario)
{
	*novo_salario = salario * (1 + porcentagem/100);
}
