#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee) {
	int retorno = -1;
	int flag = 0;
	char bufferId[50];
	char bufferName[128];
	char bufferHoras[50];
	char bufferSueldo[50];

	Employee *pEmployee;
	while (!feof(pFile)) {
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferName,
				bufferHoras, bufferSueldo);
		if (flag == 0) {
			flag++;
			continue;
		}
		pEmployee = employee_newParametros(bufferId, bufferName, bufferHoras,
				bufferSueldo);
		if (pEmployee != NULL) {
			ll_add(pArrayListEmployee, pEmployee);
			retorno = 0;
		}
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee) {

	return 1;
}
