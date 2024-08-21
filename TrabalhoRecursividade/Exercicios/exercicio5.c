#include <stdio.h>
#include <conio.h>

void inverter_vetor(int vetor[], int inicio, int fim) {
    if (inicio >= fim) {
        return;
    }

    int aux = vetor[inicio];
    vetor[inicio] = vetor[fim];
    vetor[fim] = aux;

    inverter_vetor(vetor, inicio + 1, fim - 1);
}

int main() {
    int vetor[10], i;
    
    printf("Digite 10 numeros reais: \n");
    for (i = 0; i < 10; i++) {
        printf("Posicao %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    inverter_vetor(vetor, 0, 9);

    printf("\nVetor invertido: \n");
    for (i = 0; i < 10; i++) {
        printf("%d\n", vetor[i]);
    }
    printf("\n");

    return 0;
}
