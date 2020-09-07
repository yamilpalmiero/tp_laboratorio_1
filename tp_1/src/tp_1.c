#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"

int main(void) {
	setbuf(stdout, NULL);

	int flag1 = 0;
	int flag2 = 0;
	int flag3 = 0;
	int num1;
	int num2;
	int opcion;
	int suma = 0;
	int resta = 0;
	float division = 0;
	int multiplicacion = 0;
	int factorial1 = 0;
	int factorial2 = 0;

	printf("\n*****MENU*****");

	do {
		if (flag1 == 0 && flag2 == 0) {
			printf("\n\n1- Ingrese 1er operando (A=x).");
			printf("\n2- Inrgese 2do operando (B=y).");
			printf("\n3- Calcular todas las operaciones.");
			printf("\n4- Informar resultados.");
			printf("\n5- Salir.");
		} else if (flag1 == 1 && flag2 == 0) {
			printf("\n\n1- Ingrese 1er operando (A=%d).", num1);
			printf("\n2- Inrgese 2do operando (B=y).");
			printf("\n3- Calcular todas las operaciones.");
			printf("\n4- Informar resultados.");
			printf("\n5- Salir.");
		} else if (flag1 == 0 && flag2 == 1) {
			printf("\n\n1- Ingrese 1er operando (A=x).");
			printf("\n2- Inrgese 2do operando (B=%d).", num2);
			printf("\n3- Calcular todas las operaciones.");
			printf("\n4- Informar resultados.");
			printf("\n5- Salir.");
		} else {
			printf("\n\n1- Ingrese 1er operando (A=%d).", num1);
			printf("\n2- Inrgese 2do operando (B=%d).", num2);
			printf("\n3- Calcular todas las operaciones.");
			printf("\n4- Informar resultados.");
			printf("\n5- Salir.");
		}

		printf("\nIngrese una opcion: ");
		scanf("%d", &opcion);

		switch (opcion) {
		case 1:
			printf("\nIngrese 1er operando: ");
			scanf("%d", &num1);
			flag1 = 1;
			break;
		case 2:
			printf("\nIngrese 2do operando: ");
			scanf("%d", &num2);
			flag2 = 1;
			break;
		case 3:
			if (flag1 == 0 || flag2 == 0) {
				printf("\nError, debe ingresar ambos operandos.\n");
				system("pause");
			} else {
				suma = sumar(num1, num2);
				resta = restar(num1, num2);
				division = dividir(num1, num2);
				multiplicacion = multiplicar(num1, num2);
				factorial1 = factorial(num1);
				factorial2 = factorial(num2);
				printf("\nSe calcularon todas las operaciones.");
				flag3 = 1;
			}
			break;
		case 4:
			if (flag3 == 0) {
				printf("\nError, no realizo ningun calculo.\n");
				system("pause");
				break;
			}
			printf("\nLos resultados son:");
			if (num2 == 0) {
				printf("\n%d + %d = %d", num1, num2, suma);
				printf("\n%d - %d = %d", num1, num2, resta);
				printf("\n%d / %d = Error, no se puede dividir por cero.", num1, num2);
				printf("\n%d * %d = %d", num1, num2, multiplicacion);
				printf("\n%d! = %d", num1, factorial1);
				printf("\n%d! = %d", num2, factorial2);
			} else {
				printf("\n%d + %d = %d", num1, num2, suma);
				printf("\n%d - %d = %d", num1, num2, resta);
				printf("\n%d / %d = %.2f", num1, num2, division);
				printf("\n%d * %d = %d", num1, num2, multiplicacion);
				printf("\n%d! = %d", num1, factorial1);
				printf("\n%d! = %d", num2, factorial2);
			}
			break;
		case 5:
			printf("\nSalio de la calculadora.\n\n");
			system("pause");
			break;
		}
	} while (opcion != 5);

	return 0;
}
