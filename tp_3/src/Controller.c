#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#include "LinkedList.h"

int controller_findID(LinkedList *pArrayListEmployee, int id, int *index) {
	Employee *pAux;
	int length = ll_len(pArrayListEmployee);
	int i;
	int retorno = -1;
	int bufferInt;
	if (pArrayListEmployee != NULL) {
		for (i = 0; i < length; i++) {
			pAux = ll_get(pArrayListEmployee, i);
			employee_getId(pAux, &bufferInt);
			if (bufferInt == id) {
				retorno = 0;
				*index = i;
				break;
			}
		}
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------
int controller_arrayMaxID(LinkedList *pArrayListEmployee) {
	Employee *pAux;
	int length;
	int currentID;
	int maxID = -1;
	int i;
	if (pArrayListEmployee != NULL) {
		length = ll_len(pArrayListEmployee);
		for (i = 0; i < length; i++) {
			pAux = ll_get(pArrayListEmployee, i);
			employee_getId(pAux, &currentID);
			if (currentID > maxID) {
				maxID = currentID;
			}
		}
	}
	maxID += 1;
	return maxID;
}
//---------------------------------------------------------------------------------------------------------------------------
int controller_loadFromText(char *path, LinkedList *pArrayListEmployee) {
	int retorno = -1;
	FILE *pFile = NULL;
	if (path != NULL && pArrayListEmployee != NULL) {
		pFile = fopen(path, "r");
		if (pFile != NULL) {
			if (!parser_EmployeeFromText(pFile, pArrayListEmployee)) {
				printf("Carga exitosa.");
				retorno = 0;
			}
		}
		fclose(pFile);
	}

	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee) {
	int retorno = -1;
	FILE *pFile = NULL;
	Employee auxEmpleado;
	Employee *pEmpleado;
	int lastIndex = 0;
	if (path != NULL && pArrayListEmployee != NULL) {
		pFile = fopen(path, "r");
		if (pFile != NULL) {
			while (!feof(pFile)) {
				fread(&auxEmpleado, sizeof(Employee), 1, pFile);
				pEmpleado = employee_new();
				if (!employee_setId(pEmpleado, auxEmpleado.id)
						&& !employee_setNombre(pEmpleado, auxEmpleado.nombre)
						&& !employee_setHorasTrabajadas(pEmpleado,
								auxEmpleado.horasTrabajadas)
						&& !employee_setSueldo(pEmpleado, auxEmpleado.sueldo)) {
					ll_add(pArrayListEmployee, pEmpleado);
					lastIndex++;
				} else {
					employee_delete(pEmpleado);
				}
			}
			retorno = 0;
			ll_remove(pArrayListEmployee, lastIndex - 1); //el ultimo ingreso se repite, asi que se elimina
		}
		fclose(pFile);
	}
	if (!retorno) {
		printf("Archivo cargado exitosamente");
	}

	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------
int controller_addEmployee(LinkedList *pArrayListEmployee) {
	int retorno = -1;
	Employee *pAux = employee_new();
	char bufferChar[128];
	int bufferInt, bufferInt2;
	int id;
	if (pArrayListEmployee != NULL && pAux != NULL) {
		id = controller_arrayMaxID(pArrayListEmployee);
		if (id != -1) {
			if (utn_getName("\nIngrese el nombre: ",
					"\nError: Nombre invalido. Ingreselo nuevamente: ", 0, 128,
					2, bufferChar)) {
				return retorno;
			}
			if (utn_getEntero(&bufferInt, "\nIngrese las horas trabajadas: ",
					"\nError.", 0, 100000, 2)) {
				return retorno;
			}
			if (utn_getEntero(&bufferInt2, "\nIngrese el sueldo: ",
					"\nError: Sueldo invalido. Ingreselo nuevamente: ", 0,
					1000000, 2)) {
				return retorno;
			}
			employee_setId(pAux, id);
			employee_setNombre(pAux, bufferChar);
			employee_setHorasTrabajadas(pAux, bufferInt);
			employee_setSueldo(pAux, bufferInt2);
			ll_add(pArrayListEmployee, pAux);
			printf("\nEmpleado ingresado correctamente\n");
			retorno = 0;
		}
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------
int controller_editEmployee(LinkedList *pArrayListEmployee) {
	int retorno = -1;
	int bufferInt;
	int opcion;
	int index;
	char bufferChar[128];
	Employee *pAux = NULL;
	if (pArrayListEmployee != NULL) {
		if (!utn_getEntero(&bufferInt, "\nIngrese el ID: ",
				"\nError: ID invalida. Ingreselo nuevamente: ", 0, 1000000,
				2)) {
			if (!controller_findID(pArrayListEmployee, bufferInt, &index)) {
				pAux = ll_get(pArrayListEmployee, index);
				if (!utn_getEntero(&opcion,
						"\n1) Modificar Nombre\n2) Modificar Horas Trabajadas\n3) Modificar sueldo\n",
						"\nError: Opcion invalida. Ingresela nuevamente: ", 1,
						3, 2)) {
					switch (opcion) {
					case 1:
						if (!utn_getName("\nIngrese el nombre: ",
								"\nError: Nombre invalido. Ingreselo nuevamente: ",
								0, 128, 2, bufferChar)) {
							employee_setNombre(pAux, bufferChar);
							retorno = 0;
						}
						break;
					case 2:
						if (!utn_getEntero(&bufferInt,
								"\nIngrese las horas trabajadas: ", "\nError.",
								0, 100000, 2)) {
							employee_setHorasTrabajadas(pAux, bufferInt);
							retorno = 0;
						}
						break;
					case 3:
						if (!utn_getEntero(&bufferInt, "\nIngrese el sueldo: ",
								"\nError: Sueldo invalido. Ingreselo nuevamente: ",
								0, 1000000, 2)) {
							employee_setSueldo(pAux, bufferInt);
							retorno = 0;
						}
						break;
					default:
						printf("Opcion invalida.");
						break;
					}
				}
			} else {
				return retorno;
			}
		}
		if (retorno == 0) {
			printf("Empleado ingresado correctamente.");
		}
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------
int controller_removeEmployee(LinkedList *pArrayListEmployee) {
	int retorno = -1;
	int bufferInt;
	int index;
	Employee *pAux = NULL;
	if (pArrayListEmployee != NULL) {
		if (!utn_getEntero(&bufferInt, "\nIngrese el ID: ",
				"\nError: ID invalida. Ingreselo nuevamente: ", 0, 1000000,
				2)) {
			if (!controller_findID(pArrayListEmployee, bufferInt, &index)) {
				retorno = 0;
				//ll_remove(pArrayListEmployee, index);
				pAux = ll_pop(pArrayListEmployee, index);
				employee_delete(pAux);
				printf("Empleado eliminado correctamente.");
			}
		} else {
			return retorno;
		}
	}
	return retorno;

}
//---------------------------------------------------------------------------------------------------------------------------
int controller_ListEmployee(LinkedList *pArrayListEmployee) {
	int retorno = -1;
	Employee *pEmpleado;
	int auxID, auxSueldo, auxHoras;
	char bufferChar[128];
	int length;
	int i;
	if (pArrayListEmployee != NULL) {
		length = ll_len(pArrayListEmployee);
		for (i = 0; i < length; i++) {
			pEmpleado = ll_get(pArrayListEmployee, i);
			employee_getId(pEmpleado, &auxID);
			employee_getSueldo(pEmpleado, &auxSueldo);
			employee_getHorasTrabajadas(pEmpleado, &auxHoras);
			employee_getNombre(pEmpleado, bufferChar);
			printf("ID: %d - Nombre: %s - Horas Trabajadas: %d - Sueldo: $%d\n",
					auxID, bufferChar, auxHoras, auxSueldo);
			retorno = 0;
		}
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------
int controller_sortEmployee(LinkedList *pArrayListEmployee) {
	int retorno = -1;
	if (pArrayListEmployee != NULL) {
		ll_sort(pArrayListEmployee, employee_compararPorNombre, 0);
		retorno = 0;
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------
int controller_saveAsText(char *path, LinkedList *pArrayListEmployee) {
	int retorno = -1;
	int i;
	int id, sueldo, horas;
	char name[4096];
	int lengthArray;

	FILE *pFile = NULL;
	Employee *pAux = NULL;
	if (path != NULL && pArrayListEmployee != NULL) {
		pFile = fopen("data.csv", "w");
		if (pFile != NULL) {
			lengthArray = ll_len(pArrayListEmployee);
			for (i = 0; i < lengthArray; i++) {
				pAux = ll_get(pArrayListEmployee, i);
				if (pAux != NULL && !employee_getId(pAux, &id)
						&& !employee_getSueldo(pAux, &sueldo)
						&& !employee_getHorasTrabajadas(pAux, &horas)
						&& !employee_getNombre(pAux, name)) {
					fprintf(pFile, "%d,%s,%d,%d\n", id, name, horas, sueldo);
				} else {
					employee_delete(pAux);
				}
			}
			retorno = 0;
		}
		fclose(pFile);
	}
	if (!retorno) {
		printf("Archivo guardado exitosamente");
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------
int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee) {
	int retorno = -1;
	int i;
	Employee *pEmployee = NULL;
	FILE *pFile = NULL;
	if (path != NULL && pArrayListEmployee != NULL) {
		pFile = fopen(path, "w");
		if (pFile != NULL) {
			for (i = 0; i < ll_len(pArrayListEmployee); i++) {
				pEmployee = ll_get(pArrayListEmployee, i);
				//printf("%s\n",pEmployee->nombre);
				fwrite(pEmployee, sizeof(Employee), 1, pFile);
			}
		}
		retorno = 0;
		fclose(pFile);
	}
	if (!retorno) {
		printf("Archivo guardado exitosamente");
	}
	return retorno;
	return 1;
}
