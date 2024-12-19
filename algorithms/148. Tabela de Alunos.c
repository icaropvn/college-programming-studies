// Lista - Exercícios 18 e 19

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define L 60
#define C 3

void formar_estatistica(float tabela[L][C]);
void imprimir(float tabela[L][C]);
int aprovados(float tabela[L][C]);

int main()
{
	float tabela[L][C];
	
	srand(time(NULL));
	
	formar_estatistica(tabela);
	imprimir(tabela);
	
	printf("Quantidade de Alunos Aprovados = %i\n", aprovados(tabela));
	
	return 0;
}

void formar_estatistica(float tabela[L][C])
{
	int i, j;
	
	for(i=0; i<L; i++)
	{
		for(j=0; j<C; j++)
		{
			if(j == 2)
				tabela[i][j] = (tabela[i][j-2] + tabela[i][j-1]) / 2 ;
			else
				tabela[i][j] = (float)(rand() % 11) / ((rand() % 11) + 1) ;
		}
	}
}

void imprimir(float tabela[L][C])
{
	int i, j;
	
	printf("| Nº Aluno | Nota P. | Nota E. |  Média  |\n");
	printf("|----------------------------------------|\n");
	
	for(i=0; i<L; i++)
	{
		for(j=0; j<C; j++)
		{
			if(j == 0)
				printf("| Aluno %2.i | %7.1f ", i+1, tabela[i][j]);
			else if(j == 2)
				printf(" %7.1f |", tabela[i][j]);
			else
				printf("| %7.1f |", tabela[i][j]);
		}
		printf("\n");
	}
	
	printf("|----------------------------------------|\n\n");
}

int aprovados(float tabela[L][C])
{
	int i, j;
	int aprovados = 0;
	
	for(i=0; i<L; i++)
	{
		if(tabela[i][2] >= 5.0)
			aprovados++;
	}
	
	return aprovados;
}
