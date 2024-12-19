// 025 - Cadastro de Alunos II

#include <stdio.h>
#include <string.h>
#include <locale.h>
#define MAX 30

typedef struct
{
    int codigo, faltas;
    float notas[2];
    float media;
    char status[3];
} dadosAlunos;

void menu(dadosAlunos alunos[], int cont);
void cadastrar(dadosAlunos alunos[], int cont);
void mostrar(dadosAlunos alunos[], int cont);
int pesquisar(dadosAlunos alunos[], int codigo, int cont);
void alterar(dadosAlunos alunos[], int cont);
void relatorio(dadosAlunos alunos[], int cont);

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
    int codigo_pesquisa, codigo_cadastro, flag;
    
    while(1)
    {
        printf("TOTAL DE ALUNOS: %i\n", cont);
        printf("[1] - Cadastrar\n[2] - Mostrar\n[3] - Pesquisar\n[4] - Alterar\n[5] - Relatório\n[6] - Sair\nR: ");
        scanf("%i", &resposta_usuario);
    
        switch(resposta_usuario)
        {
            case 1:
                if(cont == MAX)
                    printf("\nMáximo de alunos cadastrados.\n\n");
                else
                {
                    printf("------------------------");
                    printf("\nCódigo: ");
                    scanf("%i", &codigo_cadastro);
                    
                    if(cont > 0)
                    {
                        for(i=0; i<cont; i++)
                        {
                            if(alunos[i].codigo == codigo_cadastro)
                            {
                                printf("Código já está cadastrado.");
                                break;
                            }
                            
                            if(i == cont-1)
                            {
                                
                            }
                        }
                    }
                    else
                    {
                        alunos[cont].codigo = codigo_cadastro ;
                        cadastrar(alunos, cont);
                        cont++;
                    }
                }
                break;
            case 2:
                if(cont == 0)
                {
                	printf("---------------------------\n");
                    printf("Nenhum aluno cadastrado.\n");
                    printf("---------------------------\n");
                }
                else
                    mostrar(alunos, cont);
                break;
            case 3:
                if(cont == 0)
                {
                	printf("---------------------------------------\n");
                    printf("Cadastre um aluno antes de pesquisar.\n");
                    printf("---------------------------------------\n");
                }
                else
                {
                    printf("------------------------");
                    printf("\nInsira o código do aluno: ");
                    scanf("%i", &codigo_pesquisa);
                    
                    if(pesquisar(alunos, codigo_pesquisa, cont) != -1)
                    {
                        i = pesquisar(alunos, codigo_pesquisa, cont);
                        
                        printf("\n-----------------------------------------------------------------------------------------------------------------\n");
                        printf("  Aluno  \t|\tNota Parcial\t|\tNota Final\t|\tMédia\t|\tFaltas\t|\tStatus\t|\n");
                        printf("  %i  \t|\t%.2f\t\t|\t%.2f\t\t|\t%.2f\t|\t%i\t|\t%s\t|", alunos[i].codigo, alunos[i].notas[0], alunos[i].notas[1], alunos[i].media, alunos[i].faltas, alunos[i].status);
                        printf("\n-----------------------------------------------------------------------------------------------------------------\n");
                    }
                    else
                    {
                        printf("------------------------\n");
                        printf("Aluno não encontrado.\n\n");
                    }
                }
                break;
            case 4:
                if(cont > 0)
                    alterar(alunos, cont);
                else
                {
                    printf("----------------------------------\n");
                    printf("Cadastre alunos para mudar dados.\n");
                    printf("----------------------------------\n");
                }
                break;
            case 5:
                if(cont > 0)
                    relatorio(alunos, cont);
                else
                {
                    printf("-------------------------------------------\n");
                    printf("Cadastre alunos para gerar um relatório.\n");
                    printf("-------------------------------------------\n");
                }
                break;
            case 6:
                printf("\nAté mais!\n");
                break;
            default:
                printf("\nInsira uma resposta válida.\n\n");
                break;
        }
        
        if(resposta_usuario == 6)
            break;
    }
}

