#ifndef UTN_H_
#define UTN_H_

#endif /* UTN_H_ */

/*
 * brief Toma un numero entero por teclado y lo devuelve por puntero
 * param Direccion de memoria donde se guardara el entero
 * param Mensaje que pide el dato numerico
 * param Mensaje de error cuando lo que se ingresa por teclado no es lo solicitado
 * param Valor minimo posible
 * param Valor maximo posible
 * param Cantidad de intentos para ingresar el dato correctamente
 */
int utn_getEntero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos);

/*
 * brief Toma un numero con decimales por teclado y lo devuelve por puntero
 * param Direccion de memoria donde se guardara el flotante
 * param Mensaje que pide el dato numerico
 * param Mensaje de error cuando lo que se ingresa por teclado no es lo solicitado
 * param Valor minimo posible
 * param Valor maximo posible
 * param Cantidad de intentos para ingresar el dato correctamente
 */
float utn_getFlotante(float *pResultado, char *mensaje, char *mensajeError,
		float minimo, float maximo, int reintentos);

/*
 * brief Lee una cadena por teclado hasta que encuentra un '\n' o hasta que llega a longitud - 1
 * param cadena Puntero al espacio de memoria donde se va a copiar la cadena obtenida
 * param longitud Define el tamaño de la cadena
 * return Retorna 0 si se pudo obtener la cadena y -1 si no
 */
int utn_myGets(char *cadena, int longitud);

/*
 * brief Obtiene un numero entero
 * param pResultado Puntero al espacio de memoria donde se dejara el resultado
 * return Retorna 0 si se obtuvo el numero entero y -1 si no
 */
int utn_getInt(int *pResultado);

/*
 * brief Recibe una cadena y evalua si todos sus elementos son numeros
 * param cadena Puntero al espacio de memoria donde se va a guardar la cadena
 * param limite Define el tamaño de la cadena
 * return Retorna 1 si es verdad que todos sus elementos son numeros y 0 si no
 */
int utn_esNumerica(char *cadena, int limite);

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

/*
 * brief Imprime un menu de opciones por pantalla
 * return Retorna la opcion seleccionada por el usuario
 */
int menu();

/*
 * brief Imprime un menu de opciones por pantalla
 * return Retorna la opcion seleccionada por el usuario
 */
int submenuInformes();
