#include <stdio.h>
#include <conio.h>
#include <string.h>

#define TF 5

void carregar_vetor(int vet[TF]){
	int i;
	printf("<<Carregando Vetor>>\n\n");
	for(i=0; i<TF; i++){
		printf("Informe o Vetor[%d]: ", i);
		scanf("%d", &vet[i]);
	}	
}

void exibir_vetor(int vet[TF]){
	int i;
	printf("\n<<Exibindo Vetor>>\n\n");
	for(i=0; i<TF; i++){
		printf("Vetor[%d] = %d\n", i, vet[i]);
	}
}

void main (){
	int vet[TF];
	carregar_vetor(vet);
	exibir_vetor(vet);
}

