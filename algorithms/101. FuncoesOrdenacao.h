// Header: Algoritmos de Ordenação

#ifndef SORTFUNCTIONS_H
#define SORTFUNCTIONS_H

void bubbleSort(int vetor[], int tam)
{
	int i, j;
	int aux;
	
	for(i=0; i<tam; i++)
	{
		for(j=0; j<tam-1; j++)
		{
			if(vetor[j] > vetor[j+1])
			{
				aux = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = aux;
			}
		}
	}
}

void selectionSort(int vetor[], int tam)
{
	int i, j;
	int menor_index;
	int aux;
	
	for(i=0; i<tam; i++)
	{
		menor_index = i;
		
		for(j=i+1; j<tam; j++)
		{
			if(vetor[j] < vetor[menor_index])
				menor_index = j;
		}
		
		if(vetor[menor_index] < vetor[i])
		{
			aux = vetor[i];
			vetor[i] = vetor[menor_index];
			vetor[menor_index] = aux;
		}
	}
}

void insertionSort(int vetor[], int tam)
{
	int i, j;
	int aux;
	
	for(i=1; i<tam; i++)
	{
		aux = vetor[i];
		
		for(j=i-1; j>=0 && vetor[j] > aux; j--)
		{
			vetor[j+1] = vetor[j];
		}
		
		vetor[j+1] = aux;
	}
}

#endif // SORTFUNCTIONS_H
