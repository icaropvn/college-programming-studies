// Teste 005 - Média Simples de N números

#include <stdio.h>
#include <stdlib.h>

int i, quantity, num, num_soma = 0, confirm = 1 ;
float media ;

main()
{
	while(confirm == 1)
	{
		printf("Gostaria de fazer a media de quantos numeros? ");
		scanf("%i", &quantity);
	
		for(i=1; i<quantity+1; i++)
		{
			printf("\n\nNumero %i: ", i);
			scanf("%i", &num);
			
			num_soma = num_soma + num ;
			printf("Soma total ate agora: %i", num_soma);
		}
	
		printf("\n\nMedia dos %i Numeros Digitados: %.2f\n\n", quantity, media = 1.0*num_soma / quantity);
		
		printf("Gostaria de fazer outra media?\n1 - Sim\n0 - Nao\n");
		scanf("%i", &confirm);
		
		if(confirm == 0)
		{
			printf("\nAte mais!\n\n");
			system("pause");
		}
		else if(confirm != 1)
		{
			while(confirm != 0 && confirm != 1)
			{
				printf("\nERRO!\nInsira uma resposta valida.\n");
				scanf("%i", &confirm);	
			}
		}		
	}
}
