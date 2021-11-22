/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* Nombre del archivo a cargar
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados
 * \return int devuelve 1 si todo esta bien. 0 si hubo algun problema
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/** \brief Carga los datos de los empleados desde un archivo .bin (modo binario).
 *
 * \param path char* Nombre del archivo a cargar
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados
 * \return int devuelve 1 si todo esta bien. 0 si hubo algun problema
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados
 * \return int devuelve 1 si todo esta bien. 0 si hubo algun problema
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);
/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados
 * \return int devuelve 1 si todo esta bien. 0 si hubo algun problema
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);
/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados
 * \return int devuelve 1 si todo esta bien. 0 si hubo algun problema
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados
 * \return int devuelve 1 si todo esta bien. 0 si hubo algun problema
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados
 * \return int devuelve 1 si todo esta bien. 0 si hubo algun problema
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);
/** \brief Guarda los datos de los empleados en un archivo .csv (modo texto)
 *
 * \param path char* Nombre del archvio a cargar
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados
 * \return int devuelve 1 si todo esta bien. 0 si hubo algun problema
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/** \brief Guarda los datos de los empleados en un archivo .bin (modo binario)
 *
 * \param path char* Nombre del archivo a cargar
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados
 * \return int devuelve 1 si todo esta bien. 0 si hubo algun problema
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


