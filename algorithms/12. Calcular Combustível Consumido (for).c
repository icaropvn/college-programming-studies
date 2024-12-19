/* Elabore um algoritmo para calcular o consumo (Km/l) em cada trecho de uma 
   viagem com QUATRO trechos onde o tanque é abastecido antes da viagem 
   e no final de cada trecho. Calcular também o consumo total na viagem.*/
   
#include <stdio.h>
#include <stdlib.h>

int i, trechos ;
float dist, litros, consumo, soma_dist=0.0, litros_total=0.0 ;

main()
{
	printf("Quantos trechos na viagem foram feitos?\n");
	scanf("%i", &trechos);
	
	if(trechos > 0)
	{
		for(i=1; i<trechos+1; i++)
		{
		printf("Insira a distancia percorrida (trecho %i) (Km): ", i);
		scanf("%f", &dist);
		soma_dist = soma_dist + dist ;
		
		printf("Insira a quantidade de combustivel gasto (trecho %i) (L): ", i);
		scanf("%f", &litros);
		litros_total = litros_total + litros ;
		
		printf("\nDistancia Total: %.2f Km\n", soma_dist);
		printf("Litros Totais: %.2f L", litros_total);
		
		printf("\n\nConsumo Trecho %i: %.2f Km/L\n\n", i, consumo = dist / litros);
		}

		printf("Consumo Total: %.2f Km/L\n\n", consumo = soma_dist / litros_total);
	}
	else
		printf("ERRO! Insira um valor POSITIVO\n\n");
	
	system("pause");
}