void cadastrar(dadosAlunos alunos[], int cont)
{
    printf("Nota Parcial: ");
    scanf("%f", &alunos[cont].notas[0]);
    
    printf("Nota Exame: ");
    scanf("%f", &alunos[cont].notas[1]);
    
    printf("Faltas: ");
    scanf("%i", &alunos[cont].faltas);
    
    alunos[cont].media = (alunos[cont].notas[0]*0.4 + alunos[cont].notas[1]*0.6);
    
    if(alunos[cont].media >= 5.0 && alunos[cont].faltas <= 20)
        strcpy(alunos[cont].status, "APR");
    else
        strcpy(alunos[cont].status, "REP");
    
    printf("------------------------\n");
}

void mostrar(dadosAlunos alunos[], int cont)
{
    int i;
    
    printf("\n-----------------------------------------------------------------------------------------------------------------\n");
    printf("  Aluno  \t|\tNota Parcial\t|\tNota Final\t|\tMédia\t|\tFaltas\t|\tStatus\t|\n");
    
    for(i=0; i<cont; i++)
    {
        printf("  %i  \t|\t%.2f\t\t|\t%.2f\t\t|\t%.2f\t|\t%i\t|\t%s\t|", alunos[i].codigo, alunos[i].notas[0], alunos[i].notas[1], alunos[i].media, alunos[i].faltas, alunos[i].status);
        printf("\n");
    }
    
    printf("-----------------------------------------------------------------------------------------------------------------\n");
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

void alterar(dadosAlunos alunos[], int cont)
{
    int codigo, i, flag = 0 ;
    
    printf("------------------------");
    
    printf("\nInsira o código do aluno para alterar dados: ");
    scanf("%i", &codigo);
    
    for(i=0; i<cont; i++)
    {
        if(codigo == alunos[i].codigo)
        {
            flag = 1;
            
            printf("Nova Nota Parcial: ");
            scanf("%f", &alunos[i].notas[0]);
            
            printf("Nova Nota Exame: ");
            scanf("%f", &alunos[i].notas[1]);
            
            printf("Novas Faltas: ");
            scanf("%i", &alunos[i].faltas);
        
            alunos[i].media = (alunos[i].notas[0]*0.4 + alunos[i].notas[1]*0.6);
            
            if(alunos[i].media >= 5.0 && alunos[i].faltas <= 20)
                strcpy(alunos[i].status, "APR");
            else
                strcpy(alunos[i].status, "REP");
            
            break;
        }
    }
    
    if(flag == 0)
        printf("\nAluno não encontrado.");
    
    printf("\n------------------------\n");
}

void relatorio(dadosAlunos alunos[], int cont)
{
    int i ;
    int aprovados = 0, reprovados = 0;
    float media_turma = 0, maior_media, menor_media;
    float taxa_apr, taxa_rep ; 
    
    for(i=0; i<cont; i++)
    {
        media_turma = media_turma + alunos[i].media;
        
        if(strcmp(alunos[i].status, "APR") == 0)
            aprovados++ ;
        else
            reprovados++ ;
        
        if(i == 0)
        {
            maior_media = alunos[i].media ;
            menor_media = alunos[i].media ;
        }
        else
        {
            if(alunos[i].media > maior_media)
                maior_media = alunos[i].media ;
            if(alunos[i].media < menor_media)
                menor_media = alunos[i].media ;
        }
    }
    
    media_turma = media_turma / cont ;
    taxa_apr = (aprovados / cont) * 100 ;
    taxa_rep = (reprovados / cont) * 100 ;
    
    printf("------------------------");
    printf("\nTotal de Estudantes: %i\n\nMédia da Turma: %.1f\n\n", cont, media_turma);
    printf("Número de Aprovados: %i\nNúmero de Reprovados: %i\n\n", aprovados, reprovados);
    printf("Taxa de Aprovação: %.1f%%\nTaxa de Reprovação: %.1f%%\n\n", taxa_apr, taxa_rep);
    printf("Maior Média: %.1f\nMenor Média: %.1f\n", maior_media, menor_media);
    printf("------------------------\n");
}

