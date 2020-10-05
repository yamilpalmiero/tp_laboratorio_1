#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"
#include "arrayEmployee.h"

int main(void) {
	setbuf(stdout, NULL);

	char nombre[51];
	float salario;

	if (utn_getCadena(nombre, "\nIngrese nombre: ", "\nError.", 1, 51, 2)
			== 0) {
		printf("\nNombre: %s", nombre);
	}

	if (utn_getFlotante(&salario, "\nIngrese salario: ", "\nError.", 1,
			10000000, 2) == 0) {
		printf("\nSalario: %.2f", salario);
	}

	return EXIT_SUCCESS;
}
