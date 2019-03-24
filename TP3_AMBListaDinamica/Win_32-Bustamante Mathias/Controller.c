#include "Controller.h"
#include "Employee.h"

int tamLista(LinkedList* listaEmpleados)
{
    int tamLista;
    tamLista=ll_len(listaEmpleados);

    return tamLista;
}


int menuPrincipal(LinkedList* listaEmpleados)
{
    int opcion;
    int lista;

    lista=tamLista(listaEmpleados);
    printf("\n TRABAJO PRACTICO N3\n\n CANTIDAD EN LISTA: %d\n", lista);

    printf("\nOPC\n\n");
    printf(" 1 CARGAR DATOS DE EMPLEADOS MODO: TEXTO\n");
    printf(" 2 CARGAR DATOS DE EMPLEADOS MODO: BINARIO\n\n");
    printf("   EMPLEADOS\n\n");
    printf(" 3 ALTA\n");
    printf(" 4 MODIFICACION\n");
    printf(" 5 BAJA\n");
    printf(" 6 LISTAR EMPLEADOS\n");
    printf(" 7 ORDENAR EMPLEADOS\n\n");
    printf(" 8 GUARDAR DATOS DE EMPLEADOS MODO: TEXTO\n");
    printf(" 9 GUARDAR DATOS DE EMPLEADOS MODO: BINARIO\n\n");
    printf(" 0 [SALIR]\n\n");
    printf("%c  OPCION ELEGIDA: ", 254);
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}


int subMenuDoss()
{
    int opcion;

    system("cls");
    printf("[ORDENAR POR CRITERIO]\n\n");
    printf(" 1 ID [MENOR-MAYOR]\n\n");
    printf(" 2 ID [MAYOR-MENOR]\n\n");
    printf(" 3 NOMBRE [A-Z]\n\n");
    printf(" 4 NOMBRE [Z-A]\n\n");
    printf(" 5 HORAS TRABAJADAS [MENOR-MAYOR]\n\n");
    printf(" 6 HORAS TRABAJADAS [MAYOR-MENOR]\n\n");
    printf(" 7 SUELDO [MENOR-MAYOR]\n\n");
    printf(" 8 SUELDO [MAYOR-MENOR]\n\n");
    printf("\n 0 PARA SALIR\n\n");

    printf("\n %c OPCION ELEGIDA: ", 254);
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    pArchivo=fopen(path,"r");
    int estado=0;

    if(pArchivo==NULL)
    {
        system("cls");
        printf("NO EXISTE EL ARCHIVO\n");
        system("pause");
        system("cls");
    }
    else
    {
        estado = parser_EmployeeFromText(pArchivo,pArrayListEmployee);
    }

    return estado;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    pArchivo=fopen(path,"rb");

    int estado=0;

    if(pArchivo==NULL)
    {
        system("cls");
        printf("NO EXISTE EL ARCHIVO\n");
        system("pause");
        system("cls");
    }
    else
    {
        estado = parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);
    }

    return estado;
}


