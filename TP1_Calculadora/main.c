#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "UTN_INPUT.h"


int main()
{
    char seguir='S';
    float operandoUno=0, operandoDos=0,resSuma,resResta,resMultiplicacion,resDivision;
    unsigned long int resFactorialA, resFactorialB;
    int opcion;

    while(seguir=='S')
    {
        printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
        printf("\t%c MENU CALCULADORA %c\n",186,186);
        printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
        printf("1- INGRESAR 1er OPERANDO (A=%.2f)\n",operandoUno);
        printf("2- INGRESAR 2do OPERANDO (B=%.2f)\n\n",operandoDos);
        printf("3- CALCULAR TODAS LAS OPERACIONES\n\n");
        printf("   %cSUMA (A+B)\n",250);
        printf("   %cRESTA (A-B)\n",250);
        printf("   %cDIVISION (A/B)\n",250);
        printf("   %cMULTIPLICACION (A*B)\n",250);
        printf("   %cFACTORIAL (A! & B!)\n\n",250);
        printf("4- IMPRIMIR RESULTADO DE TODAS LAS OPERACIONES ANTERIORES\n\n\n");
        printf("0- SALIR\n\n");
        printf("%c  OPCION ELEGIDA: ", 254);
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {

        case 0:
            seguir = 'N';
            break;

        case 1:                                     /**PRIMERO OPERANDO1*/
            printf("\nINGRESE 1er OPERANDO: ");
            fflush(stdin);
            scanf("%f",&operandoUno);
            system("cls");
            break;

        case 2:
            printf("\nINGRESE 2do OPERANDO: ");     /**SEGUNDO OPERANDO*/
            fflush(stdin);
            scanf("%f",&operandoDos);
            system("cls");
            break;

        case 3:
            /**CALCULOS DE TODAS LAS OPERACIONES*/
            system("cls");
            resSuma=suma(operandoUno,operandoDos);
            resResta=resta(operandoUno,operandoDos);
            resMultiplicacion=multiplicacion(operandoUno,operandoDos);
            resDivision=division(operandoUno,operandoDos);
            resFactorialA=factorial(operandoUno);
            resFactorialB=factorial(operandoDos);
            printf("...SE CALCULARON TODAS LAS OPERACIONES PARA A=%.2f Y B=%.2f\n\n",operandoUno,operandoDos);
            break;
        case 4:

            system("cls");

            printf("\t RESULTADO DE TODAS LAS OPERACIONES PARA A=%.2f Y B=%.2f\n\n\n",operandoUno,operandoDos);

            //SUMA
            printf("EL RESULTADO DE (A+B) ES: %.2f\n\n", resSuma);
            //RESTA
            printf("EL RESULTADO DE (A-B) ES: %.2f\n\n", resResta);
            //DIVISION
            if (operandoDos==0)
            {
                printf("%c NO SE PUEDE DIVIDIR POR CERO\n\n",158);
            }
            else
            {
                printf("EL RESULTADO DE (A/B) ES: %.2f\n\n", resDivision);
            }
            //MULTIPLICACION
            printf("EL RESULTADO DE (A*B) ES: %.2f\n\n", resMultiplicacion);
            //FACTORIAL DE A
            if (operandoUno<1)  /**VERIFICA QUE EL ENTERO SEA MAYOR A 0, SI NO ES ASI, IMPRIME EN PANTALLA EL ERROR*/
            {
                printf("%c EL FACTORIAL DE |A| NO SE APLICA PORQUE EL NUMERO ES MENOR A 1\n\n",158);
            }
            else if (operandoUno>16)
            {
                printf("%c EL FACTORIAL DE |A| NO SE APLICA PORQUE SU RESULTADO ES MUY GRANDE, MAXIMO 16\n\n",158);
            }
            else
            {
                printf("EL RESULTADO DEL FACTORIAL DE |A| ES: %ld\n\n", resFactorialA);
            }
            //FACTORIAL DE B
            if (operandoDos<1)  /**VERIFICA QUE EL ENTERO SEA MAYOR A 0, SI NO ES ASI, IMPRIME EN PANTALLA EL ERROR*/
            {
                printf("%c EL FACTORIAL DE |B| NO SE APLICO PORQUE EL NUMERO ES MENOR A 1\n\n\n",158);
            }
            else if (operandoDos>16)
            {
                printf("%c EL FACTORIAL DE |B| NO SE APLICO PORQUE SU RESULTADO ES MUY GRANDE, MAXIMO 16\n\n",158);
            }
            else
            {
                printf("EL RESULTADO DEL FACTORIAL DE |B| ES: %ld\n\n\n", resFactorialB);
            }
            system("pause");
            system("cls");
            break;

        default:
            system("cls");
            seguir=verificarSN();
        }
    }

    return 0;
}
