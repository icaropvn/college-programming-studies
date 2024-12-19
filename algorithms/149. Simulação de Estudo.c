// Lista - Exercício 19

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define L 2000
#define C 4

void preencher(float tabela[L][C]);
void imprimir(float tabela[L][C]);
void calcular_medias(float tabela[L][C]);

int main()
{
	float tabela[L][C];
	
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	preencher(tabela);
	imprimir(tabela);
	
	calcular_medias(tabela);
	
	return 0;
}

void preencher(float tabela[L][C])
{
	int i, j;
	
	for(i=0; i<L; i++)
	{
		for(j=0; j<C; j++)
		{
			if(j == 0)
				tabela[i][j] = i+1 ;
			else if(j == 1)
				tabela[i][j] = (float)((rand() % 71) + 140) / 100;
			else if(j == 2)
				tabela[i][j] = ((rand() % 106) + 45);
			else
				tabela[i][j] = tabela[i][j-1] / (tabela[i][j-2] * tabela[i][j-2]) ;
		}
	}
}

void imprimir(float tabela[L][C])
{
	int i, j;
	
	printf("| Paciente      | Altura | Peso  |  IMC  |\n");
	printf("------------------------------------------\n");
	
	for(i=0; i<L; i++)
	{
		for(j=0; j<C; j++)
		{
			if(j == 0)
				printf("| Paciente %4.0f ", tabela[i][j]);
			else if(j == 1)
				printf("|  %5.2f ", tabela[i][j]);
			else if(j == 2)
				printf("| %5.1f ", tabela[i][j]);
			else
				printf("| %5.1f |", tabela[i][j]);
		}
		printf("\n");
	}
	
	printf("------------------------------------------\n");
}

void calcular_medias(float tabela[L][C])
{
	int i, j;
	float media_altura = 0.0, media_peso = 0.0, media_imc = 0.0;
	
	for(i=0; i<L; i++)
	{
		for(j=0; j<C; j++)
		{
			if(j == 1)
				media_altura = media_altura + tabela[i][j];
			else if(j == 2)
				media_peso = media_peso + tabela[i][j];
			else if(j == 3)
				media_imc = media_imc + tabela[i][j];
		}
	}
	
	media_altura = media_altura / L ;
	media_peso = media_peso / L ;
	media_imc = media_imc / L ;
	
	printf("\nMédia de Altura:......%.2fm\n", media_altura);
	printf("Média de Peso:........%.1fKg\n", media_peso);
	printf("Média de IMC:.........%.1f\n", media_imc);
}
