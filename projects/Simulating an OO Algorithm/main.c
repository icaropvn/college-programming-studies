/*
	Avaliação Diagnóstica - POO
	Ícaro Costa Pavan
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "pessoa.h"

int main() {
	time_t t;
	struct tm *dataAtual;
	time(&t);
	dataAtual = localtime(&t);
	int dia_atual = dataAtual->tm_mday;
	int mes_atual = dataAtual->tm_mon + 1;
	int ano_atual = dataAtual->tm_year + 1900;
	
	Pessoa *albert_einstein;
	Pessoa *isaac_newton;
	char nome[100];
	int dia_nasc = 14, mes_nasc = 3, ano_nasc = 1879;
	
	strcpy(nome, "Albert Einstein");
	albert_einstein = criarPessoa(nome, dia_nasc, mes_nasc, ano_nasc);
	
	strcpy(nome, "Isaac Newton");
	dia_nasc = 4;
	mes_nasc = 1;
	ano_nasc = 1643;
	isaac_newton = criarPessoa(nome, dia_nasc, mes_nasc, ano_nasc);
	
	getDataNascimento(albert_einstein, &dia_nasc, &mes_nasc, &ano_nasc);
	
	printf("Nome: %s\n", informaNome(albert_einstein));
	printf("Data de nascimento: %02i/%02i/%4i\n", dia_nasc, mes_nasc, ano_nasc);
	printf("Idade que teria hoje (%4i): %i anos\n\n", ano_atual, calculaIdade(albert_einstein, dia_atual, mes_atual, ano_atual));
	
	getDataNascimento(isaac_newton, &dia_nasc, &mes_nasc, &ano_nasc);
	
	printf("Nome: %s\n", informaNome(isaac_newton));
	printf("Data de nascimento: %02i/%02i/%4i\n", dia_nasc, mes_nasc, ano_nasc);
	printf("Idade que teria hoje (%4i): %i anos\n\n", ano_atual, calculaIdade(isaac_newton, dia_atual, mes_atual, ano_atual));
	
	getchar();
	return 0;
}
