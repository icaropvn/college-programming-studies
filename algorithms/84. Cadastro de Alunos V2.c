// 001 - Cadastro de Alunos V2

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAX 3

struct dados_alunos
{
	int codigo, faltas ;
	char nome[50], status[3] ;
	float notas[2], media ;
};

typedef struct dados_alunos dados_alunos ;

void menu(int cont_alunos)
{
	printf("Total de Alunos: %i\n", cont_alunos);
	printf("1) Adicionar\n2) Listar\n3) Sair\nR: ");
}

void adicionar(dados_alunos aluno[], int cont_alunos)
{	
	if(cont_alunos < MAX)
	{
		printf("\nCódigo: ");
		scanf("%i", &aluno[cont_alunos].codigo);
		fflush(stdin);
		
		printf("Nome: ");
		scanf("%50[^\n]s", &aluno[cont_alunos].nome);
		fflush(stdin);
		
		printf("Nota Parcial: ");
		scanf("%f", &aluno[cont_alunos].notas[0]);
		
		printf("Nota Exame: ");
		scanf("%f", &aluno[cont_alunos].notas[1]);
		
		printf("Faltas: ");
		scanf("%i", &aluno[cont_alunos].faltas);
		
		printf("\n");
	}
	else
		printf("\nMÁXIMO DE ALUNOS REGISTRADOS\n\n");
}

void calcular(dados_alunos aluno[], int cont_alunos)
{
	aluno[cont_alunos].media = aluno[cont_alunos].notas[0]*0.4 + aluno[cont_alunos].notas[1]*0.6 ;
		
	if(aluno[cont_alunos].media >= 5.0)
		strcpy(aluno[cont_alunos].status, "APR");
	else
		strcpy(aluno[cont_alunos].status, "REP");
}

void listar(dados_alunos aluno[], int cont_alunos)
{
	int i ;
	
	if(cont_alunos > 0)
	{
		printf("\nCódigo\t\tNome\t\t\tParcial\t\tExame\tMédia\tFaltas\tStatus");
	
		for(i=0; i<cont_alunos; i++)	
			printf("\n%i\t\t%s\t\t\t%.1f\t\t%.1f\t%.1f\t%i\t%s", aluno[i].codigo, aluno[i].nome, aluno[i].notas[0], aluno[i].notas[1], aluno[i].media, aluno[i].faltas, aluno[i].status);
	}
	else
		printf("\nNenhum cadastro efetuado ainda. Lista vazia.");
	
	printf("\n\n");
}

int main()
{
	int cont_alunos = 0, user_answer ;
	dados_alunos aluno[MAX] ;
	
	setlocale(LC_ALL, "Portuguese");
	
	do
	{
		menu(cont_alunos);
		scanf("%i", &user_answer);
		
		switch(user_answer)
		{
			case 1:
				adicionar(aluno, cont_alunos);
				calcular(aluno, cont_alunos);
				cont_alunos++ ;	
				break;
			case 2:
				listar(aluno, cont_alunos);
				break;
			case 3:
				break;
			default:
				printf("\nResposta inválida.\n\n");
				break;
		}
		
		if(user_answer == 3)
			break;
		
	} while(1);
	
	printf("\nAté mais!");
	
	return 0;
}
