#include <stdio.h>
#include <conio.h>
/*
2.	Faça um algoritmo recursivo para cálculo do fatorial
 de um número positivo. Fazer antes um algoritmo não recursivo.
*/

int fatorial_nao_recursivo(int n){
	int fat, i;
	
	for(fat = 1; n > 1; n--){
		fat = fat * n;	
	}
	
	return fat;
}

int fatorial_recursivo(int n){
	int fat = n, i;
	
	if (n == 0){
		return 1;
	}
	else{
		return n * fatorial_recursivo(n-1);
	}
}

void main()
{
   int n;
   
   printf("\n Programa para calcular a fatorial de N:\n");

   printf("\n Digite o numero: ");
   scanf("%d", &n); 
   printf("\nFatorial (nao recursivo) de %d = %d \n", n, fatorial_nao_recursivo(n));
   printf("\nFatorial (recursivo) de %d = %d \n", n, fatorial_recursivo(n));
   
}


