/*
	Avaliação Diagnóstica - POO
	Ícaro Costa Pavan
*/

#ifndef PESSOA_H
#define PESSOA_H

typedef struct Pessoa Pessoa;

void setNome(Pessoa *pessoa, char *nome);
char* informaNome(Pessoa *pessoa);
void ajustaDataDeNascimento(Pessoa *pessoa, int dia, int mes, int ano);
void getDataNascimento(Pessoa *pessoa, int *dia, int *mes, int *ano);

Pessoa* criarPessoa(char *nome, int dia, int mes, int ano);
int calculaIdade(Pessoa *pessoa, int dia_atual, int mes_atual, int ano_atual);

#endif
