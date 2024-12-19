/*
Algoritmos de Recursão

Recursão é:
- repetições sem loop

* Ao usar Recursão, é preciso definir de imediato 
qual será a condição de parada

*memória em stack

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int somar(int num);

int main()
{
	int num;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Insira um número para somar seus antecessores: ");
	scanf("%i", &num);
	
	printf("\n%i", somar(num));
	
	return 0;
}

int somar(int num)
{
	if(num == 0)
		return 0;
	else
	    return num + somar(num - 1);
}
