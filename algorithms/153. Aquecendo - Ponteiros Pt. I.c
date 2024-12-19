/*
Aquecendo: Ponteiros Pt. I

	Escreva um procedimento que receba um vetor inteiro, seu tamanho e os endereços de duas
variáveis inteiras, menor e maior, salve nestas variáveis o menor e o maior valor do vetor.
*/

#include <stdio.h>
#include <stdlib.h>

void arrayAnalysis(int array[], int array_size, int *biggest, int *smallest);

int main()
{
	int biggest, smallest;
	int array[10] = {2, 4, 7, 8, 12, 13, 16, 21, 25, 30};
	
	arrayAnalysis(array, 10, &biggest, &smallest);
	
	printf("Maior: %i\nMenor: %i\n", biggest, smallest);
	
	return 0;
}

void arrayAnalysis(int array[], int array_size, int *biggest, int *smallest)
{
	int i;
	
	for(i=0; i<array_size; i++)
	{
		if(i == 0)
		{
			*biggest = array[i];
			*smallest = array[i];
		}
		
		if(array[i] > *biggest)
			*biggest = array[i];
		
		if(array[i] < *smallest)
			*smallest = array[i];
	}
}
