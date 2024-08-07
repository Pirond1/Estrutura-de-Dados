#include <stdio.h>
#include <conio.h>
#include <string.h>

//1. Fazer um algoritmo para ler um valor x e determinar se ele é par ou ímpar

void main (){
	int valor;
	printf("Informe o Valor de um numero inteiro: ");
	scanf("%d", &valor);
	if(valor % 2 == 0){
		printf("\nNumero Par!");
	}else{
		printf("\nNumero Impar!");
	}
}
