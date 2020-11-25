#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include <string.h>

Employee* employee_new() {
	return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char *idStr, char *nombreStr,
		char *horasTrabajadasStr, char *sueldoStr) {
	Employee *punteroAlumno = NULL;
	Employee *AuxpunteroAlumno;

	int id;
	int sueldo;
	int horasTrabajas;

	punteroAlumno = employee_new();

	if (punteroAlumno != NULL) {
		id = atoi(idStr);   //CONVIERTO LAS CADENAS A ENTEROS
		horasTrabajas = atoi(horasTrabajadasStr);
		sueldo = atoi(sueldoStr);

		if (!employee_setId(punteroAlumno, id)
				&& !employee_setNombre(punteroAlumno, nombreStr)
				&& !employee_setHorasTrabajadas(punteroAlumno, horasTrabajas)
				&& !employee_setSueldo(punteroAlumno, sueldo)) {
			AuxpunteroAlumno = punteroAlumno;
		}

	}
	return AuxpunteroAlumno;

}

int employee_alta(LinkedList *this) {
	Employee *listEmployee;
	int retorno = -1;
	char auxNombre[1000];
	char auxId[1000];
	char auxSueldo[1000];
	char auxHorasTrabajas[1000];
	int id;
	int sueldo;
	int horasTra;
	if (this != NULL) {
		listEmployee = employee_new();

		if (listEmployee != NULL) {
			printf("ALTA EMPLEADO\n");
			printf("INGRESE LOS DATOS DEL EMPLEADO\n");

			printf("ingrese ID del emppleado\n");
			scanf("%d", &id);

			printf("ingrese nombre\n");
			fflush(stdin);
			gets(auxNombre);

			printf("ingrese horas trabajas\n");
			scanf("%d", &horasTra);

			printf("ingrese sueldo\n");
			scanf("%d", &sueldo);

			sprintf(auxId, "%d", id);
			sprintf(auxHorasTrabajas, "%d", horasTra);
			sprintf(auxSueldo, "%d", sueldo);

			listEmployee = employee_newParametros(auxId, auxNombre,
					auxHorasTrabajas, auxSueldo);

			ll_add(this, listEmployee);

			retorno = 0;

		}

	}
	return retorno;
}

int employee_imprimir(LinkedList *this) {
	int retorno = -1;

	Employee *listEmployee;
	int i;
	int id;
	char nombre[1000];
	int sueldo;
	int horasTrabajas;
	int cantidad;

	cantidad = ll_len(this);

	if (this != NULL) {
		for (i = 0; i < cantidad; i++) {
			listEmployee = ll_get(this, i);
			if (listEmployee != NULL) {
				employee_getId(listEmployee, &id);
				employee_getNombre(listEmployee, nombre);
				employee_getHorasTrabajadas(listEmployee, &horasTrabajas);
				employee_getSueldo(listEmployee, &sueldo);

				printf(
						"\nID: %d   Nombre: %s   Horas Que Trabaja: %d   Sueldo: %d \n",
						id, nombre, horasTrabajas, sueldo);
				printf(
						"-----------------------------------------------------------------------------");

				retorno = 0;
			}

		}

	}

	return retorno;
}

void employee_delete(Employee *listEmployee) {
	if (listEmployee != NULL) {
		free(listEmployee);
	}
}

int employee_setNombre(Employee *this, char *nombre) {
	int retorno = -1;

	if (this != NULL && nombre != NULL) {
		strncpy(this->nombre, nombre, 128);
		retorno = 0;
	}

	return retorno;
}

int employee_getNombre(Employee *this, char *nombre) {
	int retorno = -1;

	if (this != NULL && nombre != NULL) {
		strncpy(nombre, this->nombre, 128);
		retorno = 0;
	}

	return retorno;
}

int employee_setSueldo(Employee *this, int sueldo) {
	int retorno = -1;

	if (this != NULL && sueldo >= 0) {
		this->sueldo = sueldo;
		retorno = 0;
	}

	return retorno;
}

int employee_getSueldo(Employee *this, int *sueldo) {
	int retorno = -1;

	if (this != NULL && sueldo >= 0) {
		*sueldo = this->sueldo;
		retorno = 0;
	}

	return retorno;
}

int employee_setId(Employee *this, int id) {
	int retorno = -1;

	if (this != NULL && id >= 0) {
		this->id = id;
		retorno = 0;
	}

	return retorno;
}
/** \brief
 *
 * \param this Employee*
 * \param id int*
 * \return int
 *
 */
int employee_getId(Employee *this, int *id) {
	int retorno = -1;

	if (this != NULL && id >= 0) {
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas) {
	int retorno = -1;

	if (this != NULL && horasTrabajadas >= 0) {
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}

	return retorno;
}

int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas) {
	int retorno = -1;

	if (this != NULL && horasTrabajadas >= 0) {
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}

	return retorno;
}

int employee_CompareByName(void *e1, void *e2) {
	Employee *auxE1;
	Employee *auxE2;

	if (e1 != NULL && e2 != NULL) {
		auxE1 = (Employee*) e1;
		auxE2 = (Employee*) e2;
	}

	return strcmp(auxE1->nombre, auxE2->nombre);
}

