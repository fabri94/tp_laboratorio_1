/*
 * ArrayEmployee.h
 *
 *  Created on: 16 oct. 2021
 *      Author: Fabri
 */

#ifndef ARRAYEMPLOYEE_H_
#define ARRAYEMPLOYEE_H_

typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;


/** \brief Muestra el menu principal
 *
 * \return int Devuelve la opcion seleccionada por el usuario
 *
 */
int menu();

/** \brief Muestra el menu modificaciones del empleado
 *
 * \return int Devuelve la opcion seleccionada por el usuario
 *
 */
int menuModificacion();

/** \brief Muestra el menu de informes
 *
 * \return int Devuelve la opcion seleccionada por el usuario
 *
 */
int menuInformes();
/** \brief Imprime por pantalla los sectores correspondientes a cada numero
 *
 * \return void
 *
 */
void mostrarSectores();

/** \brief Inicializa todas las posiciones del array de empelados en 0
 *
 * \param lst Employee* Puntero al array de empleados
 * \param len int Tamaño del array de empleados
 * \return int Devuelve -1 si hubo un error en los parametros. 0 si pudo inicializar efectivamente el array en 0
 *
 */
int initEmployees(Employee* lst, int len);

/** \brief Busca si hay algun lugar vacio en el array de empleados, y de ser asi devuelve el primero encontrado.
 *
 * \param lst Employee* Puntero al array de empleados
 * \param len int Tamaño del array de empleados
 * \return int Devuelve -1 si no encuentra posicion libre. De lo contrario devuelve el indice de la primera posicion libre encontrada
 *
 */
int findEmpty(Employee* lst, int len);

/** \brief Carga en el array existente de empleados, en la primera posicion libre encontrada, el alta de un nuevo empleado
 *
 * \param lst Employee* Puntero al array de empleados
 * \param len int Tamaño del array de empleados
 * \param id int ID que asigna al empleado a cargar
 * \param name[] char Nombre del empleado
 * \param lastName[] char Apellido del empleado
 * \param salary float Salario del empleado
 * \param sector int Sector al que pertenece el empleado
 * \return int Devuelve -1 en caso de que haya habido un error en la carga (puntero apuntando a una direccion nula, o el array esta lleno). 0 si se pudo cargar correctamente
 *
 */
int addEmployees(Employee* lst, int len, int id, char name[], char lastName[], float salary, int sector);

/** \brief Busca a un empleado por el ID y en caso de encontrarlo, devuelve la posicion en la que se encuentra.
 *
 * \param lst Employee* Puntero al array de empleados
 * \param len int Tamaño del array de empleados
 * \param id int El ID que el usuario esta buscando
 * \return int Devuelve el indice de la posicion en la que se encuentra el empleado, o -1 en caso de que no se haya encontrado o el puntero apunte a una direccion de memoria nula
 *
 */
int findEmployeeById(Employee* lst, int len, int id);

/** \brief Permite buscar a un empleado por su ID y hacer una baja logica del mismo (ajusta el campo isEmpty=1)
 *
 * \param lst Employee* Puntero al array de empleados
 * \param len int Tamaño del array de empleados
 * \param id int El ID del empleado que el usuario quiere dar de baja
 * \return int Devuelve 0 si la baja se pudo hacer correctamente, o -1 en caso de que haya habido un error con los parametros
 *
 */
int removeEmployee(Employee* lst, int len, int id);

/** \brief Ordena todos los elementos del array de empleados. El parametro orden indica si el orden sera ASCENDENTE o DESCENDENTE
 *
 * \param lst Employee* Puntero al array de empleados
 * \param len int Tamaño del array de empleados
 * \param order int En caso de que el valor ingresado sea 1, se ordenara de forma ascendente. Si el valor ingresado es 0, se ordena de forma descendente
 * \return int Devuelve -1 si hubo un error al intentar ordenar el array (problema con el puntero del array de empleados o tamaño del mismo). 0 si se pudo ordenar
 *
 */
int sortEmployees(Employee* lst, int len, int order);

/** \brief Permite modificar el nombre, apellido, salario o sector de un empleado cargado
 *
 * \param lst Employee* Puntero al array de empleados
 * \param len int Tamaño del array de empleados
 * \return int Devuelve 0 si hubo un error al intentar modificar el empleado. 1 si esta todo ok
 *
 */
int modifyEmployee(Employee* lst, int len);

/** \brief Muestra por pantalla un empleado de la lista
 *
 * \param emp Employee El empleado a mostrar
 * \return void
 *
 */
void printEmployee(Employee emp);

/** \brief Muestra por pantalla la lista de empleados
 *
 * \param lst Employee* Puntero al array de empleados
 * \param len int Tamaño del array de empleados
 * \return int Devuelve -1 en caso de que haya habido un error con los parametros. 0 si pudo mostrar los empleados correctamente
 *
 */
int printEmployees(Employee* lst, int len);


/** \brief Calcula el total y el promedio de los salarios de todos los empleados
 *
 * \param lst Employee* Puntero al array de empleados
 * \param len int Tamaño del array empleados
 * \param pTotalSalarios float* Puntero al total de los salarios de los empleados
 * \param pPromedioSalarios float* Puntero al promedio de los salarios de los empleados
 * \return int Devuelve 1 si los calculos fueron realizados con exito. 0 si hubo un error (puntero aputandno a direccion de memoria nula, o problemas con el tamaño del array)
 *
 */
int calcularTotalYPromedioSalarios(Employee* lst, int len, float* pTotalSalarios, float* pPromedioSalarios);

/** \brief Cuenta cuantos empleados superan el salario promedio. En caso de encontrar uno, se incrementa el contador por uno
 *
 * \param lst Employee* Puntero al array de empleados
 * \param len int Tamaño del array de empleados
 * \param pPromedioSalarios float* Puntero al promedio de los salarios de los empleados
 * \param contadorEmp int* Puntero al contador de empleados que superan el salario promedio
 * \return int Devuelve 1 si esta todoOk. 0 si hubo un error con los parametros(puntero aputandno a direccion de memoria nula, o problemas con el tamaño del array)
 *
 */
int contadorDeEmpleadosMayorSalario(Employee* lst, int len, float* pPromedioSalarios, int* contadorEmp);


//int cargarDatosEmpleado(char name[], char lastName[], float salary, int sector);


#endif /* ARRAYEMPLOYEE_H_ */
