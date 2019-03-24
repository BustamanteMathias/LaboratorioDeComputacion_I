#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "UTN_INPUT.h"

float suma (float a, float b)
{
    float resSuma;
    resSuma = a+b;
    return resSuma;
}

float resta (float a, float b)
{
    float resResta;

    resResta = a-b;
    return resResta;
}

float division (float a, float b)
{
    float resDivision;

    /**
    VERIFICACION DE DIVISION POR CERO
        if (b==0)
        {
            printf("%c NO SE PUEDE DIVIDIR POR CERO\n\n",158);
        }*/

    resDivision = (float)a/b;
    return(resDivision);
}

float multiplicacion(float a, float b)
{
    float resMult;
    resMult = a*b;
    return resMult;
}

unsigned long int factorial(int a)
{
    unsigned long int resFactorial;
    while(a>=1)
    {
        if(a==1)
            return 1;
        resFactorial=a* factorial(a-1);
        return (resFactorial);
    }
    return 0;
}


char verificarSN(void)
{
    char letra;
    printf("OPCION NO VALIDA, DESEA CONTINUAR?...S/N?: ");
    letra=toupper(getche());
    while(!((letra=='S')||(letra=='N')))
    {
        printf("\nOPCION NO VALIDA...REINGRESE...(S/N) :");
        letra=toupper(getche());
    }
    system("cls");

    if (letra=='N')
    {
        printf("\n\nAPLICACION TERMINADA POR EL USUARIO!\n");
    }
    return (letra);
}
