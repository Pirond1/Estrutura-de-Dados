#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct no{
    int valor;
    struct no *prox;
};

typedef struct no Lista;

Lista* criarLista(){
    return NULL;
}

int listaVazia(Lista *lista){
    return (lista == NULL);
}

int totalElementosLista(Lista *lista){
	system("cls");
    int totalElementos = 0;
    Lista *pont = lista;
    while(pont != NULL){
        totalElementos++;
        pont = pont->prox;
    }
	return totalElementos;
	system("pause");
}

void exibirLista(Lista *lista){
	system("cls");
    if(listaVazia(lista)){
        printf("Lista Vazia\n");
    }else{
        Lista *pont = lista;
        while(pont != NULL){
            printf("%d -> ", pont->valor);
            pont = pont->prox;
        }
        printf("NULL\n");
        system("pause");
    }
}

Lista* inserirNoInicioLista(Lista *lista, int valor){
    Lista* novoNo = (Lista*) malloc(sizeof(Lista));
    novoNo->valor = valor;
    novoNo->prox = lista;
    return novoNo;
}

Lista* inserirNoOrdenado(Lista *lista, int valor){
	system("cls");
    Lista *novoNo = (Lista*) malloc(sizeof(Lista));
    novoNo->valor = valor;

    if(lista == NULL || lista->valor >= valor){
        novoNo->prox = lista;
        return novoNo;
    }else{
        Lista *pont = lista;
        while(pont->prox != NULL && pont->prox->valor < valor){
            pont = pont->prox;
        }
        novoNo->prox = pont->prox;
        pont->prox = novoNo;
    }
    return lista;
}

int pesquisarElemento(Lista *lista, int valor){
	system("cls");
    Lista *pont = lista;
    while(pont != NULL){
        if(pont->valor == valor) return 1;
        pont = pont->prox;
    }
    return 0;
}

Lista* removerQualquerNo(Lista *lista, int valor){
	system("cls");
    if(listaVazia(lista)) return lista;

    if(lista->valor == valor){
        Lista *removerNo = lista;
        lista = lista->prox;
        free(removerNo);
        return lista;
    }

    Lista *pont = lista;
    while(pont->prox != NULL && pont->prox->valor != valor){
        pont = pont->prox;
    }

    if(pont->prox != NULL){
        Lista *removerNo = pont->prox;
        pont->prox = removerNo->prox;
        free(removerNo);
    }
    return lista;
}

Lista* alterarElemento(Lista *lista, int valorAntigo, int valorNovo){
	system("cls");
    Lista *pont = lista;
    while(pont != NULL){
        if(pont->valor == valorAntigo){
            pont->valor = valorNovo;
            break;
        }
        pont = pont->prox;
    }
    return lista;
}

void main(){
	system("cls");
	setlocale(LC_ALL,"portuguese");
    Lista *lista = criarLista();
    int opcao, valor, novoValor;

    do{
        printf("\n<<Menu de Opções>>\n\n");
        printf("1- Inserir Elemento Ordenado\n");
        printf("2- Alterar Elemento\n");
        printf("3- Excluir Elemento\n");
        printf("4- Localizar Elemento\n");
        printf("5- Exibir Todos Elementos\n");
        printf("6- Exibir Quantidade de Elementos\n");
        printf("0- Sair\n");
        printf("Escolha uma Opção: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("Informe o Valor a ser Inserido: ");
                scanf("%d", &valor);
                lista = inserirNoOrdenado(lista, valor);
                break;
            case 2:
                printf("Informe o Valor a ser Alterado: ");
                scanf("%d", &valor);
                printf("Informe o Novo Valor: ");
                scanf("%d", &novoValor);
                lista = alterarElemento(lista, valor, novoValor);
                break;
            case 3:
                printf("Informe o Valor a ser Excluído: ");
                scanf("%d", &valor);
                lista = removerQualquerNo(lista, valor);
                break;
            case 4:
                printf("Informe o Valor a ser Localizado: ");
                scanf("%d", &valor);
                if(pesquisarElemento(lista, valor))
                    printf("Elemento Encontrado.\n");
                else
                    printf("Elemento Não Encontrado.\n");
                break;
            case 5:
                exibirLista(lista);
                break;
            case 6:
                printf("Quantidade de Elementos na Lista: %d\n", totalElementosLista(lista));
                break;
            case 0:
                printf("Obrigado por Utilizar!\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);
}

