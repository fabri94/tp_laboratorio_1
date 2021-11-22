/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE* archivo de donde se obtienen los datos
 * \param pArrayListEmployee LinkedList* puntero a la lista de empleados
 * \return int devuelve 1 si esta todo bien o 0 si hubo algun problema
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param pFile FILE* archivo de donde se obtienen los datos
 * \param pArrayListEmployee LinkedList* puntero a la lista de empleados
 * \return int devuelve 1 si esta todo bien o 0 si hubo algun problema
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
