// Teste Biblioteca time.h - Imprimindo horas e dias

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main(void)
{
	int temp;
    int hours, minutes, seconds, day, month, year;
    time_t transacao;
 	
 	printf("Ocorrer transacao?\nR [1/0]: ");
 	scanf("%i", &temp);
 	
    time(&transacao);
 	struct tm *local = localtime(&transacao);
 	
 	hours = local->tm_hour;
    minutes = local->tm_min;
    seconds = local->tm_sec;
    
    day = local -> tm_mday;
    month = local -> tm_mon;
    year = local -> tm_year;
 	
 	printf("Finalizar programa? ");
 	scanf("%i", &temp);
 	
 	printf("Hora da Transacao: %02d:%02d:%02d", hours, minutes, seconds);
 	printf("\nDia da Transacao: %02d/%02d/%2d", day, month+1, year+1900);
 	
    return 0;
}
