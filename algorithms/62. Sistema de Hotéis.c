/*
Teste 035
"Sistema de Hotéis"

Suponha que você esteja desenvolvendo o sistema de um hotel que deva 
exibir mensagens na recepção para diferentes ações dos hospedes, são elas:

1. Fazer Check-in
2. Chamar serviço de quarto
3. Fazer pedido
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int choice ;

main()
{
	setlocale(LC_ALL, "Portugese");
	
	do
	{	
		printf("Digite o número correspondente ao serviço desejado:\n1 - Fazer Check-in\n2 - Chamar Serviço de Quarto\n3 - Fazer Pedido\nR: ");
		scanf("%i", &choice);
		
		switch(choice)
		{
			case 1:
				printf("<check-in choice>\n\n");
				break;
			case 2:
				printf("<serviço de quarto choice>\n\n");
				break;
			case 3:
				printf("<pedido choice>\n\n");
				break;
			default:
				printf("Escolha inválida.\n\n");
				break;
		}
	} while(choice != 1 && choice != 2 && choice != 3);
	
	system("pause");
}
