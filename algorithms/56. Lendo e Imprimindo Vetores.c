/*
Teste 030
"Lendo e Imprimindo Vetores"

Algoritmo para ler valores do usuário e atribuí-los a um vetor.
*/

#include <stdio.h>
#include <stdlib.h>

int i, flag = 0 ;
float vetor[5], soma ;

main()
{	
	printf("Insira 5 valores:\n");
	
	for(i=0; i<5; i++)
	{
		scanf("%f", &vetor[i]);
		soma += vetor[i] ;
	}
	
	printf("\nValores inseridos: ");
	
	for(i=0; i<5; i++)
	{
		if(i == 4)
			flag = 1 ;
		
		if(flag == 0)
			printf("%.2f, ", vetor[i]);
		else
			printf("%.2f", vetor[4]);
	}
	
	printf("\nSoma dos Valores: %.2f", soma);
	
	printf("\n\n");
	
	system("pause");
}
