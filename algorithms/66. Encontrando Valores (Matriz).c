/*
Teste 039
"Encontrando Valores (Matriz)"

Algoritmo para ler duas matrizes e buscar seus elementos (?).
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int i, j, a[3][3], value ;

main()
{
	setlocale(LC_ALL, "Portuguese");
	
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("Insira o valor da posição A[%i,%i]: ", i+1, j+1);
			scanf("%i", &a[i][j]);
		}
	}
	
	printf("\nInsira o valor a ser procurado na matriz A: ");
	scanf("%i", value);
	
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			if(value == a[i][j])
			{
				printf("O valor %i se encontra na posição A[%i, %i]\n\n", value, i+1, j+1);
				i = 3 ;
				j = 3 ;
			}
		}
	}
	
	system("pause");
}
