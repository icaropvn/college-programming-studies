// Algoritmo de simulação de um Caixa Eletrônico

// colocar sistema de cadastramento inicial
// colocar sistema de login com senha (personalizar de acordo com o usuario)

// PROBLEMA 001: realloc não funciona junto com setlocale
// PROBLEMA 002: imprimir hora dá errado (imprime 00) + não funciona junto com realloc as funções de manipulação de tempo

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define LIMIT 15

typedef struct
{
	int dia, mes, ano;
	int hora, minuto, segundo;
	char tipo;
	float valor;
} dadosExtrato;

void diaHoje(int date[]);

int simular_cedulas(int notas[]);

void menu(float saldo, int notas[], int quant_notas, dadosExtrato *dados, int date[]);

void sacar(float *saldo, int notas[], int quant_notas, dadosExtrato *dados, int *cont, int date[]);
int verificar_notas(int saque, int notas[], int quant_notas);
void definir_cedulas(int saque, int notas[]);
void guardar_momento_transacao(dadosExtrato *dados, int cont);

void depositar(float *saldo, dadosExtrato *dados, int *cont);

void verificar_saldo(float *saldo, int notas[], int quant_notas, dadosExtrato *dados, int *cont, int date[]);

void extrato(dadosExtrato *dados, int cont);

char confirmarSaida();

int confirmar_transacao(float valor);

int main()
{
	float saldo;
	int notas[6] = {200, 100, 50, 20, 10, 5};
	int quantidade_notas;
	dadosExtrato *dados;
	int today_date[3];
	
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	dados = calloc(1, sizeof(dadosExtrato));
	
	diaHoje(today_date);
	
	quantidade_notas = simular_cedulas(notas);
	saldo = (rand() % 5000) + ((float)(rand() % 100) / 100);
	
	menu(saldo, notas, quantidade_notas, dados, today_date);
	
	return 0;
}

void diaHoje(int date[])
{
	time_t today_date;
	
	time(&today_date);
	struct tm *local = localtime(&today_date);
					
	date[0] = local -> tm_mday;
	date[1] = local -> tm_mon + 1;
	date[2] = local -> tm_year + 1900;
}

int simular_cedulas(int notas[])
{
	int cont = 0;
	int quantidade_notas, temp;
	
	quantidade_notas = (rand() % 5) + 1;
	
	while(cont < (6 - quantidade_notas))
	{
		temp = rand() % 6;
		
		if(notas[temp] != 0)
		{
			notas[temp] = 0;
			cont++;
		}
	}
	
	return quantidade_notas;
}

void menu(float saldo, int notas[], int quant_notas, dadosExtrato *dados, int date[])
{
	int cont_transacao = 0;
	char answer;
	
	while(answer != 'E' && answer != 'e')
	{
		printf("Bem-Vindo(a) [NOME DE USUÁRIO]!\nO que deseja fazer hoje?\n");
		printf("[A] Sacar\n[B] Depositar\n[C] Verificar Saldo\n[D] Extrato\n[E] Sair\nR: ");
		scanf(" %c", &answer);
		
		if(answer == 'A' || answer == 'a')
			sacar(&saldo, notas, quant_notas, dados, &cont_transacao, date);
		else if(answer == 'B' || answer == 'b')
			depositar(&saldo, dados, &cont_transacao);
		else if(answer == 'C' || answer == 'c')
			verificar_saldo(&saldo, notas, quant_notas, dados, &cont_transacao, date);
		else if(answer == 'D' || answer == 'd')
			extrato(dados, cont_transacao);
		else if(answer == 'E' || answer == 'e')
			answer = confirmarSaida();
		else
			printf("\nResposta Inválida. Escolha uma das opções.\n\n");
	}
}

