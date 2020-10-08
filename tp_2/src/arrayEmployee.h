#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct {
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
} Employee;

#endif /* ARRAYEMPLOYEES_H_ */

/** brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (1) if Ok
 *
 **/
int initEmployees(Employee *list, int len);

/*
 * brief Recorre el array de empleados y devuelve el primer lugar vacio que encuentra
 * param list Array de empleados
 * param len Longitud del array
 * param posicion Puntero al espacio de memoria donde se va a guardar la posicion libre que encontro
 * return Retorna 0 si encuentra un espacio libre y -1 si no
 */
int buscarLibre(Employee *list, int len, int *posicion);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
 free space] - (0) if Ok
 **/
int addEmployee(Employee *list, int len);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
 pointer received or employee not found]
 **/
int findEmployeeById(Employee *list, int len, int id, int *posicion);

/*
 * brief Busca un empleado por su id y modifica el campo requerido
 * param list Array de empleados
 * param len Tamaño del array
 * return Retorna 0 si salio OK y -1 si no
 */
int modifyEmployee(Employee *list, int len);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
 find a employee] - (0) if Ok
 **/
int removeEmployee(Employee *list, int len);

/** \brief Sort the elements in the array of employees, the argument order
 indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee *list, int len, int order1, int order2);

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee *list, int length);

/*
 * brief Recibe el array de empleados y calcula el promedio de todos los salarios
 * param list Array de empleados
 * param len Longitud del array
 * param pResultado Puntero al espacio de memoria donde se va a guardar el promedio
 * param pSuma Puntero al espacio donde se guardara la suma
 * return Retorna 0 si OK y -1 si no
 */
int calcularPromedioSalario(Employee *list, int len, float *pResultado, float *pSuma);

/*
 * brief Recibe un array de estructuras y la recorre para fijarse si tiene al menos un dato cargado
 * param list Array de empleados
 * param len Longitud del array
 * return Retorna 1 si esta completamente vacio y 0 si tiene al menos un empleado guardado
 */
int arrayVacio(Employee *list, int len);

/*
 * brief Recibe un array de empleados y compara los salarios con el promedio
 * param list Array de empleados
 * param len Longitud del array
 * param promedio Promedio de los salarios
 * return Retorna la cantidad de salarios que superan al promedio
 */
int salarioMayorPromedio(Employee *list, int len, float promedio);
