/*
Teste 038
"Getchar"

Teste de uso da função getchar()
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	char letra;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Digite uma letra: ");
	// scanf("%c", &letra);
	letra = getchar();
	
	printf("Caracter lido: %c\n", letra);
	
	return 0;
}
