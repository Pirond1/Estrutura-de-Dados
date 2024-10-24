#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
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

Filme* criarLista() {
    return NULL;
}

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

void ordenarFilmes(Filme* lista) {
    if (lista == NULL) return;

    int trocado;
    Filme *i, *j = NULL;

    do {
        trocado = 0;
        i = lista;

        while (i->prox != j) {
            if (i->ano > i->prox->ano) {
                char nomeAux[100], generoAux[50];
                int anoAux, minutagemAux;

                strcpy(nomeAux, i->nome);
                anoAux = i->ano;
                minutagemAux = i->minutagem;
                strcpy(generoAux, i->genero);

                strcpy(i->nome, i->prox->nome);
                i->ano = i->prox->ano;
                i->minutagem = i->prox->minutagem;
                strcpy(i->genero, i->prox->genero);

                strcpy(i->prox->nome, nomeAux);
                i->prox->ano = anoAux;
                i->prox->minutagem = minutagemAux;
                strcpy(i->prox->genero, generoAux);

                trocado = 1;
            }
            i = i->prox;
        }
        j = i;
    } while (trocado);
}

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
    system("cls");
}

void listarFilmesReverso(Filme* lista) {
    Filme* temp = lista;

    while (temp != NULL && temp->prox != NULL) {
        temp = temp->prox;
    }

    int i = 1;
    system("cls");
    printf("<<Listar Filmes em Ordem Reversa>>\n\n");
    while (temp != NULL) {
        printf("<<Filme %d>>\n\n", i++);
        printf("Nome: %s\n", temp->nome);
        printf("Ano: %d\n", temp->ano);
        printf("Minutagem: %d\n", temp->minutagem);
        printf("Gênero: %s\n\n", temp->genero);
        temp = temp->ant;
    }
    system("pause");
    system("cls");
}

void BuscaMinuscula(char* str) {
    int i;
	for (i=0;str[i];i++){
        str[i] = tolower(str[i]);
    }
}

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
            BuscaMinuscula(nomeBusca);
            while (temp != NULL) {
                char nomeTemp[100];
                strcpy(nomeTemp, temp->nome);
                BuscaMinuscula(nomeTemp);
                if (strcmp(nomeTemp, nomeBusca) == 0) {
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
            BuscaMinuscula(generoBusca);
            while (temp != NULL) {
                char generoTemp[50];
                strcpy(generoTemp, temp->genero);
                BuscaMinuscula(generoTemp);
                if (strcmp(generoTemp, generoBusca) == 0) {
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

            if (temp->ant != NULL) {
                temp->ant->prox = temp->prox;
            } else {
                lista = temp->prox;
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
    system("cls");
}

Filme* carregarFilmes() {
    FILE *arquivo = fopen("filmes.bin", "rb");
    if (arquivo == NULL) {
        return NULL;
    }

    Filme* lista = NULL;
    Filme* ultimo = NULL;
    Filme temp;

    while (fread(&temp, sizeof(Filme), 1, arquivo)) {
        Filme* novoFilme = (Filme*) malloc(sizeof(Filme));
        *novoFilme = temp;
        novoFilme->prox = NULL;
        novoFilme->ant = ultimo;

        if (ultimo != NULL) {
            ultimo->prox = novoFilme;
        } else {
            lista = novoFilme;
        }

        ultimo = novoFilme;
    }

    fclose(arquivo);
    return lista;
}

void salvarFilmes(Filme* lista) {
    FILE *arquivo = fopen("filmes.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao Salvar!\n");
        return;
    }

    Filme* temp = lista;
    while (temp != NULL) {
        fwrite(temp, sizeof(Filme), 1, arquivo);
        temp = temp->prox;
    }

    fclose(arquivo);
}

void main() {
    setlocale(LC_ALL, "portuguese");
    Filme* lista = carregarFilmes();
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
                
                printf("\nFilme Inserido com Sucesso!\n");
                system("pause");
                system("cls");
                break;
            }
            case 2:
                buscarFilme(lista);
                ordenarFilmes(lista);
                break;
            case 3:
                listarFilmes(lista);
                break;
            case 4:
                listarFilmesReverso(lista);
                break;
            case 0:
                printf("\nSalvando Algoritimo, Aguarde...\n");
                salvarFilmes(lista);
                Sleep(3000);
                printf("\nInformações Salvas com Sucesso!\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}

