/*
	Avaliação Diagnóstica - POO
	Ícaro Costa Pavan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"

typedef struct Pessoa {
	char nome[100];
	int dia_nasc, mes_nasc, ano_nasc;
}Pessoa;

void setNome(Pessoa *pessoa, char *nome) {
	if(pessoa != NULL)
		strncpy(pessoa->nome, nome, sizeof(pessoa->nome) - 1);
}

char* informaNome(Pessoa *pessoa) {
	return pessoa != NULL ? pessoa->nome : NULL;
}

void ajustaDataDeNascimento(Pessoa *pessoa, int dia, int mes, int ano) {
	if(pessoa != NULL) {
		pessoa->dia_nasc = dia;
		pessoa->mes_nasc = mes;
		pessoa->ano_nasc = ano;
	}
}

void getDataNascimento(Pessoa *pessoa, int *dia, int *mes, int *ano) {
	if(pessoa != NULL) {
		*dia = pessoa->dia_nasc;
		*mes = pessoa->mes_nasc;
		*ano = pessoa->ano_nasc;
	}
}

Pessoa* criarPessoa(char *nome, int dia, int mes, int ano) {
	Pessoa *pessoa = malloc(sizeof(Pessoa));
	
	if(pessoa) {
		strncpy(pessoa->nome, nome, sizeof(pessoa->nome) - 1);
		pessoa->dia_nasc = dia;
		pessoa->mes_nasc = mes;
		pessoa->ano_nasc = ano;
	}
	
	return pessoa;
}

int calculaIdade(Pessoa *pessoa, int dia_atual, int mes_atual, int ano_atual) {
	if(pessoa->mes_nasc < mes_atual)
		return ano_atual - pessoa->ano_nasc;
	else if(pessoa->mes_nasc == mes_atual) {
		if(pessoa->dia_nasc <= dia_atual)
			return ano_atual - pessoa->ano_nasc;
		else
			return (ano_atual - pessoa->ano_nasc) - 1;
	}
	else {
		return (ano_atual - pessoa->ano_nasc) - 1;
	}
}
