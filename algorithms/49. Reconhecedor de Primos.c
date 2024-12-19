/*
Teste 018
"Reconhecedor de Primos"

Algoritmo para ler um número n e retornar o próximo número
primo a partir dele.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int num, aux, divisor ;

main()
{
	setlocale(LC_ALL, "Portuguese");
	
	printf("Insira um número: ");
	scanf("%i", &num);
	
	if(num != 1)
	{
		for(aux=1; aux<10; aux++)
		{
			if(num != aux && num % aux == 0)
				divisor++ ;
		}
	
	    if(divisor == 1)	
		    printf("O número é primo.\n\n");
	    else
		    printf("O número não é primo.\n\n");
	}
	
	else
		printf("O número 1 é inválido.\n\n");
	
	system("pause");
}
