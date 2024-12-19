#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define CASAS 5
#define RUAS 10

void simularCodigos(int cohab[CASAS][RUAS]);
void imprimirCohab(int cohab[CASAS][RUAS]);
void buscarCodigo(int cohab[CASAS][RUAS], int *rua, int *casa);

int main()
{
    int cohab[CASAS][RUAS];
    int rua = -1, casa = -1;
    int answer;
    int cont_busca;
    
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    
    simularCodigos(cohab);
    
    while(answer != 2)
    {
        if(cont_busca == 0)
            printf("Olá! Deseja fazer a busca por um hidrômetro?\n");
        else
            printf("Deseja buscar outro código?\n");
            
        printf("[1] Fazer Busca\n[2] Sair\nR: ");
        scanf("%i", &answer);
        
        if(answer == 1)
        {
            printf("---------------------------------------------------------------------------------\n");
            
            imprimirCohab(cohab);
            printf("\n");
            
            buscarCodigo(cohab, &rua, &casa);
        
            if(rua == -1 || casa == -1)
            {
                printf("\nHidrômetro não encontrado.\n");
                printf("---------------------------------\n");
            }
            else
            {
                printf("\nO Hidrômetro se encontra na CASA %i, na RUA %i.\n", rua, casa);
                printf("--------------------------------------------------\n");
            }
            
            cont_busca++;
        }
        else if(answer == 2)
        {
            printf("\nTenha um bom dia!");
        }
        else
        {
            printf("\nErro. Insira uma opção válida.\n");
            printf("----------------------------------\n");
        }
    }
    
    
    return 0;
}

void simularCodigos(int cohab[CASAS][RUAS])
{
    int i, j;
    int aux = rand() % 10000;
    
    for(i=0; i<CASAS; i++)
    {
        for(j=0; j<RUAS; j++)
        {
            cohab[i][j] = aux;
            aux++;
        }
    }
}

void imprimirCohab(int cohab[CASAS][RUAS])
{
    int i, j;
    
    for(i=0; i<CASAS; i++)
    {
        for(j=0; j<RUAS; j++)
        {
            if(j == 0)
                printf("| %i |", cohab[i][j]);
            else
                printf(" %i |", cohab[i][j]);
        }
        printf("\n");
    }
}

void buscarCodigo(int cohab[CASAS][RUAS], int *rua, int *casa)
{
    int i, j;
    int code;
    
    printf("Insira o código de 5 dígitos a ser buscado: ");
    scanf("%i", &code);
    
    for(i=0; i<CASAS; i++)
    {
        for(j=0; j<RUAS; j++)
        {
            if(cohab[i][j] == code)
            {
                *casa = i;
                *rua = j;
                break;
            }
        }
    }
}