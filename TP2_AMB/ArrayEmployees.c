#include "ArrayEmployees.h"


void initEmployees(Employee* pEmpleados, int QTY_EMPLOYEE)
{
    int i;
    for(i=0; i<QTY_EMPLOYEE; i++)
    {
        pEmpleados[i].isEmpty=LIBRE;
    }
}

int buscarEspacioLibre(Employee* pEmpleados, int QTY_EMPLOYEE)
{
    int indiceVectorLibre=-1;
    int i;

    for(i=0; i<QTY_EMPLOYEE; i++)
    {
        if(pEmpleados[i].isEmpty==LIBRE)
        {
            indiceVectorLibre=i;
            break;
        }

    }

    return indiceVectorLibre;
}

Employee listarEmpleados()
{
    Employee eEmpleado;

    pedirNombreValidarChars(eEmpleado.name, 51);
    pedirApellidoValidarChars(eEmpleado.lastName, 51);
    eEmpleado.salary = pedirFloatPositivo("INGRESE SALARIO");
    eEmpleado.sector = pedirIntRangoMinMax("INGRESE SECTOR", 1, 9999);

    return eEmpleado;
}

int altaEmpleado(Employee* pEmpleados, int QTY_EMPLOYEE)
{
    int index;
    int founded=0;

    index=buscarEspacioLibre(pEmpleados, QTY_EMPLOYEE);

    if(index!=-1)
    {
        system("cls");
        puts("\nINGRESE DATOS DEL PERSONAL\n\n");

        pEmpleados[index]=listarEmpleados();
        pEmpleados[index].isEmpty=OCUPADO;
        pEmpleados[index].id=index+1;

        puts("\n[CARGA EXITOSA] ");
        system("pause");
        system("cls");
        founded=1;
    }
    return founded;
}

int modificarEmployee(Employee* pEmpleados, int QTY_EMPLOYEE)
{
    int flag=0;
    int flagDos=0;
    int eID;
    int i;
    int founded=0;
    int verificar=cantidadEmpleadosTrueFalse(pEmpleados, QTY_EMPLOYEE);

    if (verificar==0)
    {
        system("cls");
        puts("\n[ERROR] NINGUN EMPLEADO PARA MODIFICAR\n\n");
    }

    while(verificar==1&&flag==0)
    {
        flag=1;
        system("cls");
        puts("\nMODIFICAR EMPLEADO\n\n");
        eID=pedirInt("INGRESE LEGAJO A MODIFICAR");
        system("cls");
        printf("\nLEGAJO: N%c %d\n", 248, eID);

        for(i=0; i<QTY_EMPLOYEE; i++)
        {
            if(pEmpleados[i].id==eID&&pEmpleados[i].isEmpty==OCUPADO)
            {
                puts("\n[EXITO] EMPLEADO ENCONTRADO\n");
                switch(imprimirSubMenu())

                {
                case 1:
                    system("cls");
                    pedirNombreValidarChars(pEmpleados[i].name, 51);
                    founded=1;
                    break;
                case 2:
                    system("cls");
                    pedirApellidoValidarChars(pEmpleados[i].lastName, 51);
                    founded=1;
                    break;
                case 3:
                    system("cls");
                    pEmpleados[i].salary=pedirFloat("INGRESE SALARIO");
                    founded=1;
                    break;
                case 4:
                    system("cls");
                    pEmpleados[i].sector=pedirInt("INGRESE SECTOR");
                    founded=1;
                    break;
                case 5:
                    system("cls");
                    pedirNombreValidarChars(pEmpleados[i].name, 51);
                    pedirApellidoValidarChars(pEmpleados[i].lastName, 51);
                    pEmpleados[i].salary = pedirFloat("INGRESE SALARIO: ");
                    pEmpleados[i].sector = pedirInt("INGRESE SECTOR");
                    founded=1;
                    break;
                case 0:
                    puts("\n[EMPLEADO NO MODIFICADO]\n");
                    flagDos=1;
                    break;
                default:
                    puts("\n[ERROR] OPCION NO VALIDA\n");
                    flagDos=1;
                    break;
                }
            }

        }
        if (founded==0&&flagDos==0)
        {
            puts("\n[ERROR] LEGAJO DE EMPLEADO NO ENCONTRADO\n");
            break;
        }
    }
    return founded;
}

int bajaEmployee(Employee* pEmpleados, int QTY_EMPLOYEE)
{
    int flag=0;
    int eID;
    int i;
    int founded=0;
    char confirmar='N';
    int verificar=cantidadEmpleadosTrueFalse(pEmpleados, QTY_EMPLOYEE);

    if (verificar==0)
    {
        system("cls");
        puts("\n[ERROR] NINGUN EMPLEADO PARA DAR DE BAJA\n\n");
    }

    while(verificar==1&&flag==0)
    {
        flag=1;
        system("cls");
        puts("\nBAJA EMPLEADO\n\n");
        eID=pedirInt("INGRESE LEGAJO A DAR DE BAJA");
        system("cls");
        printf("\nLEGAJO: N%c %d\n", 248, eID);

        for(i=0; i<QTY_EMPLOYEE; i++)
        {
            if(pEmpleados[i].id==eID&&pEmpleados[i].isEmpty==OCUPADO)
            {
                puts("\n[EXITO] EMPLEADO ENCONTRADO\n");

                confirmar=pedirConfirmacion("\nSEGURO QUE DESEA ELIMINAR? [S] CONFIRMAR O [SALIR] CUALQUIER TECLA");

                while(confirmar=='S')
                {
                    pEmpleados[i].isEmpty=ELIMINADO;
                    founded=1;
                    puts("\n[BAJA EXITOSA]");
                    break;
                }
                if(founded!=1||confirmar!='S')
                {
                    puts("\n[BAJA CANCELADA] ");
                    founded=1;
                }
            }

        }
        if (founded==0)
        {
            puts("\n[ERROR] LEGAJO DE EMPLEADO NO ENCONTRADO\n");
            break;
        }
    }

    return founded;
}

