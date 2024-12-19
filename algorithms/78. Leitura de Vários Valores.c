/*
Teste 051
"Leitura de Vários Valores"
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num1, num2, num3 ;
	
	printf("Insira 3 valores inteiros: ");
	scanf("%i%i%i", &num1, &num2, &num3);
	
	printf("\nValores lidos: %i, %i, %i\n", num1, num2, num3);
	
	return 0;
}