void sacar(float *saldo, int notas[], int quant_notas, dadosExtrato *dados, int *cont, int date[])
{
	int i;
	char answer;
	int saque;
	
	while(1)
	{
		printf("------------------------------------------\n");
		printf("Transações disponíveis para hoje: %02i\n\n", LIMIT - *cont);
		printf("[A] - Digitar Valor para Sacar\n[B] - Voltar para o Menu\nR: ");
		scanf(" %c", &answer);
		
		if(answer == 'A' || answer == 'a' || answer == 'B' || answer == 'b')
			break;
		else
			printf("\nOpção Inválida.\n");
	}
	
	if(answer == 'A' || answer == 'a')
	{
		printf("------------------------------------------\n");
		printf("Notas disponíveis hoje (%02d/%02d/%04d):\n", date[0], date[1], date[2]);
		
		for(i=0; i<6; i++)
		{
			if(notas[i] != 0)
				printf(" - R$%i,00\n", notas[i]);
		}
		
		printf("\nSaldo Atual: R$%.2f\n", *saldo);
		printf("Digite o valor desejado para sacar: R$");
		scanf("%i", &saque);	

		if(saque < *saldo)
		{	
			if(verificar_notas(saque, notas, quant_notas))
			{
				printf("------------------------------------------\n");
				printf("Você receberá:\n");
				definir_cedulas(saque, notas);
				
				printf("\n");
				
				if(confirmar_transacao(saque))
				{
					*saldo -= saque;
					(*(dados + *cont)).valor = saque;
					(*(dados + *cont)).tipo = '-';
					
					guardar_momento_transacao(dados, *cont);
					(*cont)++;
					
					dados = realloc(dados, *cont + 1);
					
					printf("\nSaque realizado com sucesso! Retire as cédulas ao lado.\n");
					sleep(1);
					
					printf("----------------------------------------------------------\n");
				}
				else
				{
					printf("\nCancelando Operação...");
					sleep(2);
					printf("\nOperação Cancelada.\n");
					printf("------------------------------------------\n");
				}
			}
			else
			{
				printf("\nO valor desejado é inválido devido às notas disponíveis do dia.\n");
				printf("---------------------------------------------------------------\n");
				sleep(2);
			}
		}
		else
		{
			printf("\nOperação Cancelada. O valor de saque desejado é maior que seu saldo atual.\n");
			printf("---------------------------------------------------------------\n");
		}
	}
	else
	{
		printf("\nVoltando para o menu...\n");
		printf("--------------------------\n");
		sleep(2);
	}
}

int verificar_notas(int saque, int notas[], int quant_notas)
{
	int i;
	int cont = 0;
	
	for(i=0; i<6; i++)
	{
		if(notas[i] != 0 && saque % notas[i] == 0)
		{
			saque = saque % notas[i];
			
			if(saque == 0)
				break;
		}
	}
	
	if(saque == 0)
		return 1;
	else
		return 0;
}

void definir_cedulas(int saque, int notas[])
{
	int i;
	int cont;
	int quant_notas[6] = {0, 0, 0, 0, 0, 0};
	
	for(i=0; i<6; i++)
	{
		if(notas[i] != 0)
		{
			if(saque >= notas[i])
			{
				cont = i;
				break;
			}
		}
	}
		
	while(cont <= 6 && saque > 0)
	{
		if(notas[cont] != 0)
		{
			quant_notas[cont] = saque / notas[cont] ;
			saque = saque % notas[cont] ;
		}	
		else
			quant_notas[cont] = 0;
		
		cont++ ;
	}
	
	for(i=0; i<6; i++)
	{
		if(quant_notas[i] > 1)
			printf("%i Notas de R$%i,00\n", quant_notas[i], notas[i]);
		else if(quant_notas[i] == 1)
			printf("%i Nota de R$%i,00\n", quant_notas[i], notas[i]);
	}
		
	for(i=0; i<6; i++)
	{
		quant_notas[i] = 0;
	}
}


void guardar_momento_transacao(dadosExtrato *dados, int cont)
{
	time_t momento_transacao;
	
	time(&momento_transacao);
	struct tm *local = localtime(&momento_transacao);
					
	(*(dados + cont)).hora = 0; //local -> tm_hour;
	(*(dados + cont)).minuto = 0; //local -> tm_min;
	(*(dados + cont)).segundo = 0; //local -> tm_sec;
}


