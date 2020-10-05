#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"
#include "array.h"
#include "arrayEmployee.h"
#define TAM 51

//----------------------------------------------------------------------------------------------------------
int initEmployees(Employee *list, int len) {
	int retorno = -1;
	int i;

	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			list[i].isEmpty = 1;
			retorno = 0;
		}
	}
	return retorno;
}
//----------------------------------------------------------------------------------------------------------
int buscarLibre(Employee *list, int len, int *posicion) {
	int retorno = -1;
	int i;

	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == 1) {
				*posicion = i;
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}
//----------------------------------------------------------------------------------------------------------
int addEmployee(Employee *list, int len, int id, char name[], char lastName[],
		float salary, int sector) {
	int retorno = -1;
	int posicion;

	if (list != NULL && len > 0) {
		if (buscarLibre(list, len, &posicion) == -1) {
			printf("\nNo hay lugares vacios.");
		} else {
			list[posicion].id = id;
			utn_getCadena(list[posicion].name, "\nIngrese nombre: ", "\nError.",
					1, TAM, 2);
			utn_getCadena(list[posicion].lastName, "\nIngrese apellido: ",
					"\nError.", 1, TAM, 2);
			utn_getFlotante(&list[posicion].salary, "\nIngrese salario: ",
					"\nError.", 1, 1000000, 2);
			utn_getEntero(&list[posicion].sector, "\nIngrese sector: ",
					"\nError.", 1, 100, 2);
			list[posicion].isEmpty = 0;
			printf(
					"\nPosicion: %d\nId: %d\nNombre: %s\nApellido: %s\nSalario: %.2f\nSector: %d",
					posicion, list[posicion].id, list[posicion].name,
					list[posicion].lastName, list[posicion].salary,
					list[posicion].sector);
			retorno = 0;
		}
	}
	return retorno;
}
//----------------------------------------------------------------------------------------------------------
int findEmployeeById(Employee *list, int len, int id, int *posicion) {
	int retorno = -1;
	int i;

	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == 1) {
				continue;
			} else if (list[i].id == id) {
				*posicion = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
//----------------------------------------------------------------------------------------------------------
int removeEmployee(Employee *list, int len, int id) {
	return -1;
}
//----------------------------------------------------------------------------------------------------------
int sortEmployees(Employee *list, int len, int order) {
	return 0;
}
//----------------------------------------------------------------------------------------------------------
int printEmployees(Employee *list, int length) {
	return 0;
}
//----------------------------------------------------------------------------------------------------------
