/*
Teste 020
"Imposto de Renda"

<R$654 		- 	6%
R$654 		- 	39 + 18%		nos próximos 653 
R$1,307 	- 	157 + 19%		nos próximos 1,307 
R$2,614 	- 	405 + 20%		nos próximos 1,307 
R$3,921 	- 	667 + 21 %		nos próximos 2,614 
R$6,535 	- 	1,216 + 23%		nos próximos 2,614 
R$9,149 	- 	1,817 + 25%		nos próximos 2,614 
R$11,763 	- 	2,470 + 27%		nos próximos 2,614 
R$14,377 	- 	3,176 + 31%		nos próximos 3,921 
R$18,298 	- 	4,392 + 35%		nos próximos 13,070 
R$31,368 	- 	8,966 + 39%		nos próximos 19,605 
R$50,973 	- 	16,612 + 43%	nos próximos 27,447 
R$78,420 	- 	28,414 + 47%	no restante 
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int i, flag = 0 ;
float renda, imposto ;

main()
{
	printf("Insira sua renda: R$");
	scanf("%f", &renda);
	
	if(renda < 654)
		imposto = renda*0.06 ;
	else if(renda < 1307)
		imposto = 39 + renda*0.18 ;
	else if(renda < 2614)
		imposto = 157 + renda*0.19 ;
	else if(renda < 3921)
		imposto = 405 + renda*0.20 ;
	else if(renda < 6535)
		imposto = 667 + renda*0.21 ;
	else if(renda < 9149)
		imposto = 1216 + renda*0.23 ;
	else if(renda < 11763)
		imposto = 1817 + renda*0.25 ;
	else if(renda < 14377)
		imposto = 2470 + renda*0.27 ;
	else if(renda < 18298)
		imposto = 3176 + renda*0.31 ;
	else if(renda < 31368)
		imposto = 4392 + renda*0.35 ;
	else if(renda < 50973)
		imposto = 8966 + renda*0.39 ;
	else if(renda < 78420)
		imposto = 16612 + renda*0.43 ;
	else
		imposto = 28414 + renda*0.47 ;
		
	printf("Imposto de Renda a pagar: R$%.2f\n\n", imposto);
	
	system("pause");
}
