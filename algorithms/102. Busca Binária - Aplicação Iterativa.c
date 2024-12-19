// Busca Binária: Implementação e Estudo do Algoritmo

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void fillRandomArray(int array[]);
void sortArray(int array[]);
int binarySearch(int array[], int value, int beginning, int end);
void verifyValueFound(int value);

int main()
{
	int i;
	int array[15];
	int value, value_found;
	
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	fillRandomArray(array);
	sortArray(array);
	
	printf("Insira um número para buscar no vetor: ");
	scanf("%i", &value);
	
	value_found = binarySearch(array, value, 0, 14);
	
	verifyValueFound(value_found);
	
	return 0;
}

void fillRandomArray(int array[])
{
	int i;
	
	for(i=0; i<15; i++)
	{
		array[i] = rand() % 51;
	}
}

void sortArray(int array[])
{
	int i, j;
	int aux;
	
	for(i=0; i<15; i++)
	{
		for(j=0; j<14; j++)
		{
			if(array[j] > array[j+1])
			{
				aux = array[j];
				array[j] = array[j+1];
				array[j+1] = aux;
			}
		}
	}
}

int binarySearch(int array[], int value, int beginning, int end)
{
	int middle;
	
	while(beginning <= end)
	{	
		middle = (end + beginning) / 2;
		
		if(array[middle] == value)
			return middle;
		else if(array[middle] < value)
			beginning = middle + 1;
		else
			end = middle - 1;
	}
	
	return -1;
}

void verifyValueFound(int value)
{
	if(value == -1)
		printf("\nValor não se econtra no vetor.\n");
	else
		printf("\nValor se encontra no índice %i do vetor.\n", value);
}
