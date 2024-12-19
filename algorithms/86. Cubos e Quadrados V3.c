// 004 - Cubos e Quadrados V3

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

typedef struct
{
	int value;
	int square;
	int cube;
} dataNum;

dataNum elevar(dataNum num);

int main()
{
	dataNum num;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Insira um número: ");
	scanf("%i", &num.value);
	
	num = elevar(num);
	
	printf("\nValue:  %3.i", num.value);
	printf("\nSquare: %3.i", num.square);
	printf("\nCube:   %3.i\n", num.cube);
	
	return 0;
}

dataNum elevar(dataNum num)
{
	num.square = pow(num.value, 2);
	num.cube = pow(num.value, 3);
	
	return num;
}
