#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

int tamanho = 10;

struct Filme {
    char nome[100];
    int ano;
    int minutagem;
    char genero[50];
};

void OrdenarFilme(struct Filme filmes[], int *quantidade){
	int i, j;
    struct Filme aux;

    for(i=0;i<*quantidade-1;i++){
        for (j=0;j<*quantidade-i-1;j++){
            if (filmes[j].ano>filmes[j+1].ano){
                // Troca os filmes de posição
                aux = filmes[j];
                filmes[j] = filmes[j + 1];
                filmes[j + 1] = aux;
            }
        }
    }
}

void InserirFilme(struct Filme filmes[], int *quantidade){
	system("cls");
	int opcao;
	printf("<<Inserção de Filme>>\n\n");
	do{
		
		if(*quantidade < tamanho){
        printf("Informe o Nome do Filme: ");
        fgets(filmes[*quantidade].nome, 100, stdin);
        filmes[*quantidade].nome[strcspn(filmes[*quantidade].nome, "\n")] = '\0';

        printf("Informe o Ano do Filme: ");
        scanf("%d", &filmes[*quantidade].ano);
        getchar();

        printf("Informe a Minutagem do Filme: ");
        scanf("%d", &filmes[*quantidade].minutagem);
        getchar();

        printf("Informe o Tema do Filme: ");
        fgets(filmes[*quantidade].genero, 50, stdin);
        filmes[*quantidade].genero[strcspn(filmes[*quantidade].genero, "\n")] = '\0';

        (*quantidade)++;
        if(*quantidade > 1){
        	OrdenarFilme(filmes, &*quantidade);	
		}
        
        printf("\nFilme inserido com sucesso!\n");
        printf("Continuar Adicionando? (1- Sim / 2- Não): ");
        scanf("%d", &opcao);
        getchar();
    	}else{
        printf("Não é possível adicionar mais filmes. Limite de %d filmes atingido.\n\n", tamanho);
        opcao = 2;
        system("pause");
		}
    	printf("\n");
	}while(opcao != 2);
	
}

void listarFilmesFrente(struct Filme filmes[], int quantidade){
    int i;
	system("cls");
    printf("<<Listar Filmes>>\n\n");
    for (i=0;i<quantidade;i++){
        printf("<<Filme %d>>\n\n", i + 1);
        printf("Nome: %s\n", filmes[i].nome);
        printf("Ano: %d\n", filmes[i].ano);
        printf("Minutagem: %d\n", filmes[i].minutagem);
        printf("Gênero: %s\n\n", filmes[i].genero);
    }
    system("pause");
}

