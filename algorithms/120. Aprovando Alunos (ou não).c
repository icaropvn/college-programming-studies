/*
014 - Aprovando Alunos (ou não)

Escreva uma função que receba 4 notas e retorne um valor verdade (0 ou 1),
de forma que identifique se o aluno está aprovado ou não. Considere
a média de corte 7,0.
*/

#include <stdio.h>
#include <stdlib.h>

int verificar(float notas[]);

int main()
{
	int i ;
	float notas[4] ;
	
	printf("Aluno: Almeida Montgomery\n\n");
	
	for(i=0; i<=3; i++)
	{
		printf("Nota 0%i: ", i+1);
		scanf("%f", &notas[i]);
	}
	
	if(verificar(notas) == 1)
		printf("\nAluno APROVADO\n");
	else
		printf("\nAluno REPROVADO\n");
	
	return 0;
}

int verificar(float notas[])
{
	float media ;
	
	media = (notas[0] + notas[1] + notas[2] + notas[3])/4 ;
	
	if(media >= 7.0)
		return 1;
	else
		return 0;
}
