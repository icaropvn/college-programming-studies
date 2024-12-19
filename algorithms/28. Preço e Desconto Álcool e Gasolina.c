/* Teste preço gasolina/alcool com desconto
ler tipo de combustivel e quantidade (L)
imprimir valor bruto, desconto e valor com desconto

alcool - 2,09
3% desc abaixo de 20L
5% desc acima de 20L

gasolina - 2,99
4% desc abaixo de 20L
6% desc acima de 20L

como fazer para tirar a pergunta da quantidade quando não é escolhido uma letra valida?????
*/

#include <stdio.h>
#include <stdlib.h>

int flag ;
float litros, vbruto, valordesc, desconto ;
char tipo, tipo_final ;

main()
{
	printf("Qual o tipo de combustivel (A/G)?\n");
	scanf("%c", &tipo);
	
	if (tipo == 'A' || tipo == 'a')
	{
		printf("\nInsira a quantidade (L): ");
		scanf("%f", &litros);
		
		tipo_final = 'A' ;
		vbruto = 2.09*litros;
		
		if (litros > 20)
			desconto = vbruto*0.05;
		else
			desconto = vbruto*0.03;
	}
	else if (tipo == 'G' || tipo == 'g')
	{
		printf("\nInsira a quantidade (L): ");
		scanf("%f", &litros);
		
		tipo_final = 'G' ;
		vbruto = 2.99*litros;
		
		if (litros > 20)
			desconto = vbruto*0.06;
		else
			desconto = vbruto*0.04;
	}
	else
	{
		flag = 1 ;
		printf("\nERRO! Insira um tipo valido\n");	
	}

	if (flag == 0)
	{
		valordesc = vbruto - desconto ;
		printf("Tipo............%c\n", tipo_final);
		printf("Valor bruto.....R$%4.2f\n", vbruto);
		printf("Desconto........R$%4.2f\n", desconto);
		printf("Valor Final.....R$%4.2f\n", valordesc);	
	}
	
	system("pause");
}
