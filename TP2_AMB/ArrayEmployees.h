#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "UTN_INPUTS.h"

#define LIBRE 0
#define OCUPADO 1
#define ELIMINADO -1


/**EMTRUCTURA DEL TIPO EMPLEADO-EMPLOYEE*/
/** \brief
ESTRUCTURA PARA UN EMPLEADO CON
ID=LEGAJO
NAME=NOMBRE
LASTNAME=APELLIDO
SALARY=SALARIO
SECTOR=SECTOR DE EMPLEO
ISEMPITY=TOMA VALORES PARA SABER SU ESTADO, EN ESTE CASO ESTRUCTURA LIBRE, OCUPADA O ELIMINADA
 */
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;

/********************************************************************************************/

/** \brief RECORRE TODAS LAS ESTRUCTURAS DE EMPLOYEE E INICIA SUS ESTADOS EN LIBRE PARA SU FUTURO USO, SOLO UNA VEZ AL INICIAR EL PROGRAMA
 *
 * \param Employee* ESTRUCTURA DE EMPLOYEE
 * \param int CANTIDAD DE ESTRUCTURAS A RECORRER
 * \return void
 *
 */
void initEmployees(Employee*, int);

/** \brief RECORRE LA ESTRUCTURA EN BUSCA DE UN ESPACIO LIBRE, AL ENCONTRARLO ROMPE LA BUSQUEDA Y DEVUELVE EL PRIMER INDICE LIBRE PARA SU USO
 *
 * \param Employee* ESTRUCTURA DE EMPLOYEE
 * \param int CANTIDAD DE ESTRUCTURAS A RECORRER
 * \return int RETORNA EL INDICE DEL ARRAY LIBRE PARA SU USO
 *
 */
int buscarEspacioLibre(Employee*, int);

/** \brief DA DE ALTA A UN EMPLOYEE, USA LISTAREMPLEADOS PARA LLENAR LOS PARAMETROS DEL ARRAY, DA UN LEGAJO AUTOMATICO Y CAMBIA SU ESTADO A OCUPADO
 *
 * \param Employee* ESTRUCTURA DE EMPLOYEE
 * \param int CANTIDAD DE ESTRUCTURAS A RECORRER
 * \return int RETORNA 0 SI LA CARGA NO FUE EXITOSA O 1 SI SE DIO DE ALTA CORRECTAMENTE
 *
 */
int altaEmpleado(Employee*, int);

/** \brief LLENA LOS CAMPOS DEL EMPLEADO QUE INGRESA EL USUARIO
 *
 * \return Employee RETORNA LOS DATOS DE LA ESTRUCTURA YA CARGADOS
 *
 */
Employee listarEmpleados();

/** \brief PIDE LEGAJO A MODIFICAR
 *
 * \param Employee* ESTRUCTURA DE EMPLOYEE
 * \param int CANTIDAD DE ESTRUCTURAS A RECORRER
 * \return int RETORNA 0 SI LA MODIFICACION NO FUE EXITOSA O 1 SI SE MODIFICO CORRECTAMENTE
 *
 */
int modificarEmployee(Employee*, int);

/** \brief PIDE LEGAJO A DAR DE BAJA Y CAMBIA SU ESTADO DE OCUPADO A ELIMINADO, PERO NO LO BORRA DEL SISTEMA
 *
 * \param Employee* ESTRUCTURA DE EMPLOYEE
 * \param int CANTIDAD DE ESTRUCTURAS A RECORRER
 * \return int RETORNA 0 SI LA BAJA NO FUE EXITOSA O 1 SI SE DIO DE BAJA CORRECTAMENTE
 *
 */
int bajaEmployee(Employee*, int);

/** \brief RECORRE TODAS LAS ESTRUCTURAS OCUPADAS Y LOS ORDENA POR APELLIDO
 *
 * \param Employee* ESTRUCTURA DE EMPLOYEE
 * \param int CANTIDAD DE ESTRUCTURAS A RECORRER
 * \return void
 *
 */
void ordenarAlfabeticamente(Employee*, int);

