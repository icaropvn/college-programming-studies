// Criando Bibliotecas - Funções Matemáticas

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "FuncoesMatematicas.h"

void menu(float num1, float num2);

int main()
{
	float num1, num2;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Insira um número: ");
	scanf("%f", &num1);
	
	printf("Insira outro número: ");
	scanf("%f", &num2);
	
	menu(num1, num2);
	
	return 0;
}

void menu(float num1, float num2)
{
	int answer ;
	
	printf("\n[1] Somar\n[2] Subtrair\n[3] Multiplicar\n[4] Dividir\n[5] Exponenciar\n");
	scanf("%i", &answer);
	
	printf("\n");
	
	switch(answer)
	{
		case 1:
			printf("%.3f + %.3f = %.3f\n", num1, num2, somar(num1, num2));
			break;
		case 2:
			printf("%.3f - %.3f = %.3f\n", num1, num2, subtrair(num1, num2));
			break;
		case 3:
			printf("%.3f . %.3f = %.3f\n", num1, num2, multiplicar(num1, num2));
			break;
		case 4:
			if(dividir(num1, num2) == -1)
				printf("Erro. Divisor não pode ser zero (0).\n");
			else
				printf("%.3f / %.3f = %.3f\n", num1, num2, dividir(num1, num2));
			break;
		case 5:
			printf("%.3f ^ %.3f = %.3f\n", num1, num2, exponenciar(num1, num2));
			break;
	}
}
