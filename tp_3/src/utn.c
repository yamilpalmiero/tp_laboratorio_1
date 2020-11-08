#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "utn.h"
//---------------------------------------------------------------------------------------------------------------------------------------
int utn_getEntero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {

	int retorno = -1;
	int bufferEntero;

	do {

		printf("%s", mensaje);

		if (utn_getInt(&bufferEntero) == 0 && bufferEntero >= minimo
				&& bufferEntero <= maximo) {
			retorno = 0;
			*pResultado = bufferEntero; //VARIABLE DEL MAIN
			break;
		}

		printf("%s", mensajeError);
		reintentos--;

	} while (reintentos <= 0);

	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int utn_getFlotante(float *pResultado, char *mensaje, char *mensajeError,
		float minimo, float maximo, int reintentos) {

	int retorno = -1;
	float bufferFlotante;

	do {

		printf("%s", mensaje);

		if (utn_getFloat(&bufferFlotante) == 0 && bufferFlotante >= minimo
				&& bufferFlotante <= maximo) {
			retorno = 0;
			*pResultado = bufferFlotante;
			break;
		}

		printf("%s", mensajeError);
		reintentos--;

	} while (reintentos <= 0);

	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int utn_getCadena(char *pCadena, char *mensaje, char *mensajeError, int minimo,
		int maximo, int reintentos) {

	int retorno = -1;
	char bufferCadena[101];

	do {

		printf("%s", mensaje);
		fflush(stdin);
		gets(bufferCadena);

		if (strlen(bufferCadena) >= minimo && strlen(bufferCadena) < maximo) { //No puede ser <= maximo por el '\0'
			strcpy(pCadena, bufferCadena); //pResultado no hace falta ponerle el * porque como es cadena ya es puntero
			retorno = 0;
			break;
		}

		printf("%s", mensajeError);
		reintentos--;

	} while (reintentos <= 0);

	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
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
//---------------------------------------------------------------------------------------------------------------------------------------
int utn_esNumericaEnteros(char *cadena, int limite) {
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
//---------------------------------------------------------------------------------------------------------------------------------------
int utn_getInt(int *pResultado) {
	int retorno = -1;
	char bufferString[50];

	if (pResultado != NULL
			&& utn_myGets(bufferString, sizeof(bufferString)) == 0
			&& utn_esNumericaEnteros(bufferString, strlen(bufferString))) {
		retorno = 0;
		*pResultado = atoi(bufferString);
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int utn_esNumericaFlotantes(char *cadena, int limite) {
	int retorno = 1; //VERDADERO
	int i;

	for (i = 0; i < limite && cadena[i] != '\0'; i++) {
		if (i == 0 && (cadena[i] == '+' || cadena[i] == '-')) {
			continue; //VUELVE A ITERAR EN FOR osea se saltea el prox if
		}
		if ((cadena[i] < '0' || cadena[i] > '9') && cadena[i] != '.') {
			retorno = 0; //FALSO osea que hay un valor que no es un numero
			break; //SALE DEL FOR
		}
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int utn_getFloat(float *pResultado) {
	int retorno = -1;
	char bufferString[50];

	if (pResultado != NULL
			&& utn_myGets(bufferString, sizeof(bufferString)) == 0
			&& utn_esNumericaFlotantes(bufferString, strlen(bufferString))) {
		retorno = 0;
		*pResultado = atof(bufferString);
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int getString(char *msg, char *msgError, int min, int max, int reintentos,
		char *resultado) {
	int retorno = -1;
	char bufferStr[max + 10];

	if (msg != NULL && msgError != NULL
			&& min <= max&& reintentos>=0 && resultado!=NULL) {
		do {
			printf("%s", msg);
			fflush(stdin);
			fgets(bufferStr, sizeof(bufferStr), stdin);
			bufferStr[strlen(bufferStr) - 1] = '\0';

			if (strlen(bufferStr) >= min && strlen(bufferStr) < max) // tamaño (max) =cantidad de elementos (strlen) + 1(\0)
					{
				strncpy(resultado, bufferStr, max);
				retorno = 0;
				break;
			}
			printf("%s 1", msgError);
			(reintentos)--;
		} while ((reintentos) >= 0);
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int utn_getName(char *msg, char *msgError, int min, int max, int reintentos,
		char *resultado) {
	int retorno = -1;
	char bufferStr[max];

	if (msg != NULL && msgError != NULL
			&& min <= max&& reintentos>=0 && resultado!=NULL) {
		do {
			if (!getString(msg, msgError, min, max, reintentos, bufferStr)) //==0
					{
				if (isValidName(bufferStr) == 1) {
					strncpy(resultado, bufferStr, max);
					retorno = 0;
					break;
				} else {
					printf("%s 2", msgError);
					reintentos--;
				}
			}
		} while (reintentos >= 0);
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int isValidName(char *stringRecibido) //si fuera un numero podrìa necesitar parametros para validar max y min
{
	int retorno = 1; // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
	int i;
	for (i = 0; stringRecibido[i] != '\0'; i++) {
		//printf("%d",i);
		if ((stringRecibido[i] < 'A' || stringRecibido[i] > 'Z')
				&& (stringRecibido[i] < 'a' || stringRecibido[i] > 'z')
				&& stringRecibido[i] != ' ') {
			retorno = 0;
			break;
		}
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int utn_getUnsignedInt(char *msg, char *msgError, int min, int max,
		int reintentos, int *input) {
	int retorno = -1;
	char bufferStr[max];

	if (msg != NULL && msgError != NULL
			&& min < max&& reintentos>=0 && input!=NULL) {
		do {
			if (!getString(msg, msgError, min, max, reintentos, bufferStr)) //==0 sin errores !0
					{
				if (isValidNumber(bufferStr) == 1) {
					*input = atoi(bufferStr); // unsigned long int strtoul(const char *str, char **end, int base)?
					retorno = 0;
					break;
				} else {
					printf("%s", msgError);
					reintentos--;
				}
			}
		} while (reintentos >= 0);
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int isValidNumber(char *stringRecibido) {
	int retorno = 1;
	int i;
	for (i = 0; stringRecibido[i] != '\0'; i++) {
		if (stringRecibido[i] < '0' || stringRecibido[i] > '9') {
			retorno = 0;
			break;
		}
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int utn_getSignedInt(char *msg, char *msgError, int minSize, int maxSize,
		int min, int max, int reintentos, int *input) {
	int retorno = -1;
	char bufferStr[maxSize];

	if (msg != NULL && msgError != NULL
			&& minSize < maxSize&& min<max && reintentos>=0 && input!=NULL) {
		do {
			if (!getString(msg, msgError, minSize, maxSize, reintentos,
					bufferStr)) //==0 sin errores !0
					{
				if (isValidSignedNumber(bufferStr) == 1) {
					*input = atoi(bufferStr); // atoi array to int
					retorno = 0;
					break;
				} else {
					printf("%s 2", msgError);
					reintentos--;
				}
			}
		} while (reintentos >= 0);
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int isValidSignedNumber(char *stringRecibido) {
	int retorno = 1; // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
	int i;
	for (i = 0; stringRecibido[i] != '\0'; i++) {
		if ((stringRecibido[i] < '0' || stringRecibido[i] > '9')
				&& (stringRecibido[0] != '+' && stringRecibido[0] != '-')) {
			retorno = 0;
			break;
		}
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int utn_getTelefono(char *msg, char *msgError, int minSize, int maxSize,
		int min, int max, int reintentos, char *input) {
	int retorno = -1;
	char bufferStr[maxSize];

	if (msg != NULL && msgError != NULL
			&& minSize < maxSize&& min<max && reintentos>=0 && input!=NULL) {
		do {
			if (!getString(msg, msgError, minSize, maxSize, reintentos,
					bufferStr)) //==0 sin errores !0
					{
				if (isValidTelephone(bufferStr) == 1) {
					strncpy(input, bufferStr, maxSize);
					retorno = 0;
					break;
				} else {
					printf("%s 2", msgError);
					reintentos--;
				}
			}
		} while (reintentos >= 0);
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int isValidTelephone(char *stringRecibido) {
	int retorno = 1; // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
	int i;
	for (i = 0; stringRecibido[i] != '\0'; i++) {
		if ((stringRecibido[i] < '0' || stringRecibido[i] > '9')
				&& (stringRecibido[i] != '-' || stringRecibido[i] != ' ')) {
			retorno = 0;
			break;
		}
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int utn_getDNI(char *msg, char *msgError, int minSize, int maxSize,
		int reintentos, char *input) {
	maxSize = 11; //con puntos
	minSize = 8;  // sin puntos
	int retorno = -1;
	char bufferStr[maxSize];

	if (msg != NULL && msgError != NULL
			&& minSize < maxSize&& reintentos>=0 && input!=NULL) {
		do {
			if (!getString(msg, msgError, minSize, maxSize, reintentos,
					bufferStr)) //==0 sin errores !0
					{
				if (isValidDNI(bufferStr) == 1) {
					strncpy(input, bufferStr, maxSize);
					retorno = 0;
					break;
				} else {
					printf("%s 2", msgError);
					reintentos--;
				}
			}
		} while (reintentos >= 0);
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int isValidDNI(char *stringRecibido) {
	int retorno = 1; // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
	int i;
	for (i = 0; stringRecibido[i] != '\0'; i++) {
		if ((stringRecibido[i] < '0' || stringRecibido[i] > '9')
				&& (stringRecibido[i] != '.')) {
			retorno = 0;
			break;
		}
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int utn_getCUIT(char *msg, char *msgError, int reintentos, char *input) {
	int maxSize = 14; //con guiones 13 elementos
	int minSize = 11;  // sin puntos
	int retorno = -1;
	char bufferStr[maxSize];

	if (msg != NULL && msgError != NULL
			&& minSize < maxSize&& reintentos>=0 && input!=NULL) {
		do {
			if (!getString(msg, msgError, minSize, maxSize, reintentos,
					bufferStr)) //==0 sin errores !0
					{
				if (isValidCUIT(bufferStr) == 1) {
					strncpy(input, bufferStr, maxSize);
					retorno = 0;
					break;
				} else {
					printf("%s 2", msgError);
					reintentos--;
				}
			}
		} while (reintentos >= 0);
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int isValidCUIT(char *stringRecibido) {
	int retorno = 1; // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
	int i;
	int j;
	char buffer[14];
	strncpy(buffer, stringRecibido, 14);

	for (i = 0; buffer[i] != '\0'; i++) {
		if ((buffer[i] < '0' || buffer[i] > '9') && (buffer[i] != '-')) // chequeo que solo sean numeros o -
				{
			retorno = 0;
			break;
		}

		if (buffer[i] == '-')  //elimino los -
				{
			for (j = i; buffer[j] != '\0'; j++) {
				strncpy(&buffer[j], &buffer[j + 1], 1);
			}
		}
	}

	int digitos[10] = { 2, 3, 4, 5, 6, 7, 2, 3, 4, 5 };
	int acumulado = 0;
	int verificador;

	for (i = 0; i < strlen(buffer - 1); i++) {
		acumulado += buffer[i] * digitos[i];
	}

	verificador = 11 - (acumulado % 11);
	if (verificador == 11) {
		verificador = 0;
	}

	if (buffer[11] != verificador) {
		retorno = 0;
	}

	//if(stringRecibido[2]!='-' || stringRecibido[11]!='-' || stringRecibido[0]!='2' || stringRecibido[1]!='0' || stringRecibido[1]!='3' || stringRecibido[1]!='4' || stringRecibido[1]!='7')
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int utn_getEmail(char *msg, char *msgError, int minSize, int maxSize,
		int reintentos, char *input) {
	int retorno = -1;
	char bufferStr[maxSize];

	if (msg != NULL && msgError != NULL
			&& minSize < maxSize&& reintentos>=0 && input!=NULL) {
		do {
			if (!getString(msg, msgError, minSize, maxSize, reintentos,
					bufferStr)) //==0 sin errores !0
					{
				if (isValidEmail(bufferStr) == 1) {
					strncpy(input, bufferStr, maxSize);
					retorno = 0;
					break;
				} else {
					printf("%s 2", msgError);
					reintentos--;
				}
			}
		} while (reintentos >= 0);
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int isValidEmail(char *stringRecibido) {
	int retorno = 1; // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
	int i;
	for (i = 0; stringRecibido[i] != '\0'; i++) {
		if ((stringRecibido[i] < '-' && stringRecibido[i] != '+')
				|| (stringRecibido[i] > '9' && stringRecibido[i] < '@')
				|| (stringRecibido[i] > 'Z' && stringRecibido[i] != '_'
						&& stringRecibido[i] < 'a')
				|| stringRecibido[i] > 'z') {
			retorno = 0;
			break;
		}
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int utn_getTexto(char *msg, char *msgError, int minSize, int maxSize,
		int reintentos, char *input) {
	int retorno = -1;
	char bufferStr[maxSize];

	if (msg != NULL && msgError != NULL
			&& minSize < maxSize&& reintentos>=0 && input!=NULL) {
		do {
			if (!getString(msg, msgError, minSize, maxSize, reintentos,
					bufferStr)) //==0 sin errores !0
					{
				if (isValidTexto(bufferStr) == 1) {
					strncpy(input, bufferStr, maxSize);
					retorno = 0;
					break;
				} else {
					printf("%s 2", msgError);
					reintentos--;
				}
			}
		} while (reintentos >= 0);
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int isValidTexto(char *stringRecibido) {
	int retorno = 1; // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
	int i;
	for (i = 0; stringRecibido[i] != '\0'; i++) {
		if (stringRecibido[i] < ' ' || stringRecibido[i] > 'z') {
			retorno = 0;
			break;
		}
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int utn_getAlfanumerico(char *msg, char *msgError, int minSize, int maxSize,
		int reintentos, char *input) {
	int retorno = -1;
	char bufferStr[maxSize];

	if (msg != NULL && msgError != NULL
			&& minSize < maxSize&& reintentos>=0 && input!=NULL) {
		do {
			if (!getString(msg, msgError, minSize, maxSize, reintentos,
					bufferStr)) //==0 sin errores !0
					{
				if (isValidAlphanumeric(bufferStr) == 1) {
					strncpy(input, bufferStr, maxSize);
					retorno = 0;
					break;
				} else {
					printf("%s 2", msgError);
					reintentos--;
				}
			}
		} while (reintentos >= 0);
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int isValidAlphanumeric(char *stringRecibido) {
	int retorno = 1; // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
	int i;
	for (i = 0; stringRecibido[i] != '\0'; i++) {
		if (stringRecibido[i] < '0'
				|| (stringRecibido[i] > '9' && stringRecibido[i] < 'A')
				|| (stringRecibido[i] > 'Z' && stringRecibido[i] < 'a')
				|| stringRecibido[i] > 'z') {
			retorno = 0;
			break;
		}
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int utn_getChar(char *msg, char *msgError, int min, int max, int reintentos,
		char *resultado) {
	int retorno = -1;
	char bufferChar[256];

	if (msg != NULL && msgError != NULL
			&& min <= max&& reintentos>=0 && resultado!=NULL) {
		do {
			if (!getString(msg, msgError, 1, 3, reintentos, bufferChar)) //==0
					{
				if (isValidChar(bufferChar[0]) == 1) {
					//printf("OK");
					*resultado = bufferChar[0];
					retorno = 0;
					break;
				} else {
					printf("%s 2", msgError);
					reintentos--;
				}
			}
		} while (reintentos >= 0);
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int isValidChar(char charRecibido) {
	int retorno = 1; // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
	if (charRecibido < 'A' || (charRecibido > 'Z' && charRecibido < 'a')
			|| charRecibido > 'z')
		retorno = 0;
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int isLetter(char *pointerString) {
	int i = 0;
	while (pointerString[i] != '\0') {
		if ((pointerString[i] != ' ')
				&& (pointerString[i] < 'a' || pointerString[i] > 'z')
				&& (pointerString[i] < 'A' || pointerString[i] > 'Z')) {
			return 0;
		}
		i++;
	}
	return 1;
}
//---------------------------------------------------------------------------------------------------------------------------------------
