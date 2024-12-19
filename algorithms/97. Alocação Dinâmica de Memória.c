// Alocação Dinâmica de Memória

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct 
{
	int dia, mes, ano;
	int hora, minuto, segundo;
	char tipo;
	float valor;
} dadosExtrato;

//int simular_cedulas(int cedulas[]);

//void menu(float saldo, int cedulas[], int quant_cedulas, dadosExtrato dados, int tam);

void sacar(float *saldo, dadosExtrato dados[], int *tam);
void extrato(dadosExtrato dados[], int tam);

int main()
{
	float saldo = 9999.99;
	//int cedulas[6] = {200, 100, 50, 20, 10, 5};
	//int quantidade_notas;
	int tam = 1;
	dadosExtrato *dados;
	
	int answer;
	
	//setlocale(LC_ALL, "Portuguese");
	//srand(time(NULL));
	
	dados = malloc(tam * sizeof(dadosExtrato));
	
	while(1)
	{
		printf("1 - Sacar\n2 - Ver Extrato\n");
		scanf("%i", &answer);
		
		if(answer == 1)
			sacar(&saldo, dados, &tam);
		else if(answer == 2)
			extrato(dados, tam);
	}
	
	free(dados);
	
	return 0;
}

void sacar(float *saldo, dadosExtrato dados[], int *tam)
{
	int saque;
	
	printf("------------------\n");
	
	printf("Saldo Atual: %.2f\n\nQuanto deseja sacar?\nR$", *saldo);
	scanf("%i", &saque);
	
	*saldo -= saque;
	
	dados[*tam-1].valor = saque;
	
	*tam = *tam + 1;
	
	dados = realloc(dados, *tam * sizeof(dadosExtrato));
	
	printf("------------------\n");
}

void extrato(dadosExtrato dados[], int tam)
{
	int i;
	
	printf("------------------\n");
	
	for(i=0; i<tam-1; i++)
	{
		printf("Transacao %03i: R$%.2f\n", i+1, dados[i].valor);
	}
	
	printf("------------------\n");
}
