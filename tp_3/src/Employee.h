#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct {
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
} Employee;

/** \brief constructor que crea memoria dinamica
 *
 * \return Employee*
 *
 */
Employee* employee_new();

/** \brief constructor con parametros
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */
Employee* employee_newParametros(char *idStr, char *nombreStr,
		char *horasTrabajadasStr, char *sueldoStr);

/** \brief da de alta a un empleado
 *
 * \param this LinkedList*
 * \return int 1 ok -1 error
 *
 */
int employee_alta(LinkedList *this);

/** \brief ejecuta funcion free sobre el puntero dado
 *
 * \param listEmployee Employee*
 * \return void
 *
 */
void employee_delete(Employee *listEmployee);

/** \brief elimina un empleado de la lista
 *
 * \param this LinkedList*
 * \return int 1 ok -1 error
 *
 */
int employee_elimiarEmpleado(LinkedList *this);

/** \brief modifica empleado de la lista
 *
 * \param this LinkedList*
 * \return int 1 ok -1 error
 *
 */
int employee_modificarEmpleado(LinkedList *this);

/** \brief imprime la lista de empleados
 *
 * \param this LinkedList*
 * \return int 1 ok -1 error
 *
 */
int employee_imprimir(LinkedList *this);

/** \brief guarda la lista en un archivo texto
 *
 * \param direccionArchivo char*
 * \param this LinkedList*
 * \return int 1 ok -1 error
 *
 */
int employee_guardarArchivoTxt(char *direccionArchivo, LinkedList *this);

/** \brief guarda la lista en archivo binario
 *
 * \param direccionArchivo char*
 * \param this LinkedList*
 * \return int 1 ok -1 error
 *
 */
int employee_guardarArchivoBinary(char *direccionArchivo, LinkedList *this);

/** \brief setter de id empleado
 *
 * \param this Employee*
 * \param id int
 * \return int 1 ok -1 error
 *
 */
int employee_setId(Employee *this, int id);

/** \brief getter de id empleado
 *
 * \param this Employee*
 * \param id int*
 * \return int 1 ok -1 error
 *
 */
int employee_getId(Employee *this, int *id);

/** \brief setter de nombre
 *
 * \param this Employee*
 * \param nombre char*
 * \return int 1 ok -1 error
 *
 */
int employee_setNombre(Employee *this, char *nombre);

/** \brief getter de nombre
 *
 * \param this Employee*
 * \param nombre char*
 * \return int 1 ok -1 error
 *
 */
int employee_getNombre(Employee *this, char *nombre);

/** \brief setter de horas trabajadas
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas);

/** \brief getter de horas trabajadas
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int 1 ok -1 error
 *
 */
int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas);

/** \brief set de sueldo
 *
 * \param this Employee*
 * \param sueldo int
 * \return int 1 ok -1 error
 *
 */
int employee_setSueldo(Employee *this, int sueldo);

/** \brief getter de sueldo
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int 1 ok -1 error
 *
 */
int employee_getSueldo(Employee *this, int *sueldo);

/** \brief compara 2 nombres de una lista a fin de realizar un ordenamiento
 *
 * \param void* empleado1
 * \param void* empleado2
 * \return int (1 mayor - 0 igual - -1 menor)
 *
 */
int employee_CompareByName(void *e1, void *e2);

/** \brief compara 2 id's de una lista a fin de realizar un ordenamiento
 *
 * \param void* empleado1
 * \param void* empleado2
 * \return int (1 mayor - 0 igual - -1 menor)
 *
 */
int employee_CompareById(void *e1, void *e2);
#endif // employee_H_INCLUDED
