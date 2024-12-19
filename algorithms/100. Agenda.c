/* Algoritmo que simula o funcionamento de uma agenda */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct
{
	int hora, minutos;
	char descricao[50];
} compromisso;

typedef struct
{
	compromisso compromissos[10];
	int contador_compromisso;
	int dia;
} agenda;

typedef struct
{
	agenda agenda[5][7];
} mes;

void preencherMeses(mes meses[], int meses_31[], int meses_30[]);
int verificarMes(int mes, int meses_31[], int meses_30[]);

void registrarNome(char nome[]);

void menu(char nome[], mes meses[], int meses_31[], int meses_30[]);
int escolherMes();
int escolherTipoAgenda(mes meses[]);

void marcarCompromisso(int mes_escolhido, mes meses[], int meses_31[], int meses_30[]);
int marcarDataCompromisso(int mes_escolhido, mes meses[], int meses_31[], int meses_30[]);
int procurarDiaNaAgenda(int dia, int mes_escolhido, mes meses[]);
void marcarHoraCompromisso(mes meses[], int mes_escolhido, int ind_semana, int ind_dia);

void imprimirMesUnico(int mes_escolhio, mes meses[]);
void imprimirAno(mes meses[]);
void marcarDescricaoCompromisso();
void imprimirCompromissosMesUnico(mes meses[], int mes_escolhido);
void imprimirCompromissosAno(mes meses[]);

int main()
{
	char nome[50];
	int meses_31[7] = {1, 3, 5, 7, 8, 10, 12};
	int meses_30[4] = {4, 6, 9, 11};
	mes meses[12];
	
	setlocale(LC_ALL, "Portuguese");
	
	preencherMeses(meses, meses_31, meses_30);
	
	registrarNome(nome);
	
	menu(nome, meses, meses_31, meses_30);
	
	return 0;
}

void preencherMeses(mes meses[], int meses_31[], int meses_30[])
{
	int i, j, k;
	int contador_dia = 1;
	int mes_overflow_flag = 0;
	
	for(i=0; i<12; i++)
	{
		mes_overflow_flag = 0;
		contador_dia = 1;
		
		for(j=0; j<5; j++)
		{
			for(k=0; k<7; k++)
			{
				// transformar esse bloco inteiro numa funcao propria
				meses[i].agenda[j][k].contador_compromisso = 0;
				
				meses[i].agenda[j][k].dia = contador_dia;
				
				if(verificarMes(i+1, meses_31, meses_30) == 0)
				{
					if(contador_dia == 31)
					{
						mes_overflow_flag = 1;
						contador_dia = 0;
					}
				}
				else if(verificarMes(i+1, meses_31, meses_30) == 1)
				{
					if(contador_dia == 30)
					{
						mes_overflow_flag = 1;
						contador_dia = 0;
					}
				}
				else
				{
					if(contador_dia == 29)
					{
						mes_overflow_flag = 1;
						contador_dia = 0;
					}
				}
				
				if(mes_overflow_flag == 0)
					contador_dia++;
			}
		}
	}
}

int verificarMes(int mes, int meses_31[], int meses_30[])
{
	int i;
	
	if(mes == 2)
		return 2;
		
	for(i=0; i<4; i++)
	{
		if(meses_30[i] == mes)
			return 1;
	}
	
	return 0;
}

void registrarNome(char nome[])
{
	printf("Insira o nome de usuário: ");
	scanf("%[^\n]", nome);
	
	fflush(stdin);
}

void menu(char nome[], mes meses[], int meses_31[], int meses_30[])
{
	int answer;
	int mes;
	int agenda_escolhida;
	
	while(answer != 3)
	{
		printf("\nBem-vindo à sua agenda 2024, %s!", nome);
		printf("\n[1] Marcar Compromisso\n[2] Ver Agenda\n[3] Sair\nR: ");
		scanf("%i", &answer);
		
		switch(answer)
		{
			case 1:
				mes = escolherMes();
				
				imprimirMesUnico(mes, meses);
				marcarCompromisso(mes, meses, meses_31, meses_30);
				break;
			case 2:
				escolherTipoAgenda(meses);
				break;
			case 3:
				printf("\nAté a próxima, %s!", nome);
				break;
			default:
				printf("Opção Inválida.");
				break;
		}
	}
}

