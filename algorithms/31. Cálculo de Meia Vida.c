/* Teste 006 - Cálculo de Massa e Meia Vida
Um determinado material radioativo perde metade da sua massa a cada 50 segundos.
Dada a massa inicial, em gramas, calcular o tempo para que a massa se torne menor que 0.5 grama.
Escrever a massa inicial, a massa final e o tempo calculado em horas, minutos e segundos. */

#include <stdio.h>
#include <stdlib.h>

int tempo = 0, h, m, s, resto ;
float massa, massa_inicial ;

main()
{
	printf("Qual a massa inicial do material (g)? ");
	scanf("%f", &massa_inicial);
	
	massa = massa_inicial ;
	
	while(massa >= 0.5)
	{
		massa = massa / 2 ;
		tempo = tempo + 50 ;
	}
	
	h = tempo / 3600 ;
	resto = tempo % 3600 ;
	m = resto / 60 ;
	s = resto % 60 ;
	
	printf("\nMassa Inicial: %.3fg\nMassa Final: %.3fg\nTempo: %ih%im%is\n\n", massa_inicial, massa, h, m , s);
	
	system("pause");
}
