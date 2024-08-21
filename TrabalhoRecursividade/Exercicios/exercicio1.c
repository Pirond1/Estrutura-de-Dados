#include <stdio.h>
#include <conio.h>
/*
1.	Faça uma rotina recursiva para calcular a
 somatória de todos os números de 1 a N (N será lido do teclado).
*/
int soma(int num)
{
	int resultado;
	if (num == 1)
	{
		return (1);
	}
   	else
    {
    	resultado = num + soma(num - 1);
    }
	return (resultado);
}

void main()
{
   int num;
   int somatorio;

   printf("\n Programa para calcular a somatoria de todos os numeros de 1 a N:\n");

   printf("\n Digite o numero: ");
   scanf("%d", &num); 
   somatorio = soma(num);
   printf("\n O somatorio dos numeros de 1 ate %d = %d \n", num, somatorio);
}
