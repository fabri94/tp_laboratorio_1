#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
int todoOk =0;
    int cant;
    char buffer[4][20];
    Employee* nuevoEmpleado;
    if(pFile!=NULL&&pArrayListEmployee!=NULL)
    {
        while(!feof(pFile))
        {
            cant=fscanf(pFile, "%[^,],%[^,],%[^,],%s",buffer[0],buffer[1],buffer[2],buffer[3]);
            if(cant==4)
            {
                nuevoEmpleado=employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
                if(nuevoEmpleado!=NULL)
                {
                    ll_add(pArrayListEmployee, nuevoEmpleado);
                    todoOk=1;
                }
              else
                {
                    employee_delete(nuevoEmpleado);
                }
            }
        }
    }
    return todoOk;
}


int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk =0;
    Employee* nuevoEmpleado=NULL;

    if(pFile!=NULL&&pArrayListEmployee!=NULL)
    {
        while(!feof(pFile))
        {
            nuevoEmpleado=employee_new();
            if(nuevoEmpleado!=NULL)
            {
                if(fread(nuevoEmpleado,sizeof(Employee),1, pFile)== 1)
                {
                    ll_add(pArrayListEmployee, nuevoEmpleado);
                    todoOk=1;
                }
              else
                {
                    employee_delete(nuevoEmpleado);
                }
            }
        }
    }
    return todoOk;
}
