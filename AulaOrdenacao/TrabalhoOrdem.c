#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>

void selectSort(int vetor[], int tam) {
    
    double tempoexecucao;
	clock_t tempoInicial = clock();
	
	int elemento, esq, dir;
	printf("\n\n<<< Comecou o selectSort >>>\n\n");

    for (esq = 0; esq < tam; esq++) {
        for (dir = esq + 1; dir < tam; dir++) {
            if (vetor[esq] > vetor[dir]) {
                elemento = vetor[esq];
                vetor[esq] = vetor[dir];     
                vetor[dir] = elemento;      
            }
        }
    }
    tempoexecucao = ((double)clock() - tempoInicial) / CLOCKS_PER_SEC;
	printf("Finalizou o Tempo de Execucao SelectSort: %f", tempoexecucao);
}

void insertSort(int vetor[], int tam) {
	double tempoexecucao;
	clock_t tempoInicial = clock();
	  
    printf("\n\n<<< Comecou o insertSort >>>\n\n");
    
	int esq, elemento, dir;
    for (dir = 1; dir < tam; dir++) {
        elemento = vetor[dir];
        esq = dir - 1;
        while (esq >= 0 && vetor[esq] > elemento) {
            vetor[esq + 1] = vetor[esq];
            esq--;
        }
        vetor[esq + 1] = elemento;
    }
    tempoexecucao = ((double)clock() - tempoInicial) / CLOCKS_PER_SEC;
	printf("Finalizou o Tempo de Execucao InsertSort: %f", tempoexecucao);
}

void bubbleSort(int vetor[], int tam) {
	
	double tempoexecucao;
	clock_t tempoInicial = clock();
    
    printf("\n\n<<< Comecou o bubbleSort >>>\n\n");
    
	int elemento, houveTroca, indice;
    int tamanho = tam;
	
    do {
        houveTroca = 0;
        for (indice = 0; indice < tamanho - 1; indice++) {
            if (vetor[indice] > vetor[indice + 1]) {
                elemento = vetor[indice];
                vetor[indice] = vetor[indice + 1];
                vetor[indice + 1] = elemento;
                houveTroca = 1;
            }
        }
        tamanho--;
    }
    while (houveTroca == 1);
    
    tempoexecucao = ((double)clock() - tempoInicial) / CLOCKS_PER_SEC;
	printf("Finalizou o Tempo de Execucao Bubble: %f", tempoexecucao);
}



void main(){
	int tam, i, escolha = 0, escolha2 = 0;
	printf("Informe a Quantidade que deseja comparar (1- 1000, 2- 5000, 3- 10000, 4-20000, 5- 50000): ");
	scanf("%d", &escolha);
	printf("Deseja ser (1- Randomico ou 2- Ordenado)?: ");
	scanf("%d", &escolha2);
	
	if(escolha2 == 1){
		
		if(escolha == 1){
			
			int vetor1[1000], vetor2[1000], vetor3[1000];
			
			srand(time(NULL));
			for(i=0; i<1000; i++){
				vetor1[i] = (rand() % 1000);
				vetor2[i] = vetor1[i];
				vetor3[i] = vetor1[i];	
			}
			tam = 1000;
			selectSort(vetor1, tam);
			insertSort(vetor2, tam);
			bubbleSort(vetor3, tam);
		}
		else if(escolha == 2){
			
			int vetor1[5000], vetor2[5000], vetor3[5000];
			srand(time(NULL));
			for(i=0; i<5000; i++){
				vetor1[i] = (rand() % 5000);
				vetor2[i] = vetor1[i];
				vetor3[i] = vetor1[i];		
			}
			tam = 5000;
			selectSort(vetor1, tam);
			insertSort(vetor2, tam);
			bubbleSort(vetor3, tam);
		}
		else if(escolha == 3){
			int vetor1[10000], vetor2[10000], vetor3[10000];
			srand(time(NULL));
			for(i=0; i<10000; i++){
				vetor1[i] = (rand() % 10000);
				vetor2[i] = vetor1[i];
				vetor3[i] = vetor1[i];
			}
			tam = 10000;
			selectSort(vetor1, tam);
			insertSort(vetor2, tam);
			bubbleSort(vetor3, tam);
		}
		else if(escolha == 4){
			int vetor1[20000], vetor2[20000], vetor3[20000];
			srand(time(NULL));
			for(i=0; i<20000; i++){
				vetor1[i] = (rand() % 20000);
				vetor2[i] = vetor1[i];
				vetor3[i] = vetor1[i];
			}
			tam = 20000;
			selectSort(vetor1, tam);
			insertSort(vetor2, tam);
			bubbleSort(vetor3, tam);
		}
		else if(escolha == 5){
			int vetor1[50000], vetor2[50000], vetor3[50000];
			srand(time(NULL));
			for(i=0; i<50000; i++){
				vetor1[i] = (rand() % 50000);
				vetor2[i] = vetor1[i];
				vetor3[i] = vetor1[i];
			}
			tam = 50000;
			selectSort(vetor1, tam);
			insertSort(vetor2, tam);
			bubbleSort(vetor3, tam);
		}
		else{
			printf("Escolha Incorreta!\n");
		}
	}
	else if(escolha2 == 2){
		
		if(escolha == 1){
			
			int vetor1[1000], vetor2[1000], vetor3[1000];
			
			for(i=0; i<1000; i++){
				vetor1[i] = i;
				vetor2[i] = vetor1[i];
				vetor3[i] = vetor1[i];	
			}
			tam = 1000;
			selectSort(vetor1, tam);
			insertSort(vetor2, tam);
			bubbleSort(vetor3, tam);
		}
		else if(escolha == 2){
			
			int vetor1[5000], vetor2[5000], vetor3[5000];
			
			for(i=0; i<5000; i++){
				vetor1[i] = i;
				vetor2[i] = vetor1[i];
				vetor3[i] = vetor1[i];		
			}
			tam = 5000;
			selectSort(vetor1, tam);
			insertSort(vetor2, tam);
			bubbleSort(vetor3, tam);
		}
		else if(escolha == 3){
			int vetor1[10000], vetor2[10000], vetor3[10000];
			
			for(i=0; i<10000; i++){
				vetor1[i] = i;
				vetor2[i] = vetor1[i];
				vetor3[i] = vetor1[i];
			}
			tam = 10000;
			selectSort(vetor1, tam);
			insertSort(vetor2, tam);
			bubbleSort(vetor3, tam);
		}
		else if(escolha == 4){
			int vetor1[20000], vetor2[20000], vetor3[20000];
			
			for(i=0; i<20000; i++){
				vetor1[i] = i;
				vetor2[i] = vetor1[i];
				vetor3[i] = vetor1[i];
			}
			tam = 20000;
			selectSort(vetor1, tam);
			insertSort(vetor2, tam);
			bubbleSort(vetor3, tam);
		}
		else if(escolha == 5){
			int vetor1[50000], vetor2[50000], vetor3[50000];
			
			for(i=0; i<50000; i++){
				vetor1[i] = i;
				vetor2[i] = vetor1[i];
				vetor3[i] = vetor1[i];
			}
			tam = 50000;
			selectSort(vetor1, tam);
			insertSort(vetor2, tam);
			bubbleSort(vetor3, tam);
		}
		else{
			printf("Escolha Incorreta!\n");
		}
	}
	
	
}

