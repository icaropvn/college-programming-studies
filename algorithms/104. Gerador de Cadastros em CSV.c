/*
Sistema de cadastramento de alunos na UNAERP

1. Alunos podem ser cadastrados através de código (RA), etapa (semestre), ano de início, mensalidade, bolsa e e-mails (máximo de 3)

2. É possível listar o cadastramentos efetuados no ciclo atual do programa.

3. É possível gerar um arquivo CSV contendo todas as informações de cadastro do ciclo atual.

4. É possível sair do programa.

-- DESVANTAGENS --

- Não é possível alterar as informações de cadastros já efetuados

- Os cadastros não se mantêm após o fim de um ciclo, porque as informações são sobrescritas no arquivo CSV

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#define TAM 50

typedef struct
{
	char emails[50];
} emails;

typedef struct
{
	int codigo, etapa, ano_inicio;
	float mensalidade, bolsa;
	int quant_emails;
	emails email[3];
} dadosAlunos;

void menu(dadosAlunos alunos[], int *contador);
void opcaoEscolhida(int resposta, dadosAlunos alunos[], int *contador);
void cadastrarAluno(dadosAlunos alunos[], int *contador);
void lerEmail(dadosAlunos alunos[], int contador);
void listarCadastros(dadosAlunos alunos[], int contador);
void imprimirEmails(dadosAlunos alunos[], int j);
void gerarArquivo(dadosAlunos alunos[], int contador);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	dadosAlunos alunos[TAM];
	int contador = 0;
	
	menu(alunos, &contador);
	
	return 0;
}

void menu(dadosAlunos alunos[], int *contador)
{
	int resposta = 0;
	
	while(resposta != 4)
	{
		printf("Alunos Cadastrados: %02i\nEscolha uma opção:\n", *contador);
		printf("[1] Cadastrar Novo Aluno\n[2] Listar Cadastros\n[3] Gerar Arquivo CSV\n[4] Sair\n");
		printf("R: ");
		scanf("%i", &resposta);
		
		opcaoEscolhida(resposta, alunos, &*contador);
	}
}

void opcaoEscolhida(int resposta, dadosAlunos alunos[], int *contador)
{	
	switch(resposta)
	{
		case 1:
			cadastrarAluno(alunos, &*contador);
			break;
		case 2:
			listarCadastros(alunos, *contador);
			break;
		case 3:
			gerarArquivo(alunos, *contador);
			break;
		case 4:
			break;
		default:
			printf("Ops! Opcao Invalida.");
			break;
	}
}

void cadastrarAluno(dadosAlunos alunos[], int *contador)
{
	printf("--------------------------------");
	
	printf("\nInsira o RA: ");
	scanf("%i", &alunos[*contador].codigo);
	
	printf("Insira a etapa: ");
	scanf("%i", &alunos[*contador].etapa);
	
	printf("Insira o ano de inicio: ");
	scanf("%i", &alunos[*contador].ano_inicio);
	
	printf("Insira a mensalidade: R$");
	scanf("%f", &alunos[*contador].mensalidade);
	
	printf("Insira valor da bolsa (se nao houver responder 0): R$");
	scanf("%f", &alunos[*contador].bolsa);
	
	printf("--------------------------------");
	
	lerEmail(alunos, *contador);
	
	(*contador)++;
}

void lerEmail(dadosAlunos alunos[], int contador)
{
	int i;
	int verificacao = 0;
	
	while(verificacao == 0)
	{
		printf("\nQuantos e-mails deseja cadastrar?\nR: ");
		scanf("%i", &alunos[contador].quant_emails);
		
		verificacao = verificarQuantEmails(contador, alunos[contador].quant_emails);
	}
	
	for(i=0; i<alunos[contador].quant_emails; i++)
	{
		printf("\nInsira o e-mail %02i: ", i+1);
		scanf(" %50[^\n]", alunos[contador].email[i].emails);
	}
	
	printf("--------------------------------\n");
}

int verificarQuantEmails(int contador, int quant_emails_escolhida)
{
	if(quant_emails_escolhida > 3)
	{
		printf("\nQuantidade inválida. Você só pode cadastrar até 3 e-mails.\n");
		return 0;
	}
	else
		return 1;
}

void listarCadastros(dadosAlunos alunos[], int contador)
{
	int i;
	
	if(contador == 0)
	{
		printf("\n========================");
		printf("\nNenhum aluno cadastrado.");
		printf("\n========================\n\n");
	}
	else
	{
		printf("\n|---RA---|-ETAPA-|-ANO DE INICIO-|-MENSALIDADE-|---BOLSA---|-E-MAILS--------------------------------------------|\n");
		
		for(i=0; i<contador; i++)
		{
			if(contador > 1)
				printf("|-------------------------------------------------------------------------------------------------------------|\n");
			
			printf("| %06i |    %02i |          %4i |  R$%8.2f |", alunos[i].codigo, alunos[i].etapa, alunos[i].ano_inicio, alunos[i].mensalidade);
			
			if(alunos[i].bolsa == 0)
		        printf("         - ");
		    else
		        printf(" R$%7.2f ", alunos[i].bolsa);
			
			imprimirEmails(alunos, i);
		}
		
		printf("|---------------------------------------------------------------------------------------------------------------|\n\n");
	}
}

void imprimirEmails(dadosAlunos alunos[], int j)
{
	int i;
	
	for(i=0; i<alunos[j].quant_emails; i++)
	{
		if(i == 0)
			printf("| %50s |\n", alunos[j].email[i].emails);
		else
			printf("|                                                          | %50s |\n", alunos[j].email[i].emails);
	}
		
}

void gerarArquivo(dadosAlunos alunos[], int contador)
{
	FILE *file;
	char nome_escolhido[50];
	int i, j;
	
	printf("\n---------------------------------");
	printf("\nEscolha o nome do arquivo CSV: ");
	scanf(" %50[^\n]", nome_escolhido);
	
	strcat(nome_escolhido, ".csv");
	
	file = fopen(nome_escolhido, "w");
	
	for(i=0; i<contador; i++)
	{
		fprintf(file, "%06i; %02i; %4i; %08.2f; %07.2f;", alunos[i].codigo, alunos[i].etapa, alunos[i].ano_inicio, alunos[i].mensalidade, alunos[i].bolsa);
		
		for(j=0; j<alunos[i].quant_emails; j++)
		{
			if(j == alunos[i].quant_emails-1)
				fprintf(file, "%s\n", alunos[i].email[j].emails);
			else
				fprintf(file, " %s;", alunos[i].email[j].emails);
		}
	}
	
	sleep(1);
	printf("\nArquivo gerado com sucesso!");
	sleep(2);
	
	printf("\n---------------------------------\n\n");
}
