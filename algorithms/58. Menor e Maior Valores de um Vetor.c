/*
Teste 032
"Menor e Maior Valores de um Vetor"

Algoritmo para ler 5 valores, colocá-los em um vetor, imprimir o primeiro maior, o primeiro menor deles
e suas respectivas posições dentro do vetor.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int i, valores[5] ;
int maior, menor ;
int i_maior, i_menor ;

main()
{
	setlocale(LC_ALL, "Portuguese");
	
	for(i=0; i<5; i++)
	{
		printf("Insira o valor %i: ", i+1);
		scanf("%i", &valores[i]);
		
		if(i == 0)
		{
			menor = valores[0] ;
			maior = valores[0] ;
		}
		
		if(valores[i] < menor)
		{	
			menor = valores[i] ;
			i_menor = i ;
		}
			
		if(valores[i] > maior)
		{	
			maior = valores[i] ;
			i_maior = i ;
		}
	}
	
	printf("\nMenor Valor: %i\nMaior Valor: %i\n", menor, maior);
	printf("\nPosição do Menor: %i (índice %i)\n", i_menor+1, i_menor);
	printf("Posição do Maior: %i (índice %i)\n\n", i_maior+1, i_maior) ;
	
	system("pause");
}
