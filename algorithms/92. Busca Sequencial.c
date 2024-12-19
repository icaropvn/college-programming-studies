// Algoritmo de Busca Sequencial

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void sortear_vetor(int vetor[]);
int ler_palpite();
int buscar_palpite(int palpite, int vetor[]);

int main()
{
	int vetor[8];
	int palpite;
	
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	printf("[Máquina] > Vou sortear um vetor de 8 posições.\n");
	sortear_vetor(vetor);
	sleep(2);
	
	printf("[Máquina] > Sorteando...\n");
	sleep(3);
	
	printf("[Máquina] > Tente adivinhar um número desse vetor!\n");
	sleep(2);
	
	while(1)
	{
		palpite = ler_palpite();
		
		if(buscar_palpite(palpite, vetor) == 1)
		{
			printf("\n[Máquina] > Parabéns! O número %i está no vetor!\n", palpite);
			break;
		}
		else
		{
			printf("\n[Máquina] > Você errou :(\n");
			printf("[Máquina] > Tente de novo!\n");
		}
	}
	
	return 0;
}

void sortear_vetor(int vetor[])
{
	int i;
	
	for(i=0; i<8; i++)
	{
		vetor[i] = (rand() % 15) + 1;
	}
}

int ler_palpite()
{
	int palpite;
	
	printf("[Máquina] > Insira aqui sua proposta: ");
	scanf("%i", &palpite);
	
	return palpite;
}

int buscar_palpite(int palpite, int vetor[])
{
	int i;
	
	for(i=0; i<8; i++)
	{
		if(vetor[i] == palpite)
			return 1;
	}
	
	return 0;
}
