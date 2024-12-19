/*
Teste 050
"getc"

Teste das funções getc() e fgetc()
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char letter1, letter2;
	
	printf("Insira uma letra (getc()): ");
	letter1 = getc(stdin);
	// A função getc precisa de um parâmetro que direciona de onde deve ser lido o caracter
	// stdin é a entrada padrão do PC (teclado)
	
	printf("Insira outra letra (fgetc()): ");
	letter2 = fgetc(stdin);
	// O 'f' do fgetc() vem da palavra file, ou seja, esta função é útil para ler
	// caracteres de dentro de arquivos.
	// !!! POR ALGUM MOTIVO ESSA FUNÇÃO NÃO FUNCIONA AQUI !!!
	
	printf("\nCaracteres lidos: %c - %c\n", letter1, letter2);
	
	return 0;
}
