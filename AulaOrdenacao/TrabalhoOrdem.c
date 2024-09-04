#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>


double selectSort(int vetor[], int tam) {
	time_t tempo;
    time(&tempo);
    struct tm *tempo0 = localtime(&tempo);
  	
    
    double tempoexecucao;
	clock_t tempoInicial = clock();
	
	int elemento, esq, dir;
	printf("\n<<< Comecou o selectSort %d (hora %02d:%02d:%02d) >>>\n", tam,  tempo0->tm_hour, tempo0->tm_min, tempo0->tm_sec);
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
    struct tm *tempo1 = localtime(&tempo);
	printf("Finalizou o Tempo de Execucao SelectSort %d: %f, (hora %02d:%02d:%02d)", tam, tempoexecucao,   tempo1->tm_hour, tempo1->tm_min, tempo1->tm_sec);
	return tempoexecucao;
}

double insertSort(int vetor[], int tam) {
	time_t tempo = time(NULL);
    time(&tempo);
    struct tm *tempo0 = localtime(&tempo);
	
	double tempoexecucao;
	clock_t tempoInicial = clock();
	
    printf("\n<<< Comecou o insertSort %d (hora %02d:%02d:%02d) >>>\n", tam, tempo0->tm_hour, tempo0->tm_min, tempo0->tm_sec);
    
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
    struct tm *tempo1 = localtime(&tempo);
	printf("Finalizou o Tempo de Execucao InsertSort %d: %f, (hora %02d:%02d:%02d)", tam, tempoexecucao,   tempo1->tm_hour, tempo1->tm_min, tempo1->tm_sec);
	return tempoexecucao;
}

double bubbleSort(int vetor[], int tam) {
	time_t tempo = time(NULL);
    time(&tempo);
    struct tm *tempo0 = localtime(&tempo);
	
	double tempoexecucao;
	clock_t tempoInicial = clock();
    
    printf("\n\n<<< Comecou o bubbleSort %d (hora %02d:%02d:%02d) >>>\n", tam,  tempo0->tm_hour, tempo0->tm_min, tempo0->tm_sec);
    
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
    struct tm *tempo1 = localtime(&tempo);
	printf("Finalizou o Tempo de Execucao Bubble %d: %f, (hora %02d:%02d:%02d)", tam, tempoexecucao,   tempo1->tm_hour, tempo1->tm_min, tempo1->tm_sec);
	return tempoexecucao;
}


