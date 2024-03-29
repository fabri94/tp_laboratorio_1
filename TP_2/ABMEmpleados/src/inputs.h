/*
 * inputs.h
 *
 *  Created on: 16 oct. 2021
 *      Author: Fabri
 */

#ifndef INPUTS_H_
#define INPUTS_H_

/** \brief Pide un numero entero al usuario y lo valida. Le da un valor x de intentos para ingresarlo
 *
 * \param pNumero int* puntero a la variable en donde se devolvera el numero ingresado por el usuario
 * \param lInf int valor minimo que puede ingresar el usuario
 * \param lSup int valor maximo que puede ingresar el usuario
 * \param intentos int cantidad de intentos que tiene el usuario para ingresar el numero
 * \param msj[] char mensaje que se imprime por pantalla y le indica al usuario que ingrese el numero
 * \param msjError[] char mensaje que se imprime por pantalla y que le indica al usuario que el numero ingresado no es valido
 * \return int Devuelve 1 si esta todoOk. 0 si hubo un error
 *
 */
int getEntero(int* pNumero, int lInf, int lSup, int intentos, char msj[], char msjError[]);

/** \brief Pide un numero flotante al usuario y lo valida. Le da un valor x de intentos para ingresarlo
 *
 * \param pNumero float* puntero a la variable en donde se devolvera el numero ingresado por el usuario
 * \param lInf float valor minimo que puede ingresar el usuario
 * \param lSup float valor maximo que puede ingresar el usuario
 * \param intentos int cantidad de intentos que tiene el usuario para ingresar el numero
 * \param msj[] char mensaje que se imprime por pantalla y le indica al usuario que ingrese el numero
 * \param msjError[] char mensaje que se imprime por pantalla y que le indica al usuario que el numero ingresado no es valido
 * \return int Devuelve 1 si esta todoOk. 0 si hubo un error
 *
 */
int getFlotante(float* pNumero, float lInf, float lSup, int intentos, char msj[], char msjError[]);

/** \brief Pide una o varias palabras validando que se traten de caracteres ingresados, y que no superen el largo de la variable en donde se almacenara, dando x cantidad de intentos
 *
 * \param cadena[] char variable en donde se devolvera la cadena ingresada por el usuario
 * \param largo int tama�o de la variable cadena
 * \param intentos int intentos totales que tiene el usuario para ingresar una cadena de texto valida
 * \param msj[] char mensaje que se imprime por pantalla y le indica al usuario que ingrese la cadena de texto
 * \param msjError[] char mensaje que se imprime por pantalla y que le indica al usuario que la cadena de texto ingresda no es valida
 * \return int Devuelve 1 si esta todoOk. 0 si hubo un error
 *
 */
int getCadena(char cadena[], int largo, int intentos, char msj[], char msjError[]);

/** \brief formatea un nombre o apellido (sustantivo propio)
 *
 * \param cadena[] char el sustantivo propio que se formateara
 * \return int Devuelve 1 si esta todoOk. 0 si hubo un error
 *
 */
int formatearSustPropio(char cadena[]);


#endif /* INPUTS_H_ */
