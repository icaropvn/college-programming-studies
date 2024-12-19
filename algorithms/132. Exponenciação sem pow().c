// Lista - Exercício 01

#include <stdio.h>
#include <locale.h>

void exponenciar(int num1, int num2, int *num3);

int main()
{
    int num1, num2, num3 = 1;
    
    setlocale(LC_ALL, "Portuguese");
    
    printf("Insira um valor: ");
    scanf("%i", &num1);
    
    printf("Insira outro valor: ");
    scanf("%i", &num2);
    
    if(num1 >= 0 && num2 >= 0)
    {
        exponenciar(num1, num2, &num3);
        
        printf("\n%i ^ %i = %i\n", num1, num2, num3);
    }
    else
        printf("\nValores Negativos.\n");

    return 0;
}

void exponenciar(int num1, int num2, int *num3)
{
    int i;
        
    for(i=1; i<=num2; i++)
    {
        *num3 = *num3 * num1 ;
    }
}
