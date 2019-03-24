#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "UTN_INPUTS.h"

void pedirNombre(char* nombre, int TAM)
{
    char buffer[1000];
    int maximosCharParaVerificar=TAM;

    printf("INGRESE NOMBRE: ");
    fflush(stdin);
    gets(buffer);

    while(strlen(buffer)>maximosCharParaVerificar||strlen(buffer)<1)
    {
        system("cls");
        printf("\n[ERROR 1 a %d CARACTERES MAX] REINGRESE NOMBRE: ", maximosCharParaVerificar-1);
        fflush(stdin);
        gets(buffer);

    }
    strlwr(buffer);//PASO TODO A MINUSCULA
    buffer[0]=toupper(buffer[0]); //CONVIERTO PRIMER CARACTER EN MAYUSCULA
    strcpy (nombre, buffer);//DESCARGO EL BUFFER EN EL NOMBRE
}

void pedirApellido(char* apellido, int TAM)
{
    char buffer[1000];
    int maximosCharParaVerificar=TAM;

    printf("INGRESE APELLIDO: ");
    fflush(stdin);
    gets(buffer);

    while(strlen(buffer)>maximosCharParaVerificar||strlen(buffer)<1)
    {
        system("cls");
        printf("\n[ERROR 1 a %d CARACTERES MAX] REINGRESE APELLIDO: ", maximosCharParaVerificar-1);
        fflush(stdin);
        gets(buffer);

    }
    strlwr(buffer);//PASO TODO A MINUSCULA
    buffer[0]=toupper(buffer[0]); //CONVIERTO PRIMER CARACTER EN MAYUSCULA
    strcpy (apellido, buffer);//COMO SALI DESCARGO EL BUFFER EN EL NOMBRE

}

int validarChars(char* nombreParaValidar)
{
    int i=0, retornoValidacion=0, j;

    j=strlen(nombreParaValidar);

    while (i<j && retornoValidacion==0)
    {
        if (isalpha(nombreParaValidar[i])!=0)
        {
            i++;
        }
        else
        {
            retornoValidacion=1;
            system("cls");
            printf("\n[ERROR SOLO CARACTERES ALFABETICOS] RE");
        }
    }
    return retornoValidacion;
}

void pedirNombreValidarChars(char* nombre, int TAM)
{
    int validar=0;
    do
    {
        pedirNombre(nombre, TAM);
        validar=validarChars(nombre);
    }
    while (validar!=0);

}

void pedirApellidoValidarChars(char* apellido, int TAM)
{
    int validar=0;
    do
    {
        pedirApellido(apellido, TAM);
        validar=validarChars(apellido);
    }
    while (validar!=0);

}

int imprimirMenu()
{
    int opcion;
    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
           201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("\n\t%cTRABAJO PRACTICO N%c2 %c ADMINISTRAR EMPLEADOS%c\n",186,248,186,186);
    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n\n",
           200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    printf(" 1 ALTA DE EMPLEADO\n\n");
    printf(" 2 MODIFICAR EMPLEADO\n\n");
    printf(" 3 BAJA DE EMPLEADO\n\n");
    printf(" 4 INFORMAR\n\n");
    printf("   %cLISTADO DE EMPLEADOS POR NOMBRE Y SECTOR\n",250);
    printf("   %cTOTAL Y PROMEDIO DE LOS SALARIOS/EMPLEADOS QUE SUPERAN EL SUELDO PROMEDIO\n\n\n",250);
    printf("\n 0 SALIR\n\n");
    printf("\n %c OPCION ELEGIDA: ", 254);
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}

int imprimirSubMenu()
{
    int opcion;

    printf("\tELIJA OPCION PARA MODIFICAR EMPLEADO\n\n");
    printf(" 1 NOMBRE\n\n");
    printf(" 2 APELLIDO\n\n");
    printf(" 3 SALARIO\n\n");
    printf(" 4 SECTOR\n\n");
    printf(" 5 MODIFICAR TODOS LOS CAMPOS\n\n\n");
    printf(" 0 SALIR\n\n");
    printf("\n%c  OPCION ELEGIDA: ", 254);
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}

int validarNumeroExcluyeSignos(char* numero)
{
    int i=0, retornoValidacion=0, j;

    j=strlen(numero);
    while (i<j && retornoValidacion==0)
    {
        if (isdigit(numero[i])!=0||numero[i]=='.'||numero[i]==','||numero[i]=='-')
        {
            i++;
        }
        else
        {
            retornoValidacion=1;
        }
    }
    return retornoValidacion;
}

int validarNumero(char* numero)
{
    int i=0, retornoValidacion=0, j;

    j=strlen(numero);
    while (i<j && retornoValidacion==0)
    {
        if (isdigit(numero[i])!=0)
        {
            i++;
        }
        else
        {
            retornoValidacion=1;
        }
    }
    return retornoValidacion;
}

