#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int recursiveBinarySearch(int array[], int value, int beginning, int end);

int main()
{
	int test_array[20];
	int i, aux;
	
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
		
	for(i=0; i<20; i++)
	{
		test_array[i] = rand() % 101;
		printf("%i ", test_array[i]);
	}
	
	aux = recursiveBinarySearch(test_array, 40, 0, 49);
	
	if(aux == 1)
		printf("\nO valor está no vetor.");
	else
		printf("\nO valor não existe no vetor.");
	
	return 0;
}

int recursiveBinarySearch(int array[], int value, int beginning, int end)
{
	int mid;
	
	if(beginning <= end)
	{
		mid = (beginning + end) / 2;
		
		if(array[mid] == value)
			return 1;
		else if(mid < value)
			return recursiveBinarySearch(array, value, mid+1, end);
		else
			return recursiveBinarySearch(array, value, beginning, mid-1);
	}
	
	return -1;
}
