/*
 * ArrayEmployee.c
 *
 *  Created on: 16 oct. 2021
 *      Author: Finelli Fabrizio Nicolás
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployee.h"
#include "inputs.h"

int menu()
{
    int opcion;
    system("cls");
    printf("     ***ABM Empleados ***\n\n");
    printf("1- Alta empleado\n");
    printf("2- Modificar empleado\n");
    printf("3- Baja empleado\n");
    printf("4- Informes\n");
    printf("5- Salir\n");
    printf("\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

int menuModificacion()
{
    int opcion;
    printf("\n");
    printf(" ***Menu de modificaciones*** \n");
    printf("1- Modificar nombre\n");
    printf("2- Modificar apellido\n");
    printf("3- Modificar salario\n");
    printf("4- Modificar sector\n");
    printf("\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

int menuInformes()
{
    int opcion;
    system("cls");
    printf("      ***Informes*** \n\n");
    printf("1- Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n");
    printf("2- Mostrar total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n");
    printf("\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    printf("\n");

    return opcion;

}

void mostrarSectores()
{
    printf(" ID      Sector\n");
    printf("------------------\n");
    printf(" 100  Ventas\n");
    printf(" 101  Contable\n");
    printf(" 102  Sistemas\n");
    printf(" 103  Legales\n");
    printf(" 104  RR.HH\n");
}

int initEmployees(Employee* lst, int len)
{
    int todoOk=-1;
    if(lst!=NULL&&len>0)
    {
        for(int i=0;i<len;i++)
        {
            lst[i].isEmpty=1;
        }
        todoOk=0;
    }


    return todoOk;
}

int findEmpty(Employee* lst, int len)
{
    int posicionLibre=-1; //me devuelve -1 si no encuentra posicion libre. sino devuelve el indice de la posicion libre

        for(int i=0;i<len;i++)
        {
            if(lst[i].isEmpty)
            {
                posicionLibre=i;
                break;
            }
        }

    return posicionLibre;
}

int addEmployees(Employee* lst, int len, int id, char name[], char lastName[], float salary, int sector)
{
    int todoOk=-1;
    int indice;
    if(lst!=NULL&&len>0&&id>0&&name!=NULL&&lastName!=NULL)
    {
        system("cls");
        printf("   **** Alta empleado ****\n\n");
        indice=findEmpty(lst,len);
        if(indice==-1)
        {
            printf("No hay lugar en el sistema\n");
        }else
        {
            lst[indice].id=id;

            if(!getCadena(name,51,5,"Ingrese el nombre del empleado: ","Error en la carga del nombre \n\n"))
            {
                printf("Se excedio el limite de intentos\n\n");
            }else
            {
                if(!getCadena(lastName,51,5,"Ingrese el apellido del empleado: ","Error en la carga del apellido \n\n"))
                {
                    printf("Se excedio el limite de intentos\n\n");
                }else
                {
                    if(!getFlotante(&salary,20000,1000000,5,"Ingrese el salario del empleado: ","Error en la carga del salario \n\n"))
                    {
                        printf("Se excedio el limite de intentos\n\n");
                    }else
                    {
                        mostrarSectores();
                        if(!getEntero(&sector,100,104,5,"Ingrese sector del empleado: ","Error en la carga del sector \n\n"))
                        {
                            printf("Se excedio el limite de intentos\n\n");
                        }
                        formatearSustPropio(name);
                        formatearSustPropio(lastName);
                        strcpy(lst[indice].name,name);
                        strcpy(lst[indice].lastName,lastName);
                        lst[indice].salary=salary;
                        lst[indice].sector=sector;
                        lst[indice].isEmpty=0;
                        todoOk=0;
                    }
                }
            }
        }
    }

    return todoOk;
}

int findEmployeeById(Employee* lst, int len, int id)
{
    int posicionEmpleado=-1;

        for(int i=0;i<len;i++)
        {
            if(lst[i].id==id&&!lst[i].isEmpty)//si el id que le paso coincide con uno que ya este cargado y ademas me cercioro de que esa posicion no este libre, entonces entro
            {
                posicionEmpleado=i;
                break;
            }

        }

    return posicionEmpleado;
}

int removeEmployee(Employee* lst, int len, int id)
{
    int todoOk=-1;
    int indice;
    char confirma;

    if(lst!=NULL&&len>0)
    {
        indice=findEmployeeById(lst,len,id); //llamo a la funcion buscar por id, y al indice encontrado en la lista de personas analizada por la fx, lo asigno a la variable indice de este scope
        if(indice==-1)
        {
            printf("El id: %d no existe en el sistema\n",id);

        }else
        {
            printf("----------------------------------------------------------\n");
            printf("   ID       Nombre    Apellido    Salario   Sector\n");
            printf("----------------------------------------------------------\n");
            printEmployee(lst[indice]);
            printf("Confirma baja?: ");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma=='s'||confirma=='S')
            {
                lst[indice].isEmpty=1;
                todoOk=0;

            }else
            {
                printf("Baja cancelada por el usuario\n");
            }
        }
    }

    return todoOk;

}

int modifyEmployee(Employee* lst, int len)
{
    int todoOk=0;
    int id;
    int indice;
    char confirma;
    Employee auxEmployee;

    if(lst!=NULL&&len>0)
    {
        printf("\n\nIngrese id: ");
        scanf("%d",&id);
        indice=findEmployeeById(lst,len,id); //llamo a la funcion buscar por id, y al indice encontrado en la lista de personas analizada por la fx, lo asigno a la variable indice de este scope
        if(indice==-1)
        {
            printf("El id: %d no existe en el sistema\n",id);

        }else
        {
            printf("\n");
            printf("----------------------------------------------------------\n");
            printf("   ID       Nombre    Apellido    Salario   Sector\n");
            printf("----------------------------------------------------------\n");
            printEmployee(lst[indice]);
            printf("\n");
            //submenu
            printf("¿Confirma modificacion?: ");
            fflush(stdin);
            scanf("%c",&confirma);

            if(confirma=='s')
            {
                switch(menuModificacion())
                {
                case 1:
                    if(!getCadena(auxEmployee.name,51,5,"Ingrese nuevo nombre: ","Error en la carga del nuevo nombre \n\n"))
                    {
                        printf("Hubo un error al modificar el nombre del empleado\n");
                    }else
                    {
                        formatearSustPropio(auxEmployee.name);
                        strcpy(lst[indice].name,auxEmployee.name);
                    }
                    break;
                case 2:
                    if(!getCadena(auxEmployee.lastName,51,5,"Ingrese nuevo apellido: ","Error en la carga del nuevo apellido \n\n"))
                    {
                        printf("Hubo un error al modificar el apellido del empleado\n");
                    }else
                    {
                        formatearSustPropio(auxEmployee.lastName);
                        strcpy(lst[indice].lastName,auxEmployee.lastName);
                    }
                    break;
                case 3:
                    if(!getFlotante(&auxEmployee.salary,20000,1000000,5,"Ingrese nuevo salario del empleado: ","Error en la carga del nuevo salario \n\n"))
                    {
                        printf("Hubo un error al modificar el salario del empleado\n");
                    }else
                    {
                        lst[indice].salary=auxEmployee.salary;
                    }
                    break;
                case 4:
                    if(!getEntero(&auxEmployee.sector,100,104,5,"Ingrese nuevo sector del empleado: ","Error en la carga del nuevo sector \n\n"))
                    {
                        printf("Hubo un error al modificar el sector del empleado\n");
                    }else
                    {
                        lst[indice].sector=auxEmployee.sector;
                    }
                    break;
                default:
                    printf("Opcion invalida!!!");
                    system("pause");
                    break;
                }
                todoOk=1;
            }else
            {
                printf("Modificacion cancelada\n");
            }
        }


    }

    return todoOk;
}

void printEmployee(Employee emp)
{
    printf(" %4d %10s    %10s   %9.2f    %3d\n",
           emp.id,
           emp.name,
           emp.lastName,
           emp.salary,
           emp.sector);
}

int printEmployees(Employee* lst, int len)
{
    int todoOk=-1;
    int flag=1;


    if(lst!=NULL&&len>0)
    {
        system("cls");
        printf("     *****  Lista de Empleados  *****\n");
        printf("----------------------------------------------------------\n");
        printf("   ID      Nombre     Apellido     Salario    Sector\n");
        printf("----------------------------------------------------------\n");
        for(int i=0;i<len;i++)
        {
            if(!lst[i].isEmpty)
            {
                printEmployee(lst[i]);
                flag=0;
            }
        }
        if(flag)
        {
            printf("El listado esta vacio...\n");
        }
        todoOk=0;
    }

    return todoOk;
}

int sortEmployees(Employee* lst, int len, int order)
{
    int todoOk=-1;
    Employee auxEmployee;

    if(lst!=NULL&&len>0&&(!order||order))
    {
        for(int i=0; i<len-1;i++)
        {
            for(int j=i+1;j<len;j++)
            {
                if(order)
                {
                    if((lst[i].sector>lst[j].sector)||((lst[i].sector==lst[j].sector)&&strcmp(lst[i].lastName,lst[j].lastName)>0))//orden ascendente de empleados)
                    {
                        auxEmployee=lst[i];
                        lst[i]=lst[j];
                        lst[j]=auxEmployee;
                    }
                }else if(!order)
                {
                    if((lst[i].sector<lst[j].sector)||((lst[i].sector==lst[j].sector)&&strcmp(lst[i].lastName,lst[j].lastName)<0)) //orden descendente de empleados)
                    {
                        auxEmployee=lst[i];
                        lst[i]=lst[j];
                        lst[j]=auxEmployee;
                    }
                }
                todoOk=0;
            }
        }
    }


    return todoOk;
}

int calcularTotalYPromedioSalarios(Employee* lst, int len, float* pTotalSalarios, float* pPromedioSalarios)
{
    int todoOk=0;
    int contadorEmpleados=0;

    if(lst!=NULL&&len>0&&pTotalSalarios!=NULL&&pPromedioSalarios!=NULL)
    {
        for(int i=0;i<len;i++)
        {
            if(!lst[i].isEmpty)
            {
                *pTotalSalarios=lst[i].salary + (*pTotalSalarios);
                contadorEmpleados++;
            }
        }
        *pPromedioSalarios=(*pTotalSalarios)/contadorEmpleados;
        todoOk=1;
    }
    return todoOk;
}

int contadorDeEmpleadosMayorSalario(Employee* lst, int len, float* pPromedioSalarios, int* contadorEmp)
{
    int todoOk=0;
    if(lst!=NULL&&pPromedioSalarios!=NULL&&contadorEmp!=NULL)
    {
        for(int i=0;i<len;i++)
        {
            if(!lst[i].isEmpty && lst[i].salary>*pPromedioSalarios)
            {
                (*contadorEmp)++;
            }
        }
        todoOk=1;
    }

    return todoOk;
}

/*int cargarDatosEmpleado(char name[], char lastName[], float salary, int sector)
{
    int todoOk=-1;
    int indice;
    if(lst!=NULL&&len>0&&id>0&&name!=NULL&&lastName!=NULL)
    {
        system("cls");
        printf("   **** Alta empleado ****\n\n");
        indice=findEmpty(lst,len);
        if(indice==-1)
        {
            printf("No hay lugar en el sistema\n");
        }else
        {
            lst[indice].id=id;

            if(!getCadena(name,51,5,"Ingrese el nombre del empleado: ","Error en la carga del nombre"))
            {
                printf("Se excedio el limite de intentos\n\n");
            }else
            {
                if(!getCadena(lastName,51,5,"Ingrese el apellido del empleado: ","Error en la carga del apellido"))
                {
                    printf("Se excedio el limite de intentos\n\n");
                }else
                {
                    if(!getFlotante(&salary,20000,1000000,5,"Ingrese el salario del empleado: ","Error en la carga del salario"))
                    {
                        printf("Se excedio el limite de intentos\n\n");
                    }else
                    {
                        mostrarSectores();
                        if(!getEntero(&sector,100,104,5,"Ingrese sector del empleado: ","Error en la carga del sector"))
                        {
                            printf("Se excedio el limite de intentos\n\n");
                        }
                        formatearSustPropio(name);
                        formatearSustPropio(lastName);
                        strcpy()
                        todoOk=0;
                    }
                }
            }
        }
    }

    return todoOk;


}*/
