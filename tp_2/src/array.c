#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "array.h"
//------------------------------------------------------------------------------------------------------------------------
int utn_iniArrayEnteros(int array[], int cantidad) {
	int i;
	int retorno = -1;
	if (array != NULL && cantidad > 0) {
		for (i = 0; i < cantidad; i++) {
			array[i] = 0;
		}
		retorno = 0;
	}
	return retorno;
}
//------------------------------------------------------------------------------------------------------------------------
void utn_iniArrayFlotantes(float array[], int cantidad) {
	int i;
	for (i = 0; i < cantidad; i++) {
		array[i] = 0;
	}
}
//------------------------------------------------------------------------------------------------------------------------
void utn_iniArrayCaracteres(char array[], int cantidad) {
	int i;
	for (i = 0; i < cantidad; i++) {
		array[i] = ' ';
	}
}
//------------------------------------------------------------------------------------------------------------------------
void utn_imprimirElemento(int arrayInt[], float arrayFloat[], int elemento) {
	printf("\nElemento\tLegajo\tNombre\tEdad\tSueldo");
	printf("\n%d\t%d\t%d\t%.2f", elemento, elemento + 1, arrayInt[elemento],
			arrayFloat[elemento]);
}
//------------------------------------------------------------------------------------------------------------------------
/*void utn_imprimirElementos(int arrayInt[], float arrayFloat[], int elemento,
		int cantidad) {
	int i;
	for (i = 0; i < cantidad; i++) {
		utn_imprimirElemento(arrayInt, arrayFloat, elemento);
	}
}*/
//------------------------------------------------------------------------------------------------------------------------
void utn_calcularPromedio(float arrayFloat[], int cantidad, float *pResultado) {
	int i;
	float suma = 0;
	int contador = 0;

	for (i = 0; i < cantidad; i++) {
		if (arrayFloat[i] > 0) {
			suma = suma + arrayFloat[i];
			contador++;
		}
	}
	*pResultado = suma / contador;
}
//------------------------------------------------------------------------------------------------------------------------
void utn_cargarArrays(int arrayInt[], float arrayFloat[], int cantidad) {
	int posicion;

	printf("Ingrese posicion donde cargar los datos: ");
	scanf("%d", &posicion);
	printf("Edad: ");
	scanf("%d", &arrayInt[posicion]);
	printf("Sueldo: ");
	scanf("%f", &arrayFloat[posicion]);
}
//------------------------------------------------------------------------------------------------------------------------
void utn_ordenarArraysPorEntero(int arrayInt[], float arrayFloat[],
		int cantidad) {
	int i;
	int j;
	int auxInt = 0;
	int auxFloat = 0;

	for (i = 0; i < cantidad - 1; i++) {
		for (j = i + 1; j < cantidad; j++) {
			if (arrayInt[i] > arrayInt[j]) {

				auxInt = arrayInt[i];
				arrayInt[i] = arrayInt[j];
				arrayInt[j] = auxInt;

				auxFloat = arrayFloat[i];
				arrayFloat[i] = arrayFloat[j];
				arrayFloat[j] = auxFloat;
			}
		}
	}
}
//------------------------------------------------------------------------------------------------------------------------
