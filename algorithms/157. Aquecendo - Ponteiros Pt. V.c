/*
Aquecendo: Ponteiros Pt. V	
	
	Implemente a função strcpy(char *destino, char *origem) usando ponteiros.
*/

#include <stdio.h>
#include <stdlib.h>

int myStrcpy(char *destino, char *origem);

int main()
{
	char nome[50] = {"Jorgeney"};
	char nome_copia[50];
	
	printf("Tamanho da string: %i\n", myStrcpy(nome_copia, nome));
	printf("String copiada: %s", nome_copia);
	
	return 0;
}

int myStrcpy(char *destino, char *origem)
{
	int i = 0;
	
	while(*(origem + i) != '\0')
	{
		*(destino + i) = *(origem + i);
		i++;
	}
	
	*(destino + i) = '\0';
	
	return i;
}
