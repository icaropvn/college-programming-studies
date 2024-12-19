#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/* Este é um algoritmo de cadastro de alunos que simula um banco de dados
através de um arquivo .txt. */

// definição da struct que contém os dados de cada aluno
typedef struct
{
    int code;
    char name[50];
    float parcial_grade, exam_grade, avarage;
} studentData;

void flushBuffer();

void menu(studentData students[], int *counter);
    void selectOption(int answer, studentData students[], int *counter);
        void registerNewStudent(studentData students[], int *counter);
            void pullDataDocument(studentData students[], int *counter);
            void getDataNewRegister(studentData students[], int *counter);
            void sortStudents(studentData students[], int counter);
            void writeRegistersDocument(studentData students[], int counter);
        void showRegisters(studentData students[]);

int verifyErrorFile(FILE *file);

// função principal: declara o idioma da lib "locale.h" e declara os dados base. Invoca o Menu
int main()
{
	setlocale(LC_ALL, "Portuguese");
	
    studentData students[60];
    int counter = 0;
    
    menu(students, &counter);
    
    return 0;
}

// função que limpa o buffer do teclado de maneira mais direta e segura em relação ao 'fflush(stdin)'
void flushBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// função Menu que coleta a opção desejada do usuário e invoca a função que determina o caminho certo
void menu(studentData students[], int *counter)
{
    int answer = 0;
    
    while(answer != 3)
    {
        printf("Escolha uma opção:\n");
        printf("[1] Cadastrar Novo Aluno\n[2] Exibir Alunos Cadastrados\n[3] Sair\nR: ");
        scanf("%i", &answer);
        
        selectOption(answer, students, &*counter);
    }
}

// função que determina a execução do algoritmo de acordo com a escolha do usuário
void selectOption(int answer, studentData students[], int *counter)
{
    switch(answer)
    {
        case 1:
            registerNewStudent(students, &*counter);
            break;
        case 2:
            showRegisters(students);
            break;
        case 3:
            printf("\nAté mais!");
            break;
        default:
            printf("\nOpção Inválida.\n-----------------------------");
            break;
    }
    
    printf("\n");
}

// função geral que define a ordem das funções para a execução da lógica do registro de um novo aluno
void registerNewStudent(studentData students[], int *counter)
{
    pullDataDocument(students, &*counter);
    
    getDataNewRegister(students, &*counter);
        
    sortStudents(students, *counter);
        
    writeRegistersDocument(students, *counter);
}

// função que lê e atribui ao vetor os dados do arquivo txt
void pullDataDocument(studentData students[], int *counter)
{
    FILE *file;
    
    file = fopen("022 - Lista de Cadastros.txt", "r");
    *counter = 0;
    
    if(!verifyErrorFile(file))
    {
        while(fscanf(file, "%i %s %f %f %f", &students[*counter].code, students[*counter].name, &students[*counter].parcial_grade, &students[*counter].exam_grade, &students[*counter].avarage) != EOF)
            (*counter)++;
    }
    
    fclose(file);
}

// função que coleta os dados do novo registro do usuário e atribui ao final do vetor
void getDataNewRegister(studentData students[], int *counter)
{
    printf("\nInsira o código do aluno: ");
    scanf("%6i", &students[*counter].code);
    flushBuffer();
        
    printf("Insira o nome do aluno: ");
    scanf(" %50[^\n]", students[*counter].name);
    flushBuffer();
        
    printf("Insira a nota parcial: ");
    scanf("%f", &students[*counter].parcial_grade);
        
    printf("Insira a nota do exame: ");
    scanf("%f", &students[*counter].exam_grade);
        
    students[*counter].avarage = students[*counter].parcial_grade * 0.4 + students[*counter].exam_grade * 0.6;
        
    (*counter)++;
}

// função que ordena o vetor de dados em ordem crescente de código
void sortStudents(studentData students[], int counter)
{
	int i, j;
	studentData aux;
	
	for(i=0; i<counter; i++)
	{
		for(j=0; j<counter-1; j++)
		{
			if(students[j].code > students[j+1].code)
			{		    
				aux = students[j];
				students[j] = students[j+1];
				students[j+1] = aux;
			}
		}
	}
}

// função que retorna o vetor já ordenado e implementado com novo registro ao arquivo txt
void writeRegistersDocument(studentData students[], int counter)
{
    FILE *file;
    int i;
    
    file = fopen("022 - Lista de Cadastros.txt", "w");
    
    for(i=0; i<counter; i++)
    {
        fprintf(file, "%6i  %50s  %5.2f  %5.2f  %5.2f\n", students[i].code, students[i].name, students[i].parcial_grade, students[i].exam_grade, students[i].avarage);
    }
    
    fclose(file);
}

// função que mostra em forma de tabela todos os dados encontrados no arquivo txt
void showRegisters(studentData students[])
{
    int code;
    char name[50];
    float parcial_grade, exam_grade, avarage;
    
    FILE *file = fopen("022 - Lista de Cadastros.txt", "r");
    
    printf("\n|-- RA --|----------------------- NOME -----------------------|- PARCIAL -|- EXAME -|- MÉDIA -|\n");
    
    if(!verifyErrorFile(file))
    {
        while(fscanf(file, "%i %s %f %f %f", &code, name, &parcial_grade, &exam_grade, &avarage) != EOF )
        {
            printf("| %6i | %50s | %9.2f | %7.2f | %7.2f |\n", code, name, parcial_grade, exam_grade, avarage);
        }
        
        printf("|---------------------------------------------------------------------------------------------|\n");
        
        fclose(file);
    }
}

// função geral que verifica o retorno da tentativa de abrir o arquivo, se for NULL, mensagem apropriada é escrita
int verifyErrorFile(FILE *file)
{
    if(file == NULL)
    {
        printf("\nAlgo deu errado. Arquivo pode estar corrompido.\n");
        return 1;
    }
    
    return 0;
}
