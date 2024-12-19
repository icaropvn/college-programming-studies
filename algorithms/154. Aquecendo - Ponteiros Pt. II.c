/*
Aquecendo: Ponteiros Pt. II

	Escreva um procedimento que troca os valores dos parâmetros recebidos. Sua assinatura deve
ser:

void troca(float *a, float *b);

*/

#include <stdio.h>
#include <stdlib.h>

void troca(float *a, float *b);

int main()
{
	float num1 = 35, num2 = 104;
	
	printf("Numero 01: %.2f\nNumero 02: %.2f", num1, num2);
	
	troca(&num1, &num2);
	
	printf("\n\nAPOS A TROCA\n---------------------\nNumero 01: %.2f\nNumero 02: %.2f", num1, num2);
	
	return 0;
}

void troca(float *a, float *b)
{
	float aux;
	
	aux = *b;
	*b = *a;
	*a = aux;
}
