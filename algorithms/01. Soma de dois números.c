// Exemplo de cálculos simples

#include <stdio.h>
#include <stdlib.h>

int n1, n2, soma, produto ;

main()
{
	printf("Entre um numero inteiro: ") ;
	scanf("%i", &n1);
	printf("Entre outro numero inteiro: ") ;
	scanf("%i", &n2);
	
	soma = n1 + n2 ;
	produto = n1 * n2 ;
	
	printf("\nO valor da soma e: %i\n", soma);
	printf("O valor do produto e: %i\n\n", produto);
	
	system("pause");
}