void depositar(float *saldo, dadosExtrato dados[], int *cont)
{
	float deposito;
	int aux;
	
	printf("-------------------------------------------\n");
	
	while(aux != deposito)
	{
		printf("Transações disponíveis para hoje: %02i\n\n", LIMIT - *cont);
		
		printf("Saldo Atual: R$%.2f", *saldo);
		printf("\nInsira o valor desejado para depositar: R$");
		scanf("%f", &deposito);
		
		aux = deposito;
		
		if(aux == deposito)
		{
			printf("\n");
			
			if(confirmar_transacao(deposito))
			{
				if(*cont <= LIMIT - 1)
				{
					*saldo += deposito;
					
					dados[*cont].valor = deposito;
					dados[*cont].tipo = '+';
					
					guardar_momento_transacao(dados, *cont);
					
					*cont = *cont + 1;
					
					printf("\nDepósito realizado com sucesso!\nNovo Saldo: R$%.2f\n", *saldo);
					sleep(1);
					printf("Transações disponíveis: %02i\n", LIMIT - *cont);
					sleep(2);
				}
				else
				{
					printf("\nLimite de transações do dia atingido. Operação Cancelada.\n");
				}
				
				printf("------------------------------------------\n");
			}
			else
			{
				printf("\nCancelando Operação...");
				sleep(2);
				printf("\nOperação Cancelada.\n");
				printf("------------------------------------------\n");
			}
		}
		else
		{
			printf("\nValor inválido para realizar depósito. Tente novamente.\n\n");
		}
	}
}

void verificar_saldo(float *saldo, int notas[], int quant_notas, dadosExtrato dados[], int *cont, int date[])
{
	char answer;
	
	printf("------------------------------\n");
	
	while(1)
	{
		printf("Saldo Atual: R$%.2f", *saldo);
		
		printf("\n\nDeseja realizar alguma operação?\n");
		printf("[A] Saque\n[B] Depósito\n[C] Voltar para o menu\nR: ");
		scanf(" %c", &answer);
		
		if(answer == 'A' || answer == 'a')
		{
			sacar(&*saldo, notas, quant_notas, dados, &*cont, date);
			break;
		}
		else if(answer == 'B' || answer == 'b')
		{
			depositar(&*saldo, dados, &*cont);
			break;
		}
		else if(answer == 'C' || answer == 'c')
		{
			printf("\nVoltando para o menu...\n");
			sleep(2);
			printf("------------------------------\n");
			break;
		}
		else
			printf("\nOpção Inválida.\n\n");
	}
}

void extrato(dadosExtrato *dados, int cont)
{
	int i;
	
	printf("----------------------------------------------------------\n");
	
	if(cont > 0)
	{
		printf("| Hora     | Tipo | Valor      |\n");
	
		for(i=0; i<cont; i++)
		{
			printf("| %02d:%02d:%02d |    %c | R$%8.2f |\n", (*(dados + i)).hora, (*(dados + i)).minuto, (*(dados + i)).segundo, (*(dados + i)).tipo, (*(dados + i)).valor);
		}
		printf("----------------------------------------------------------\n");
	}
	else
	{
		printf("Você ainda não realizou nenhuma transação.\nExtrato Inexistente.\n");
		printf("----------------------------------------------------------\n");
	}
}

char confirmarSaida()
{
	char answer;
	
	printf("----------------------------------------------------------\n");

	while(1)
	{
		printf("Tem certeza que deseja sair?\n\n[A] Confirmar Saída\n[B] Retornar ao Menu\nR: ");
		scanf(" %c", &answer);
		
		if(answer == 'A' || answer == 'a')
		{
			printf("----------------------------------------------------------\n");
			printf("\nAté mais! Volte sempre.");
			return 'e';
		}
		else if(answer == 'B' || answer == 'b')
		{
			printf("----------------------------------------------------------\n");
			return 'a';
		}
		else
			printf("\nOpção Inválida.\n\n");
	}
	
}

int confirmar_transacao(float valor)
{
	char answer;
	
	printf("Confirmar Transação?\n");
	printf("[A] Confirmar\n[B] Cancelar Transação\nR: ");
	scanf(" %c", &answer);
	
	if(answer == 'A' || answer == 'a')
		return 1;
	else if(answer == 'B' || answer == 'b')
		return 0;
	else
		printf("\nResposta Inválida.\n");
}
