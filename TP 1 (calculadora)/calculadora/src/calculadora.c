/*
 ============================================================================
 Name        : calculadora.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"

int main()
{
	setbuf(stdout,NULL);
	char salir='n';
	    char confirma;
	    int opcion;
	    int flagPrimerOperando=0;
	    int flagSegundoOperando=0;
	    int flagOperaciones=0;
	    float primerOperando;
	    float segundoOperando;
	    float resultado;
	    double resultadoFactorialPrimerOperando;
	    double resultadoFactorialSegundoOperando;

	    do
	    {
	        system("cls");
	        printf("*****MENU DE OPCIONES*****\n\n");

	        if(flagPrimerOperando)
	        {
	            printf("1.Modificar primer operando: %.2f\n",primerOperando);
	        }else if(!flagPrimerOperando)
	        {
	            printf("1.Ingrese primer operando (A=X).\n");
	        }
	        if(flagSegundoOperando)
	        {
	            printf("1.Modificar segundo operando: %.2f\n",segundoOperando);
	        }else if(!flagSegundoOperando)
	        {
	            printf("2.Ingrese segundo operando (B=Y).\n");
	        }
	        if(flagPrimerOperando&&flagSegundoOperando)
	        {
	            printf("3.Calcular operaciones.\n\n a)Calcular la suma(%.2f+%.2f).\n b)Calcular la resta(%.2f-%.2f).\n c)Calcular la multiplicacion(%.2f*%.2f).\n d)Calcular la division (%.2f/%.2f).\n e)Calcular los factoriales (%.0f!,%.0f!).\n\n",primerOperando,segundoOperando,primerOperando,segundoOperando,primerOperando,segundoOperando,primerOperando,segundoOperando,primerOperando,segundoOperando);
	        }else if(flagPrimerOperando&&!flagSegundoOperando)
	        {
	            printf("3.Calcular operaciones.\n\n a)Calcular la suma(%.2f+B).\n b)Calcular la resta(%.2f-B).\n c)Calcular la multiplicacion(%.2f*B).\n d)Calcular la division (%.2f/B).\n e)Calcular los factoriales (%.0f!,B!).\n\n",primerOperando,primerOperando,primerOperando,primerOperando,primerOperando);
	        }else if(!flagPrimerOperando&&flagSegundoOperando)
	        {
	            printf("3.Calcular operaciones.\n\n a)Calcular la suma(A+%.2f).\n b)Calcular la resta(A-%.2f).\n c)Calcular la multiplicacion(A*%.2f).\n d)Calcular la division (A/%.2f).\n e)Calcular los factoriales (A!,%.0f!).\n\n",segundoOperando,segundoOperando,segundoOperando,segundoOperando,segundoOperando);
	        }else
	        {
	            printf("3.Calcular operaciones.\n\n a)Calcular la suma(A+B).\n b)Calcular la resta(A-B).\n c)Calcular la multiplicacion(A*B).\n d)Calcular la division (A/B).\n e)Calcular los factoriales (A!,B!).\n\n");
	        }
	        printf("4.Mostrar resultados.\n");
	        printf("5.Salir.\n\n\n");
	        printf("Ingrese una opcion por favor: ");
	        fflush(stdin);
	        scanf("%d",&opcion);

	        switch(opcion)
	        {
	        case 1:
	            primerOperando=pedirNumero();
	            flagPrimerOperando=1;
	            system("pause");
	            break;
	        case 2:
	            if(flagPrimerOperando)
	            {
	                segundoOperando=pedirNumero();
	                flagSegundoOperando=1;
	            }else
	            {
	                printf("Error. Solamente podes cargar el segundo operando, despues de haber cargado el primero.\n");
	            }
	            system("pause");
	            break;
	        case 3:
	            if(flagPrimerOperando&&flagSegundoOperando)
	            {
	                printf("Todas las operaciones fueron calculadas.\n");
	                flagOperaciones=1;
	            }else if(flagPrimerOperando&&!flagSegundoOperando)
	            {
	                printf("Error. Debes cargar el segundo operando para poder realizar todas las operaciones.\n");
	            }else if(!flagPrimerOperando&&!flagSegundoOperando)
	            {
	                printf("Error. Debes cargar ambos operandos para poder realizar todas las operaciones.\n");
	            }
	            system("pause");
	            break;
	        case 4:
	            if(flagOperaciones)
	            {
	                resultado=sumar(primerOperando,segundoOperando);
	                printf("\n%.2f + %.2f = %.2f\n\n",primerOperando,segundoOperando,resultado);
	                resultado=restar(primerOperando,segundoOperando);
	                printf("%.2f - %.2f = %.2f\n\n",primerOperando,segundoOperando,resultado);
	                resultado=multiplicar(primerOperando,segundoOperando);
	                printf("%.2f * %.2f = %.2f\n\n",primerOperando,segundoOperando,resultado);
	                if(segundoOperando!=0)
	                {
	                    resultado=dividir(primerOperando,segundoOperando);
	                    printf("%.2f / %.2f = %.2f\n\n",primerOperando,segundoOperando,resultado);
	                }else
	                {
	                    printf("La division no pudo ser calculada ya que no se puede dividir por 0.\n\n");
	                }
	                resultadoFactorialPrimerOperando=factorial(primerOperando);
	                if(resultadoFactorialPrimerOperando==0)
	                {
	                    printf("No se pudo calcular %.0f! ya que se trata de un numero negativo.\n\n",primerOperando);
	                }else if(resultadoFactorialPrimerOperando== -1)
	                {
	                    printf("El numero %.0f es demasiado grande para ser factoriado. Pruebe ingresando un valor por debajo de 170.\n\n",primerOperando);
	                }else
	                {
	                    printf("%.0f! = %.0lf\n\n",primerOperando,resultadoFactorialPrimerOperando);
	                }
	                resultadoFactorialSegundoOperando=factorial(segundoOperando);
	                if(resultadoFactorialSegundoOperando==0)
	                {
	                    printf("No se pudo calcular %.0f! ya que se trata de un numero negativo.\n\n",segundoOperando);
	                }else if(resultadoFactorialSegundoOperando== -1)
	                {
	                    printf("El numero %.0f es demasiado grande para ser factoriado. Pruebe ingresando un valor por debajo de 170.\n\n",segundoOperando);
	                }else
	                {
	                    printf("%.0f! = %.0lf\n\n",segundoOperando,resultadoFactorialSegundoOperando);
	                }
	                flagPrimerOperando=0;
	                flagSegundoOperando=0;
	                flagOperaciones=0;
	            }else
	            {
	                printf("Para mostrar los resultados primero debe realizar todas las operaciones.\n");
	            }
	            system("pause");
	            break;
	        case 5:
	            printf("?Esta segurx que desea salir? 's' para si, 'n' para no.\n");
	            fflush(stdin);
	            confirma=getchar();
	            if(confirma=='s'||confirma=='S')
	            {
	                salir='s';
	            }
	            break;
	        default:
	            printf("Opcion invalida, por favor ingrese una opcion de la 1 a la 5.\n");
	            system("pause");
	            break;
	        }
	    }while(salir=='n'||salir=='N');
}
