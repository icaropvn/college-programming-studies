// maior e menor de três números inteiros não iguais

#include <stdio.h>
#include <stdlib.h>

int n1, n2, n3, maior, menor ;

main()
{
	printf("Insira o primeiro numero: ");
	scanf("%i", &n1);
	
	printf("Insira o segundo numero: ");
	scanf("%i", &n2);
	
	printf("Insira o terceiro numero: ");
	scanf("%i", &n3);
	
	if(n1 > n2)
	{
		if(n1 > n3)
		{
			maior = n1;
			if(n2 > n3)
				menor = n3;
			else
				menor = n2;
		}
		else
		{
			maior = n3;
			menor = n2;
		}
	}
	else
	{
		if(n1 > n3)
		{
			maior = n2;
			menor = n3;
		}
		else
		{
			if(n2 > n3)
			{
				maior = n2;
				menor = n1;
			}
			else
			{
				maior = n3;
				menor = n1;
			}
		}
	}
	
	printf("Maior: %i\n", maior);
	printf("Menor: %i\n\n", menor);
	
	system("pause");
}
