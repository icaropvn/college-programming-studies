/*
Atividade 024
"Verificando Existência - Vetores"

Algoritmo para ler um vetor de 5 números inteiros
e verificar a existência de número qualquer dentro
desse vetor.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int i, vetor[5], num, flag = 0 ;

main()
{
	setlocale(LC_ALL, "Portuguese");
	
	for(i=0; i<5; i++)
	{
		printf("Insira o valor %i: ", i+1);
		scanf("%i", &vetor[i]);
	}
	
	printf("\nInsira um numero para verificar sua existencia: ");
	scanf("%i", &num);
	
	for(i=0; i<5; i++)
	{
		if(num == vetor[i])
		{
			printf("\nO valor %i se encontra na posicao %i.\n\n", num, i+1);
			flag = 1 ;
		}
	}
	
	if(flag == 0)
		printf("\nO valor nao consta no vetor.\n\n");
	
	system("pause");
}