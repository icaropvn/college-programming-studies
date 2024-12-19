// Tabuada (for)

#include <stdio.h>
#include <stdlib.h>

int i, num, tab, end, confirm = 1 ;

main()
{
	while(confirm == 1)
	{
		printf("Insira um numero para ser a base da tabuada: ");
		scanf("%i", &num);
	
		printf("Insira ate quanto o valor %i sera multiplicado: ", num);
		scanf("%i", &end);
	
		for(i=1; i<end+1; i++)
		{
			tab = num*i ;
			printf("%i x %2.i = %3.i\n", num, i, tab);
		}
	
		printf("\nDeseja fazer outra tabuada?\n[1] Sim\n[0] Nao\n");
		scanf("%i", &confirm);

		if(confirm == 0)
			system("pause");
		else if(confirm != 1)
			while(confirm != 0 && confirm != 1)
			{
				printf("ERRO! Digite uma resposta valida.\n");
				scanf("%i", &confirm);	
			}	
	}
}
