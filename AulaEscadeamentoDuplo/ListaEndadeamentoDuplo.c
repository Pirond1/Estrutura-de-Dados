#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

struct Filme {
    char nome[100];
    int ano;
    int minutagem;
    char genero[50];
    struct Filme *prox;
    struct Filme *ant;
};

typedef struct Filme Filme;

// Cria uma nova lista vazia
Filme* criarLista() {
    return NULL;
}

// Insere um filme no início da lista
Filme* inserirFilme(Filme* lista, char* nome, int ano, int minutagem, char* genero) {
    Filme* novoFilme = (Filme*) malloc(sizeof(Filme));
    strcpy(novoFilme->nome, nome);
    novoFilme->ano = ano;
    novoFilme->minutagem = minutagem;
    strcpy(novoFilme->genero, genero);
    novoFilme->prox = lista;
    novoFilme->ant = NULL;

    if (lista != NULL) {
        lista->ant = novoFilme;
    }
    return novoFilme;
}

// Ordena os filmes da lista pela ano
void ordenarFilmes(Filme* lista) {
    Filme *i, *j;
    Filme aux;

    for (i = lista; i != NULL; i = i->prox) {
        for (j = i->prox; j != NULL; j = j->prox) {
            if (i->ano > j->ano) {
                aux = *i;
                *i = *j;
                *j = aux;

                // Ajusta os ponteiros de prox e ant
                if (i->prox == j) {
                    i->prox = j->prox;
                    j->prox = i;
                    j->ant = i->ant;
                    if (i->ant != NULL) i->ant->prox = j;
                    if (j->prox != NULL) j->prox->ant = i;
                    i->ant = j;
                }
            }
        }
    }
}

// Lista os filmes em ordem normal
void listarFilmes(Filme* lista) {
    int i = 1;
    system("cls");
    printf("<<Listar Filmes>>\n\n");
    Filme* temp;
    for (temp = lista; temp != NULL; temp = temp->prox) {
        printf("<<Filme %d>>\n\n", i++);
        printf("Nome: %s\n", temp->nome);
        printf("Ano: %d\n", temp->ano);
        printf("Minutagem: %d\n", temp->minutagem);
        printf("Gênero: %s\n\n", temp->genero);
    }
    system("pause");
}

// Lista os filmes em ordem reversa
void listarFilmesReverso(Filme* lista) {
    Filme* temp = lista;

    // Vai até o último filme
    while (temp != NULL && temp->prox != NULL) {
        temp = temp->prox;
    }

    int i = 1;
    system("cls");
    printf("<<Listar Filmes em Ordem Reversa>>\n\n");
    // Percorre a lista de trás para frente
    while (temp != NULL) {
        printf("<<Filme %d>>\n\n", i++);
        printf("Nome: %s\n", temp->nome);
        printf("Ano: %d\n", temp->ano);
        printf("Minutagem: %d\n", temp->minutagem);
        printf("Gênero: %s\n\n", temp->genero);
        temp = temp->ant;
    }
    system("pause");
}