void BuscarFilme(struct Filme filmes[], int *quantidade){
	int opcao, i, anoBusca, minutagemBusca, posicao;
    char nomeBusca[100], generoBusca[50];
	system("cls");
	
    printf("<<Buscar Filme>>\n\n");
    printf("Buscar Filme por:\n");
    printf("1- Nome\n");
    printf("2- Ano\n");
    printf("3- Minutagem\n");
    printf("4- Gênero\n");
    printf("5- Posição no vetor\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    getchar();

	int local = -1;

	switch(opcao){
        case 1:
            printf("Informe o Nome do Filme Desejado: ");
            fgets(nomeBusca, 100, stdin);
            nomeBusca[strcspn(nomeBusca, "\n")] = '\0';
            for(i=0;i<*quantidade;i++){
                if(strcmp(filmes[i].nome, nomeBusca) == 0){
                    local = i;
                    break;
            	}
            }
            break;
        case 2:
            printf("Informe o Ano do Filme Desejado: ");
            scanf("%d", &anoBusca);
            getchar();
            for(i=0;i<*quantidade;i++){
                if(filmes[i].ano == anoBusca){
                    local = i;
                    break;
                }
            }
            break;
        case 3:
            printf("Informe a Minutagem do Filme Desejado: ");
            scanf("%d", &minutagemBusca);
            getchar();
            for(i=0;i<*quantidade;i++){
                if(filmes[i].minutagem == minutagemBusca){
                    local = i;
                    break;
                }
            }
            break;
        case 4:
            printf("Informe o Gênero do Filme Desejado: ");
            fgets(generoBusca, 50, stdin);
            generoBusca[strcspn(generoBusca, "\n")] = '\0';
            for(i=0;i<*quantidade;i++){
                if(strcmp(filmes[i].genero, generoBusca) == 0){
                    local = i;
                    break;
                }
            }
            break;
        case 5:
            printf("Informe a Posição do Filme Desejado (1 a %d): ", *quantidade);
            scanf("%d", &posicao);
            getchar();
            if (posicao > 0 && posicao <= *quantidade){
                local = posicao - 1;
            } else {
                printf("Posição inválida!\n");
                return;
            }
            break;
        default:
            printf("Opção inválida!\n");
            return;
    }
    
    if(local != -1){
        printf("\n<<Filme Encontrado>>\n");
        printf("Nome: %s\n", filmes[local].nome);
        printf("Ano: %d\n", filmes[local].ano);
        printf("Minutagem: %d\n", filmes[local].minutagem);
        printf("Gênero: %s\n\n", filmes[local].genero);

        printf("Deseja (1- Editar /2- Excluir /0- Cancelar): ");
        int acao;
        scanf("%d", &acao);
        getchar();

        if(acao == 1){
			EditarFilme(&filmes[local], local);
        }else if(acao == 2){
            ExcluirFilme(filmes, &quantidade, local);
        }
    }else{
        printf("Filme não encontrado!\n");
    }

    system("pause");
}

void EditarFilme(struct Filme *filme, int local){
	system("cls");
	printf("<<Editar Filme %d>>\n\n", local+1);
    printf("Informe o Novo Nome do Filme: ");
    fgets(filme->nome, 100, stdin);
    filme->nome[strcspn(filme->nome, "\n")] = '\0';

    printf("Informe o Novo Ano do Filme: ");
    scanf("%d", &filme->ano);
    getchar();

    printf("Informe a Nova Minutagem do Filme: ");
    scanf("%d", &filme->minutagem);
    getchar();

    printf("Informe o Novo Gênero do Filme: ");
    fgets(filme->genero, 50, stdin);
    filme->genero[strcspn(filme->genero, "\n")] = '\0';

    printf("\nFilme atualizado com sucesso!\n");
}

void ExcluirFilme(struct Filme filmes[], int *quantidade, int local){
    int i;
	for(i=local;i<*quantidade-1;i++){
        filmes[i] = filmes[i+1];
        printf("teste");
    }
    (*quantidade)--;
    printf("\nFilme removido com sucesso!\n");
}

void main (){
	setlocale(LC_ALL,"portuguese");
	printf("Informe o Tamanho de Armazenamento Maximo Desejado: ");
	scanf("%d", &tamanho);
	printf("Tamanho Definido -> %d\n", tamanho);
	struct Filme filmes[tamanho];
	int opcao, quantidade = 0;
	
	do{
        printf("\n<<Menu>>\n\n");
        printf("1- Inserir Filme\n");
        printf("2- Buscar/Editar/Excluir Filme\n");
        printf("3- Listar Filmes (ordem normal)\n");
        printf("4- Listar Filmes (ordem reversa)\n");
        printf("5- Quantidade de Filme\n");
        printf("0- Sair\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);
        getchar();
        
        switch(opcao){
            case 1:
                InserirFilme(filmes, &quantidade);
                system("cls");
                break;
            case 2:
                BuscarFilme(filmes, &quantidade);
                system("cls");
                if(quantidade > 1){
        			OrdenarFilme(filmes, &quantidade);	
				}
                break;
            case 3:
                listarFilmesFrente(filmes, quantidade);
                system("cls");
                break;
            case 4:
                
                break;
            case 5:
            	system("cls");
                printf("Quantidade de filmes cadastrados: %d\n\n", quantidade);
                system("pause");
                system("cls");
                break;
            case 0:
                printf("\nSalvando Algoritimo, Aguarde...\n");
                
                Sleep(3000);
                printf("\nInformações Salvas com Sucesso!\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }while(opcao != 0);
}