double funcaoEspecial(int tam, int escolha2){
	int i = 0;
	if(escolha2 == 1){
		int vetor1_1k[1000], vetor2_1k[1000], vetor3_1k[1000];
			
			srand(time(NULL));
			for(i=0; i<1000; i++){
				vetor1_1k[i] = (rand() % 1000);
				vetor2_1k[i] = vetor1_1k[i];
				vetor3_1k[i] = vetor1_1k[i];	
			}
			tam = 1000;

			double retornoBubble = bubbleSort(vetor3_1k, tam);
			double retornoInsert = insertSort(vetor2_1k, tam);
			double retornoSelect = selectSort(vetor1_1k, tam);
			
			
		printf("\n");
		int vetor1_5k[5000], vetor2_5k[5000], vetor3_5k[5000];
			srand(time(NULL));
			for(i=0; i<5000; i++){
				vetor1_5k[i] = (rand() % 5000);
				vetor2_5k[i] = vetor1_5k[i];
				vetor3_5k[i] = vetor1_5k[i];		
			}
			tam = 5000;

			 retornoBubble += bubbleSort(vetor3_5k, tam);
			 retornoInsert += insertSort(vetor2_5k, tam);
			 retornoSelect += selectSort(vetor1_5k, tam);
		
		printf("\n");	
		int vetor1_10k[10000], vetor2_10k[10000], vetor3_10k[10000];
			srand(time(NULL));
			for(i=0; i<10000; i++){
				vetor1_10k[i] = (rand() % 10000);
				vetor2_10k[i] = vetor1_10k[i];
				vetor3_10k[i] = vetor1_10k[i];
			}
			tam = 10000;

			retornoBubble += bubbleSort(vetor3_10k, tam);
			retornoInsert += insertSort(vetor2_10k, tam);
			retornoSelect += selectSort(vetor1_10k, tam);
		
		printf("\n");	
		int vetor1_20k[20000], vetor2_20k[20000], vetor3_20k[20000];
			srand(time(NULL));
			for(i=0; i<20000; i++){
				vetor1_20k[i] = (rand() % 20000);
				vetor2_20k[i] = vetor1_20k[i];
				vetor3_20k[i] = vetor1_20k[i];
			}
			tam = 20000;

			retornoBubble += bubbleSort(vetor3_20k, tam);
			retornoInsert += insertSort(vetor2_20k, tam);
			retornoSelect += selectSort(vetor1_20k, tam);
		
		printf("\n");	
		int vetor1_50k[50000], vetor2_50k[50000], vetor3_50k[50000];
			srand(time(NULL));
			for(i=0; i<50000; i++){
				vetor1_50k[i] = (rand() % 50000);
				vetor2_50k[i] = vetor1_50k[i];
				vetor3_50k[i] = vetor1_50k[i];
			}
			tam = 50000;

			retornoBubble += bubbleSort(vetor3_50k, tam);
			retornoInsert += insertSort(vetor2_50k, tam);
			retornoSelect += selectSort(vetor1_50k, tam);
			
			double mediaBubble = retornoBubble / 5;
			double mediaInsert = retornoInsert / 5;
			double mediaSelect = retornoSelect / 5;
			
			printf("\n\n<<< Media Bubble >>>\n %f", mediaBubble);
			printf("\n\n<<< Media Insert >>>\n %f", mediaInsert);
			printf("\n\n<<< Media Select >>>\n %f", mediaSelect);
			
			if(mediaBubble < mediaInsert && mediaBubble < mediaSelect){
				printf("\n\n\n<<< BubbleSort foi o metodo com a media mais rapida! >>>\n\n");
			}
			else if(mediaBubble == mediaInsert && mediaBubble < mediaSelect){
				printf("\n\n\n<<< BubbleSort e InsertSort foram os metodos com medias mais rapidas! >>>\n\n");
			}
			else if(mediaBubble < mediaInsert && mediaBubble == mediaSelect){
				printf("\n\n\n<<< BubbleSort e SelectSort foram os metodos com medias mais rapidas >>>\n\n");
			}
			else if(mediaBubble == mediaInsert && mediaBubble == mediaSelect){
				printf("\n\n\n<<< Todos os Metodos tiveram a mesma eficiencia! >>>\n\n");
			}
			else if(mediaInsert < mediaBubble && mediaInsert < mediaSelect){
				printf("\n\n\n<<< InsertSelect foi o metodo com media mais rapida! >>>\n\n");
			}
			else if(mediaInsert < mediaBubble && mediaInsert == mediaSelect){
				printf("\n\n\n<<< InsertSelect e SelectSort foram os metodos com medias mais rapidas! >>>\n\n");
			}
			else if(mediaSelect < mediaInsert && mediaSelect < mediaBubble){
				printf("\n\n\n<<< SelectSort foi o metodo com a media mais rapida! >>>\n\n");
			}
	}
	else if(escolha2 == 2){
		int vetor1_1k[1000], vetor2_1k[1000], vetor3_1k[1000];
			
			srand(time(NULL));
			for(i=0; i<1000; i++){
				vetor1_1k[i] = i;
				vetor2_1k[i] = vetor1_1k[i];
				vetor3_1k[i] = vetor1_1k[i];	
			}
			tam = 1000;

			double retornoBubble = bubbleSort(vetor3_1k, tam);
			double retornoInsert = insertSort(vetor2_1k, tam);
			double retornoSelect = selectSort(vetor1_1k, tam);
		
		printf("\n");	
		int vetor1_5k[5000], vetor2_5k[5000], vetor3_5k[5000];
			srand(time(NULL));
			for(i=0; i<5000; i++){
				vetor1_5k[i] = i;
				vetor2_5k[i] = vetor1_5k[i];
				vetor3_5k[i] = vetor1_5k[i];		
			}
			tam = 5000;

			retornoBubble += bubbleSort(vetor3_5k, tam);
			retornoInsert += insertSort(vetor2_5k, tam);
			retornoSelect += selectSort(vetor1_5k, tam);
		
		printf("\n");	
		int vetor1_10k[10000], vetor2_10k[10000], vetor3_10k[10000];
			srand(time(NULL));
			for(i=0; i<10000; i++){
				vetor1_10k[i] = i;
				vetor2_10k[i] = vetor1_10k[i];
				vetor3_10k[i] = vetor1_10k[i];
			}
			tam = 10000;

			retornoBubble += bubbleSort(vetor3_10k, tam);
			retornoInsert += insertSort(vetor2_10k, tam);
			retornoSelect += selectSort(vetor1_10k, tam);
		
		printf("\n");	
		int vetor1_20k[20000], vetor2_20k[20000], vetor3_20k[20000];
			srand(time(NULL));
			for(i=0; i<20000; i++){
				vetor1_20k[i] = i;
				vetor2_20k[i] = vetor1_20k[i];
				vetor3_20k[i] = vetor1_20k[i];
			}
			tam = 20000;

			retornoBubble += bubbleSort(vetor3_20k, tam);
			retornoInsert += insertSort(vetor2_20k, tam);
			retornoSelect += selectSort(vetor1_20k, tam);
		printf("\n");
		int vetor1_50k[50000], vetor2_50k[50000], vetor3_50k[50000];
			srand(time(NULL));
			for(i=0; i<50000; i++){
				vetor1_50k[i] = i;
				vetor2_50k[i] = vetor1_50k[i];
				vetor3_50k[i] = vetor1_50k[i];
			}
			tam = 50000;

			retornoBubble += bubbleSort(vetor3_50k, tam);
			retornoInsert += insertSort(vetor2_50k, tam);
			retornoSelect += selectSort(vetor1_50k, tam);
			
			double mediaBubble = retornoBubble / 5;
			double mediaInsert = retornoInsert / 5;
			double mediaSelect = retornoSelect / 5;
			
			printf("\n\n<<< Media Bubble >>>\n %f", mediaBubble);
			printf("\n\n<<< Media Insert >>>\n %f", mediaInsert);
			printf("\n\n<<< Media Select >>>\n %f", mediaSelect);
			
			if(mediaBubble < mediaInsert && mediaBubble < mediaSelect){
				printf("\n\n\n<<< BubbleSort foi o metodo com a media mais rapida! >>>\n\n");
			}
			else if(mediaBubble == mediaInsert && mediaBubble < mediaSelect){
				printf("\n\n\n<<< BubbleSort e InsertSort foram os metodos com medias mais rapidas! >>>\n\n");
			}
			else if(mediaBubble < mediaInsert && mediaBubble == mediaSelect){
				printf("\n\n\n<<< BubbleSort e SelectSort foram os metodos com medias mais rapidas >>>\n\n");
			}
			else if(mediaBubble == mediaInsert && mediaBubble == mediaSelect){
				printf("\n\n\n<<< Todos os Metodos tiveram a mesma eficiencia! >>>\n\n");
			}
			else if(mediaInsert < mediaBubble && mediaInsert < mediaSelect){
				printf("\n\n\n<<< InsertSort foi o metodo com media mais rapida! >>>\n\n");
			}
			else if(mediaInsert < mediaBubble && mediaInsert == mediaSelect){
				printf("\n\n\n<<< InsertSort e SelectSort foram os metodos com medias mais rapidas! >>>\n\n");
			}
			else if(mediaSelect < mediaInsert && mediaSelect < mediaBubble){
				printf("\n\n\n<<< SelectSort foi o metodo com a media mais rapida! >>>\n\n");
			}
	}
	
}


