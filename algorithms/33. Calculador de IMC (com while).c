/* Teste 008
Faça um algoritmo que receba o peso (Kg) e altura (m) 
de um número indeterminado de pessoas. Calcule e mostre:
a)	Índice de Massa Corporal (IMC) de cada pessoa.        
	IMC= (peso/(altura*altura))
b)	O valor médio do IMC.
c)	O menor valor calculado do IMC.
d)	O menor peso.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int num = 1, calc_true = 0 ;
float peso, altura, imc, peso_menor, imc_menor, soma_imc = 0 ;
char answer ;

main()
{
	printf("Deseja calcular o IMC?\nS - Sim\nN - Nao\n");
	answer = getche() ;
	printf("\n");
	
	if(answer == 'S' || answer == 's')
	{
		calc_true = 1 ;
		
		printf("\nInsira o peso 1 (Kg): ");
		scanf("%f", &peso);
		
		peso_menor = peso ;
		
		printf("Insira a altura 1 (m): ");
		scanf("%f", &altura);
		
		imc = peso/(altura*altura);
		soma_imc = soma_imc + imc ;
		imc_menor = imc ;
		
		printf("IMC 1 - %.2f", imc);
	}
	
	while(answer == 'S' || answer == 's')
	{
		num++ ;
		printf("\n\nInsira o peso %i (Kg): ", num);
		scanf("%f", &peso);
		
		printf("Insira a altura %i (m): ", num);
		scanf("%f", &altura);
		
		imc = peso/(altura*altura);
		printf("IMC %i - %.2f", num, imc);
		
		soma_imc = soma_imc + imc ;
		
		if(peso < peso_menor)
			peso_menor = peso ;
		
		if(imc < imc_menor)
			imc_menor = imc ;
			
		printf("\n\nCalcular outro IMC?\nS - Sim\nN - Nao\n");
		answer = getche() ;
	}
	
	if(calc_true == 1)
		printf("\n\nIMC Medio - %.2f\nMenor Peso - %.2f\nMenor IMC - %.2f\n\n", soma_imc / num, peso_menor, imc_menor);
	
	system("pause");
}
