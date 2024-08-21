#include <stdio.h>
#include <conio.h>
/*
4.	Faça uma função recursiva que permita somar os elementos de um vetor de inteiros
*/
int preencher_vetor(int i){
	int valor;
	printf("Informe o valor na casa %d: ", i);
	scanf("%d", &valor);
	return valor;
}


int soma_vetor(int vetor[], int tamanho){
	if(tamanho == 0){
		return 0;
	}
	else{
		return vetor[tamanho - 1] + soma_vetor(vetor, tamanho - 1);	
	}
}

void main(){
	int tamanho = 0, i;
	printf("Informe o tamanho do vetor: ");
	scanf("%d", &tamanho);
	int vetor[tamanho];
	for (i = 0; i<tamanho; i++){
		vetor[i] = preencher_vetor(i);   	
	}
	int resultado = soma_vetor(vetor, tamanho);
	printf("\nA soma dos elementos do vetor e: %d\n", resultado);
}

