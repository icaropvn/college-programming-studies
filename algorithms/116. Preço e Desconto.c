/*
010 - Preço e Desconto

Crie uma função que receba dois valores referentes ao preço de uma
mercadoria e a porcentagem para o desconto. Retorne o novo preço com
o desconto calculado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float descontar(float price, int descount);

int main()
{
    int descount ;
    float price, new_price ;
    
    setlocale(LC_ALL, "Portuguese");
    
    printf("Insira o preço do produto: R$");
    scanf("%f", &price);
    
    printf("Insira o desconto (por cento): ");
    scanf("%i", &descount);
    
    new_price = descontar(price, descount);
    
    printf("\nPreço com desconto: R$%.2f\n", new_price);
    
    return 0;
}

float descontar(float price, int descount)
{
    return price * (1 - descount / 100.0) ;
}
