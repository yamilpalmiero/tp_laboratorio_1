#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int controller_loadFromText(char *path, LinkedList *pArrayListEmployee) {
	int retorno = -1;
	FILE *pFile;
	pFile = fopen(path, "r");

	if (pFile != NULL
			&& parser_EmployeeFromText(pFile, pArrayListEmployee) == 1) {
		printf("\nDatos cargados.");
		system("pause");
		retorno = 1;
	} else {
		printf("\nError al cargar los datos.");
		system("pause");
	}

	fclose(pFile);

	return retorno;
}

/** \brief
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee) {
	int retorno = -1;
	FILE *pFile;

	pFile = fopen(path, "rb");

	if (parser_EmployeeFromBinary(pFile, pArrayListEmployee) == 1) {
		printf("datos caragados\n");
		retorno = 1;
	} else {
		printf("algo anda mal\n");
	}
	fclose(pFile);
	return retorno;
}

int controller_addEmployee(LinkedList *pArrayListEmployee) {
	int retorno = -1;

	if (!employee_alta(pArrayListEmployee)) {
		printf("ALTA CORRECTA\n");
		retorno = 1;
		system("pause");
	} else {
		printf("ANDA MAL\n");
		retorno = -1;
	}

	return retorno;
}

int controller_editEmployee(LinkedList *pArrayListEmployee) {
	int retorno = -1;

	if (pArrayListEmployee != NULL) {
		if (employee_modificarEmpleado(pArrayListEmployee) == 1) {
			retorno = 1;
		}
	}

	return retorno;
}

int controller_removeEmployee(LinkedList *pArrayListEmployee) {
	int retorno = -1;

	if (employee_elimiarEmpleado(pArrayListEmployee) == 1) {
		retorno = 1;
	}
	return retorno;
}

int controller_ListEmployee(LinkedList *pArrayListEmployee) {
	int retorno = -1;

	if (!employee_imprimir(pArrayListEmployee)) {
		printf("\nlista de Empleados\n");
	} else {
		printf("ERROR");
	}

	return retorno;
}

int controller_sortEmployee(LinkedList *pArrayListEmployee) {
	int retorno = -1;
	int orden;
	int menu;

	if (pArrayListEmployee != NULL) {
		printf("seleccinar orden !! , 1 = ascendente -- 0= descendente\n");
		scanf("%d", &orden);

		printf("elija como ordenar \n");
		printf("1.por nombre\n");
		printf("2.por id\n");
		scanf("%d", &menu);

		switch (menu) {
		case 1:
			ll_sort(pArrayListEmployee, employee_CompareByName, orden);
			printf("ordenamiento con exito\n");
			break;
		case 2:
			ll_sort(pArrayListEmployee, employee_CompareById, orden);
			printf("ordenamiento exitoso\n");
			break;
		}
		retorno = 1;
	}

	return retorno;
}

int controller_saveAsText(char *path, LinkedList *pArrayListEmployee) {
	int retorno = -1;

	if (employee_guardarArchivoTxt(path, pArrayListEmployee) == 1) {
		printf("datos guardadosOK\n");
		retorno = 0;
	} else {
		printf("ANDA MAL\n");
	}

	return retorno;
}

int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee) {
	int retorno = -1;
	if (employee_guardarArchivoBinary(path, pArrayListEmployee) == 1) {
		printf("guardado en binario oK\n");
		retorno = 1;
	} else {
		printf("ERROR");
	}

	return retorno;
}
