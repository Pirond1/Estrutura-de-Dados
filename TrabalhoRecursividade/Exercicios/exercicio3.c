#include <stdio.h>
#include <conio.h>
/*
3.	Fa�a uma fun��o recursiva que calcule e retorne o N-�simo termo da sequ�ncia Fibonacci.
 Alguns n�meros desta sequ�ncia s�o: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89...
*/
int fibonacci(int n){
	if (n == 0 || n == 1){
		return n;
	}
	else{
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

void main()
{
	int n;
	
	printf("\n Programa para calcular a sequencia de Fibonacci de N:\n");
	printf("\n Digite o numero: ");
	scanf("%d", &n); 
	
	printf("\n\n Sequencia de Fibonacci: %d", fibonacci(n));
}

