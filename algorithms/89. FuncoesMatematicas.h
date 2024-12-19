// Header: Funções Matemáticas

#ifndef FUNCOESMAT_H
#define FUNCOESMAT_H

float somar(float num1, float num2)
{
	return num1 + num2 ;
}

float subtrair(float num1, float num2)
{
	return num1 - num2 ;
}

float multiplicar(float num1, float num2)
{
	return num1 * num2 ;
}

float dividir(float num1, float num2)
{
	if(num2 == 0)
		return -1 ;
	else
		return num1 / num2 ;
}

float exponenciar(float num1, float num2)
{	
	int i, temp = 1;
	
	if(num2 == 0)
		return 1;
	else
	{
		for(i=1; i<=num2; i++)
		{
			temp = temp * num1 ;
		}
		
		return temp ;
	}
}

#endif // FUNCOESMAT_H