void ordenarAlfabeticamente(Employee* eEmpleado, int QTY_EMPLOYEE)
{

    int i;
    int j;
    Employee auxEmpleado;

    for(i=0; i<QTY_EMPLOYEE-1; i++)
    {
        for (j=i+1; j<QTY_EMPLOYEE; j++)
        {
            if(strcmp(eEmpleado[i].lastName,eEmpleado[j].lastName)>0)
            {
                auxEmpleado=eEmpleado[i];
                eEmpleado[i]=eEmpleado[j];
                eEmpleado[j]=auxEmpleado;
            }
        }
    }
}

void listarEmployeePrioridadNombre(Employee* eEmpleado, int QTY_EMPLOYEE)
{
    int i;

    for(i=0; i<QTY_EMPLOYEE; i++)
    {
        if(eEmpleado[i].isEmpty==OCUPADO)
        {
            printf("%c %s, %s\t\t\t\t\t%d\n", 250, eEmpleado[i].lastName, eEmpleado[i].name, eEmpleado[i].sector);
        }
    }

}

void listarEmployeePrioridadSector(Employee* pEmpleados, int QTY_EMPLOYEE)
{

    int maxSector=0;
    int i;
    int j;
    int k;
    int flag=0;

    for(i=0; i<QTY_EMPLOYEE; i++)
    {
        if(pEmpleados[i].sector>maxSector&&pEmpleados[i].isEmpty==OCUPADO)
        {
            maxSector=pEmpleados[i].sector;
        }
    }

    for(j=0; j<maxSector; j++)
    {
        flag=0;
        for(k=0; k<QTY_EMPLOYEE; k++)
        {
            if(pEmpleados[k].sector==j&&pEmpleados[j].isEmpty==OCUPADO)
            {
                if(flag==0)
                {
                    printf("\nSECTOR %d\n\n", j);
                    flag=1;
                }
                printf("\n%s, %s", pEmpleados[k].lastName, pEmpleados[k].name);
            }
        }

    }

}

void ordenarAlfabeticamenteListar(Employee* eEmpleado, int QTY_EMPLOYEE)
{

    ordenarAlfabeticamente(eEmpleado, QTY_EMPLOYEE);
    listarEmployeePrioridadNombre(eEmpleado, QTY_EMPLOYEE);

}

int cantidadEmpleados(Employee* pEmpleados, int QTY_EMPLOYEE)
{

    int cantEmpleados=0;
    int i;

    for(i=0; i<QTY_EMPLOYEE; i++)
    {
        if(pEmpleados[i].isEmpty==OCUPADO)
        {
            cantEmpleados++;
        }
    }

    return cantEmpleados;
}

int cantidadEmpleadosTrueFalse(Employee* pEmpleados, int QTY_EMPLOYEE)
{

    int cantEmpleados=0;
    int i;

    for(i=0; i<QTY_EMPLOYEE; i++)
    {
        if(pEmpleados[i].isEmpty==OCUPADO)
        {
            cantEmpleados=1;
            break;
        }
    }

    return cantEmpleados;
}

float salarioTotal(Employee* pEmpleados, int QTY_EMPLOYEE)
{

    int i;
    float acumuladorSalarios=0;

    for(i=0; i<QTY_EMPLOYEE; i++)
    {
        if(pEmpleados[i].isEmpty==OCUPADO)
        {
            acumuladorSalarios=acumuladorSalarios+pEmpleados[i].salary;
        }
    }
    return acumuladorSalarios;
}

float promedioSalarioTotal(Employee* pEmpleados, int QTY_EMPLOYEE)
{

    float promedioSalarios;
    float salariosTotales;
    int cantidadEmp;

    cantidadEmp=cantidadEmpleados(pEmpleados, QTY_EMPLOYEE);
    salariosTotales=salarioTotal(pEmpleados, QTY_EMPLOYEE);

    promedioSalarios=salariosTotales/cantidadEmp;

    return promedioSalarios;
}

void listarEmpleadosSueldoMayorPromedio(Employee* pEmpleados, int QTY_EMPLOYEE, float promedioSalarios)
{

    int i;

    for(i=0; i<QTY_EMPLOYEE; i++)
    {
        if(pEmpleados[i].isEmpty==OCUPADO && pEmpleados[i].salary>=promedioSalarios)
        {
            printf("\n\t[%.2f]\t\t\t[%s, %s]\n", pEmpleados[i].salary, pEmpleados[i].lastName, pEmpleados[i].name);
        }
    }
    puts("\n\n");
    system("pause");
    system("cls");
}

