/*
Teste 055
"Posições"

Algoritmo para preencher automaticamente um vetor de 50
posições inteiras. Mostrar ao final a POSIÇÃO dos números
PARES MAIORES que 33.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
{
	int i ;
	int vetor[50], posicoes[50] ;
	
	setlocale(LC_ALL, "Portuguese");
	srand((unsigned)time(NULL));
	
	for(i=0; i<50; i++)
	{
		vetor[i] = rand() % 100 ;
		posicoes[i] = 0 ;
		
		if(vetor[i] % 2 == 0 && vetor[i] > 33)
			posicoes[i] = i ;
	}
	
	printf("Vetor Completo: [");
	
	for(i=0; i<50; i++)
	{
		if(i % 10 == 0 && i != 0)
			printf("\n		 ");
		
		if(i == 49)
			printf("%2.1i]", vetor[i]);
		else
			printf("%2.1i, ", vetor[i]);
	}
	
	printf("\n\nPosições dos números pares maiores que 33: ");
	
	for(i=0; i<50; i++)
	{
		if(posicoes[i] != 0)
			printf("%i, ", posicoes[i]+1);
	}
	
	printf("\n");
	
	return 0;
}
