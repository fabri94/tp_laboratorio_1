/*
 ============================================================================
 Name        : ABMEmpleados.c
 Author      : Finelli Fabrizio Nicolás
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployee.h"
#include "inputs.h"
#include "dataWarehouse.h"

#define EMP_QTY 1000
#define ASC 1
#define DESC 0

int main(void) {
		setbuf(stdout,NULL);
		Employee employees[EMP_QTY];
		    int nextId=10000;
		    char name[51];
		    char lastName[51];
		    float salary;
		    int sector;

		    char salir='n';
		    char confirma;

		    int empRemove;
		    int order;

		    float totalSalarios=0;
		    float promedioSalarios=0;
		    int contadorEmpleadosMayorAlPromedio=0;

		    int flag=0;

		    if(initEmployees(employees,EMP_QTY)==-1)
		    {
		        printf("Hubo un problema para inicializar los empleados\n");
		    }

		    //hardcodearEmpleados(employees,EMP_QTY,7,&nextId);

		    //printEmployees(employees,EMP_QTY);
		    do
		    {
		        switch(menu())
		        {
		            case 1:
		                if(addEmployees(employees,EMP_QTY,nextId,name,lastName,salary,sector)==-1)
		                {
		                    printf("No se pudo realizar el alta\n");
		                }else
		                {
		                    printf("Alta realizada con exito!!!\n");
		                    flag=1;
		                    nextId++;
		                }
		                system("pause");
		                break;
		            case 2:
		                if(flag)
		                {
		                    printf("   ***Modificar empleado*** \n\n");
		                    if(printEmployees(employees,EMP_QTY)==-1)
		                    {
		                        printf("Hubo un error al querer mostrar los empleados\n");
		                    }
		                    if(!modifyEmployee(employees,EMP_QTY))
		                    {
		                        printf("Hubo un error al querer modificar el empleado\n");
		                    }
		                }else
		                {
		                    printf("No se pueden realizar modificaciones si no hay empleados cargados\n");
		                }
		                system("pause");
		                break;
		            case 3:
		                if(flag)
		                {
		                    printf("  ***Baja empleado*** \n\n");
		                    if(printEmployees(employees,EMP_QTY)==-1)
		                    {
		                        printf("Hubo un error al querer mostrar los empleados\n");
		                    }
		                    printf("\n");
		                    if(!getEntero(&empRemove,10000,10999,5,"Ingrese id del empleado que desea dar de baja: ","Hubo un error con el id ingresado \n\n"))
		                    {
		                        printf("Se excedio el limite de intentos\n");
		                    }else
		                    {
		                        if(removeEmployee(employees,EMP_QTY,empRemove)==-1)
		                        {
		                            printf("Hubo un problema al realizar la baja\n");
		                        }else
		                        {
		                            printf("Baja realizada con exito\n");
		                        }
		                    }
		                }else
		                {
		                    printf("No se pueden realizar bajas si no hay empleados cargados\n");
		                }
		                system("pause");
		                break;
		            case 4:
		                if(flag)
		                {
		                    switch(menuInformes())
		                    {
		                        case 1:
		                        printf("Listado de empleados ordenados alfabeticamente por apellido y sector\n\n");
		                        if(!getEntero(&order,0,1,5,"Ingrese el numero 1 para ordernarlos de forma ascendente, o 0 para ordenarlos de forma descendente: ","Hubo un error en el orden ingresado \n\n"))
		                        {
		                            printf("Se excedio el limite de intentos\n");
		                        }else
		                        {
		                            if(order)
		                            {
		                                if(sortEmployees(employees,EMP_QTY,ASC)==-1)
		                                {
		                                    printf("Hubo un problema al realizar el ordenamiento\n");
		                                }else
		                                {
		                                    if(printEmployees(employees,EMP_QTY)==-1)
		                                    {
		                                        printf("Hubo un error al querer mostrar los empleados\n");
		                                    }
		                                }
		                            }else
		                            {
		                                if(sortEmployees(employees,EMP_QTY,DESC)==-1)
		                                {
		                                    printf("Hubo un problema al realizar el ordenamiento\n");
		                                }else
		                                {
		                                    if(printEmployees(employees,EMP_QTY)==-1)
		                                    {
		                                        printf("Hubo un error al querer mostrar los empleados\n");
		                                    }
		                                }
		                            }
		                        }
		                        break;
		                        case 2:
		                            printf("Total y promedio de los salarios, y cuantos empleados superan el salario promedio\n\n");
		                            calcularTotalYPromedioSalarios(employees,EMP_QTY,&totalSalarios,&promedioSalarios);
		                            printf("Total de salarios: %.2f\n\n",totalSalarios);
		                            printf("Promedio de salarios: %.2f\n\n",promedioSalarios);
		                            contadorDeEmpleadosMayorSalario(employees,EMP_QTY,&promedioSalarios,&contadorEmpleadosMayorAlPromedio);
		                            printf("Cantidad de empleados que superan el salario promedio: %d\n",contadorEmpleadosMayorAlPromedio);
		                            break;
		                    }
		                }else
		                {
		                    printf("No se puede acceder a los informes si no hay empleados cargados\n");
		                }
		                system("pause");
		                break;
		            case 5:
		                printf("¿Esta seguro que desea salir?: ");
		                fflush(stdin);
		                scanf("%c",&confirma);
		                if(confirma=='s')
		                {
		                    salir='s';
		                }
		                break;
		            default:
		                    printf("opcion invalida\n");
		                    system("pause");
		                    break;
		        }


		    }while(salir=='n');

	return EXIT_SUCCESS;
}
