/*
Atividade 021
"Função e Vetor"

Algoritmo para ler 5 valores de um vetor (a), ler x e tabular os valores
de p(x) de acordo com a função:

p(x) = a0*x^4 + a1*x^3 + a2*x^2 + a3*x + a4

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int i, n = 5 ;
float constantes[5], x, px = 0.0 ;

main()
{
	setlocale(LC_ALL, "Portuguese");
	
	for(i=0; i<n; i++)
	{
		printf("Insira a constante a%i: ", i);
		scanf("%f", &constantes[i]);
	}
	
	printf("Insira agora o valor de x: ");
	scanf("%f", &x);
	
	for(i=0; i<n; i++)
		px += constantes[i] * pow(x, n-(i+1));
	
	printf("\np(%.2f) = %.2f\n\n", x, px);
	
	system("pause");
}