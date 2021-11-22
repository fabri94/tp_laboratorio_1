#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "inputs.h"
#include "menu.h"

#define INTENTOS 5

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option=0;
    char respuesta;
    char salir;
    int guardado=0;

    LinkedList* listaEmpleados=ll_newLinkedList();
    if(listaEmpleados==NULL)
    {
        printf("No se pudo crear la linkedList.\n");
        exit(1);
    }

    do
    {
        menu();
        printf("\n");
        if(!getEntero(&option, 1,10, INTENTOS, "Ingrese opcion: ", "Error. \n"))
        {
            printf("Se excedio el limite de intentos...\nSe finalizara el programa.\n");
            exit(1);
        }
        respuesta='s';
        switch(option)
        {
        case 1:
            system("cls");
            if(ll_len(listaEmpleados)>0)
            {
                if(!getLetra(&respuesta, INTENTOS, "Hay empleados cargados en la lista y van a ser elminados si se prosigue.\n¿Esta seguro que quiere cargar otro archivo? 's' para si, 'n' para no", "Error. "))
                {
                    printf("Se excedio el limite de intentos.\n");
                    respuesta='n';
                }
                if(respuesta=='s')
                {
                    ll_clear(listaEmpleados);
                }
            }
            if(respuesta!='n')
            {
                    if(controller_loadFromText("data.csv",listaEmpleados))
                    {
                        printf("Archivo de texto (.csv) cargado con exito.\n");
                    }
                    else
                    {
                        printf("Hubo un error al cargar el archivo.\n");
                    }
            }
            system("pause");
            break;

        case 2:
            system("cls");
            if(ll_len(listaEmpleados)>0)
            {
                if(!getLetra(&respuesta, INTENTOS, "Hay empleados cargados en la lista y van a ser elminados si se prosigue.\n¿Esta seguro que quiere cargar otro archivo? 's' para si, 'n' para no", "Error. "))
                {
                    printf("Se excedio el limite de intentos.\n");
                    respuesta='n';
                }
                if(respuesta=='s')
                {
                    ll_clear(listaEmpleados);
                }
            }
            if(respuesta!='n')
            {
                    if(controller_loadFromBinary("data.bin",listaEmpleados))
                    {
                        printf("Archivo binario (.bin) cargado con exito.\n");
                    }
                    else
                    {
                        printf("Hubo un error.\n");
                    }

            }
            system("pause");
            break;


        case 3:
            system("cls");
            printf("------- Alta empleado -------\n");
            if(controller_addEmployee(listaEmpleados))
            {
                guardado=0;
                printf("Alta exitosa!\n");
            }
            else
            {
                printf("Hubo un error en el alta.\n");
            }

            system("pause");
            break;

        case 4:
            system("cls");
            printf("------ Modificar Empleado ------\n");
            if(controller_editEmployee(listaEmpleados))
            {
                guardado=0;
                printf("Modificacion exitosa.\n");
            }
            else
            {
                printf("Hubo un error con la modificacion del empleado.\n");
            }
            system("pause");
            break;

        case 5:
            system("cls");
            if(controller_removeEmployee(listaEmpleados))
            {
                guardado=0;
                printf("Baja exitosa.\n");
            }
            else
            {
                printf("Hubo un problema con la baja del empleado.\n");
            }
            system("pause");
            break;

        case 6:
            system("cls");
            if(controller_ListEmployee(listaEmpleados))
            {
                printf("Se listaron los empleados exitosamente.\n");
            }
            else
            {
                printf("Hubo un problema al listar los empleados.\n");
            }
            system("pause");
            break;

        case 7:
            system("cls");
            if(controller_sortEmployee(listaEmpleados))
            {
                printf("Ordenamiento de empleados exitoso.\n");
            }
            else
            {
                printf("Hubo un problema al realizar el ordenamiento de empleados.\n");
            }
            system("pause");
            break;

        case 8:
            system("cls");
            if(ll_len(listaEmpleados)>0)
            {
                if(controller_saveAsText("data.csv",listaEmpleados))
                {
                    guardado=1;
                    printf("Archivo de texto (.csv) guardado con exito.\n");
                }
            }
            else
            {
                printf("No se puede guardar el archivo si no ha ingresado ningun empleado nuevo en el mismo.\n");
            }
            system("pause");
            break;

        case 9:
            system("cls");
            if(ll_len(listaEmpleados)>0)
            {
                if(controller_saveAsBinary("data.bin",listaEmpleados))
                {
                    guardado=1;
                    printf("Archivo binario (.bin) guardado con exito.\n");
                }
            }
            else
            {
                printf("No se puede guardar el archivo si no ha ingresado ningun empleado nuevo en el mismo.\n");
            }

            system("pause");
            break;

        case 10:
            system("cls");
            if(guardado==0)
            {
                if(!getLetra(&salir, INTENTOS, "¿Esta seguro que quiere salir sin guardar? 's' para si, 'n' para no ", "Error. "))
                {
                    printf("Se excedio el limite de intentos.\n");
                }
                system("pause");
            }
            else
            {
                salir='s';
            }
        }
    }
    while(salir!='s');
    ll_deleteLinkedList(listaEmpleados);

    return 0;
}
