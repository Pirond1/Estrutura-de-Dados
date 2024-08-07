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
	printf("\n<<Exibindo Vetor Invertido>>\n\n");
	for(i=TF-1; i>=0; i--){
		printf("Vetor[%d] = %d\n", i, vet[i]);
	}
}

int somar_vetor(int vet[TF]){
	int i, soma=0;
	for(i=0; i<TF; i++){
		soma += vet[i];	
	}
	return soma;
}

void main (){
	int vet[TF], soma;
	carregar_vetor(vet);
	exibir_vetor(vet);
	soma = somar_vetor(vet);
	printf("\nValor da soma dos Vetores: %d", soma);
}

