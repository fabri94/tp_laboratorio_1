#include "LinkedList.h"
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Crea un nuevo empleado en la memoria dinamica inicializado con todos sus campos en 0 y ""
 *
 * \return Employee* devuelve la direccion de memoria del empleado
 *
 */
Employee* employee_new();


/** \brief Crea un nuevo empleado en la memoria dinamica inicializado con sus campos cargados con los parametros que se le pasan
 *
 * \param idStr char* id del empleado como cadena de texto
 * \param nombreStr char* nombre del empleado
 * \param horasTrabajadasStr char* horas trabajadas del empleado como cadena de texto
 * \param sueldoStr char* sueldo del empleado como cadena de texto
 * \return Employee* devuelve la direccion de memoria del empleado
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);


/** \brief Elimina al empleado, haciendo el free de la memoria pedida al SO
 *
 * \param this Employee* direccion del empleado a eliminar
 * \return void
 *
 */
void employee_delete(Employee* this);


/** \brief Setea el id de un empleado
 *
 * \param this Employee* direccion de memoria del empleado al cual se le quiere setear el ID
 * \param id int id a setearle al empleado
 * \return int retorna 1 si salio todo bien, o 0 si hubo algun problema
 *
 */
int employee_setId(Employee* this,int id);


/** \brief Consigue el id de un empleado
 *
 * \param this Employee* direccion de memoria del empleado del cual se quiere obtener el id
 * \param id int* direccion de memoria en donde se devuelve el id del empleado solicitado
 * \return int retorna 1 si salio todo bien, o 0 si hubo algun problema
 *
 */
int employee_getId(Employee* this,int* id);


/** \brief Setea el nombre de un empleado
 *
 * \param this Employee* direccion de memoria del empleado al cual se le quiere setear el nombre
 * \param nombre char* nombre a setearle al empleado
 * \return int retorna 1 si salio todo bien, o 0 si hubo algun problema
 *
 */
int employee_setNombre(Employee* this,char* nombre);


/** \brief Consigue el nombre de un empleado
 *
 * \param this Employee* direccion de memoria del empleado del cual se quiere obtener el nombre
 * \param nombre char* direccion de memoria en donde se devuelve el nombre del empleado solicitado
 * \return int retorna 1 si salio todo bien, o 0 si hubo algun problema
 *
 */
int employee_getNombre(Employee* this,char* nombre);


/** \brief Setea las horas trabajadas de un  empleado
 *
 * \param this Employee* direccion de memoria del empleado al cual se le quiere setear las horas trabajadas
 * \param horasTrabajadas int horas trabajadas a setearle al empleado
 * \return int retorna 1 si salio todo bien, o 0 si hubo algun problema
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);


/** \brief Obtiene las horas trabajadas de un empleado
 *
 * \param this Employee* direccion de memoria del empleado del cual se quiere obtener las horas trabajadas
 * \param horasTrabajadas int* direccion de memoria en donde se devuelve las horas trabajadas del empleado solicitado
 * \return int retorna 1 si salio todo bien, o 0 si hubo algun problema
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);


/** \brief Setea el sueldo de un empleado
 *
 * \param this Employee* direccion de memoria del empleado al cual se le quiere setear el sueldo
 * \param sueldo int sueldo a setearle al empleado
 * \return int retorna 1 si salio todo bien, o 0 si hubo algun problema
 *
 */
int employee_setSueldo(Employee* this,int sueldo);


/** \brief Obtiene el sueldo de un empleado
 *
 * \param this Employee* direccion de memoria del empleado del cual se quiere obtener el sueldo
 * \param sueldo int* direccion de memoria en donde se devuelve el sueldo del empleado solicitado
 * \return int retorna 1 si salio todo bien, o 0 si hubo algun problema
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);


/** \brief Busca el id mayor de la lista de empleados y lo devuelve
 *
 * \param pArrayListEmployee LinkedList* puntero a la lista de empleados
 * \param id int* direccion de memoria donde se devuelve el id
 * \return int retorna 1 si salio todo bien, o 0 si hubo algun problema
 *
 */
int employee_buscarMayorId(LinkedList* pArrayListEmployee,int* id);
#endif // employee_H_INCLUDED
