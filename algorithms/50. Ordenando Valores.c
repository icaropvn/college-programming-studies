/*
Teste 024
"Ordenando Valores"

Algoritmo para ler três valores (A, B, C) e mostre-os na ordem lida.
Em seguida, mostrar em ordem crescente e decrescente.
*/

#include <stdio.h>
#include <stdlib.h>

int i, a, b, c, num, maior, medio, menor ;

main()
{
	printf("Insira o valor A: ");
	scanf("%i", &a);
	
	menor = a ;
	maior = a ;
	
	for(i=2; i<4; i++)
	{	
		if(i == 2)
		{
			printf("Insira o valor B: ");
			scanf("%i", &num);
			b = num ;
		}
		else
		{
			printf("Insira o valor C: ");
			scanf("%i", &num);
			c = num ;
		}
		
		if(num < menor)
			menor = num ;
			
		if(num > maior)
			maior = num ;
	}
	
	if(a == maior && c == menor || c == maior && a == menor)
		medio = b ;
	else if(a == maior && b == menor || b == maior && a == menor)
		medio = c ;
	else if(c == maior && b == menor || b == maior && c == menor)
		medio = a ;
			
	printf("\nValor A: %i\nValor B: %i\nValor C: %i\n\n", a, b, c);
	
	printf("Ordem Crescente:\n%i - %i - %i", menor, medio, maior);
	
	printf("\n\nOrdem Decrescente:\n%i - %i - %i\n\n", maior, medio, menor);
	
	system("pause");
}
