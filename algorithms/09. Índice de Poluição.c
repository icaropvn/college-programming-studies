/* A Secretaria do Meio Ambiente mantém três listas de indústrias conhecidas por serem altamente poluentes da atmosfera.
Os resultados de várias medidas são combinados para formar o que é chamado de “índice de poluição”. Isto é controlado regularmente.
Normalmente os valores caem entre .05 e .25 (Bom). Se o valor atingir .30 (Ruim), as indústrias da lista A serão chamadas a suspender
as operações até que os valores retornem ao intervalo normal. Se o índice atingir .40 (Péssimo), as indústrias da lista B serão notificadas também.
Se o índice exceder .50 (Crítico), indústrias de todas as três listas serão avisadas para suspenderem as atividades. Preparar um algoritmo
para ler o índice de poluição e indicar as notações apropriadas.

.05 - .25 BOM
.30 RUIM - A
.40 PESSIMO - A e B
>.50 CRITICO - A, B e C

*/

#include <stdio.h>
#include <stdlib.h>

float indice ;

main()
{
	printf("Qual o INDICE DE POLUICAO atual?\n");
	scanf("%f", &indice);
	
	if (indice < 0.30)
		printf("\nO indice esta controlado. Nenhuma acao necessaria.\n\n");
	
	else if (indice < 0.40)
	{
		printf("\nO indice se encontra em estado RUIM\n");
		printf("As industrias da lista A devem suspender suas atividades.\n\n");
	}
	else if (indice <= 0.50)
	{
		printf("\nO indice se encontra em estado PESSIMO\n");
		printf("As industrias das listas A e B devem suspender suas atividades.\n\n");
	}
	else
	{
		printf("\nO indice se encontra em estado CRITICO\n");
		printf("TODAS as empresas das listas A, B e C devem suspender suas atividades.\n\n");
	}
	
	system("pause");
}

