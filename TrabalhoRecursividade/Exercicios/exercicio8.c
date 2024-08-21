#include <stdio.h>
#include <conio.h>
#include <string.h>

void imprimir_invertido(char *str, int index) {
    if (index < 0) {
        return;  
    }
    printf("%c", str[index]);  
    imprimir_invertido(str, index - 1); 
}

void main() {
    char str[100];
    printf("Digite uma Palavra de no Maximo 100 caracteres: ");
    fgets(str, 100, stdin);

    str[strcspn(str, "\n")] = '\0';

    int comprimento = strlen(str);
    printf("String invertida: ");
    imprimir_invertido(str, comprimento - 1);
}
