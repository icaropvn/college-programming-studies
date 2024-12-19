/* 
001 - Treinamento struct I

Implemente um programa que leia o nome, a idade e o endereço de 3 pessoas e
armazene os dados em uma estrutura.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// criando um tipo de dados chamada "struct dados_pessoa"
struct dados_pessoa
{
	char nome[50];
	char endereco[100];
	int idade;
};

// definindo o tipo de dado "struct dados_pessoa" como "dados_pessoa"
typedef struct dados_pessoa dados_pessoa ;

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	dados_pessoa pessoa[3];
	int i;
	
	for(i=0; i<3; i++)
	{
		printf("Nome: ");
		scanf("%50[^\n]s", &pessoa[i].nome);
		fflush(stdin);
		
		printf("Idade: ");
		scanf("%i", &pessoa[i].idade);
		fflush(stdin);
		
		printf("Endereço: ");
		scanf("%100[^\n]s", &pessoa[i].endereco);
		fflush(stdin);
		
		printf("----------------------------------\n");
	}
	
	system("cls");
	
	for(i=0; i<3; i++)
	{
		printf("----------------------------------\n");
		printf("Código: %i\n", i+1);
		printf("Nome: %s\n", pessoa[i].nome);
		printf("Idade: %i anos\n", pessoa[i].idade);
		printf("Endereço: %s\n", pessoa[i].endereco);
	}
	
	return 0;
}
