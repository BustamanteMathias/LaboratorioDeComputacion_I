#include "Employee.h"
#include "inputsGeneric.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Employee* employee_new()
{
    Employee* pEmployee;
    pEmployee=(Employee*)malloc(sizeof(Employee));

    return pEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* auxEmployee;
    auxEmployee=(Employee*)malloc(sizeof(Employee));

    auxEmployee->id=atoi(idStr);
    strcpy(auxEmployee->nombre,nombreStr);
    auxEmployee->horasTrabajadas=atoi(horasTrabajadasStr);
    auxEmployee->sueldo=atoi(sueldoStr);

    return auxEmployee;
}


int employee_setId(Employee* thisEmployee, int id)
{
    int validacion=0;

    if (validacion==0)
    {
        thisEmployee->id=id;
        validacion=1;
    }

    return validacion;
}


int employee_setNombre(Employee* thisEmployee,char* nombre)
{
    int validacion=0;

    if (validacion==0)
    {
        strcpy(thisEmployee->nombre, nombre);
        validacion=1;
    }

    return validacion;
}


int employee_setHorasTrabajadas(Employee* thisEmployee,int horasTrabajadas)
{
    int validacion=0;

    if (validacion==0)
    {
        thisEmployee->horasTrabajadas=horasTrabajadas;
        validacion=1;
    }

    return validacion;
}


int employee_setSueldo(Employee* thisEmployee,int sueldo)
{
    int validacion=0;

    if (validacion==0)
    {
        thisEmployee->sueldo=sueldo;
        validacion=1;
    }

    return validacion;
}


int subMenu()
{
    int opcion;
    printf("[MODIFICAR]\n\n");
    printf(" 1 ID\n\n");
    printf(" 2 NOMBRE\n\n");
    printf(" 3 HORAS TRABAJADAS\n\n");
    printf(" 4 SUELDO\n\n");
    printf(" 5 TODOS LOS CAMPOS ANTERIORES\n\n");

    printf("\n CUALQUIER TECLA PARA SALIR\n\n");

    printf("\n %c OPCION ELEGIDA: ", 254);
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}


int funcionEmploye(Employee* eEmployee)
{
    int retorno=0;
    int index;
    int i;

    index=5;
    for (i=0; i<100; i++)
    {
        if(eEmployee[i].id==index)
        {
            printf("ENCONTRO");
            retorno=i;
            break;
        }
        else
        {
            printf("NO ENCONTRO");
        }
    }
    return retorno;
}

int ordenar_prioridadNombre(void* eEmployeeUno, void* eEmployeeDos)
{
    int retorno;
    Employee* pEmployeeUno=(Employee*)eEmployeeUno;
    Employee* pEmployeeDos=(Employee*)eEmployeeDos;


    /**RETORNA 1=nombreDos MAYOR, 0=IGUALES, -1=nombreUno MAYOR*/
    retorno=strcmp(pEmployeeUno->nombre, pEmployeeDos->nombre);

    return retorno;
}


int ordenar_prioridadID(void* eEmployeeUno, void* eEmployeeDos)
{
    int retorno;
    Employee* pEmployeeUno=(Employee*)eEmployeeUno;
    Employee* pEmployeeDos=(Employee*)eEmployeeDos;


    /**RETORNA 1=idDos MAYOR, 0=IGUALES, -1=idUno MAYOR*/
    if(pEmployeeUno->id>pEmployeeDos->id)
    {
        retorno=1;
    }
    else if(pEmployeeUno->id<pEmployeeDos->id)
    {
        retorno=-1;
    }
    else
    {
        retorno=0;
    }

    return retorno;
}


int ordenar_prioridadSueldo(void* eEmployeeUno, void* eEmployeeDos)
{
    int retorno;
    Employee* pEmployeeUno=(Employee*)eEmployeeUno;
    Employee* pEmployeeDos=(Employee*)eEmployeeDos;


    /**RETORNA 1=sueldoDos MAYOR, 0=IGUALES, -1=idUno MAYOR*/
    if(pEmployeeUno->sueldo>pEmployeeDos->sueldo)
    {
        retorno=1;
    }
    else if(pEmployeeUno->sueldo<pEmployeeDos->sueldo)
    {
        retorno=-1;
    }
    else
    {
        retorno=0;
    }

    return retorno;
}

int ordenar_prioridadHorasTrabajadas(void* eEmployeeUno, void* eEmployeeDos)
{
    int retorno;
    Employee* pEmployeeUno=(Employee*)eEmployeeUno;
    Employee* pEmployeeDos=(Employee*)eEmployeeDos;


    /**RETORNA 1=idDos MAYOR, 0=IGUALES, -1=idUno MAYOR*/
    if(pEmployeeUno->id>pEmployeeDos->id)
    {
        retorno=1;
    }
    else if(pEmployeeUno->id<pEmployeeDos->id)
    {
        retorno=-1;
    }
    else
    {
        retorno=0;
    }

    return retorno;
}
