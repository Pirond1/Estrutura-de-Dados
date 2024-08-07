#include <stdio.h>
#include <conio.h>
#include <string.h>

//1. Fazer um algoritmo para ler um valor x e determinar se ele é par ou ímpar

void main (){
	int idade;
	printf("Informe a Idade da pessoa: ");
	scanf("%d", &idade);
	if(idade <= 10){
		printf("Idade de Crianca!");
	}else if(idade >= 11 && idade <= 16){
		printf("Idade de Adolescente!");
	}else if(idade >= 17 && idade <= 20){
		printf("Idade de Jovem!");
	}else if (idade >= 21 && idade <= 59){
		printf("Idade de Adulto!");
	}else if(idade >= 60){
		printf("Idade de Idoso!");
	}
}

