#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"
#include "arrayEmployee.h"

#define CANTIDAD_EMPLEADOS 3
#define ORDEN_ASCENDENTE 1
#define ORDEN_DESCENDENTE 0

int main(void) {
	setbuf(stdout, NULL);

	Employee list[CANTIDAD_EMPLEADOS];
	int opcionMenu;
	int opcionSubmenu;
	float sumaSalarios;
	float promedioSalarios;

	if (initEmployees(list, CANTIDAD_EMPLEADOS)) {
		printf("\nLa lista se inicializo correctamente.");
	} else {
		printf("\nError al inicializar.");
	}

	do {
		utn_getEntero(&opcionMenu,
				"\n\n***MENU EMPLEADOS***\nElija una opcion:\n\n1) Alta empleado \n2) Modificar empleado\n3) Baja empleado\n4) Informar \n5) Salir\n",
				"\nError", 1, 5, 2);

		switch (opcionMenu) {
		case 1:
			addEmployee(list, CANTIDAD_EMPLEADOS);
			break;
		case 2:
			if (arrayVacio(list, CANTIDAD_EMPLEADOS)) {
				printf("\nAun no se cargo ningun empleado.\n\n");
				system("pause");
			} else {
				modifyEmployee(list, CANTIDAD_EMPLEADOS);
			}
			break;
		case 3:
			if (arrayVacio(list, CANTIDAD_EMPLEADOS)) {
				printf("\nAun no se cargo ningun empleado.\n\n");
				system("pause");
			} else {
				removeEmployee(list, CANTIDAD_EMPLEADOS);
			}
			break;
		case 4:
			utn_getEntero(&opcionSubmenu,
					"\n\n1) Empleados ordenados por apellido y sector \n2) Total y promedio de salarios y cuantos empleados superan el salario promedio",
					"\nError", 1, 2, 2);
			switch (opcionSubmenu) {
			case 1:
				sortEmployees(list, CANTIDAD_EMPLEADOS, ORDEN_ASCENDENTE);
				printEmployees(list, CANTIDAD_EMPLEADOS);
				break;
			case 2:
				calcularPromedioSalario(list, CANTIDAD_EMPLEADOS,
						&promedioSalarios, &sumaSalarios);
				printf(
						"\nSuma total de salarios: %.2f\nPromedio: %.2f\nEmpleados con salario mayor al promedio: %d",
						sumaSalarios, promedioSalarios,
						salarioMayorPromedio(list, CANTIDAD_EMPLEADOS,
								promedioSalarios));
				break;
			}
			break;
		case 5:
			printf("\nSalio!\n\n");
			system("pause");
			break;
		}
	} while (opcionMenu != 5);

	return EXIT_SUCCESS;
}
