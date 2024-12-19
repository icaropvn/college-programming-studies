/*
Aquecendo: Ponteiros Pt. III

	Crie um programa que contenha um array de inteiros com 10 elementos. Imprima o elemento e o
endereço de cada posição do array.
*/

#include <stdio.h>
#include <stdlib.h>

void arrayPrinter(int array[], int array_size);

int main()
{
	int array[10] = {3, 5, 8, 11, 14, 16, 19, 22, 25, 27};
	int array_size = sizeof(array)/sizeof(int);
	
	arrayPrinter(array, array_size);
	
	return 0;
}

void arrayPrinter(int array[], int array_size)
{
	int i;
	
	for(i=0; i<array_size; i++)
	{
		printf("== Elemento %02i ==\n", i);
		printf("Valor: %i\nEndereco: %i\n\n", *(array + i), array + i);
	}
}