// Função para buscar filme e editar ou excluir
void buscarFilme(Filme* lista) {
    int opcao, local = -1;
    char nomeBusca[100];
    int anoBusca, minutagemBusca;
    char generoBusca[50];

    system("cls");
    printf("<<Buscar Filme>>\n\n");
    printf("Buscar Filme por:\n");
    printf("1- Nome\n");
    printf("2- Ano\n");
    printf("3- Minutagem\n");
    printf("4- Gênero\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    getchar();

    Filme* temp = lista;

    switch (opcao) {
        case 1:
            printf("Informe o Nome do Filme Desejado: ");
            fgets(nomeBusca, 100, stdin);
            nomeBusca[strcspn(nomeBusca, "\n")] = '\0';
            while (temp != NULL) {
                if (strcmp(temp->nome, nomeBusca) == 0) {
                    local = 1;
                    break;
                }
                temp = temp->prox;
            }
            break;
        case 2:
            printf("Informe o Ano do Filme Desejado: ");
            scanf("%d", &anoBusca);
            getchar();
            while (temp != NULL) {
                if (temp->ano == anoBusca) {
                    local = 1;
                    break;
                }
                temp = temp->prox;
            }
            break;
        case 3:
            printf("Informe a Minutagem do Filme Desejado: ");
            scanf("%d", &minutagemBusca);
            getchar();
            while (temp != NULL) {
                if (temp->minutagem == minutagemBusca) {
                    local = 1;
                    break;
                }
                temp = temp->prox;
            }
            break;
        case 4:
            printf("Informe o Gênero do Filme Desejado: ");
            fgets(generoBusca, 50, stdin);
            generoBusca[strcspn(generoBusca, "\n")] = '\0';
            while (temp != NULL) {
                if (strcmp(temp->genero, generoBusca) == 0) {
                    local = 1;
                    break;
                }
                temp = temp->prox;
            }
            break;
        default:
            printf("Opção inválida!\n");
            return;
    }

    if (local != -1) {
        printf("\n<<Filme Encontrado>>\n");
        printf("Nome: %s\n", temp->nome);
        printf("Ano: %d\n", temp->ano);
        printf("Minutagem: %d\n", temp->minutagem);
        printf("Gênero: %s\n\n", temp->genero);

        printf("Deseja (1- Editar /2- Excluir /0- Cancelar): ");
        int acao;
        scanf("%d", &acao);
        getchar();

        if (acao == 1) {
            printf("Informe o Novo Nome do Filme: ");
            fgets(temp->nome, 100, stdin);
            temp->nome[strcspn(temp->nome, "\n")] = '\0';

            printf("Informe o Novo Ano do Filme: ");
            scanf("%d", &temp->ano);
            getchar();

            printf("Informe a Nova Minutagem do Filme: ");
            scanf("%d", &temp->minutagem);
            getchar();

            printf("Informe o Novo Gênero do Filme: ");
            fgets(temp->genero, 50, stdin);
            temp->genero[strcspn(temp->genero, "\n")] = '\0';

            printf("\nFilme atualizado com sucesso!\n");
        } else if (acao == 2) {
            // Remover filme
            if (temp->ant != NULL) {
                temp->ant->prox = temp->prox;
            } else {
                lista = temp->prox; // Removendo o primeiro elemento
            }
            if (temp->prox != NULL) {
                temp->prox->ant = temp->ant;
            }
            free(temp);
            printf("\nFilme removido com sucesso!\n");
        }
    } else {
        printf("Filme não encontrado!\n");
    }

    system("pause");
}

void main() {
    setlocale(LC_ALL, "portuguese");
    Filme* lista = criarLista();
    int opcao;

    do {
        printf("\n<<Menu>>\n\n");
        printf("1- Inserir Filme\n");
        printf("2- Buscar/Editar/Excluir Filme\n");
        printf("3- Listar Filmes\n");
        printf("4- Listar Filmes em Ordem Reversa\n");
        printf("0- Sair\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1: {
                char nome[100], genero[50];
                int ano, minutagem;

                printf("Informe o Nome do Filme: ");
                fgets(nome, 100, stdin);
                nome[strcspn(nome, "\n")] = '\0';

                printf("Informe o Ano do Filme: ");
                scanf("%d", &ano);
                getchar();

                printf("Informe a Minutagem do Filme: ");
                scanf("%d", &minutagem);
                getchar();

                printf("Informe o Gênero do Filme: ");
                fgets(genero, 50, stdin);
                genero[strcspn(genero, "\n")] = '\0';

                lista = inserirFilme(lista, nome, ano, minutagem, genero);
                ordenarFilmes(lista);
                break;
            }
            case 2:
                buscarFilme(lista);
                break;
            case 3:
                listarFilmes(lista);
                break;
            case 4:
                listarFilmesReverso(lista);
                break;
            case 0:
                printf("\nSaindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}

