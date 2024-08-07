#include <stdio.h>
#include <conio.h>
#include <string.h>


void main (){
	int valor, maximo, minimo, count;
	for(count=1; count<=10; count++){
		printf("Informe o valor de n%d: ", count);
		scanf("%d", &valor);
		if(count == 1){
			maximo = valor;
			minimo = valor;
		}else{
			if(maximo < valor){
				maximo = valor;
			}else{
				if(minimo > valor){
					minimo = valor;
				}
			}	
		}
		
	}
	printf("Maior Valor -> %d\nMenor Valor -> %d", maximo, minimo);
}

