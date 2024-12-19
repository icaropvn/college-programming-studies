/* Área do Triângulo: algoritmo para ler a base e altura do triângulo e imprimir a base, altura e área.
Verificar se a base e/ou a altura é negativa. Caso afirmativo, imprimir mensagem de erro e não calcular a área.
Caso ambos sejam negativos, imprimir mensagem e não calcular área. */

#include <stdio.h>
#include <stdlib.h>

float base, altura, area ;

main()
{
	printf("Insira a base: ");
	scanf("%f", &base);
	
	if(base < 0)
		printf("Impossivel calcular: Base Negativa");
	
	else
	{
		printf("Insira a altura: ");
		scanf("%f", &altura);
		
		if(altura < 0)
		{
			printf("Impossivel Calcular: Altura Negativa");
		}
		else
		{
			area = (base*altura)/2 ;
			printf("A area e %.1f m2", area);
		}
	}
		
	system ("pause");
	
}
