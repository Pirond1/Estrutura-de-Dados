#include <stdio.h>
#include <conio.h>

void menu(){
	int op;
	system("cls");
	printf("Informe uma opcao: \n");
	printf("1- Fatorial: \n");
	printf("2- Alunos: \n");
	printf("0- Sair: \n");
	printf("Informe uma opcao: ");
	scanf("%d", &op);
	switch(op){
		case 1:
			fatorial();
			break;
			
		case 2:
			Alunos();
			break;
		case 0:	
			printf("Fim!");
			break;
		default: printf("Opcao Nao Encontrada!\n");
		system("pause");
	}
	
	if(op != 0){
		menu();	
	}
	
}
void main(){
	menu();
	return 0;
}
