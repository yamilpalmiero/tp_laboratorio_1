#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "arrayEmployees.h"

int menu();
int submenuInformes();

int main(void) {
	setbuf(stdout, NULL);

	return EXIT_SUCCESS;
}

int menu() {
	int opcion;

	system("cls");

	printf("Seleccioone una opcion:\n\n");
	printf("1- Alta alumno.\n");
	printf("2- Modificar empleado.\n");
	printf("3- Baja empleado.\n");
	printf("4- Informar.\n");
	printf("5- Salir.\n\n");
	scanf("%d", &opcion);

	return opcion;
}

int submenuInformes() {
	int opcion;

	system("cls");

	printf("Seleccioone una opcion:\n\n");
	printf("1- Listar por apellido y sector.\n");
	printf("2- Total y promedio de salarios, y cuantos empleados superan el salario promedio.\n");
	printf("3- Salir.\n\n");
	scanf("%d", &opcion);

	return opcion;
}

