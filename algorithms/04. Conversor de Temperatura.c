/* Algoritmo de conversão Celsius-Fahrenheit */

#include <stdio.h>
#include <stdlib.h>

float celsius, fahrenheit;

main()
{
	printf("Insira uma temperatura em Graus Celsius: ");
	scanf("%f", &celsius);
	
	fahrenheit = celsius * 9/5 + 32;
	
	printf("\nA temperatura em Fahrenheit e: %.1f\n\n", fahrenheit);
	
	system("pause");
}
