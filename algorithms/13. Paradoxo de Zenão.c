/* Paradoxo de aquiles: Aquiles e a tartaruga disputam uma corrida. 
Aquiles corre dez vezes mais rápido do que a tartaruga, porém a tartaruga 
tem 100 metros de vantagem. Pode-se argumentar que Aquiles nunca ultrapassará 
a tartaruga, pois, quando ele atingir o ponto onde a tartaruga estava, 
ela já estará um pouco à frente. Projetar um algoritmo para ler a velocidade 
da tartaruga e calcular o tempo no qual Aquiles ultrapassará a tartaruga. 

USAR WHILE
*/

#include <stdio.h>
#include <stdlib.h>

int tempo = 0 ;
float v_tart, espaco_tart = 100, espaco_aquiles = 0 ;

main()
{
	printf("Qual a velocidade da tartaruga (m/s)? ");
	scanf("%f", &v_tart);
	
	do
	{
		espaco_aquiles = espaco_aquiles + 10*v_tart ;
		espaco_tart = espaco_tart + v_tart ;
		
		printf("Tempo: %is		St = %4.2f		Sa = %4.2f\n", tempo, espaco_tart, espaco_aquiles);
		
		tempo++ ;
		
	} while(espaco_aquiles < espaco_tart);
	
	printf("\nEspaco da Ultrapassagem: Metro %.2f\nMomento da Ultrapassagem: Segundo %i\n\n", espaco_aquiles, tempo);
	
	system("pause");
}
