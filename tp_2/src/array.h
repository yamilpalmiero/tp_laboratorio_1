#ifndef ARRAY_H_
#define ARRAY_H_

#endif /* ARRAY_H_ */

/*
 * brief Recibe un array de enteros y lo inicializa en cero
 * param Array de enteros
 * param Cantidad de elementos del array
 * return Retorna 0 si funciono OK y -1 si no funcinono correctamente
 */
int utn_iniArrayEnteros(int array[], int cantidad);

/*
 * brief Recibe un array de flotantes y lo inicializa en cero
 * param Array de flotantes
 * param Cantidad de elementos del array
 * return Retorna 0 si funciono OK y -1 si no funcinono correctamente
 */
void utn_iniArrayFlotantes(float array[], int cantidad);

/*
 * brief Recibe un array de caracteres y lo inicializa en blanco
 * param Array de caracteres
 * param Cantidad de elementos
 */
void utn_iniArrayCaracteres(char array[], int cantidad);

/*
 * brief Imprime un array de enteros
 * param Array de enteros
 * param Array de flotantes
 * param Cantidad de elementos de los array
 */
void utn_imprimirElemento(int arrayInt[], float arrayFloat[], int cantidad);

/*
 * brief Imprime un array de enteros
 * param Array de enteros
 * param Cantidad de elementos
 */
void utn_imprimirElementos(float array[], int cantidad);

/*
 * brief Recibe un array de flotantes y devuelve el promedio por puntero
 * param Array de numeros flotantes
 * param Cantidad de elementos
 * param Posicion de memoria de la variable donde se guardara el resultado del promedio
 */
void utn_calcularPromedio(float arrayFloat[], int cantidad, float *pResultado);

/*
 * brief Recibe arrays para ser cargado con sus valores de manera aleatoria
 * param Array de enteros
 * param Array de flotantes
 * param Cantidad de elementos de los array paralelos
 */
void utn_cargarArrays(int arrayInt[], float arrayFloat[], int cantidad);

/*
 * brief Recibe dos array y los ordena por enteros
 * param Array de enteros
 * param Array de flotantes
 */
void utn_ordenarArraysPorEntero(int arrayInt[], float arrayFloat[],
		int cantidad);
