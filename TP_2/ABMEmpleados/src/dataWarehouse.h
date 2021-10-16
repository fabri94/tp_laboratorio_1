/*
 * dataWarehouse.h
 *
 *  Created on: 16 oct. 2021
 *      Author: Fabri
 */

#ifndef DATAWAREHOUSE_H_
#define DATAWAREHOUSE_H_

#include "ArrayEmployee.h"

/** \brief Array de empleados ya hardcodeados y predefinidos. Ayudan con la coreccion en la disposicion de las tablas y probar las fx
 * ya desarrolladas, sin tener que dar de alta un empleado necesariamente para hacerlo
 * \param lst[] Employee Array de los empleados que cargara
 * \param len int Tamaño del array de los empleados
 * \param cant int Cantidad de empleados que se quieren hardcodear en el array
 * \param pId int* ID que se le asigna a cada empleado hardcodeado
 * \return int Devuelve 1 si esta todoOk. 0 si hubo un error
 *
 */
int hardcodearEmpleados(Employee lst[], int len, int cant, int* pId);

#endif /* DATAWAREHOUSE_H_ */