int employee_CompareById(void *e1, void *e2) {
	Employee *auxEmpleado1;
	Employee *auxEmpleado2;
	int retorno;

	if (e1 != NULL && e2 != NULL) {
		auxEmpleado1 = (Employee*) e1;
		auxEmpleado2 = (Employee*) e2;

		if (auxEmpleado1->id > auxEmpleado2->id) {
			retorno = 1;

		}

		if (auxEmpleado1->id < auxEmpleado2->id) {
			retorno = -1;
		}

		if (auxEmpleado1->id == auxEmpleado2->id) {
			retorno = 0;
		}

	}

	return retorno;
}

int employee_guardarArchivoTxt(char *direccionArchivo, LinkedList *this) {
	int i;
	int cantidad;
	int retorno = -1;
	FILE *pFile;
	Employee *auxEmployee;
	int auxId;
	int auxHorasTrabajas;
	int auxSueldo;
	char auxNombre[128];

	cantidad = ll_len(this);
	pFile = fopen(direccionArchivo, "wb");

	if (pFile != NULL && direccionArchivo != NULL) {

		for (i = 0; i < cantidad; i++) {
			auxEmployee = ll_get(this, i);
			if (auxEmployee != NULL) {
				if (!employee_getId(auxEmployee, &auxId)
						&& !employee_getNombre(auxEmployee, auxNombre)
						&& !employee_getHorasTrabajadas(auxEmployee,
								&auxHorasTrabajas)
						&& !employee_getSueldo(auxEmployee, &auxSueldo)) {
					fprintf(pFile, "%d," "%s," "%d," "%d, \n", auxId, auxNombre,
							auxHorasTrabajas, auxSueldo);
				}
			}
		}

		retorno = 1;
		fclose(pFile);
	}
	return retorno;

}

int employee_guardarArchivoBinary(char *direccionArchivo, LinkedList *this) {
	int i;
	int cantidad;
	int retorno = -1;
	FILE *pFile;
	Employee *auxEmployee;
	int auxId;
	int auxHorasTrabajas;
	int auxSueldo;
	char auxNombre[128];

	cantidad = ll_len(this);
	pFile = fopen(direccionArchivo, "wb");

	if (pFile != NULL && direccionArchivo != NULL) {

		for (i = 0; i < cantidad; i++) {
			auxEmployee = ll_get(this, i);
			if (auxEmployee != NULL) {
				if (!employee_getId(auxEmployee, &auxId)
						&& !employee_getNombre(auxEmployee, auxNombre)
						&& !employee_getHorasTrabajadas(auxEmployee,
								&auxHorasTrabajas)
						&& !employee_getSueldo(auxEmployee, &auxSueldo)) {
					fwrite(auxEmployee, sizeof(Employee), 1, pFile);
				}
			}
		}

		retorno = 1;
		fclose(pFile);
	}
	return retorno;

}

int employee_modificarEmpleado(LinkedList *this) {
	Employee *auxEmployee;
	int i;
	int cantidad;
	int opcion;
	int auxId;
	int idElimar;
	int retorno = -1;
	int nuevoSueldo;
	int nuevohoras;
	char nuevoNombre[50];
	//int opcionModificar;
	//char seguir= 's';

	//employee_imprimir(this);

	printf("\ningrese id del empleado a modificar\n");
	scanf("%d", &auxId);

	if (this != NULL) {
		cantidad = ll_len(this);
		for (i = 0; i < cantidad; i++) {
			auxEmployee = ll_get(this, i);
			employee_getId(auxEmployee, &idElimar);
			if (auxId == idElimar) {
				printf(
						"\n\nID: %d  Nombre: %s  horas que trabaja: %d  Sueldo: %d",
						auxEmployee->id, auxEmployee->nombre,
						auxEmployee->horasTrabajadas, auxEmployee->sueldo);
				printf("\n\nDesea mofiicar el registro? 1= SI -- 2= NO");
				scanf("%d", &opcion);

				if (opcion == 1) {
					printf("nuevo Nombre\n");
					fflush(stdin);
					scanf("%s", nuevoNombre);
					employee_setNombre(auxEmployee, nuevoNombre);

					printf("ingrese horas nuevas\n");
					scanf("%d", &nuevohoras);
					employee_setHorasTrabajadas(auxEmployee, nuevohoras);

					printf("ingrese sueldo nuevo\n");
					scanf("%d", &nuevoSueldo);
					employee_setSueldo(auxEmployee, nuevoSueldo);

					printf("modificacion completa\n");

					retorno = 1;
				} else {
					printf("\nmodificacion cancelada");

				}
			}
		}
	}
	return retorno;
}

int employee_elimiarEmpleado(LinkedList *this) {
	Employee *auxEmployee;
	int i;
	int cantidad;
	int opcion;
	int auxId;
	int idElimar;
	int retorno = -1;

	employee_imprimir(this);

	printf("\nIngrese id del empleado a eliminar\n");
	scanf("%d", &auxId);

	if (this != NULL) {
		cantidad = ll_len(this);
		for (i = 0; i < cantidad; i++) {
			auxEmployee = ll_get(this, i);
			employee_getId(auxEmployee, &idElimar);
			if (auxId == idElimar) {
				printf("\n\nID: %d  Nombre: %s  ", auxEmployee->id,
						auxEmployee->nombre);
				printf("\n\nDesea eliminar el registro? 1= SI -- 2= NO");
				scanf("%d", &opcion);

				if (opcion == 1) {
					ll_remove(this, i);
					free(auxEmployee);
					printf("Se han dado de baja los datos");
					retorno = 1;
				} else {
					printf("\nBaja cancelada");

				}
			}
		}
	}
	return retorno;
}