int escolherMes()
{
	int mes;
	
	while(mes < 1 || mes > 12)
	{
		printf("\nQual mês você gostaria de marcar o compromisso? (1 - 12)\nR: ");
		scanf("%i", &mes);
		
		if(mes < 1 || mes > 12)
			printf("\nMês inválido.\n");
		else
			break;
	}
	
	return mes;
}

// usuario vai escolher se quer ver um mes unico ou todos os meses do ano
int escolherTipoAgenda(mes meses[])
{
	int answer;
	int mes;
	
	printf("\nEscolha uma opção:\n[1] Mostrar Mês Único\n[2] Mostrar Ano\nR: ");
	scanf("%i", &answer);
	
	switch(answer)
	{
		case 1:
			mes = escolherMes();
			imprimirMesUnico(mes, meses);
			imprimirCompromissosMesUnico(meses, mes);
			break;
		case 2:
			imprimirAno(meses);
			imprimirCompromissosAno(meses);
			break;
	}
}

void imprimirMesUnico(int mes_escolhido, mes meses[])
{
	int i, j;
	
	printf("\n|------------------------------------------------|\n");
	
	for(i=0; i<5; i++)
	{
		for(j=0; j<7; j++)
		{
			if(j == 0)
				printf("|");
			
			if(meses[mes_escolhido-1].agenda[i][j].dia == 0)
				printf("   -- |");
			else
			{
				if(meses[mes_escolhido-1].agenda[i][j].contador_compromisso == 0)
					printf("   %02i |", meses[mes_escolhido-1].agenda[i][j].dia);
				else
					printf(" X %02i |", meses[mes_escolhido-1].agenda[i][j].dia);	
			}
		}
		
		printf("\n|------------------------------------------------|\n");
	}
}

void imprimirAno(mes meses[])
{
	int i, j, k;
	
	for(i=0; i<12; i++)
	{
		printf("\n|------------------------------------------------|\n");
	
		for(j=0; j<5; j++)
		{
			for(k=0; k<7; k++)
			{
				if(k == 0)
					printf("|");
				
				if(meses[i].agenda[j][k].dia == 0)
					printf("   -- |");
				else
				{
					if(meses[i].agenda[j][k].contador_compromisso == 0)
						printf("   %02i |", meses[i].agenda[j][k].dia);
					else
						printf(" X %02i |", meses[i].agenda[j][k].dia);	
				}
			}
			
			printf("\n|------------------------------------------------|\n");
		}
	}
}

void marcarCompromisso(int mes_escolhido, mes meses[], int meses_31[], int meses_30[])
{	
	int dia;
	
	dia = marcarDataCompromisso(mes_escolhido, meses, meses_31, meses_30);
	
	procurarDiaNaAgenda(dia, mes_escolhido, meses);
}

int marcarDataCompromisso(int mes_escolhido, mes meses[], int meses_31[], int meses_30[])
{
	int dia;
		
	while(1)
	{
		printf("\nDia do compromisso: ");
		scanf("%i", &dia);
		
		if(verificarMes(mes_escolhido, meses_31, meses_30) == 0)
		{
			if(dia > 0 && dia <= 31)
				return dia;
		}
		else if(verificarMes(mes_escolhido, meses_31, meses_30) == 1)
		{
			if(dia > 0 && dia <= 30)
				return dia;
		}
		else if(verificarMes(mes_escolhido, meses_31, meses_30) == 2)
		{
			if(dia > 0 && dia <= 29)
				return dia;
		}
		else
			printf("\nDia inválido.\n");
	}
}

