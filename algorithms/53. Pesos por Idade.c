/*
Teste 027
"Pesos por Idade"

Algoritmo para receber a idade e o peso de 15 pessoas.
Calcular e mostrar as médias dos pesos das pessoas da mesma faixa etária.
As faixas etárias são: de 1 a 10 anos, de 11 a 20 anos, de 21 a 30 anos e maiores de 31 anos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int i, age, kid = 0, young = 0, mid = 0, elder = 0, flag = 0 ;
float weight, kid_w = 0.0, young_w = 0.0, mid_w = 0.0, elder_w = 0.0 ;

main()
{
	setlocale(LC_ALL, "Portuguese");
	
	for(i=1; i<16; i++)
	{
		if(flag == 1)
			printf("\n");
		
		printf("Qual é sua idade? ");
		scanf("%i", &age);
		
		printf("Qual é o seu peso (Kg)? ");
		scanf("%f", &weight);
		
		if(age < 11)
		{
			kid++ ;
			kid_w += weight ;
		}
		else if(age < 21)
		{
			young++ ;
			young_w += weight ;
		}
		else if(age <= 31)
		{
			mid++ ;
			mid_w += weight ;
		}
		else
		{
			elder++ ;
			elder_w += weight ;
		}
		
		flag = 1 ;
	}
	
	printf("\nMédia de pesos por faixa etária:\n1 - 10: %.2fKg\n11 - 20: %.2fKg\n", kid_w/kid, young_w/young);
	printf("21 - 31: %.2fKg\nMaior que 31: %.2fKg\n\n", mid_w/mid, elder_w/elder);
	
	system("pause");
}
