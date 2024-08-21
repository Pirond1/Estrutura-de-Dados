#include <stdio.h>
#include <conio.h>

#include <stdio.h>
#include <conio.h>

void imprimir_decrescente(int n) {
	
    if (n < 0) {
        return; 
    }
    printf("%d \n", n);
    imprimir_decrescente(n - 1);  
    
}

void main() {
    int N;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &N);

    if (N < 0) 
	{
        printf("Por favor, insira um numero inteiro positivo.\n");
    } 
	else 
	{
        printf("Os numeros de %d ate 0 sao: \n", N);
        imprimir_decrescente(N);
    }
}


