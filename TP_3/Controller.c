#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "inputs.h"
#include "menu.h"
#define INTENTOS 5

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    FILE* pFile=NULL;

    if(path!=NULL&&pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"r");
        if(pFile==NULL)
        {
            printf("No se pudo abrir el archivo.\n");
        }
        else
        {
            if(parser_EmployeeFromText(pFile,pArrayListEmployee))
            {
                todoOk=1;
            }
        }
        fclose(pFile);
    }
    return todoOk;
}


int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    FILE* pFile=NULL;

    if(path!=NULL&&pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"rb");
        if(pFile==NULL)
        {
            printf("No se pudo abrir el archivo.\n");
        }
        else
        {
            if(parser_EmployeeFromBinary(pFile,pArrayListEmployee))
            {
                todoOk=1;
            }
        }
        fclose(pFile);
    }
    return todoOk;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int nextId;
    char nombre[128];
    int horas;
    int sueldo;
    Employee* auxEmpleado=NULL;
    int todoOk=0;
    if(pArrayListEmployee!=NULL)
    {
        employee_buscarMayorId(pArrayListEmployee,&nextId);
        if(!getCadena(nombre, 128, INTENTOS, "Ingrese el nombre: ", "Error."))
        {
            printf("Ha excedido el limite de intentos.\n\n");
        }
        else
        {
            if (!getEntero(&sueldo, 1, 10000000, INTENTOS, "Ingrese el salario: ", "Error. "))
            {
                printf("Ha excedido el limite de intentos.\n\n");
            }
            else
            {

                if (!getEntero(&horas, 1, 10000, INTENTOS, "Ingrese horas trabajadas: ", "Error. "))
                {
                    printf("Ha excedido el limite de intentos.\n\n");
                }
                else
                {
                    formatearSustPropio(nombre);
                    auxEmpleado=employee_new();
                    if(employee_setId(auxEmpleado, nextId)&&
                            employee_setNombre(auxEmpleado,nombre)&&
                            employee_setHorasTrabajadas(auxEmpleado,horas)&&
                            employee_setSueldo(auxEmpleado,sueldo))
                    {
                        ll_add(pArrayListEmployee,auxEmpleado);
                        todoOk = 1;
                    }
                    else
                    {
                        employee_delete(auxEmpleado);
                    }
                }
            }
        }
    }
    return todoOk;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int id;
    char nombre[128];
    int horas;
    int sueldo;
    int auxId;
    int len;
    int opcion;
    Employee* auxEmpleado=NULL;
    if(pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        if(len>0)
        {
            if(getEntero(&id, 1, 10000, INTENTOS, "Ingrese ID del empleado que desae modificar: ", "Error. \n"))
            {
                for(int i=0;i<len;i++)
                {
                    auxEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
                    if(employee_getId(auxEmpleado,&auxId))
                    {
                        if(auxId==id)
                        {
                            if( employee_getNombre(auxEmpleado,nombre) &&
                                    employee_getHorasTrabajadas(auxEmpleado,&horas) &&
                                    employee_getSueldo(auxEmpleado,&sueldo))
                            {

                                menuModificaciones();
                                printf("  ID     NOMBRE        HORAS      SUELDO\n");
                                printf(" %04d    %-15s%-3d      %d\n\n", id, nombre, horas, sueldo);
                                if (!getEntero(&opcion, 1, 5, 3, "Ingrese opcion del dato que desea modificar: ", "Error. \n"))
                                {
                                    printf("Ha excedido el limite de intentos.\n");
                                }

                                switch(opcion)
                                {
                                case 1:
                                    printf("Nombre a modificar: %s\n", auxEmpleado->nombre);
                                    if (getCadena(nombre, 128, INTENTOS, "Ingrese el nuevo nombre: ", "Error. \n"))
                                    {
                                        formatearSustPropio(nombre);
                                        strcpy(auxEmpleado->nombre,nombre);
                                        printf("Nombre modificado con exito!\n");
                                        todoOk = 1;
                                    }
                                    else
                                    {
                                        printf("No se pudo modificar el nombre.\n");
                                    }
                                    break;

                                case 2:
                                    printf("Horas trabajadas a modificar: %d\n", auxEmpleado->horasTrabajadas);
                                    if(getEntero(&horas, 1, 10000, INTENTOS,"Ingrese la cantidad de horas: ", "Error. \n"))
                                    {
                                        auxEmpleado->horasTrabajadas=horas;
                                        printf("Horas modificadas con exito!\n");
                                        todoOk = 1;
                                    }
                                    else
                                    {
                                        printf("No se pudo modificar las horas trabajadas.\n");
                                    }
                                    break;

                                case 3:
                                    printf("Sueldo a modificar: %d\n",auxEmpleado->sueldo);
                                    if(getEntero(&sueldo, 1, 1000000, INTENTOS, "Ingrese el nuevo sueldo: ", "Error. \n"))
                                    {
                                        auxEmpleado->sueldo=sueldo;
                                        printf("Sueldo modificado con exito!\n");
                                        todoOk = 1;
                                    }
                                    else
                                    {
                                        printf("No se pudo modificar el sueldo.\n");
                                    }
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        else
        {
            printf("\nNo se puede modificar un empleado sin al menos haber dado de alta uno.\n\n");
        }
    }

    return todoOk;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int len;
    int todoOk=0;
    int id;
    int auxId;
    char respuesta;
    char nombre[128];
    int horas;
    int sueldo;
    Employee* auxEmpleado=NULL;

    if(pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        if(len>0)
        {
            controller_ListEmployee(pArrayListEmployee);
            if(getEntero(&id, 1, 10000, INTENTOS, "Ingrese ID del empleado que desea eliminar: ", "Error. \n"))
            {
                for(int i=0;i<len;i++)
                {
                    auxEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
                    if(employee_getId(auxEmpleado,&auxId))
                    {
                        if(auxId==id)
                        {
                            if(employee_getNombre(auxEmpleado, nombre)&&
                                    employee_getHorasTrabajadas(auxEmpleado, &horas)&&
                                    employee_getSueldo(auxEmpleado, &sueldo))
                            {
                                printf("\n  ID     NOMBRE        HORAS      SUELDO\n");
                                printf(" %04d    %-15s%-3d      %d\n\n", id, nombre, horas, sueldo);
                                if (!getLetra(&respuesta, INTENTOS, "¿Esta seguro que quiere eliminar este empleado? 's' para si, 'n' para no ", "Error. "))
                                {
                                    printf("Ha excedido el limite de intentos.\n");
                                }
                                else
                                {
                                    if(respuesta=='s')
                                    {
                                        ll_remove(pArrayListEmployee, i);
                                        todoOk =1;
                                    }

                                }

                            }
                        }
                    }
                }
            }
        }
        else
        {
            printf("\nNo se puede dar de baja un empleado sin haber dado de alta al menos uno.\n\n");
        }
    }
    return todoOk;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{

    int id;
    char nombre[128];
    int horas;
    int sueldo;
    int cantEmpleados=0;
    int todoOk =0;
    Employee* auxEmpleado;

    if(pArrayListEmployee!=NULL)
    {
        printf("--------- LISTADO DE EMPLEADOS ---------\n");
        printf("  ID     NOMBRE        HORAS      SUELDO\n");
        printf("----------------------------------------\n");
        int len=ll_len(pArrayListEmployee);

        for(int i=0;i<len;i++)
        {
            auxEmpleado=(Employee*)ll_get(pArrayListEmployee, i);
            if(employee_getId(auxEmpleado, &id) &&
                    employee_getNombre(auxEmpleado, nombre) &&
                    employee_getHorasTrabajadas(auxEmpleado, &horas) &&
                    employee_getSueldo(auxEmpleado, &sueldo))
            {
                printf(" %04d    %-15s%-3d      %d\n", id, nombre, horas, sueldo);
                cantEmpleados++;
            }
        }
        if(cantEmpleados==len)
        {
            todoOk=1;
        }
    }
    return todoOk;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    int len = ll_len(pArrayListEmployee);
    Employee* auxEmpleado1=NULL;
    Employee* auxEmpleado2=NULL;
    char nombre1[128];
    char nombre2[128];

    if(pArrayListEmployee!=NULL)
    {

        for (int i=0;i<len-1;i++)
        {
            for (int j=i+1;j<len;j++)
            {
                auxEmpleado1=ll_get(pArrayListEmployee, i);
                auxEmpleado2=ll_get(pArrayListEmployee, j);

                if(auxEmpleado1!=NULL&&auxEmpleado2!=NULL)
                {
                    if(employee_getNombre(auxEmpleado1, nombre1)&&
                            employee_getNombre(auxEmpleado2, nombre2))
                    {
                        if (strcmp(nombre1,nombre2)>0)
                        {
                            ll_set(pArrayListEmployee,i,auxEmpleado2);
                            ll_set(pArrayListEmployee,j,auxEmpleado1);
                            todoOk=1;
                        }
                    }
                }
            }
        }
    }
    return todoOk;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    char respuesta='s';
    int id;
    char nombre[128];
    int horas;
    int sueldo;
    Employee* auxEmpleado;
    FILE* pFile=NULL;
    int cantCargados=0;

    if(path!=NULL&&pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"r");
        if(pFile!=NULL)
        {
            if(!getLetra(&respuesta, INTENTOS, "¿Este archivo ya existe. Desea sobreescribirlo? 's' para si, 'n' para no", "Error. \n"))
            {
                printf("Ha exedido el limite de intentos.\n");
                respuesta='n';
            }
            fclose(pFile);
        }

        if(respuesta!='n')
        {
            pFile=fopen(path, "w");
            if(pFile==NULL)
            {
                printf("No se pudo abrir el archivo.\n");
            }
            else
            {
                fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
                for(int i=0; i< ll_len(pArrayListEmployee); i++)
                {
                    auxEmpleado=(Employee*)ll_get(pArrayListEmployee, i);
                    if(auxEmpleado!=NULL)
                    {
                        if(employee_getId(auxEmpleado,&id) &&
                                employee_getNombre(auxEmpleado,nombre) &&
                                employee_getHorasTrabajadas(auxEmpleado, &horas) &&
                                employee_getSueldo(auxEmpleado, &sueldo))
                        {
                            fprintf(pFile, "%d,%s,%d,%d\n", id, nombre, horas, sueldo);
                            cantCargados++;
                        }
                    }
                }
                if(cantCargados==ll_len(pArrayListEmployee))
                {
                    todoOk = 1;
                }

            }
        }
        fclose(pFile);
    }
    return todoOk;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    char respuesta='n';
    Employee* auxEmpleado;
    FILE* pFile=NULL;
    int cantCargados=0;

    if(path!=NULL&&pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"rb");
        if(pFile!=NULL)
        {
            if(!getLetra(&respuesta, INTENTOS, "¿Este archivo ya existe. Desea sobreescribirlo? 's' para si, 'n' para no.", "Error. \n"))
            {
                printf("Ha exedido el limite de intentos.\n");
                respuesta='s';
            }
            fclose(pFile);
        }

        if(respuesta!='s')
        {
            pFile=fopen(path, "wb");
            if(pFile==NULL)
            {
                printf("No se pudo abrir el archivo.\n");
            }
            else
            {
                for(int i=0;i<ll_len(pArrayListEmployee);i++)
                {
                    auxEmpleado=(Employee*)ll_get(pArrayListEmployee, i);
                    if(auxEmpleado!=NULL)
                    {
                        if(fwrite(auxEmpleado,sizeof(Employee),1, pFile)==1)
                        {
                            cantCargados++;
                        }

                    }
                }
                if(cantCargados==ll_len(pArrayListEmployee))
                {
                    todoOk = 1;
                }

            }
        }
        fclose(pFile);
    }
    return todoOk;
}

