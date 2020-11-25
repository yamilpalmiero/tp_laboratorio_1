#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee) {
	char idAux[2000];
	char nombreAux[2000];
	char horasAux[2000];
	char sueldoAux[2000];
	Employee *employeeAux;
	int cant;
	int retorno = -1;

	if (pFile != NULL) {

		while (!feof(pFile)) {
			cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idAux, nombreAux,
					horasAux, sueldoAux);

			if (cant == 4) {
				employeeAux = employee_newParametros(idAux, nombreAux, horasAux,
						sueldoAux);
				if (employeeAux != NULL) {
					ll_add(pArrayListEmployee, employeeAux);
					retorno = 1;
				}
			}
		}
	}

	return retorno;

}

int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee) {
	char id[2000];
	char nombre[2000];
	char horasTrabajadas[2000];
	char sueldo[2000];

	Employee *newEmpleado;
	Employee auxEmpleado;
	int cant;
	int retorno = -1;

	if (pFile != NULL) {
		while (!feof(pFile)) {
			newEmpleado = employee_new();
			cant = fread(newEmpleado, sizeof(Employee), 1, pFile);
			if (cant == 1) {
				if (newEmpleado != NULL) {
					ll_add(pArrayListEmployee, newEmpleado);
					retorno = 1;
				}
			}
		}
	}

	return retorno;

}
