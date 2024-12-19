/* Conversor Quilômetro-Jarda
"Algoritmo que lê o tempo (em segundos) que um nadador percorre 100 metros e calcula o tempo em que ele percorreria 100 jardas"
1J = 0.9144m
*/

#include <stdio.h>
#include <stdlib.h>

float t100m, t100j;

main()
{
	printf("Insira o tempo transcorrido em 100 metros (em segundos): ");
	scanf("%f", &t100m);
	
	t100j = t100m * 0.9144;
	
	printf("\nO tempo transcorrido para 100 jardas seria %.2f \n\n", t100j);
	
	system("pause");
}
