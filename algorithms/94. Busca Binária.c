// Algoritmo de Busca Sequencial

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <locale.h>

#define TAM 30

void sortear_vetor(int vetor[]);
void ordenar_vetor(int vetor[]);
int ler_palpite();
int buscar_palpite(int palpite, int vetor[]);
void imprimir(int vetor[]);

int main()
{
	int i;
	
	int vetor[TAM];
	int palpite;
	
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	printf("[Máquina] > Vou sortear um vetor de %i posições.\n", TAM);
	sortear_vetor(vetor);
	ordenar_vetor(vetor); // ordena o vetor por bubble sort
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
			
			printf("\nVetor = [");
			imprimir(vetor);
			printf("\n");
			
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
	
	for(i=0; i<TAM; i++)
	{
		vetor[i] = (rand() % 100) + 1;
	}
}

void ordenar_vetor(int vetor[])
{
	int i, j;
	int aux;
	
	for(i=0; i<TAM; i++)
	{
		for(j=i+1; j<TAM; j++)
		{
			if(vetor[j] < vetor[i])
			{
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}
		}
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
	// variáveis para usar a busca binária por 'for'
	/*
	int i;
	int loops = log2(TAM);
	*/
	
	int inicio = 0;
	int fim = TAM - 1;
	int meio;
	
	// busca binária usando 'for'
	/*
	for(i=0; i<=loops; i++)
	{
		meio = (fim + inicio) / 2;
		
		if(vetor[meio] == palpite)
			return 1;
		else if(palpite > vetor[meio])
			inicio = meio + 1;
		else
			fim = meio - 1;
	}
	*/
	
	// busca binária usando 'while'
	while(inicio <= fim)
	{
		meio = (fim + inicio) / 2;
		
		if(vetor[meio] == palpite)
			return 1;
		else if(palpite > vetor[meio])
			inicio = meio + 1;
		else
			fim = meio - 1;
	}
	
	return 0;
}

void imprimir(int vetor[])
{
	int i;
	
	for(i=0; i<TAM; i++)
	{
		if(i == 0)
			printf("%i, ", vetor[i]);
		else if(i == TAM-1)
			printf("%i]", vetor[i]);
		else
			printf("%i, ", vetor[i]);
	}
}
