// Lista - Exercício 02

#include <stdio.h>
#include <locale.h>

int fatorial(int num);

int main()
{
    int num, fatorial_num;
    
    setlocale(LC_ALL, "Portuguese");
    
    printf("Insira um valor: ");
    scanf("%i", &num);
    
    printf("\n%i! = ", num);
    
    fatorial_num = fatorial(num);
    
    printf(" = %i\n", fatorial_num);
    
    return 0;
}

int fatorial(int num)
{
    int i, fat = 1 ;
    
    for(i=num; i>=1; i--)
    {
        fat *= i ;
        
		if(i == 1)
			printf("%i", i);
		else
			printf("%i x ", i);
    }
    
    return fat;
}