void main(){
	int tam, i, escolha = 0, escolha2 = 0;
	printf("Informe a Quantidade que deseja comparar (1- 1000, 2- 5000, 3- 10000, 4-20000, 5- 50000, 6- Comparar Todos os Casos): ");
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

			double retornoBubble = bubbleSort(vetor3, tam);
			double retornoInsert = insertSort(vetor2, tam);
			double retornoSelect = selectSort(vetor1, tam);
			
			if(retornoBubble < retornoInsert && retornoBubble < retornoSelect){
				printf("\n\n\n<<< BubbleSort foi o metodo mais rapido! >>>\n\n");
			}
			else if(retornoBubble == retornoInsert && retornoBubble < retornoSelect){
				printf("\n\n\n<<< BubbleSort e InsertSort foram os metodos mais rapidos! >>>\n\n");
			}
			else if(retornoBubble < retornoInsert && retornoBubble == retornoSelect){
				printf("\n\n\n<<< BubbleSort e SelectSort foram os metodos mais rapidos >>>\n\n");
			}
			else if(retornoBubble == retornoInsert && retornoBubble == retornoSelect){
				printf("\n\n\n<<< Todos os Metodos tiveram a mesma eficiencia! >>>\n\n");
			}
			else if(retornoInsert < retornoBubble && retornoInsert < retornoSelect){
				printf("\n\n\n<<< InsertSelect foi o metodo mais rapido! >>>\n\n");
			}
			else if(retornoInsert < retornoBubble && retornoInsert == retornoSelect){
				printf("\n\n\n<<< InsertSelect e SelectSort foram os metodos mais rapidos! >>>\n\n");
			}
			else if(retornoSelect < retornoInsert && retornoSelect < retornoBubble){
				printf("\n\n\n<<< SelectSort foi o metodo mais rapido! >>>\n\n");
			}
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

			double retornoBubble = bubbleSort(vetor3, tam);
			double retornoInsert = insertSort(vetor2, tam);
			double retornoSelect = selectSort(vetor1, tam);
			
			if(retornoBubble < retornoInsert && retornoBubble < retornoSelect){
				printf("\n\n\n<<< BubbleSort foi o metodo mais rapido! >>>\n\n");
			}
			else if(retornoBubble == retornoInsert && retornoBubble < retornoSelect){
				printf("\n\n\n<<< BubbleSort e InsertSort foram os metodos mais rapidos! >>>\n\n");
			}
			else if(retornoBubble < retornoInsert && retornoBubble == retornoSelect){
				printf("\n\n\n<<< BubbleSort e SelectSort foram os metodos mais rapidos >>>\n\n");
			}
			else if(retornoBubble == retornoInsert && retornoBubble == retornoSelect){
				printf("\n\n\n<<< Todos os Metodos tiveram a mesma eficiencia! >>>\n\n");
			}
			else if(retornoInsert < retornoBubble && retornoInsert < retornoSelect){
				printf("\n\n\n<<< InsertSelect foi o metodo mais rapido! >>>\n\n");
			}
			else if(retornoInsert < retornoBubble && retornoInsert == retornoSelect){
				printf("\n\n\n<<< InsertSelect e SelectSort foram os metodos mais rapidos! >>>\n\n");
			}
			else if(retornoSelect < retornoInsert && retornoSelect < retornoBubble){
				printf("\n\n\n<<< SelectSort foi o metodo mais rapido! >>>\n\n");
			}
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

			double retornoBubble = bubbleSort(vetor3, tam);
			double retornoInsert = insertSort(vetor2, tam);
			double retornoSelect = selectSort(vetor1, tam);
			
			if(retornoBubble < retornoInsert && retornoBubble < retornoSelect){
				printf("\n\n\n<<< BubbleSort foi o metodo mais rapido! >>>\n\n");
			}
			else if(retornoBubble == retornoInsert && retornoBubble < retornoSelect){
				printf("\n\n\n<<< BubbleSort e InsertSort foram os metodos mais rapidos! >>>\n\n");
			}
			else if(retornoBubble < retornoInsert && retornoBubble == retornoSelect){
				printf("\n\n\n<<< BubbleSort e SelectSort foram os metodos mais rapidos >>>\n\n");
			}
			else if(retornoBubble == retornoInsert && retornoBubble == retornoSelect){
				printf("\n\n\n<<< Todos os Metodos tiveram a mesma eficiencia! >>>\n\n");
			}
			else if(retornoInsert < retornoBubble && retornoInsert < retornoSelect){
				printf("\n\n\n<<< InsertSelect foi o metodo mais rapido! >>>\n\n");
			}
			else if(retornoInsert < retornoBubble && retornoInsert == retornoSelect){
				printf("\n\n\n<<< InsertSelect e SelectSort foram os metodos mais rapidos! >>>\n\n");
			}
			else if(retornoSelect < retornoInsert && retornoSelect < retornoBubble){
				printf("\n\n\n<<< SelectSort foi o metodo mais rapido! >>>\n\n");
			}
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

			double retornoBubble = bubbleSort(vetor3, tam);
			double retornoInsert = insertSort(vetor2, tam);
			double retornoSelect = selectSort(vetor1, tam);
			
			if(retornoBubble < retornoInsert && retornoBubble < retornoSelect){
				printf("\n\n\n<<< BubbleSort foi o metodo mais rapido! >>>\n\n");
			}
			else if(retornoBubble == retornoInsert && retornoBubble < retornoSelect){
				printf("\n\n\n<<< BubbleSort e InsertSort foram os metodos mais rapidos! >>>\n\n");
			}
			else if(retornoBubble < retornoInsert && retornoBubble == retornoSelect){
				printf("\n\n\n<<< BubbleSort e SelectSort foram os metodos mais rapidos >>>\n\n");
			}
			else if(retornoBubble == retornoInsert && retornoBubble == retornoSelect){
				printf("\n\n\n<<< Todos os Metodos tiveram a mesma eficiencia! >>>\n\n");
			}
			else if(retornoInsert < retornoBubble && retornoInsert < retornoSelect){
				printf("\n\n\n<<< InsertSelect foi o metodo mais rapido! >>>\n\n");
			}
			else if(retornoInsert < retornoBubble && retornoInsert == retornoSelect){
				printf("\n\n\n<<< InsertSelect e SelectSort foram os metodos mais rapidos! >>>\n\n");
			}
			else if(retornoSelect < retornoInsert && retornoSelect < retornoBubble){
				printf("\n\n\n<<< SelectSort foi o metodo mais rapido! >>>\n\n");
			}
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

			double retornoBubble = bubbleSort(vetor3, tam);
			double retornoInsert = insertSort(vetor2, tam);
			double retornoSelect = selectSort(vetor1, tam);
			
			if(retornoBubble < retornoInsert && retornoBubble < retornoSelect){
				printf("\n\n\n<<< BubbleSort foi o metodo mais rapido! >>>\n\n");
			}
			else if(retornoBubble == retornoInsert && retornoBubble < retornoSelect){
				printf("\n\n\n<<< BubbleSort e InsertSort foram os metodos mais rapidos! >>>\n\n");
			}
			else if(retornoBubble < retornoInsert && retornoBubble == retornoSelect){
				printf("\n\n\n<<< BubbleSort e SelectSort foram os metodos mais rapidos >>>\n\n");
			}
			else if(retornoBubble == retornoInsert && retornoBubble == retornoSelect){
				printf("\n\n\n<<< Todos os Metodos tiveram a mesma eficiencia! >>>\n\n");
			}
			else if(retornoInsert < retornoBubble && retornoInsert < retornoSelect){
				printf("\n\n\n<<< InsertSelect foi o metodo mais rapido! >>>\n\n");
			}
			else if(retornoInsert < retornoBubble && retornoInsert == retornoSelect){
				printf("\n\n\n<<< InsertSelect e SelectSort foram os metodos mais rapidos! >>>\n\n");
			}
			else if(retornoSelect < retornoInsert && retornoSelect < retornoBubble){
				printf("\n\n\n<<< SelectSort foi o metodo mais rapido! >>>\n\n");
			}
		}
		else if(escolha == 6){
			funcaoEspecial(tam, escolha2);
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

			double retornoBubble = bubbleSort(vetor3, tam);
			double retornoInsert = insertSort(vetor2, tam);
			double retornoSelect = selectSort(vetor1, tam);
			
			if(retornoBubble < retornoInsert && retornoBubble < retornoSelect){
				printf("\n\n\n<<< BubbleSort foi o metodo mais rapido! >>>\n\n");
			}
			else if(retornoBubble == retornoInsert && retornoBubble < retornoSelect){
				printf("\n\n\n<<< BubbleSort e InsertSort foram os metodos mais rapidos! >>>\n\n");
			}
			else if(retornoBubble < retornoInsert && retornoBubble == retornoSelect){
				printf("\n\n\n<<< BubbleSort e SelectSort foram os metodos mais rapidos >>>\n\n");
			}
			else if(retornoBubble == retornoInsert && retornoBubble == retornoSelect){
				printf("\n\n\n<<< Todos os Metodos tiveram a mesma eficiencia! >>>\n\n");
			}
			else if(retornoInsert < retornoBubble && retornoInsert < retornoSelect){
				printf("\n\n\n<<< InsertSelect foi o metodo mais rapido! >>>\n\n");
			}
			else if(retornoInsert < retornoBubble && retornoInsert == retornoSelect){
				printf("\n\n\n<<< InsertSelect e SelectSort foram os metodos mais rapidos! >>>\n\n");
			}
			else if(retornoSelect < retornoInsert && retornoSelect < retornoBubble){
				printf("\n\n\n<<< SelectSort foi o metodo mais rapido! >>>\n\n");
			}
		}
		else if(escolha == 2){
			
			int vetor1[5000], vetor2[5000], vetor3[5000];
			
			for(i=0; i<5000; i++){
				vetor1[i] = i;
				vetor2[i] = vetor1[i];
				vetor3[i] = vetor1[i];		
			}
			tam = 5000;

			double retornoBubble = bubbleSort(vetor3, tam);
			double retornoInsert = insertSort(vetor2, tam);
			double retornoSelect = selectSort(vetor1, tam);
			
			if(retornoBubble < retornoInsert && retornoBubble < retornoSelect){
				printf("\n\n\n<<< BubbleSort foi o metodo mais rapido! >>>\n\n");
			}
			else if(retornoBubble == retornoInsert && retornoBubble < retornoSelect){
				printf("\n\n\n<<< BubbleSort e InsertSort foram os metodos mais rapidos! >>>\n\n");
			}
			else if(retornoBubble < retornoInsert && retornoBubble == retornoSelect){
				printf("\n\n\n<<< BubbleSort e SelectSort foram os metodos mais rapidos >>>\n\n");
			}
			else if(retornoBubble == retornoInsert && retornoBubble == retornoSelect){
				printf("\n\n\n<<< Todos os Metodos tiveram a mesma eficiencia! >>>\n\n");
			}
			else if(retornoInsert < retornoBubble && retornoInsert < retornoSelect){
				printf("\n\n\n<<< InsertSelect foi o metodo mais rapido! >>>\n\n");
			}
			else if(retornoInsert < retornoBubble && retornoInsert == retornoSelect){
				printf("\n\n\n<<< InsertSelect e SelectSort foram os metodos mais rapidos! >>>\n\n");
			}
			else if(retornoSelect < retornoInsert && retornoSelect < retornoBubble){
				printf("\n\n\n<<< SelectSort foi o metodo mais rapido! >>>\n\n");
			}
		}
		else if(escolha == 3){
			int vetor1[10000], vetor2[10000], vetor3[10000];
			
			for(i=0; i<10000; i++){
				vetor1[i] = i;
				vetor2[i] = vetor1[i];
				vetor3[i] = vetor1[i];
			}
			tam = 10000;

			double retornoBubble = bubbleSort(vetor3, tam);
			double retornoInsert = insertSort(vetor2, tam);
			double retornoSelect = selectSort(vetor1, tam);
			
			if(retornoBubble < retornoInsert && retornoBubble < retornoSelect){
				printf("\n\n\n<<< BubbleSort foi o metodo mais rapido! >>>\n\n");
			}
			else if(retornoBubble == retornoInsert && retornoBubble < retornoSelect){
				printf("\n\n\n<<< BubbleSort e InsertSort foram os metodos mais rapidos! >>>\n\n");
			}
			else if(retornoBubble < retornoInsert && retornoBubble == retornoSelect){
				printf("\n\n\n<<< BubbleSort e SelectSort foram os metodos mais rapidos >>>\n\n");
			}
			else if(retornoBubble == retornoInsert && retornoBubble == retornoSelect){
				printf("\n\n\n<<< Todos os Metodos tiveram a mesma eficiencia! >>>\n\n");
			}
			else if(retornoInsert < retornoBubble && retornoInsert < retornoSelect){
				printf("\n\n\n<<< InsertSelect foi o metodo mais rapido! >>>\n\n");
			}
			else if(retornoInsert < retornoBubble && retornoInsert == retornoSelect){
				printf("\n\n\n<<< InsertSelect e SelectSort foram os metodos mais rapidos! >>>\n\n");
			}
			else if(retornoSelect < retornoInsert && retornoSelect < retornoBubble){
				printf("\n\n\n<<< SelectSort foi o metodo mais rapido! >>>\n\n");
			}
		}
		else if(escolha == 4){
			int vetor1[20000], vetor2[20000], vetor3[20000];
			
			for(i=0; i<20000; i++){
				vetor1[i] = i;
				vetor2[i] = vetor1[i];
				vetor3[i] = vetor1[i];
			}
			tam = 20000;

			double retornoBubble = bubbleSort(vetor3, tam);
			double retornoInsert = insertSort(vetor2, tam);
			double retornoSelect = selectSort(vetor1, tam);
			
			if(retornoBubble < retornoInsert && retornoBubble < retornoSelect){
				printf("\n\n\n<<< BubbleSort foi o metodo mais rapido! >>>\n\n");
			}
			else if(retornoBubble == retornoInsert && retornoBubble < retornoSelect){
				printf("\n\n\n<<< BubbleSort e InsertSort foram os metodos mais rapidos! >>>\n\n");
			}
			else if(retornoBubble < retornoInsert && retornoBubble == retornoSelect){
				printf("\n\n\n<<< BubbleSort e SelectSort foram os metodos mais rapidos >>>\n\n");
			}
			else if(retornoBubble == retornoInsert && retornoBubble == retornoSelect){
				printf("\n\n\n<<< Todos os Metodos tiveram a mesma eficiencia! >>>\n\n");
			}
			else if(retornoInsert < retornoBubble && retornoInsert < retornoSelect){
				printf("\n\n\n<<< InsertSelect foi o metodo mais rapido! >>>\n\n");
			}
			else if(retornoInsert < retornoBubble && retornoInsert == retornoSelect){
				printf("\n\n\n<<< InsertSelect e SelectSort foram os metodos mais rapidos! >>>\n\n");
			}
			else if(retornoSelect < retornoInsert && retornoSelect < retornoBubble){
				printf("\n\n\n<<< SelectSort foi o metodo mais rapido! >>>\n\n");
			}
		}
		else if(escolha == 5){
			int vetor1[50000], vetor2[50000], vetor3[50000];
			
			for(i=0; i<50000; i++){
				vetor1[i] = i;
				vetor2[i] = vetor1[i];
				vetor3[i] = vetor1[i];
			}
			tam = 50000;
			
			double retornoBubble = bubbleSort(vetor3, tam);
			double retornoInsert = insertSort(vetor2, tam);
			double retornoSelect = selectSort(vetor1, tam);
			
			if(retornoBubble < retornoInsert && retornoBubble < retornoSelect){
				printf("\n\n\n<<< BubbleSort foi o metodo mais rapido! >>>\n\n");
			}
			else if(retornoBubble == retornoInsert && retornoBubble < retornoSelect){
				printf("\n\n\n<<< BubbleSort e InsertSort foram os metodos mais rapidos! >>>\n\n");
			}
			else if(retornoBubble < retornoInsert && retornoBubble == retornoSelect){
				printf("\n\n\n<<< BubbleSort e SelectSort foram os metodos mais rapidos >>>\n\n");
			}
			else if(retornoBubble == retornoInsert && retornoBubble == retornoSelect){
				printf("\n\n\n<<< Todos os Metodos tiveram a mesma eficiencia! >>>\n\n");
			}
			else if(retornoInsert < retornoBubble && retornoInsert < retornoSelect){
				printf("\n\n\n<<< InsertSelect foi o metodo mais rapido! >>>\n\n");
			}
			else if(retornoInsert < retornoBubble && retornoInsert == retornoSelect){
				printf("\n\n\n<<< InsertSelect e SelectSort foram os metodos mais rapidos! >>>\n\n");
			}
			else if(retornoSelect < retornoInsert && retornoSelect < retornoBubble){
				printf("\n\n\n<<< SelectSort foi o metodo mais rapido! >>>\n\n");
			}
		}
		else if(escolha == 6){
			funcaoEspecial(tam, escolha2);
		}
		else{
			printf("Escolha Incorreta!\n");
		}
	}
}

