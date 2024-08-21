#include <stdio.h>
#include <conio.h>

void imprimir_crescente(int n) {
	
    if (n < 0) {
        return; 
    }
    imprimir_crescente(n - 1);  
    printf("%d \n", n);
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
        printf("Os numeros de 0 ate %d sao: \n", N);
        imprimir_crescente(N);
    }
}


