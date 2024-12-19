/*
Teste 014
Imprimir a soma dos quadrados dos 100 primeiros números pares e 100 primeiros ímpares
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int i, soma_pares = 0, soma_impares = 0, par = 2, impar = 1 ;

main()
{
	/*
	== RESOLUÇÃO MAIS SIMPLES ==
	
	for(i=1; i<201; i++)
	{
		if(i%2 == 0)
			soma_pares = soma_pares + pow(i, 2);
		else
			soma_impares = soma_impares + pow(i, 2);
	}
	*/
	
	for(i=1; i<201; i++)
	{
		soma_pares = soma_pares + pow(par, 2);
		par = par + 2 ;
		
		soma_impares = soma_impares + pow(impar, 2);
		impar = impar + 2 ;
	}
	
	printf("Soma Pares = %i\nSoma Impares = %i\n\n", soma_pares, soma_impares);
	
	system("pause");
}
