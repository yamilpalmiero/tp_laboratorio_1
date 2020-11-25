/** \brief carga archivo de texto al programa
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 1 ok -1 error
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief carga archivo binario al programa
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 1 ok -1 error
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief agrega un empleado a la lista
 *
 * \param pArrayListEmployee LinkedList*
 * \return int1 ok -1 error
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief edita un empleado de la lista
 *
 * \param pArrayListEmployee LinkedList*
 * \return int1 ok -1 error
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief elimina un empleado de la lista
 *
 * \param pArrayListEmployee LinkedList*
 * \return int1 ok -1 error
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief imprime lista de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int1 ok -1 error
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief ordena la lista
 *
 * \param pArrayListEmployee LinkedList*
 * \return int1 ok -1 error
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief guarda la lista en un archivo de texto
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int1 ok -1 error
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/** \brief guarda la lista en un archivo binario
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int1 ok -1 error
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
