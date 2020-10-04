#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
//------------------------------------------------------------------------------------------------------------------------
int utn_getEntero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {

	int retorno = -1;
	int bufferEntero;

	do {

		printf("%s", mensaje);

		if (utn_getInt(&bufferEntero) == 0 && bufferEntero >= minimo
				&& bufferEntero <= maximo) {
			retorno = 0;
			*pResultado = bufferEntero;//VARIABLE DEL MAIN
			break;
		}

		printf("%s", mensajeError);
		reintentos--;

	} while (reintentos <= 0);

	return retorno;
}
//------------------------------------------------------------------------------------------------------------------------
int utn_getFlotante(float *pResultado, char *mensaje, char *mensajeError,
		float minimo, float maximo, int reintentos) {

	int retorno = -1;
	float bufferEntero;

	do {

		printf("%s", mensaje);

		if (utn_getInt(&bufferEntero) == 0 && bufferEntero >= minimo
				&& bufferEntero <= maximo) {
			retorno = 0;
			*pResultado = bufferEntero;
			break;
		}

		printf("%s", mensajeError);
		reintentos--;

	} while (reintentos <= 0);

	return retorno;
}
//------------------------------------------------------------------------------------------------------------------------
int utn_myGets(char *cadena, int longitud) {
	int retorno = -1;
	char bufferString[1000];

	if (cadena != NULL && longitud > 0) {
		fflush(stdin);
		if (fgets(bufferString, sizeof(bufferString), stdin) != NULL) { //fgets si sale mal devuelve NULL
			if (bufferString[strlen(bufferString) - 1] == '\n') {
				bufferString[strlen(bufferString) - 1] = '\0';
			}
			if (strlen(bufferString) <= longitud) {
				strncpy(cadena, bufferString, longitud);
				retorno = 0;
			}
		}

	}
	return retorno;
}
//------------------------------------------------------------------------------------------------------------------------
int utn_esNumerica(char *cadena, int limite) {
	int retorno = 1; //VERDADERO
	int i;

	for (i = 0; i < limite && cadena[i] != '\0'; i++) {
		if (i == 0 && (cadena[i] == '+' || cadena[i] == '-')) {
			continue; //VUELVE A ITERAR EN FOR osea se saltea el prox if
		}
		if (cadena[i] < '0' || cadena[i] > '9') {
			retorno = 0; //FALSO osea que hay un valor que no es un numero
			break; //SALE DEL FOR
		}
	}
	return retorno;
}
//------------------------------------------------------------------------------------------------------------------------
int utn_getInt(int *pResultado) {
	int retorno = -1;
	char bufferString[50];

	if (pResultado != NULL
			&& utn_myGets(bufferString, sizeof(bufferString)) == 0
			&& utn_esNumerica(bufferString)) {
		retorno = 0;
		*pResultado = atoi(bufferString);
	}
	return retorno;
}
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
void utn_imprimirElementos(int arrayInt[], float arrayFloat[], int elemento,
		int cantidad) {
	int i;
	for (i = 0; i < cantidad; i++) {
		utn_imprimirElemento(arrayInt, arrayFloat, elemento);
	}
}
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
int menu() {
	int opcion;

	system("cls");

	printf("Seleccioone una opcion:\n\n");
	printf("1- Alta alumno.\n");
	printf("2- Modificar empleado.\n");
	printf("3- Baja empleado.\n");
	printf("4- Informar.\n");
	printf("5- Salir.\n\n");
	scanf("%d", &opcion);

	return opcion;
}
//------------------------------------------------------------------------------------------------------------------------
int submenuInformes() {
	int opcion;

	system("cls");

	printf("Seleccioone una opcion:\n\n");
	printf("1- Listar por apellido y sector.\n");
	printf(
			"2- Total y promedio de salarios, y cuantos empleados superan el salario promedio.\n");
	printf("3- Salir.\n\n");
	scanf("%d", &opcion);

	return opcion;
}
//------------------------------------------------------------------------------------------------------------------------

