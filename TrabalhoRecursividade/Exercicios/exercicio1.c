#include <stdio.h>
#include <conio.h>
/*
1.	Fa�a uma rotina recursiva para calcular a
 somat�ria de todos os n�meros de 1 a N (N ser� lido do teclado).
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
