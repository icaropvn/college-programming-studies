// Teste 009 - Calculador de Media Simples e Ponderada (com escolha)

#include <stdio.h>
#include <stdlib.h>

int i, quantity, answer ;
float media, valor, peso, produto, produto_final = 0, soma_peso = 0, soma_final = 0;

main()
{
	printf("Qual media gostaria de calcular?\n1 - Media Simples\n2 - Media Ponderada\n0 - Sair\n");
	scanf("%i", &answer);
	
	while(answer != 0)
	{
		if(answer == 2)
		{
			printf("\nQuantos valores gostaria de fazer a media? ");
			scanf("%i", &quantity);
	
			for(i=1; i<quantity+1; i++)
			{
				printf("\nInsira o valor %i: ", i);
				scanf("%f", &valor);
				printf("Peso do valor %i: ", i);
				scanf("%f", &peso);
				
				soma_peso =  soma_peso + peso ;
				produto = valor*peso ;
				produto_final = produto_final + produto ;
			}
		
			media = produto_final / soma_peso ;
			printf("\nMedia: %.2f\n\n", media);
		}
		
		else if(answer == 1)
		{
			printf("\nQuantos valores gostaria de fazer a media? ");
			scanf("%i", &quantity);
		
			for(i=1; i<quantity+1; i++)
			{
				printf("Insira o valor %i: ", i);
				scanf("%f", &valor);
				
				soma_final = soma_final + valor ;
			}
			
			media = soma_final / quantity ;
			printf("\nMedia: %.2f\n\n", media);
		}
		
		else
			printf("\nErro. Digite um valor valido.\n\n");
		
			printf("Qual media gostaria de calcular?\n1 - Media Simples\n2 - Media Ponderada\n0 - Sair\n");
			scanf("%i", &answer);
	}
	
	printf("\nAte mais!\n");
	system("pause");
}
