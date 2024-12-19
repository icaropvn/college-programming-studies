/* Algoritmo para calcular o valor do salário família que um colaborador recebe
Quem recebe até R$806,80 => R$41,37 p/ filho
Quem recebe mais que R$806,80 => R$29,16 p/ filho */

#include <stdio.h>
#include <stdlib.h>

int filhos ;
float salariocolab, salariof ;

main()
{
	printf("Insira o salario do colaborador: ");
	scanf("%f", &salariocolab);
	
	printf("Insira o numero de filhos do colaborador: ");
	scanf("%i", &filhos);
	
	if(salariocolab <= 806.80)
	{
		salariof = salariocolab + 41.37*filhos;
		printf("O salario familia e: R$ %.2f\n\n", salariof);
	}
	else
	{
		salariof = salariocolab + 29.16*filhos;
		printf("O salario familia e: R$ %.2f\n\n", salariof);
	}

	system("pause");
}
