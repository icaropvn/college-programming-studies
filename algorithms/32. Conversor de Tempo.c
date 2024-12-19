// Teste 007 - Conversor de Tempo

#include <stdio.h>
#include <stdlib.h>

int tempo_s, tempo_m, tempo_h, resto, tempo_entrada ;

main()
{
	printf("Insira o tempo em segundos: ");
	scanf("%i", &tempo_entrada);
	
	tempo_h = tempo_entrada / 3600 ;
	resto = tempo_entrada % 3600 ;
	
	tempo_m = resto / 60 ;
	tempo_s = resto % 60 ;
	
	printf("\nTempo (s): %is\n", tempo_entrada);
	printf("Tempo (m): %im%is\n", tempo_m, tempo_s);
	printf("Tempo (h): %ih%im%is\n\n", tempo_h, tempo_m, tempo_s);
	
	return 0;
}
