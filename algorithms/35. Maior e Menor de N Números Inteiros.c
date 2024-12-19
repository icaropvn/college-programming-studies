// Teste 010 - Maior e Menor de N Números Inteiros

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int i, quantity, num, maior = 0, menor ;

main()
{
	printf("Quantos numeros deseja inserir? ");
	scanf("%i", &quantity);
	
	printf("\nInsira o numero inteiro 1: ");
	scanf("%i", &menor);
	
	for(i=2; i<quantity+1; i++)
	{
		printf("Insira o numero inteiro %i: ", i);
		scanf("%i", &num);
		
		if(num > maior)
			maior = num ;
		
		if(num < menor)
			menor = num ;
	}
	
	printf("\n\nMaior Numero: %i\nMenor Numero : %i\n\n", maior, menor);
	
	system("pause");
}