void concatenarNombreApellido(char* nombreCompleto, char* cadenaApellido, char*cadenaNombre)
{
    int i;

    /** FORMATO "Apellido, Nombre" */

    strcpy(nombreCompleto, cadenaApellido);
    strcat(nombreCompleto, ", ");
    strcat(nombreCompleto, cadenaNombre);

    strlwr(nombreCompleto); //CONVIERTE TODA LA CADENA A MINUSCULA

    nombreCompleto[0]=toupper(nombreCompleto[0]);

    for(i=0; i<strlen(nombreCompleto); i++)
    {
        if (isspace(nombreCompleto[i])) //(nombreCompleto[i]==' ')
        {
            nombreCompleto[i+1]=toupper(nombreCompleto[i+1]);//PASA EN MAYUSCULA EL CARACTER DESPUES DEL ESPACIO
        }
    }
}

int pedirInt(const char* MSJ)
{
    int valorInt;
    char buffer[30];

    printf("%s: ", MSJ);
    fflush(stdin);
    gets(buffer);

    while(validarNumero(buffer)==1)
    {
        printf("[ERROR] REINGRESE NUMERO: ");
        fflush(stdin);
        gets(buffer);
    }

    valorInt=atoi(buffer);

    return valorInt;
}

float pedirFloat(const char* MSJ)
{

    float valorFlotante;
    char buffer[30];

    printf("%s: ", MSJ);
    fflush(stdin);
    gets(buffer);

    while(validarNumeroExcluyeSignos(buffer)==1)
    {
        printf("[ERROR] REINGRESE NUMERO: ");
        fflush(stdin);
        gets(buffer);
    }

    valorFlotante=atof(buffer);

    return valorFlotante;
}

char pedirChar(const char* MSJ)
{
    char letra, buffer[1000];

    printf("%s: ", MSJ);
    fflush(stdin);
    gets(buffer);

    while(strlen(buffer)!=1)
    {
        printf("[ERROR]SOLO UNA LETRA. REINGRESE: ");
        fflush(stdin);
        gets(buffer);
    }
    buffer[0]=toupper(buffer[0]); //CONVIERTO PRIMER CARACTER EN MAYUSCULA
    letra=buffer[0];

    return letra;
}

char pedirConfirmacion(const char* MSJ)
{
    char confirmar;
    confirmar=pedirChar(MSJ);
    //confirmar=strlwr(confirmar); PASA A MINUSCULA

    return confirmar;
}

void pedirCadena(char* cadena, int TAM)
{
    char buffer[1000];
    int maximosCharParaVerificar=TAM;

    printf("INGRESE NOMBRE: ");
    fflush(stdin);
    gets(buffer);

    while(strlen(buffer)>maximosCharParaVerificar||strlen(buffer)<1)
    {
        system("cls");
        printf("\n[ERROR 1 a %d CARACTERES MAX] REINGRESE NOMBRE: ", maximosCharParaVerificar);
        fflush(stdin);
        gets(buffer);

    }
    strlwr(buffer);//PASO TODO A MINUSCULA
    buffer[0]=toupper(buffer[0]); //CONVIERTO PRIMER CARACTER EN MAYUSCULA
    strcpy (cadena, buffer);//DESCARGO EL BUFFER EN EL NOMBRE
}

int pedirIntRangoMinMax(const char* MSJ, int valorMinimo, int valorMaximo)
{

    int valorInt;
    char buffer[30];

    do
    {
        printf("%s: ", MSJ);
        fflush(stdin);
        gets(buffer);

        while(validarNumero(buffer)==1)
        {
            printf("[ERROR] REINGRESE NUMERO: ");
            fflush(stdin);
            gets(buffer);
            system("cls");
        }

        valorInt=atoi(buffer);

        if(valorInt<valorMinimo||valorInt>valorMaximo)
        {
            printf("[ERROR] VALORES ENTRE [%d-%d]\n", valorMinimo, valorMaximo);
            system("pause");
            system("cls");
        }

    }
    while(valorInt<valorMinimo||valorInt>valorMaximo);

    return valorInt;
}

float pedirFloatPositivo(const char* MSJ)
{

    float valorFlotante;
    char buffer[30];

    do
    {
        printf("%s: ", MSJ);
        fflush(stdin);
        gets(buffer);

        while(validarNumeroExcluyeSignos(buffer)==1)
        {
            printf("[ERROR] REINGRESE NUMERO: ");
            fflush(stdin);
            gets(buffer);
            system("cls");
        }

        valorFlotante=atof(buffer);

        if(valorFlotante<0)
        {
            puts("[ERROR] VALOR SOLO POSITIVO\n");
            system("pause");
            system("cls");
        }

    }
    while(valorFlotante<0);

    return valorFlotante;
}

