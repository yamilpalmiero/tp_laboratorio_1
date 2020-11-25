/** \brief efectua el parser de una lista ingresada desde archivo en formato texto
 *
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int 1ok  -1 error
 *
 */
int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee);

/** \brief efectua el parser de una lista ingresada desde archivo en formato binario
 *
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int 1ok  -1 error
 *
 */
int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee);
