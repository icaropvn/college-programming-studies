/*
Atividade 020
"Vetor Suave"

Algoritmo para analisar dados de experimentos e calcular a suavização destes.

Para todos os valores do vetor (exceto o primeiro e o último) substituir
pelo valor dado na fórmula:

(Vi-1 + Vi + Vi+1) / 3
Sendo Vi um valor do vetor original
*/

#include <stdio.h>
#include <stdlib.h>

int i ;
float vetor[5], suave[5], valor_suave ;

main()
{
	for(i=0; i<5; i++)
	{
		printf("Insira o valor %i do experimento: ", i+1);
		scanf("%f", &vetor[i]);
	}
	
	suave[0] = vetor[0] ;
	suave[4] = vetor[4] ;
	
	for(i=1; i<4; i++)
		suave[i] = (vetor[i-1] + vetor[i] + vetor[i+1]) / 3 ;
	
	printf("\nVetor Suave = ");
	
	for(i=0; i<5; i++)
		printf("%.2f ", suave[i]);
	
	printf("\n\n");
	
	system("pause");
}
