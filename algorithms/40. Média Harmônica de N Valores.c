/*
Teste 015

Média Harmônica de N valores positivos diferentes de zero
Ler N

MH = n / (soma(1/xi))
*/

#include <stdio.h>
#include <stdlib.h>
// #include <math.h>
#include <locale.h>

int i, n, x ;
float soma = 0.0, media ;

main()
{
	setlocale(LC_ALL, "Portuguese");
	
	printf("Insira a quantidade de valores (n): ");
	scanf("%i", &n);
	
	for(i=1; i<n+1; i++)
	{
		printf("Insira o valor %i: ", i);
		scanf("%i", &x);
		
		soma = soma + 1.0 / x ;
	}
	
	media = n / soma ;
	
	printf("\nMédia Harmônica de %i valores = %.4f\n\n", n, media);
	
	system("pause");
}
