/*
019 - Imprimindo Vetores

Crie um procedimento que imprima o conteúdo de um
vetor de inteiros de qualquer tamanho.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void imprimir_vetor_sequencia(int vetor[], int tamanho);
void imprimir_vetor_par(int vetor[], int tamanho);
void imprimir_vetor_impar(int vetor[], int tamanho);

int main()
{
	int tamanho, resposta_usuario ;
	int vetor[tamanho] ;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Insira o tamanho do vetor: ");
	scanf("%i", &tamanho);
	
	if(tamanho == 0)
		printf("\nVetor vazio.\n");
	else
	{
		printf("\nComo deseja preencher seu vetor?\n[1] - Números em sequência\n[2] - Números Pares\n[3] - Números Ímpares\nR: ");
		scanf("%i", &resposta_usuario);
	
		if(resposta_usuario == 1 || resposta_usuario == 2 || resposta_usuario == 3)
			printf("\nVetor = [");
	
		switch(resposta_usuario)
		{
			case 1:
				imprimir_vetor_sequencia(vetor, tamanho);
				break;
			case 2:
				imprimir_vetor_par(vetor, tamanho);
				break;
			case 3:
				imprimir_vetor_impar(vetor, tamanho);
				break;
			default:
				printf("\nResposta Inválida.\n");
				break;
		}
	}
	
	printf("\n");
	
	return 0;
}

void imprimir_vetor_sequencia(int vetor[], int tamanho)
{
	int i ;
	
	for(i=0; i<tamanho; i++)
	{
		vetor[i] = i+1;
		
		if(i == tamanho-1)
			printf("%i]", vetor[i]);
		else
			printf("%i, ", vetor[i]);
	}
}

void imprimir_vetor_par(int vetor[], int tamanho)
{
	int i ;
	
	for(i=0; i<tamanho; i++)
	{
		if(i == 0)
			vetor[i] = 2;
		else
			vetor[i] = vetor[i-1] + 2;
			
		if(i == tamanho-1)
			printf("%i]", vetor[i]);
		else
			printf("%i, ", vetor[i]);
	}
}

void imprimir_vetor_impar(int vetor[], int tamanho)
{
	int i ;
	
	for(i=0; i<tamanho; i++)
	{
		if(i == 0)
			vetor[i] = 1;
		else
			vetor[i] = vetor[i-1] + 2;
		
		if(i == tamanho-1)
			printf("%i]", vetor[i]);
		else
			printf("%i, ", vetor[i]);
	}
}