int procurarDiaNaAgenda(int dia, int mes_escolhido, mes meses[])
{
	int i, j;
	
	for(i=0; i<5; i++)
	{
		for(j=0; j<7; j++)
		{
			if(dia == meses[mes_escolhido-1].agenda[i][j].dia)
			{
				meses[mes_escolhido-1].agenda[i][j].contador_compromisso++;
				
				marcarHoraCompromisso(meses, mes_escolhido, i, j);
				marcarDescricaoCompromisso(meses, mes_escolhido, i, j);
			}
		}
	}
}

void marcarHoraCompromisso(mes meses[], int mes_escolhido, int ind_semana, int ind_dia)
{
	int contador;
	contador = meses[mes_escolhido-1].agenda[ind_semana][ind_dia].contador_compromisso;
	
	printf("Insira a hora do compromisso: ");
	scanf("%i", &meses[mes_escolhido-1].agenda[ind_semana][ind_dia].compromissos[contador-1].hora);
	
	printf("Insira os minutos do compromisso: ");
	scanf("%i", &meses[mes_escolhido-1].agenda[ind_semana][ind_dia].compromissos[contador-1].minutos);
	
	fflush(stdin);
}

void marcarDescricaoCompromisso(mes meses[], int mes_escolhido, int ind_semana, int ind_dia)
{	
	int contador;
	contador = meses[mes_escolhido-1].agenda[ind_semana][ind_dia].contador_compromisso;

	printf("Insira a descrição do compromisso: ");
	scanf("%[^\n]", &meses[mes_escolhido-1].agenda[ind_semana][ind_dia].compromissos[contador-1].descricao);
	
	fflush(stdin);
}

void imprimirCompromissosMesUnico(mes meses[], int mes_escolhido)
{
	int i, j, k;
	int existe_compromisso = 0;
	
	for(i=0; i<5; i++)
	{
		for(j=0; j<7; j++)
		{
			if(meses[mes_escolhido-1].agenda[i][j].contador_compromisso > 0)
			{
				existe_compromisso = 1;
				
				printf("\n====== Dia %02i/%02i ======\n", meses[mes_escolhido-1].agenda[i][j].dia, mes_escolhido);
				
				for(k=0; k<meses[mes_escolhido-1].agenda[i][j].contador_compromisso; k++)
				{
					printf("\nCompromisso: %s\n", meses[mes_escolhido-1].agenda[i][j].compromissos[k].descricao);
					printf("Hora: %02ih%02i\n", meses[mes_escolhido-1].agenda[i][j].compromissos[k].hora, meses[mes_escolhido-1].agenda[i][j].compromissos[k].minutos);
				}
			}
		}
	}
	
	if(!existe_compromisso)
		printf("\nVocê não possui compromissos marcados.\n");
	
	printf("\n===========================================");
}

void imprimirCompromissosAno(mes meses[])
{
	int i, j, k, l;
	int existe_compromisso = 0;
	
	for(i=0; i<12; i++)
	{
		for(j=0; j<5; j++)
		{
			for(k=0; k<7; k++)
			{
				if(meses[i].agenda[j][k].contador_compromisso > 0)
				{
					existe_compromisso = 1;
					
					printf("\n====== Dia %02i/%02i ======\n", meses[i].agenda[j][k].dia, i+1);
					
					for(l=0; l<meses[i].agenda[j][k].contador_compromisso; l++)
					{
						printf("\nCompromisso: %s\n", meses[i].agenda[j][k].compromissos[l].descricao);
						printf("Hora: %02ih%02i\n", meses[i].agenda[j][k].compromissos[l].hora, meses[i].agenda[j][k].compromissos[l].minutos);
					}
				}
			}
		}
	}
	
	if(!existe_compromisso)
		printf("\nVocê não possui compromissos marcados.\n");
	
	printf("\n===========================================");
}
