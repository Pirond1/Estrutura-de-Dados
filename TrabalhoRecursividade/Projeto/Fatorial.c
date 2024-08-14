#include <stdio.h>
#include <conio.h>

int calc_fatorial(int n){
	system("cls");
	
	if(n==0){
		return 1;	
	}
	else{
		return n * calc_fatorial(n-1);
	} 
	
	
}

int fatorial(){
	system("cls");
	int n = 0;
	printf("Informe um Numero (Maximo Aceito: 16): ");
	scanf("%d", &n);
	printf("Fatorial: %d\n", calc_fatorial(n));
	system("pause");
}
