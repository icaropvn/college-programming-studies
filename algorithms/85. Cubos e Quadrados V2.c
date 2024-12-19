// 003 - Cubos e Quadrados V2

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

typedef struct
{
	int value ;
	int square ;
	int cube ;
} dataNum;

void elevar(dataNum *num);

int main()
{
	dataNum num ;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Insira um número: ");
	scanf("%i", &num.value);
	
	elevar(&num);
	
	printf("\nQuadrado de %i = %i\n", num.value, num.square);
	printf("Cubo de %i = %i\n", num.value, num.cube);
}

void elevar(dataNum *num)
{
	(*num).square = pow((*num).value, 2);
	(*num).cube = pow((*num).value, 3);
}
