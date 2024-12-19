/*
Atividade 019
"Média Harmônica (vetor)"

Algoritmo para calcular a média harmônica de 5 números
inteiros positivos.

MH = n / somatoria de n termos 1/xi, começando i=1

Sendo:
- n: Total de Termos
- xi: Termo Atual do Vetor
*/

#include <stdio.h>
#include <stdlib.h>

int i, vetor[5] ;
float somatoria = 0.0, media_harmonica ;

main()
{
	for(i=0; i<5; i++)
	{
		printf("Insira o valor %i: ", i+1);
		scanf("%i", &vetor[i]);
		
		somatoria += 1.0 / vetor[i] ;
	}
	
	media_harmonica = 5 / somatoria ;
	
	printf("\nMedia Harmonica = %.2f\n\n", media_harmonica);
	
	system("pause");
}