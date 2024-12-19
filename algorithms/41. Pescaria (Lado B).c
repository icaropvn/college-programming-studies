/*
Teste 016 - Pescaria (Lado B)

Algoritmo para ler o limite de peso de peixes pescados e
imprimir o total de peixes pescados.

Quando o limite for ultrapassado, devolver o peixe e imprimir o total levado e o número de peixes.
Prever a possibilidade de interromper a pescaria antes de alcançar o limite diário.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

int answer = 1, n_peixes = 1 ;
float peso_limite, peso_peixe, peso_total = 0 ;

main()
{
	setlocale(LC_ALL, "Portuguese");
	
	printf("Limite de Peso Hoje (Kg): ");
	scanf("%f", &peso_limite);
	
	do
	{
		printf("\nPeso do Peixe %i: ", n_peixes);
		scanf("%f", &peso_peixe);
		n_peixes++ ;
		
		if(peso_peixe > 0)
			peso_total += peso_peixe ;
		else
		{
			n_peixes-- ;
			printf("Colocar um peso válido.\n");
		}
		
		if(peso_total < peso_limite && peso_peixe > 0)
		{
			printf("Continuar?\n1 - Sim\n0 - Não\nR: ");
			scanf("%i", &answer);
		}
		
	} while(peso_total < peso_limite && answer != 0);
	
	n_peixes-- ;
	
	if(peso_total > peso_limite)
	{
		printf("\nPeixes Levados: %i", n_peixes-1);
		printf("\nPeso Total: %.3fKg\n", peso_total - peso_peixe);
		printf("1 Peixe foi deixado, excedendo o peso limite em %.3fKg\n\n", peso_total - peso_limite);
	}
	else
	{
		printf("\nPeixes Levados: %i", n_peixes);
		printf("\nPeso Total: %.3fKg\n\n", peso_total);
	}
	
	system("pause");
}
