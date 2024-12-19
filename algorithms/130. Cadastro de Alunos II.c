// 024 - Cadastro de Alunos II

#include <stdio.h>
#include <string.h>
#include <locale.h>
#define MAX 30

typedef struct
{
    int codigo;
    float notas[2];
    float media;
    char status[3];
} dadosAlunos;

void menu(dadosAlunos alunos[], int cont);
void cadastrar(dadosAlunos alunos[], int cont);
void listar(dadosAlunos alunos[], int cont);
int pesquisar(dadosAlunos alunos[], int codigo, int cont);

int main()
{
    int resposta_usuario, contador = 0;
    dadosAlunos alunos[MAX];
    
    setlocale(LC_ALL, "Portuguese");
    
    menu(alunos, contador);
    
    return 0;
}

void menu(dadosAlunos alunos[], int cont)
{
    int i;
    int resposta_usuario;
    int codigo_pesquisa;
    
    while(1)
    {
        printf("TOTAL DE ALUNOS: %i\n", cont);
        printf("[1] - Cadastrar\n[2] - Listar\n[3] - Pesquisar\n[4] - Sair\nR: ");
        scanf("%i", &resposta_usuario);
    
        switch(resposta_usuario)
        {
            case 1:
                if(cont == MAX)
                    printf("\nMáximo de alunos cadastrados.\n\n");
                else
                {
                    cadastrar(alunos, cont);
                    cont++;
                }
                break;
            case 2:
                if(cont == 0)
                    printf("\nNenhum aluno cadastrado.\n\n");
                else
                    listar(alunos, cont);
                break;
            case 3:
                if(cont == 0)
                    printf("\nCadastre um aluno antes de pesquisar.\n\n");
                else
                {
                    printf("\nInsira o código do aluno: ");
                    scanf("%i", &codigo_pesquisa);
                    
                    if(pesquisar(alunos, codigo_pesquisa, cont) != -1)
                    {
                        i = pesquisar(alunos, codigo_pesquisa, cont);
                        
                        printf("-------------------------------------------------------------------------------------------------\n");
                        printf("  Aluno  \t|\tNota Parcial\t|\tNota Final\t|\tMédia\t|\tStatus\t|\n");
                        printf("  %i  \t|\t%.2f\t\t|\t%.2f\t\t|\t%.2f\t|\t%s\t|", alunos[i].codigo, alunos[i].notas[0], alunos[i].notas[1], alunos[i].media, alunos[i].status);
                        printf("\n-------------------------------------------------------------------------------------------------\n");
                    }
                    else
                    {
                        printf("-------------------------------------------------------------------------------------------------\n");
                        printf("Aluno não encontrado.\n\n");
                    }
                }
                break;
            case 4:
                printf("\nAté mais!");
                break;
            default:
                printf("\nInsira uma resposta válida.\n\n");
                break;
        }
        
        if(resposta_usuario == 4)
            break;
    }
}

void cadastrar(dadosAlunos alunos[], int cont)
{
    printf("------------------------");
    printf("\nCódigo: ");
    scanf("%i", &alunos[cont].codigo);
    
    printf("Nota Parcial: ");
    scanf("%f", &alunos[cont].notas[0]);
    
    printf("Nota Exame: ");
    scanf("%f", &alunos[cont].notas[1]);
    
    alunos[cont].media = (alunos[cont].notas[0]*0.4 + alunos[cont].notas[1]*0.6);
    
    if(alunos[cont].media >= 5.0)
        strcpy(alunos[cont].status, "APR");
    else
        strcpy(alunos[cont].status, "REP");
    
    printf("------------------------\n");
}

void listar(dadosAlunos alunos[], int cont)
{
    int i;
    
    printf("\n-------------------------------------------------------------------------------------------------\n");
    printf("  Aluno  \t|\tNota Parcial\t|\tNota Final\t|\tMédia\t|\tStatus\t|\n");
    
    for(i=0; i<cont; i++)
    {
        printf("  %i  \t|\t%.2f\t\t|\t%.2f\t\t|\t%.2f\t|\t%s\t|", alunos[i].codigo, alunos[i].notas[0], alunos[i].notas[1], alunos[i].media, alunos[i].status);
        printf("\n");
    }
    
    printf("-------------------------------------------------------------------------------------------------\n");
}

int pesquisar(dadosAlunos alunos[], int codigo, int cont)
{
    int i;
    
    for(i=0; i<cont; i++)
    {
        if(alunos[i].codigo == codigo)
            return i;
    }
    
    return -1;
}