int controller_validarID(LinkedList* thisLinkedList, int busquedaID)
{
    int i;
    int estado=1;
    Employee* auxEmployee;
    auxEmployee=employee_new();

    for(i=0; i<ll_len(thisLinkedList); i++)
    {
        auxEmployee=ll_get(thisLinkedList, i);
        if(auxEmployee->id==busquedaID)
        {
            estado=0;
            break;
        }
    }
    return estado;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    int id;
    int estadoID;
    int estadoCarga=0;
    int flag=0;

    Employee* auxEmployee;
    auxEmployee=employee_new();

    system("cls");

    do
    {
        id=getInt("INGRESE ID PARA EMPLEADO: ");
        if(controller_validarID(pArrayListEmployee,id))
        {
            employee_setId(auxEmployee, id);
            estadoID=1;
        }
        else
        {
            if(getContinuar("\n[ERROR] ID YA EXISTENTE [S] REINGRESAR - [N] SALIR: "))
            {
                system("cls");
                printf("\nRE");
                estadoID=0;
            }
            else
            {
                estadoID=2;
            }
        }
    }
    while(estadoID==0);


    while(estadoID==1&&flag==0)
    {

        system("cls");
        printf("[ID VALIDO]\n");
        printf("\nALTA EMPLEADO [ ID - %d ]\n\n", auxEmployee->id);
        getName(nombre,128);
        horasTrabajadas=getInt("INGRESE HORAS: ");
        sueldo=getInt("INGRESE SUELDO: ");

        employee_setNombre(auxEmployee, nombre);
        employee_setHorasTrabajadas(auxEmployee, horasTrabajadas);
        employee_setSueldo(auxEmployee, sueldo);
        system("cls");


        ll_add(pArrayListEmployee,auxEmployee);
        printf("\n\n[INFORMACION DE EMPLEADO]\n");
        printf("\nID: %d\nNOMBRE: %s\nHORAS TRABAJADAS: %d\nSUELDO: %d\n\n", auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);

        estadoCarga=1;
        flag=1;
    }

    return estadoCarga;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int busquedaID;
    int opcionSubMenu;
    int estado=0;
    int horasTrabajadas;
    int sueldo;
    char nombre[128];
    int auxHorasTrabajadas;
    int auxSueldo;
    char auxNombre[128];
    int i;
    int encontro=0;
    int flag=0;
    int id;
    int auxID;
    int cantidadLista;

    system("cls");

    cantidadLista=ll_len(pArrayListEmployee);

    if (cantidadLista==0)
    {
        puts("\n[SIN EMPLEADOS PARA DAR DE BAJA]\n");
    }
    else
    {
        busquedaID=getInt("INGRESE ID A MODIFICAR: ");
        auxEmployee=employee_new();

        for(i=0; i<tamLista(pArrayListEmployee); i++)
        {
            auxEmployee=ll_get(pArrayListEmployee, i);
            if(auxEmployee->id==busquedaID)
            {
                encontro=1;
                break;
            }
        }
        if (encontro==0)
        {
            printf("\n[EMPLEADO NO ENCONTRADO]");
        }
        while(encontro==1 && flag==0)
        {
            printf("\n\n[EMPLEADO ENCONTRADO]");
            printf("\n\n ID: %d\n NOMBRE: %s\n HORAS TRABAJADAS: %d\n SUELDO: %d\n\n", auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);

            opcionSubMenu=subMenu();

            switch(opcionSubMenu)
            {

            case 1:
                //id
                id=auxEmployee->id;
                auxID=getInt("INGRESE NUEVO ID: ");

                printf("\n\nDESEA CAMBIAR EL ID DE '%d' POR '%d'", id, auxID);
                if(getContinuar("\n[S] CONFIRMAR [N] CANCELAR: "))
                {
                    employee_setId(auxEmployee,auxID);
                    ll_set(pArrayListEmployee, busquedaID, auxEmployee);
                    flag=1;
                }
                else
                {
                    system("pause");
                }
                break;

            case 2:
                //NOMBRE
                strcpy(nombre, auxEmployee->nombre);
                getName(auxNombre,128);

                printf("\n\nDESEA CAMBIAR EL NOMBRE '%s' POR '%s'", nombre, auxNombre);
                if(getContinuar("\n[S] CONFIRMAR [N] CANCELAR: "))
                {
                    employee_setNombre(auxEmployee,auxNombre);
                    ll_set(pArrayListEmployee, busquedaID, auxEmployee);
                    flag=1;
                }
                else
                {
                    system("pause");
                }

                break;
            case 3:
                //horas
                horasTrabajadas=auxEmployee->horasTrabajadas;
                auxHorasTrabajadas=getInt("INGRESE HORAS TRABAJADAS: ");


                printf("\n\nDESEA CAMBIAR LAS HORAS TRABAJADAS '%d' POR '%d'", horasTrabajadas, auxHorasTrabajadas);
                if(getContinuar("\n[S] CONFIRMAR [N] CANCELAR: "))
                {
                    employee_setHorasTrabajadas(auxEmployee,auxHorasTrabajadas);
                    ll_set(pArrayListEmployee, busquedaID, auxEmployee);
                    flag=1;
                }
                else
                {
                    system("pause");
                }

                break;
            case 4:
                //sueldo
                sueldo=auxEmployee->sueldo;
                auxSueldo=getInt("INGRESE SUELDO: ");

                printf("\n\nDESEA CAMBIAR EL SUELDO DE '%d' por '%d'", sueldo, auxSueldo);
                if(getContinuar("\n[S] CONFIRMAR [N] CANCELAR: "))
                {
                    employee_setSueldo(auxEmployee,auxSueldo);
                    ll_set(pArrayListEmployee, busquedaID, auxEmployee);
                    flag=1;
                }
                else
                {
                    system("pause");
                }
                break;

            case 5:
                printf("\n FALTA PONER TODO CUANDO LO VALIDE");
                break;

            default:
                flag=1;
                printf("\n\n[MODIFICACION CANCELADA] ");
                break;
            }

            estado=1;

        }

        system("pause");
        system("cls");
    }

    return estado;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int busquedaIndex;
    int encontro=0;
    int flag=0;
    Employee* auxEmployee;

    system("cls");
    if(tamLista(pArrayListEmployee)==0)
    {
        {
            puts("\n[SIN EMPLEADOS PARA DAR DE BAJA]\n");
            encontro=0;
        }
    }
    else
    {
        busquedaIndex=getInt("INGRESE ID A ELIMINAR: ");
        auxEmployee=employee_new();

        for(i=0; i<tamLista(pArrayListEmployee); i++)
        {
            auxEmployee=ll_get(pArrayListEmployee, i);
            if(auxEmployee->id==busquedaIndex)
            {
                encontro=1;
                break;
            }
        }
        if (encontro==0)
        {
            printf("\n[EMPLEADO NO ENCONTRADO]");
        }

        while(encontro==1&&flag==0)
        {
            printf("\n\n[EMPLEADO ENCONTRADO]");
            printf("\n\n ID: %d\n NOMBRE: %s\n HORAS TRABAJADAS: %d\n SUELDO: %d", auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
            printf("\n\nDESEA ELIMINARLO?");

            if(getContinuar("\n[S] PARA CONTINUAR [N] PARA CANCELAR: "))
            {
                ll_remove(pArrayListEmployee, i);
                flag=1;
            }
            else
            {
                flag=1;
                encontro=0;
                printf("\nBAJA CANCELADA]");
                system("pause");

            }
        }
    }

    return encontro;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int control=0;

    Employee* auxEmployee;
    auxEmployee=employee_new();

    system("cls");
    puts("LISTA DE EPMPLEADOS\n\n\n");
    puts(" [ID]\t[NOMBRE]\t[HS TRABAJADAS]\t\t[SUELDO]\n\n");

    for(i=0; i<tamLista(pArrayListEmployee); i++)
    {
        auxEmployee=ll_get(pArrayListEmployee, i);
        printf("%d\t%s\t\t%d\t%d\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
        control++;
        if (control==500)
        {
            control=0;
            system("pause");
        }
    }
    return 1;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int estado=0;
    LinkedList* clonLinkedList;
    clonLinkedList=ll_clone(pArrayListEmployee);

    switch(subMenuDoss())
    {
        system("cls");
    case 0:
        estado=0;
        break;
    case 1:
        puts("\n[ORDENANDO]... \n\n");
        ll_sort(clonLinkedList,ordenar_prioridadID,1);
        controller_ListEmployee(clonLinkedList);
        estado=1;
        break;
    case 2:
        puts("\n[ORDENANDO]... \n\n");
        ll_sort(clonLinkedList,ordenar_prioridadID,0);
        controller_ListEmployee(clonLinkedList);
        estado=1;
        break;
    case 3:
        puts("\n[ORDENANDO]... \n\n");
        ll_sort(clonLinkedList,ordenar_prioridadNombre,1);
        controller_ListEmployee(clonLinkedList);
        estado=1;
        break;
    case 4:
        puts("\n[ORDENANDO]... \n\n");
        ll_sort(clonLinkedList,ordenar_prioridadNombre,0);
        controller_ListEmployee(clonLinkedList);
        estado=1;
        break;
    case 5:
        puts("\n[ORDENANDO]... \n\n");
        ll_sort(clonLinkedList,ordenar_prioridadHorasTrabajadas,1);
        controller_ListEmployee(clonLinkedList);
        estado=1;
        break;
    case 6:
        puts("\n[ORDENANDO]... \n\n");
        ll_sort(clonLinkedList,ordenar_prioridadHorasTrabajadas,0);
        controller_ListEmployee(clonLinkedList);
        estado=1;
        break;
    case 7:
        puts("\n[ORDENANDO]... \n\n");
        ll_sort(clonLinkedList,ordenar_prioridadSueldo,1);
        controller_ListEmployee(clonLinkedList);
        estado=1;
        break;
    case 8:
        puts("\n[ORDENANDO]... \n\n");
        ll_sort(clonLinkedList,ordenar_prioridadSueldo,0);
        controller_ListEmployee(clonLinkedList);
        estado=1;
        break;
    default:
        puts("\n[OPCION NO VALIDA]");
        break;
    }

    ll_clear(clonLinkedList);
    ll_deleteLinkedList(clonLinkedList);

    return estado;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int i;
    int cantidadLista;
    int carga;

    FILE* pArchivo;
    pArchivo=fopen(path, "w");

    Employee* auxEmployee;
    auxEmployee=employee_new();

    system("cls");
    cantidadLista=ll_len(pArrayListEmployee);

    puts("\nGUARDAR LISTA ACTUAL [MODO TEXTO]\n\n");

    if(cantidadLista==0)
    {
        puts("\n[LISTA VACIA]\n");
    }

    if(getContinuar("\nSI CONTINUA SE REEMPLAZARA EL ARCHIVO EXISTENTE. CONTINUAR [S] CANCELAR [N]: "))
    {
        for(i=0; i<tamLista(pArrayListEmployee); i++)
        {
            auxEmployee=ll_get(pArrayListEmployee, i);
            fprintf(pArchivo, "%d,",auxEmployee->id);
            fprintf(pArchivo, "%s,",auxEmployee->nombre);
            fprintf(pArchivo, "%d,",auxEmployee->horasTrabajadas);
            fprintf(pArchivo, "%d\n",auxEmployee->sueldo);
        }
        carga=1;
    }
    else
    {
        carga=0;
    }

    fclose(pArchivo);

    return carga;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int carga;
    int i;
    int cantidadLista;

    FILE* pArchivo;
    pArchivo=fopen(path, "wb");    //WB escribir binario

    Employee* auxEmployee;
    auxEmployee=employee_new();

    cantidadLista=ll_len(pArrayListEmployee);

    system("cls");

    puts("\nGUARDAR LISTA ACTUAL [MODO BINARIO]\n\n");

    if(cantidadLista==0)
    {
        puts("\n[LISTA VACIA]\n");
    }
    if(getContinuar("\nSI CONTINUA SE REEMPLAZARA EL ARCHIVO EXISTENTE. CONTINUAR [S] CANCELAR [N]: "))
    {
        for(i=0; i<tamLista(pArrayListEmployee); i++)
        {
            auxEmployee=ll_get(pArrayListEmployee, i);
            fwrite(auxEmployee,sizeof(Employee),1,pArchivo);
        }
        carga=1;
    }
    else
    {
        carga=0;
    }

    fclose(pArchivo);

    return carga;
}

