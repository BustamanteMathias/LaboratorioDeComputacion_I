#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "string.h"

int parser_EmployeeFromText(FILE* pArchivo, LinkedList* pArrayListEmployee)
{

    Employee* auxEmployee;

    char id[10];
    char nombre[50];
    char horasTrabajadas[10];
    char sueldo[10];

    while(!feof(pArchivo)&&pArrayListEmployee!=NULL)
    {

        auxEmployee=employee_new();

        fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",id, nombre, horasTrabajadas, sueldo);

        auxEmployee=employee_newParametros(id,nombre,horasTrabajadas,sueldo);

        ll_add(pArrayListEmployee,auxEmployee);

        //printf("%d %s %d %d\n", auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
    }
    free(pArchivo);
    return 1;
}

int parser_EmployeeFromBinary(FILE* pArchivo, LinkedList* pArrayListEmployee)
{

    Employee* auxEmployee;

    while(!feof(pArchivo)&&pArrayListEmployee!=NULL)
    {
        auxEmployee=employee_new();
        fread(auxEmployee,sizeof(Employee),1,pArchivo);

        if (feof(pArchivo))
        {
            break;
        }
        else
        {
            ll_add(pArrayListEmployee,auxEmployee);
        }

    }

    free(pArchivo);

    return 1;
}

