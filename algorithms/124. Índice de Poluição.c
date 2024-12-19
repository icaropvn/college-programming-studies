/*
018 - Índice de Poluição

Escreva um procedimento que leia o índice de poluição
e indique providências apropriadas.

*Considere índice de poluição = i

Se:
- i < 0.30 				Boa: Nenhuma providência
- 0.30 = i < 0.40 		Ruim: Suspender empresas da lista A
- 0.40 = i = 0.50 		Péssima: Suspender empresas da lista A e B
- i > 0.50				Crítica: Suspender todas as empresas
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void verificar_indice(float indice);

int main()
{
	float indice ;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Insira o índice de poluição atual: ");
	scanf("%f", &indice);
	
	verificar_indice(indice);
	
	return 0;
}

void verificar_indice(float indice)
{
	if(indice < 0.3)
		printf("\nÍndice Bom.\nNenhuma providência a ser tomada.\n");
	else if(indice < 0.4)
		printf("\nÍndice Ruim.\nSuspender empresas da lista A.\n");
	else if(indice <= 0.5)
		printf("\nÍndice PÉSSIMO.\nSuspender empresas da lista A e B.\n");
	else
		printf("\nÍndice CRÍTICO!!!\nSUSPENDER TODAS AS EMPRESAS.");
}
