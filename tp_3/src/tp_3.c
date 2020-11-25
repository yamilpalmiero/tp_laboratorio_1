#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

int main() {
	char seguir = 's';
	LinkedList *listaEmpleados = ll_newLinkedList();

	do {
		switch (opcionesMenu()) {
		case 1:
			controller_loadFromText("data.csv", listaEmpleados);
			break;
		case 2:
			controller_loadFromBinary("data.bin", listaEmpleados);
			system("pause");
			break;
		case 3:
			controller_addEmployee(listaEmpleados);
			break;
		case 4:
			controller_editEmployee(listaEmpleados);
			system("pause");
			break;
		case 5:
			controller_removeEmployee(listaEmpleados);
			system("pause");
			break;
		case 6:
			controller_ListEmployee(listaEmpleados);
			system("pause");
			break;
		case 7:
			controller_sortEmployee(listaEmpleados);
			system("pause");
			break;
		case 8:
			controller_saveAsText("data.csv", listaEmpleados);
			system("pause");
			break;
		case 9:
			controller_saveAsBinary("data.bin", listaEmpleados);
			system("pause");
			break;
		case 10:
			printf("Salir");
			system("pause");
			seguir = 'n';
			break;

		}

	} while (seguir == 's');

	return 0;
}