/** \brief RECORRE LOS EMPLOYEE CON ESTADO OCUPADO Y LOS ORDENA ALFABETICAMENTE
 *
 * \param Employee* ESTRUCTURA DE EMPLOYEE
 * \param int CANTIDAD DE ESTRUCTURAS A RECORRER
 * \return void
 *
 */
void listarEmployeePrioridadNombre(Employee*, int);

/** \brief RECORRE LOS EMPLOYEE CON ESTADO OCUPADO Y LOS ORDENA POR SECTOR
 *
 * \param Employee* ESTRUCTURA DE EMPLOYEE
 * \param int CANTIDAD DE ESTRUCTURAS A RECORRER
 * \return void
 *
 */
void listarEmployeePrioridadSector(Employee*, int);

/** \brief RECORRE LOS EMPLOYEE CON ESTADO OCUPADO, LOS ORDENA ALFABETICAMENTE Y LOS IMPRIME POR CONSOLA
 *
 * \param Employee* ESTRUCTURA DE EMPLOYEE
 * \param int CANTIDAD DE ESTRUCTURAS A RECORRER
 * \return void
 *
 */
void ordenarAlfabeticamenteListar(Employee*, int);

/** \brief RECORRE TODAS LAS ESTRUCTURAS PARA SABER LA CANTIDAD DE EMPLEADOS OCUPADOS QUE HAY EN EL SISTEMA
 *
 * \param Employee* ESTRUCTURA DE EMPLOYEE
 * \param int CANTIDAD DE ESTRUCTURAS A RECORRER
 * \return int RETORNA LA CANTIDAD DE EMPLEADOS ENCONTRADOS
 *
 */
int cantidadEmpleados(Employee*, int);

/** \brief RECORRE TODAS LAS ESTRUCTURAS PARA SABER LA CANTIDAD DE EMPLEADOS OCUPADOS QUE HAY EN EL SISTEMA
 *
 * \param Employee* ESTRUCTURA DE EMPLOYEE
 * \param int CANTIDAD DE ESTRUCTURAS A RECORRER
 * \return int RETORNA 0 SI NO ENCONTRO EMPLEADOS DADOS DE ALTA O 1 SI HAY ALGUN EMPLEADO EN EL SISTEMA
 * (PUEDE HABER EMPLOYEE ELIMINADOS QUE SIGUEN ESTANDO EN SISTEMA PERO SOLO VALIDA SOLO EN EMPLOYEE DADOS DE ALTA)
 */
int cantidadEmpleadosTrueFalse(Employee*, int);

/** \brief RECORRE TODAS LAS ESTRUCTURAS EN ALTA Y ACUMULA LOS SALARIOS
 *
 * \param Employee* ESTRUCTURA DE EMPLOYEE
 * \param int CANTIDAD DE ESTRUCTURAS A RECORRER
 * \return float RETORNA ACUMULACION TOTAL DE LOS SALARIOS
 *
 */
float salarioTotal(Employee*, int);

/** \brief RECORRE TODAS LAS ESTRUCTURAS EN ALTA, ACUMULA LOS SALARIOS, CALCULA LA CANTIDAD DE USUARIOS TOTAL Y SACA UN PROMEDIO DE SALARIOS
 *
 * \param Employee* ESTRUCTURA DE EMPLOYEE
 * \param int CANTIDAD DE ESTRUCTURAS A RECORRER
 * \return float RETORNA PROMEDIO DE SALARIOS SOBRE EL TOTAL DE LOS EMPLEADOS EN ALTA
 *
 */
float promedioSalarioTotal(Employee*, int);

/** \brief  RECIBE EL PROMEDIO DE SUELDOS Y RECORRE LOS EMPLEADOS BUSCANDO QUE SU SUELDO SUPERE AL PROMEDIO, DESPUES LOS IMPRIME EN PANTALLA
 *
 * \param Employee* ESTRUCTURA DE EMPLOYEE
 * \param int CANTIDAD DE ESTRUCTURAS A RECORRER
 * \param float RECIBE PROMEDIO DE SALARIOS
 * \return void
 *
 */
void listarEmpleadosSueldoMayorPromedio(Employee*, int, float);
