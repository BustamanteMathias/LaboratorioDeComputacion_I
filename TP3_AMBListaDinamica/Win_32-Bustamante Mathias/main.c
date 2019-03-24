#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

int main()
{
    int option;
    int cantidadLista;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        system("cls");
        cantidadLista=ll_len(listaEmpleados);
        option=menuPrincipal(listaEmpleados);

        switch(option)
        {
        case 0:
            if(getSalida("\nSALIR -> [S] PARA CONFIRMAR [N] PARA CANCELAR: "))
            {
                option=0;
                ll_clear(listaEmpleados);
                ll_deleteLinkedList(listaEmpleados);
            }
            else
            {
                option=1;
            }
            break;

        case 1:

            if(controller_loadFromText("data.csv",listaEmpleados))
            {
                printf("\n[CARGA MODO TEXTO: EXITOSA] ");
            }
            else
            {
                printf("\n[CARGA MODO TEXTO: FALLIDA] ");
            }
            system("pause");
            break;

        case 2:

            if(controller_loadFromBinary("dataBinario.dat",listaEmpleados))
            {
                puts("\n[CARGA MODO BINARIO: EXITOSA]\n");
            }
            else
            {
                puts("\n[CARGA MODO BINARIO: FALLIDA]\n");
            }
            system("pause");
            break;

        case 3:

            if(controller_addEmployee(listaEmpleados))
            {
                puts("\n[CARGA DE EMPLEADO EXITOSA]\n");

            }
            else
            {
                puts("\n[FALLA EN CARGA DE EMPLEADO]\n");
            }
            system("pause");
            break;

        case 4:

            if(controller_editEmployee(listaEmpleados))
            {
                puts("\n[MODIFICACION DE EMPLEADO EXITOSA]\n");
            }

            else
            {
                puts("\n[MODIFICACION DE EMPLEADO FALLIDA]\n");
            }

            system("pause");

            break;

        case 5:

            if(controller_removeEmployee(listaEmpleados))
            {
                puts("\n[BAJA DE EMPLEADO EXITOSA]\n");
            }

            else
            {
                puts("\n[BAJA DE EMPLEADO FALLIDA]\n");
            }

            system("pause");
            break;

        case 6:
            if(cantidadLista==0)
            {
                puts("\n[SIN EMPLEADOS PARA LISTAR]\n");
            }
            else
            {
                if(controller_ListEmployee(listaEmpleados))
                {
                    puts("\n[LISTA IMPRESA CON EXITO]\n");
                }
            }
            system("pause");
            break;

        case 7:
            while(cantidadLista!=0)
            {
                if(controller_sortEmployee(listaEmpleados))
                {
                    puts("\n[LISTA ORDENADA CON EXITO]\n");
                    break;
                }
                else
                {
                    break;
                }
            }
            if (cantidadLista==0)
            {
                puts("\n[SIN EMPLEADOS PARA LISTAR]\n");
            }

            system("pause");
            break;

        case 8:

            if(controller_saveAsText("data.csv", listaEmpleados))
            {
                puts("\n[LISTA GUARDADA CON EXITO]\n");
            }
            else
            {
                puts("\n[GUARDADO CANCELADO]\n");
            }
            system("pause");

            break;

        case 9:
            if(controller_saveAsBinary("dataBinario.dat", listaEmpleados))
            {
                puts("\n[LISTA GUARDADA CON EXITO]\n");
            }
            else
            {
                puts("\n[GUARDADO CANCELADO]\n");
            }
            system("pause");

            break;
        default:
            system("cls");
            puts("\n\n[OPCION NO VALIDA] ");

        }
        system("cls");

    }
    while(option != 0);


    return 0;
}
