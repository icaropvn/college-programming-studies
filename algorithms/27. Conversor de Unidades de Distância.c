// Teste de Conversor de Medidas

#include <stdio.h>
#include <stdlib.h>

float valor, deci, centi, metro;
int unidade;

main()
{
	printf("Insira um valor: ");
	scanf("%f", &valor);
	
	printf("O valor esta em que unidade?\n");
	printf("Digite 1 para METRO\n");
	printf("Digite 2 para DECIMETRO\n");
	printf("Digite 3 para CENTIMETRO\n");
	scanf("%i", &unidade);
	
	if(unidade==1)
	{
		deci = valor * 10 ;
		centi = valor * 100 ;
		printf("Valor em decimetros: %f\n", deci);
		printf("Valor em centimetros: %f\n", centi);
	}
	else
	{
		if(unidade==2)
		{
			metro = valor * 0.1 ;
			centi = valor * 10 ;
			printf("Valor em metro: %f\n", metro);
			printf("Valor em centimetros: %f\n", centi);
		}
		else
		{
			if(unidade==3)
			{
				metro = valor * 0.01 ;
				deci = valor * 0.1 ;
				printf("Valor em metro: %f\n", metro);
				printf("Valor em decimetros: %f\n", deci);
			}
			else
			{
				printf("ERRO! Selecione um dos numeros citados acima\n\n");
			}
		}
	}
	
	system("pause");
}
