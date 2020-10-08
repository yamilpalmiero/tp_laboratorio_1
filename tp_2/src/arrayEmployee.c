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
			retorno = 1;
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
int addEmployee(Employee *list, int len) {
	int retorno = -1;
	int posicion;

	if (list != NULL && len > 0) {
		if (buscarLibre(list, len, &posicion) == -1) {
			printf("\nNo hay lugares vacios.");
		} else {
			list[posicion].id = posicion;
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
int modifyEmployee(Employee *list, int len) {
	int retorno = -1;
	int posicion;
	int id;
	int opcion;

	if (list != NULL && len > 0) {
		printEmployees(list, len);
		utn_getEntero(&id, "\nId a modificar: ", "\nError", 0, 999, 2);
		if (findEmployeeById(list, len, id, &posicion) == -1) {
			printf("\nEl id ingresado no existe.");
		} else {
			do {
				printf(
						"\nPosicion: %d\nId: %d\nNombre: %s\nApellido: %s\nSalario: %.2f\nSector: %d\n",
						posicion, list[posicion].id, list[posicion].name,
						list[posicion].lastName, list[posicion].salary,
						list[posicion].sector);
				utn_getEntero(&opcion,
						"\nModificar: \n\n1-Nombre \n2-Apellido \n3-Salario \n4-Sector \n5-Salir\n",
						"\nError", 1, 5, 2);
				switch (opcion) {
				case 1:
					utn_getCadena(list[posicion].name, "\nNombre: ", "\nError",
							1, 51, 2);
					break;
				case 2:
					utn_getCadena(list[posicion].lastName, "\nApellido: ",
							"\nError", 1, 51, 2);
					break;
				case 3:
					utn_getFlotante(&list[posicion].salary, "\nSalario: ",
							"\nError.", 1, 1000000, 2);
					break;
				case 4:
					utn_getEntero(&list[posicion].sector, "\nSector: ",
							"\nError.", 1, 100, 2);
					break;
				case 5:
					break;
				default:
					printf("\nOpcion invalida");
				}
			} while (opcion != 5);
			retorno = 0;
		}
	}
	return retorno;
}
//----------------------------------------------------------------------------------------------------------
int removeEmployee(Employee *list, int len) {
	int retorno = -1;
	int posicion;
	int id;

	if (list != NULL && len > 0) {
		printEmployees(list, len);
		utn_getEntero(&id, "\nId a eliminar: ", "\nError.", 0, 999, 2);
		if (findEmployeeById(list, len, id, &posicion) == -1) {
			printf("\nEl id ingresado no existe.");
		} else {
			list[posicion].isEmpty = 1;
			retorno = 0;
		}
	}

	return retorno;
}
//----------------------------------------------------------------------------------------------------------
int sortEmployees(Employee *list, int len, int order) {
	int retorno = -1;
	int i, j;
	Employee buffer;

	if (list != NULL && len > 0) {
		for (i = 0; i < len - 1; i++) {
			for (j = i + 1; j < len; j++) {
				if (strcmp(list[i].lastName, list[j].lastName) > 0
						&& order == 1) { //Ordena por apellido de manera ascendente (order=1)
					buffer = list[i];
					list[i] = list[j];
					list[j] = buffer;
				} else if (strcmp(list[i].lastName, list[j].lastName) < 0
						&& order == 0) { //Ordena por apellido de manera descendente (order=0)
					buffer = list[i];
					list[i] = list[j];
					list[j] = buffer;
				} else if (strcmp(list[i].lastName, list[j].lastName) == 0) { //Mismo apellido entonces ordena por sector
					if (list[i].sector > list[j].sector) {
						buffer = list[i];
						list[i] = list[j];
						list[j] = buffer;
					}
				}
			}
		}
	}

	return retorno;
}
//----------------------------------------------------------------------------------------------------------
int printEmployees(Employee *list, int len) {
	int retorno = -1;
	int i;

	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == 1) {
				continue;
			} else {
				printf(
						"\nPosicion: %d\nId: %d\nNombre: %s\nApellido: %s\nSalario: %.2f\nSector: %d\n",
						i, list[i].id, list[i].name, list[i].lastName,
						list[i].salary, list[i].sector);
			}
		}
		retorno = 0;
	}

	return retorno;
}
//----------------------------------------------------------------------------------------------------------
int calcularPromedioSalario(Employee *list, int len, float *pResultado,
		float *pSuma) {
	int retorno = -1;
	int i;
	float suma = 0;
	int contador = 0;

	for (i = 0; i < len; i++) {
		if (list[i].isEmpty == 0) {
			suma += list[i].salary;
			contador++;
		}
	}
	retorno = 0;
	*pSuma = suma;
	*pResultado = suma / contador;

	return retorno;
}
//----------------------------------------------------------------------------------------------------------
int arrayVacio(Employee *list, int len) {
	int retorno = 1;
	int i;

	if (list != NULL && len >= 0) {
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == 0) {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
//----------------------------------------------------------------------------------------------------------
int salarioMayorPromedio(Employee *list, int len, float promedio) {
	int contador = 0;
	int i;

	if (list != NULL && len >= 0) {
		for (i = 0; i < len; i++) {
			if (list[i].salary > promedio) {
				contador++;
			}
		}
	}

	return contador;
}
