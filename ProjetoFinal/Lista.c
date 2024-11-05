#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        printf("\nElemento %d adicionado à fila.\n\n", data);
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
    printf("\nElemento %d adicionado à fila.\n\n", data);
}

void displayQueue(Queue* queue) {
    if (queue->front == NULL) {
        printf("\nA fila está vazia.\n");
        return;
    }
    Node* temp = queue->front;
    printf("\nElementos na fila: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void updateFront(Queue* queue, int newData) {
    if (queue->front == NULL) {
        printf("\nA fila está vazia. Não há nada para atualizar.\n\n");
        return;
    }
    queue->front->data = newData;
    printf("\nPrimeiro elemento atualizado para %d.\n\n", newData);
}

void dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("\nA fila está vazia. Não há nada para remover.\n\n");
        return;
    }
    Node* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL)
        queue->rear = NULL;
    printf("Elemento %d removido da fila.\n\n", temp->data);
    free(temp);
}

int main() {
	setlocale(LC_ALL, "portuguese");
    Queue* queue = createQueue();
    int choice, data;

    while (1) {
    	system("cls");
        printf("\n<<Menu>>\n");
    	printf("1. Adicionar elemento na fila\n");
    	printf("2. Exibir elementos da fila\n");
    	printf("3. Atualizar o primeiro elemento da fila\n");
   		printf("4. Remover o primeiro elemento da fila\n");
    	printf("5. Sair\n");
    	printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            	system("cls");
                printf("Digite o elemento a ser adicionado: ");
                scanf("%d", &data);
                enqueue(queue, data);
                system("pause");
                break;
            case 2:
                displayQueue(queue);
                system("pause");
                break;
            case 3:
            	system("cls");
                printf("Digite o novo valor para o primeiro elemento: ");
                scanf("%d", &data);
                updateFront(queue, data);
                system("pause");
                break;
            case 4:
            	system("cls");
                dequeue(queue);
                system("pause");
                break;
            case 5:
                printf("\nSaindo do programa.\n");
                exit(0);
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}

