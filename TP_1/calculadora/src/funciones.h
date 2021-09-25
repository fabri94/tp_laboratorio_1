/*
 * funciones.h
 *
 *  Created on: 14 abr. 2021
 *      Author: Fabri
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/** \brief Le permite al usuario ingresar un numero
 *
 * \param Variable en donde se asigna el numero
 * \return El numero ingresado por el usuario
 *
 */

float pedirNumero();
/** \brief Le permite al usuario sumar dos numeros
 *
 * \param Primer numero a sumar
 * \param Segundo numero que se suma con el primero
 * \return Retorna el resultado de la suma entra ambos numeros
 *
 */

float sumar(float a, float b);
/** \brief Le permite al usuario restar dos numeros
 *
 * \param Primer numero a restar
 * \param Segundo numero que resta al primero
 * \return Retorna el resultado de la resta entre ambos operandos
 *
 */

float restar(float a, float b);
/** \brief Le permite al usuario multiplicar dos numeros
 *
 * \param Primer operando a multiplicar
 * \param Segundo operando que se multiplica con el primero ingresado
 * \return El resultado de la multiplicacion entre ambos operandos
 *
 */

float multiplicar(float a, float b);
/** \brief Le permite al usuario dividir dos numeros entre si
 *
 * \param Primer operando a dividir (dividendo)
 * \param Segundo operando que se divide por el primero (divisor)
 * \return El resultado de la division entre ambos operandos
 *
 */

float dividir(float a, float b);
/** \brief Le permite al usuario calcular el factorial de un numero comprendido entre 0 y 170
 *
 * \param El numero a factoriar
 * \return El factorial del operando ingresado
 *
 */

double factorial(float a);

#endif /* FUNCIONES_H_ */
