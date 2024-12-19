/*
Atividade 018

Algoritmo para ler as multas (por código)
Leve (0).......... 2 pontos
Moderada (1)...... 3 pontos
Grave (2)......... 5 pontos
Gravíssima (3).... 10 pontos

Calcular e imprimir o total de pontos na carteira.

Terminar quando o usuário não quiser mais informar multas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int codigo, pontos = 0, flag = 0, multas ;
char answer ;

main()
{
	do
	{
		if(flag == 1)
			printf("\n");
		
		printf("Qual tipo de multa voce cometeu?\n0 - Leve\n1 - Media\n2 - Grave\n3 - Gravissima\n");
		scanf("%i", &codigo);
		
		multas++ ;
		
		if(codigo == 0)
			pontos += 2 ;
		else if(codigo == 1)
			pontos += 3 ;
		else if(codigo == 2)
			pontos += 5;
		else if(codigo == 3)
			pontos += 10;
		else
		{	
			printf("Digite um codigo valido.\n\n");
			multas-- ;
		}
		
		printf("Deseja inserir mais multas (s/n)?\n");
		answer = getche();
		flag = 1 ;
		
	} while(answer == 's' || answer == 'S');
	
	printf("\n\nVoce cometeu %i multa(s).", multas);
	printf("\nVoce possui %i pontos na sua CNH.\n\n", pontos);
	
	system("pause");
}
