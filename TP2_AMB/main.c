#include "ArrayEmployees.h"
#define QTY_EMPLOYEE 1000

int main()
{
    char seguir = 'S';
    float totalSalarios;
    float promedioSalarios;

    Employee eEmpleados [QTY_EMPLOYEE];
    initEmployees(eEmpleados, QTY_EMPLOYEE);

    do
    {
        switch(imprimirMenu())
        {
        case 0:
            return 0;
            break;

        case 1:
            altaEmpleado(eEmpleados, QTY_EMPLOYEE);
            break;

        case 2:
            if(modificarEmployee(eEmpleados, QTY_EMPLOYEE))
            {
                puts("\n[MODIFICACION EXITOSA] ");
                system("pause");
                system("cls");
            }
            else
            {
                system("pause");
                system("cls");
            }
            break;

        case 3:
            if(bajaEmployee(eEmpleados, QTY_EMPLOYEE))
            {
                system("pause");
                system("cls");
            }
            else
            {
                system("pause");
                system("cls");
            }
            break;

        case 4:
            system("cls");
            if(cantidadEmpleadosTrueFalse(eEmpleados, QTY_EMPLOYEE))
            {
                puts("\nLISTADO DE EMPLEADOS\n\n");
                printf("%s\t\t\t\t\t%s\n\n", "[EMPLEADO]", "[SECTOR]");

                ordenarAlfabeticamenteListar(eEmpleados, QTY_EMPLOYEE);

                totalSalarios=salarioTotal(eEmpleados, QTY_EMPLOYEE);
                promedioSalarios=promedioSalarioTotal(eEmpleados, QTY_EMPLOYEE);

                puts("\nTOTAL Y PROMEDIO DE SUELDOS\n\n");
                printf("%s [%.2f]\n%s [%.2f]\n\n", "TOTAL DE SALARIOS", totalSalarios, "PROMEDIO DE SALARIOS",promedioSalarios);
                puts("\n\tEMPLEADOS QUE SUPERAN EL PROMEDIO\n\n");
                puts("\t[SALARIO]\t\t\t[EMPLEADO]\n\n");
                listarEmpleadosSueldoMayorPromedio(eEmpleados, QTY_EMPLOYEE, promedioSalarios);
            }
            else
            {
                puts("\n[ERROR] SIN EMPLEADOS PARA INFORMAR\n\n");
                system("pause");
                system("cls");
            }
            break;

        default:
            puts("\n   [ERROR] OPCION NO VALIDA. REINGRESE.\n");
            system("pause");
            system("cls");
            break;
        }
    }
    while(seguir=='S');

    return 0;
}
