#include <stdio.h>
#include <conio.h>
#include <string.h>

//1. Fazer um algoritmo para ler um valor x e determinar se ele � par ou �mpar

void main (){
	char nome[50];
	float tempo;
	printf("Informe o nome do competidor: ");
	scanf("%s", nome);
	printf("Informe o tempo do competidor: ");
	scanf("%f", &tempo);
	if(tempo < 10){
		printf("100 Pontos!");	
	}else if(tempo >= 10 && tempo <= 13){
		printf("70 Pontos!");
	}else{
		printf("40 Pontos!");
	}
}