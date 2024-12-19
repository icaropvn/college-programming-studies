/*
Algoritmo para encontrar valores duplicados num vetor:

1) O vetor é sorteado.

2) Ocorre a verificação de duplicatas, imprimindo as seguintes informações:

	=== Número X ===
	Aparece primeiro em: [posição da primeira ocorrência]
	[número de duplicatas] duplicatas, na(s) posição(ões): A, B, C e D

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define TAM 15

void preencherVetor(int vetor[], int vet_aux[]);
void imprimirVetor(int vetor[]);
void ordenarVetor(int vetor[]);

void verificarDuplicatas(int vetor[], int vet_og[]);

void preencherVetBL(int vet_bl[]);
int verificarValorBlacklist(int valor, int vet_bl[]);
void adicionarNumBlacklist(int num, int vet_bl[]);

void obterPosicoes(int vet_og[], int valor, int cont);

int main()
{
	int answer;
	int vetor[TAM];
	int vet_og[TAM];
	
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	preencherVetor(vetor, vet_og);
	
	printf("Vetor Sorteado = ");
	imprimirVetor(vetor);
	
	ordenarVetor(vetor);
	
	/*
	printf("\nVetor Ordenado = ");
	imprimir(vetor);
	*/
	
	printf("\n");
	
	verificarDuplicatas(vetor, vet_og);
	
	printf("\n");
	
	return 0;
}

void preencherVetor(int vetor[], int vet_og[])
{
	int i;
	
	for(i=0; i<TAM; i++)
	{
		vetor[i] = (rand() % 10) + 1 ;
		vet_og[i] = vetor[i];
	}
}

void imprimirVetor(int vetor[])
{
	int i;
	
	for(i=0; i<TAM; i++)
	{
		if(i == 0)
			printf("[%i, ", vetor[i]);
		else if(i == TAM-1)
			printf("%i]", vetor[i]);
		else
			printf("%i, ", vetor[i]);
	}
}

void ordenarVetor(int vetor[])
{
	int i, j;
	int aux;
	
	for(i=0; i<TAM; i++)
	{
		for(j=i; j<TAM; j++)
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

void verificarDuplicatas(int vetor[], int vet_og[])
{
	int i;
	int cont_og = 0, cont_duplicatas = 0;
	int value, first_position;
	int vet_blacklist[TAM], blacklist_flag;
	int duplicata_flag = 0;
	
	preencherVetBL(vet_blacklist);
	
	for(cont_og=0; cont_og<TAM; cont_og++)
	{
		value = vet_og[cont_og];
		cont_duplicatas = 0;
		
		blacklist_flag = verificarValorBlacklist(value, vet_blacklist);
		
		if(blacklist_flag == 0)
		{
			adicionarNumBlacklist(value, vet_blacklist);
			
			first_position = cont_og;
			
			for(i=0; i<TAM; i++)
			{
				if(vetor[i] == value)
				{
					cont_duplicatas++;
				}	
			}
			
			cont_duplicatas--;
			
			if(cont_duplicatas == 1)
			{
				duplicata_flag = 1;
				printf("\n=== Número %i ===\nAparece primeiro na posição: %i\n%i duplicata na posição: ", value, first_position, cont_duplicatas);
				obterPosicoes(vet_og, value, cont_duplicatas);
				printf("\n");
			}
			else if(cont_duplicatas > 1)
			{
				duplicata_flag = 1;
				printf("\n=== Número %i ===\nAparece primeiro na posição: %i\n%i duplicatas nas posições: ", value, first_position, cont_duplicatas);
				obterPosicoes(vet_og, value, cont_duplicatas);
				printf("\n");
			}
		}
	}
	
	if(duplicata_flag == 0)
	{
		printf("\n=======================================\n");
		printf("Não existe valores duplicados no vetor.\n");
		printf("=======================================\n");
	}
}

void preencherVetBL(int vet_bl[])
{
	int i;
	
	for(i=0; i<TAM; i++)
	{
		vet_bl[i] = -1;
	}
}

void adicionarNumBlacklist(int num, int vet_bl[])
{
	int i = 0;
	int contador = 0;
	
	while(1)
	{
		if(vet_bl[i] == -1)
		{
			vet_bl[i] = num;
			break;
		}
		else
			i++;
	}
}

int verificarValorBlacklist(int valor, int vet_bl[])
{
	int i;
	
	for(i=0; i<TAM; i++)
	{
		if(valor == vet_bl[i])
			return 1;
	}
	
	return 0;
}

void obterPosicoes(int vet_og[], int valor, int cont)
{
	int i;
	int temp = -1;
	
	for(i=0; i<TAM; i++)
	{
		if(vet_og[i] == valor)
		{
			temp++;
			
			if(temp > 0)
			{
				if(temp == cont)
					printf("%i.", i);
				else if(temp == cont-1)
					printf("%i e ", i);
				else
					printf("%i, ", i);
			}
		}
	}
}
