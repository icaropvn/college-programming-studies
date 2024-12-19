/*
Teste 013
Verificação de SIN
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// float i, seno ;
int flag ;
float x = -10, seno ;

main()
{
	/*
	== RESOLUÇÃO 1 ==
	 
	for(i=-10.0; i<=10.0; i = i + 0.2)
	{
		seno = sin(i);
		printf("sen(%.2f) = %.2f\n", i, fabs(seno));
	}
	*/
	
	do
	{
		seno = sin(x) ;
		printf("sen(%2.1f) = %2.2f\n", x, fabs(seno));
		x = x + 0.2 ;
		
		if(seno > 1)
			flag = 1 ;
		
	} while(x <= 10);
	
	if(flag == 0)
		printf("\nA afirmacao e verdadeira.\n\n");
	else
		printf("\nA afirmacao e falsa.\n\n");
	
	system("pause");
}
