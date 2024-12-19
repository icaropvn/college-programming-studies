/*
Teste ???
"Desvio Padrão"

Algoritmo para calcular o desvio padrão de uma amostra de 5 números inteiros
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int i, amostra[5] ;
float media, soma = 0.0, desvio;

main()
{
	for(i=0; i<5; i++)
	{
		printf("Insira o numero %i da amostra: ", i+1);
		scanf("%i", &amostra[i]);
		
		soma += amostra[i] ;
		
	}
	
	media = soma / 5.0 ;
	soma = 0 ; // Zerar a variável para reutilização
	
	for(i=0; i<5; i++)
		soma += pow((amostra[i] - media), 2) ;
	
	desvio = sqrt(soma / 4); // Fórmula Geral -> desvio = sqrt(soma / (n - 1))
	
	printf("Desvio Padrao = %.2f\n\n", desvio);
	
	system("pause");
}
