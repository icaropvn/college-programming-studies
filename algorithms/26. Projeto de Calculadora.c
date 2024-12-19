/* se
quisermos
comentarios
em mais 
de uma
linha */

#include <stdio.h>
#include <stdlib.h>

int n1soma, n2soma, soma, resposta, n1menos, n2menos, diferenca, n1produto, n2produto, produto;

main()
{
	printf("O que voce deseja fazer?\n");
	printf("Digite 1 para Soma\nDigite 2 para Subtracao\nDigite 3 para Multiplicacao\n\n");
	scanf("%i", &resposta);
	
	if(resposta == 1)
	{
		printf("Insira um numero: ");
		scanf("%i", &n1soma);
		printf("Insira outro numero: ");
		scanf("%i", &n2soma);
		
		soma = n1soma + n2soma;
		
		printf("\nA soma e: %i\n", soma);
		return 0;
	}
	
	else if(resposta == 2)
	{
		printf("Insira um numero: ");
		scanf("%i", &n1menos);
		printf("Insira outro numero: ");
		scanf("%i", &n2menos);
		
		diferenca = n1menos - n2menos;
		
		printf("\nA diferenca e: %i\n", diferenca);
		return 0;
	}
	
	else if(resposta == 3)
	{
		printf("Insira um numero: ");
		scanf("%i", &n1produto);
		printf("Insira outro numero: ");
		scanf("%i", &n2produto);
		
		produto = n1produto * n2produto;
		
		printf("\nO produto e: %i\n", produto);
		return 0;
	}
	
	else if(resposta < 1 || resposta > 3)
	{
		printf("Erro: Digite um comando da lista acima\n");
		
		
	}
	
	system("pause");
}
