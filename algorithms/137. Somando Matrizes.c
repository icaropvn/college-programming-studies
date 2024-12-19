// Lista - Exercício 06

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define TAM 5

void somar_matrizes(int matriz1[TAM][TAM], int matriz2[TAM][TAM]);
void imprimir(int matriz[TAM][TAM]);

int main()
{
    int i, j ;
    int matriz1[TAM][TAM], matriz2[TAM][TAM] ;
    
    srand(time(NULL));
    
    for(i=0; i<TAM; i++)
    {
        for(j=0; j<TAM; j++)
        {
            matriz1[i][j] = rand() % 11;
            matriz2[i][j] = rand() % 11;
        }
    }
    
    printf("Matriz A:\n\n");
    imprimir(matriz1);
    
    printf("\n");
    
    printf("Matriz B:\n\n");
    imprimir(matriz2);
    
    somar_matrizes(matriz1, matriz2);
    
    
    return 0;
}

void somar_matrizes(int matriz1[TAM][TAM], int matriz2[TAM][TAM])
{
    int i, j ;
    int matriz3[TAM][TAM];
    
    for(i=0; i<TAM; i++)
    {
        for(j=0; j<TAM; j++)
        {
            matriz3[i][j] = matriz1[i][j] + matriz2[i][j] ;
        }
    }
    
    printf("\n");
    
    printf("Matriz SOMA:\n\n");
    imprimir(matriz3);
}

void imprimir(int matriz[TAM][TAM])
{
	int i, j ;
	char gama = 218, gama2 = 191, gama3 = 192, gama4 = 217 ;
	
	for(i=0; i<TAM; i++)
    {
        for(j=0; j<TAM; j++)
        {
            if(j == 0)
				printf("| %2.1i ", matriz[i][j]);
			else if(j == 4)
				printf("%2.1i |", matriz[i][j]);
			else
            	printf("%2.1i ", matriz[i][j]);
        }
        printf("\n");
    }
}
