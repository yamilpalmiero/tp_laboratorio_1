#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

int sumar(int x, int y) {
	int resultado;
	resultado = x + y;
	return resultado;
}

int restar(int x, int y) {
	int resultado;
	resultado = x - y;
	return resultado;
}

float dividir(int x, int y) {
	float resultado;
	if (y == 0) {
		printf("\nError, no se puede dividir por 0.");
	} else {
		resultado = (float) x / y;
	}
	return resultado;
}

int multiplicar(int x, int y) {
	int resultado;
	resultado = x * y;
	return resultado;
}

int factorial(int x) {
	int resultado;
	int i;
	if (x < 0) {
		printf("No se puede calcular el factorial de un numero negativo.");
	} else if (x == 0) {
		resultado = 1;
	} else if (x == 1) {
		resultado = 1;
	} else {
		for (i = 1; i <= x; i++) {
			resultado = x * factorial(x - 1);
		}
	}
	return resultado;
}
