/*
Atividade 023
"Biggest Difference"

Algorithm to find the biggest difference between two following
elements from a vector.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int i, vector[6], difference, bdif ;
// bdif = big difference
int num1, num2 ;

main()
{
	for(i=0; i<6; i++)
	{
		printf("Insert a value for the vector position %i: ", i+1);
		scanf("%i", &vector[i]);
	}
	
	bdif = abs(vector[1] - vector[0]) ;
	num1 = vector[0] ;
	num2 = vector[1] ;
	
	for(i=0; i<5; i++)
	{
		difference = abs(vector[i+1] - vector[i]) ;
		
		if(difference > bdif)
		{
			bdif = difference ;
			num1 = i+1 ;
			num2 = i ;
		}
	}
	
	printf("\nThe biggest difference in the vector is: %i, between %i (index %i) and %i (index %i)\n\n", bdif, vector[num1], num1, vector[num2], num2);
	
	system("pause");
}
