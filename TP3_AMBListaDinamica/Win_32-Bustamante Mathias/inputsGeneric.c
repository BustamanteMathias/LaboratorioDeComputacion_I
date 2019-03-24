#include "inputsGeneric.h"

int getMenu()
{
    system("cls");
    int opcion;

    printf("\n\tMENU\n\n");

    printf(" 1 \n\n");
    printf(" 2 \n\n");
    printf(" 3 \n\n");
    printf(" 4 \n\n");
    printf("\n\n");

    printf("\n 0 SALIR\n\n");

    printf("\n %c OPCION ELEGIDA: ", 254);
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

int subMenuUno()
{
    int opcion;

    printf(" 1\n\n");

    printf("\n 0 VOLVER ATRAS\n\n");

    printf("\n %c OPCION ELEGIDA: ", 254);
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

int subMenuDos()
{
    int opcion;

    printf(" 1 \n\n");

    printf("\n 0 VOLVER ATRAS\n\n");

    printf("\n %c OPCION ELEGIDA: ", 254);
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

void getName(char* pName, int TAM)
{
    char buffer[1000];
    int maximoChars=TAM;
    int validarSoloLetras;

    do
    {
        validarSoloLetras=0;

        printf("INGRESE NOMBRE: ");
        fflush(stdin);
        gets(buffer);

        while(strlen(buffer)>maximoChars||strlen(buffer)<1)
        {
            system("cls");
            printf("\n[ERROR 1 a %d CARACTERES MAX] REINGRESE NOMBRE: ", maximoChars);
            fflush(stdin);
            gets(buffer);
        }

        if(validarString(buffer))
        {
            strlwr(buffer);//PASO TODO A MINUSCULA
            buffer[0]=toupper(buffer[0]); //CONVIERTO PRIMER CARACTER EN MAYUSCULA
            strcpy(pName, buffer);//DESCARGO EL BUFFER EN EL NOMBRE
        }
        else
        {
            system("cls");
            validarSoloLetras=1;
            printf("\n[ERROR. CARACTERES INVALIDOS] RE");
        }
    }
    while(validarSoloLetras!=0);
}

int getNameConRetorno(char* pName, int TAM)
{
    char buffer[1000];
    int maximoChars=TAM;
    int validarSoloLetras=0;
    int cargaCorrecta=0;

    do
    {
        printf("INGRESE NOMBRE: ");
        fflush(stdin);
        gets(buffer);

        while(strlen(buffer)>maximoChars||strlen(buffer)<1)
        {
            system("cls");
            printf("\n[ERROR 1 a %d CARACTERES MAX] REINGRESE NOMBRE: ", maximoChars);
            fflush(stdin);
            gets(buffer);
        }

        if(validarString(buffer))
        {
            strlwr(buffer);//PASO TODO A MINUSCULA
            buffer[0]=toupper(buffer[0]); //CONVIERTO PRIMER CARACTER EN MAYUSCULA
            strcpy(pName, buffer);//DESCARGO EL BUFFER EN EL NOMBRE
            cargaCorrecta=1;
        }
        else
        {
            system("cls");
            validarSoloLetras=1;
            printf("\n[ERROR. CARACTERES INVALIDOS] RE");
        }
    }
    while(validarSoloLetras!=0);

    return cargaCorrecta;
}

void getLastName(char* pLastName, int TAM)
{
    char buffer[1000];
    int maximoChars=TAM;
    int validarSoloLetras=0;

    do
    {
        printf("INGRESE APELLIDO: ");
        fflush(stdin);
        gets(buffer);

        while(strlen(buffer)>maximoChars||strlen(buffer)<1)
        {
            system("cls");
            printf("\n[ERROR 1 a %d CARACTERES MAX] REINGRESE APELLIDO: ", maximoChars);
            fflush(stdin);
            gets(buffer);
        }

        if(validarString(buffer))
        {
            strlwr(buffer);//PASO TODO A MINUSCULA
            buffer[0]=toupper(buffer[0]); //CONVIERTO PRIMER CARACTER EN MAYUSCULA
            strcpy(pLastName, buffer);//DESCARGO EL BUFFER EN EL NOMBRE
        }
        else
        {
            system("cls");
            validarSoloLetras=1;
            printf("\n[ERROR. CARACTERES INVALIDOS] RE");
        }

    }
    while(validarSoloLetras!=0);
}

int getLastNameConRetorno(char* pLastName, int TAM)
{
    char buffer[1000];
    int maximoChars=TAM;
    int validarSoloLetras=0;
    int cargaCorrecta=0;

    do
    {
        printf("INGRESE APELLIDO: ");
        fflush(stdin);
        gets(buffer);

        while(strlen(buffer)>maximoChars||strlen(buffer)<1)
        {
            system("cls");
            printf("\n[ERROR 1 a %d CARACTERES MAX] REINGRESE APELLIDO: ", maximoChars);
            fflush(stdin);
            gets(buffer);
        }

        if(validarString(buffer))
        {
            strlwr(buffer);//PASO TODO A MINUSCULA
            buffer[0]=toupper(buffer[0]); //CONVIERTO PRIMER CARACTER EN MAYUSCULA
            strcpy(pLastName, buffer);//DESCARGO EL BUFFER EN EL NOMBRE
            cargaCorrecta=1;
        }
        else
        {
            system("cls");
            validarSoloLetras=1;
            printf("\n[ERROR. CARACTERES INVALIDOS] RE");
        }

    }
    while(validarSoloLetras!=0);

    return cargaCorrecta;
}

int validarString(char* pString)
{
    int i=0;
    int j;
    int retornoValidacion=1; /** 1=CHAR VALIDO || 0=CHAR INVALIDO*/

    j=strlen(pString);

    while (i<j && retornoValidacion==1)
    {
        if (isalpha(pString[i])!=0)
        {
            i++;
        }
        else
        {
            retornoValidacion=0;
            break;
        }
    }
    return retornoValidacion;
}

int getStringConRetorno(char* pString, int TAM)
{

    char buffer[1000];
    int maximoChars=TAM;
    int cargaCorrecta=0;

    printf("INGRESE TEXTO: ");
    fflush(stdin);
    gets(buffer);

    while(strlen(buffer)>maximoChars||strlen(buffer)<1)
    {
        system("cls");
        printf("\n[ERROR 1 a %d CARACTERES MAX] REINGRESE TEXTO: ", maximoChars);
        fflush(stdin);
        gets(buffer);
    }

    strlwr(buffer);//PASO TODO A MINUSCULA
    buffer[0]=toupper(buffer[0]); //CONVIERTO PRIMER CARACTER EN MAYUSCULA
    strcpy(pString, buffer);//DESCARGO EL BUFFER EN EL NOMBRE
    cargaCorrecta=1;

    return cargaCorrecta;
}

int getInt(const char* MSJ)
{
    int valorInt;
    char buffer[30];

    printf("%s", MSJ);
    fflush(stdin);
    gets(buffer);

    while(validarNumero(buffer)==1)
    {
        printf("[ERROR] RE%s", MSJ);
        fflush(stdin);
        gets(buffer);
    }

    valorInt=atoi(buffer);

    return valorInt;
}

int validarNumero(char* pBuffer)
{
    int i=0;
    int j;
    int retornoValidacion=0;

    j=strlen(pBuffer);

    while (i<j && retornoValidacion==0)
    {
        if (isdigit(pBuffer[i])!=0)
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

void concatenarNombreApellido(char* pNombreCompleto, char* pStringLastName, char*pStringName)
{
    int i;

    /** FORMATO "Apellido, Nombre" */

    strcpy(pNombreCompleto, pStringLastName);
    strcat(pNombreCompleto, ", ");
    strcat(pNombreCompleto, pStringName);

    strlwr(pNombreCompleto); //CONVIERTE TODA LA CADENA A MINUSCULA

    pNombreCompleto[0]=toupper(pNombreCompleto[0]);

    for(i=0; i<strlen(pNombreCompleto); i++)
    {
        if (isspace(pNombreCompleto[i])) //(pNombreCompleto[i]==' ')
        {
            pNombreCompleto[i+1]=toupper(pNombreCompleto[i+1]);//PASA EN MAYUSCULA EL CARACTER DESPUES DEL ESPACIO
        }
    }
}

int validarNumeroConSignos(char* pBuffer)
{
    int i=0;
    int j;
    int retornoValidacion=0;
    int acumuladorSignos=0;
    int acumuladorSignosNegativos=0;

    j=strlen(pBuffer);

    while (i<j && retornoValidacion==0)
    {
        if (isdigit(pBuffer[i])!=0||pBuffer[i]=='.'||pBuffer[i]==','||pBuffer[i]=='-')
        {
            if(pBuffer[i]=='.'||pBuffer[i]==',')
            {
                acumuladorSignos++;
            }
            if (pBuffer[i]=='-')
            {
                acumuladorSignosNegativos++;
            }
            if(acumuladorSignos>1||acumuladorSignosNegativos>1)
            {
                retornoValidacion=1;
                break;
            }
            i++;
        }
        else
        {
            retornoValidacion=1;
        }
    }
    return retornoValidacion;
}

float getFloat(const char* MSJ)
{

    float valorFlotante;
    char buffer[30];

    printf("%s", MSJ);
    fflush(stdin);
    gets(buffer);

    while(validarNumeroConSignos(buffer)==1)
    {
        printf("[ERROR] RE%s", MSJ);
        fflush(stdin);
        gets(buffer);
    }

    valorFlotante=atof(buffer);

    return valorFlotante;
}

char getChar(const char* MSJ)
{
    char letra;
    char buffer[1000];

    printf("%s", MSJ);
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

void getCuit(const char* MSJ, char* pCUIT)
{
    char buffer[1000];
    char auxUno[10];
    char auxDos[10];
    char auxTres[10];
    int bufferUno;
    int bufferDos;
    int bufferTres;

    system("cls");
    puts(MSJ);
    puts("PRIMEROS DOS DIGITOS\n\n20, 23, 24 Y 27 PARA PESONAS FISICAS\n30, 33 Y 34 PARA EMPRESAS\n");
    puts("\n[XX]-XXXXXXXX-X\n");
    printf("\n%c ", 254);
    bufferUno=getInt("INGRESE DIGITOS: ");

    while(bufferUno!=20&&bufferUno!=23&&bufferUno!=24&&bufferUno!=27&&bufferUno!=30&&bufferUno!=33&&bufferUno!=34)
    {
        system("cls");
        puts(MSJ);
        puts("PRIMEROS DOS DIGITOS\n20, 23, 24 Y 27 PESONAS FISICAS\n30, 33 Y 34 EMPRESAS\n\n");
        puts("\n[XX]-XXXXXXXX-X\n");
        bufferUno=getInt("\n[ERROR] REINGRESE DIGITOS: ");
    }

    system("cls");
    puts(MSJ);
    puts("\nNUMERO DE SOCIEDAD PARA EMPRESAS O DNI PARA PESONAS FISICAS [7-8 DIGITOS] \n");
    printf("\n%d-[XXXXXXXX]-X\n", bufferUno);
    printf("\n%c ", 254);
    bufferDos=getInt("INGRESE DIGITOS: ");

    while(bufferDos<1000000||bufferDos>100000000)
    {
        system("cls");
        puts(MSJ);
        puts("\nNUMERO DE SOCIEDAD PARA EMPRESAS O DNI PARA PESONAS FISICAS\n");
        printf("\n%d-[XXXXXXXX]-X\n", bufferUno);
        bufferDos=getInt("\n[ERROR] REINGRESE DIGITOS: ");
    }

    system("cls");
    puts(MSJ);
    puts("\nNUMERO VERIFICADOR\n");
    printf("\n%d-%d-[X]\n", bufferUno, bufferDos);
    printf("\n%c ", 254);
    bufferTres=getInt("INGRESE DIGITO: ");

    while(bufferTres<0||bufferTres>9)
    {
        system("cls");
        puts(MSJ);
        puts("\nNUMERO VERIFICADOR\n");
        printf("\n%d-%d-[X]\n", bufferUno, bufferDos);
        bufferTres=getInt("\n[ERROR] REINGRESE DIGITO: ");
    }

    system("cls");

    itoa(bufferUno,auxUno,10);
    itoa(bufferDos,auxDos,10);
    itoa(bufferTres,auxTres,10);

    strcpy(buffer, auxUno);
    strcat(buffer, "-");
    strcat(buffer, auxDos);
    strcat(buffer, "-");
    strcat(buffer, auxTres);

    strcpy(pCUIT, buffer);

    printf("\n[CARGA EXITOSA] CUIT: %s\n\n", pCUIT);

    system("pause");
    system("cls");
}

int getCuitConRetorno(const char* MSJ, char* pCUIL)
{
    char buffer[1000];
    char auxUno[10];
    char auxDos[10];
    char auxTres[10];
    int bufferUno;
    int bufferDos;
    int bufferTres;
    int retorno=0;

    system("cls");
    puts(MSJ);
    puts("PRIMEROS DOS DIGITOS\n\n20, 23, 24 Y 27 PARA PESONAS FISICAS\n30, 33 Y 34 PARA EMPRESAS\n");
    puts("\n[XX]-XXXXXXXX-X\n");
    printf("\n%c ", 254);
    bufferUno=getInt("INGRESE DIGITOS: ");

    while(bufferUno!=20&&bufferUno!=23&&bufferUno!=24&&bufferUno!=27&&bufferUno!=30&&bufferUno!=33&&bufferUno!=34)
    {
        system("cls");
        puts(MSJ);
        puts("PRIMEROS DOS DIGITOS\n20, 23, 24 Y 27 PESONAS FISICAS\n30, 33 Y 34 EMPRESAS\n\n");
        puts("\n[XX]-XXXXXXXX-X\n");
        bufferUno=getInt("\n[ERROR] REINGRESE DIGITOS: ");
    }

    system("cls");
    puts(MSJ);
    puts("\nNUMERO DE SOCIEDAD PARA EMPRESAS O DNI PARA PESONAS FISICAS [7-8 DIGITOS] \n");
    printf("\n%d-[XXXXXXXX]-X\n", bufferUno);
    printf("\n%c ", 254);
    bufferDos=getInt("INGRESE DIGITOS: ");

    while(bufferDos<1000000||bufferDos>100000000)
    {
        system("cls");
        puts(MSJ);
        puts("\nNUMERO DE SOCIEDAD PARA EMPRESAS O DNI PARA PESONAS FISICAS\n");
        printf("\n%d-[XXXXXXXX]-X\n", bufferUno);
        bufferDos=getInt("\n[ERROR] REINGRESE DIGITOS: ");
    }

    system("cls");
    puts(MSJ);
    puts("\nNUMERO VERIFICADOR\n");
    printf("\n%d-%d-[X]\n", bufferUno, bufferDos);
    printf("\n%c ", 254);
    bufferTres=getInt("INGRESE DIGITO: ");

    while(bufferTres<0||bufferTres>9)
    {
        system("cls");
        puts(MSJ);
        puts("\nNUMERO VERIFICADOR\n");
        printf("\n%d-%d-[X]\n", bufferUno, bufferDos);
        bufferTres=getInt("\n[ERROR] REINGRESE DIGITO: ");
    }

    system("cls");

    itoa(bufferUno,auxUno,10);
    itoa(bufferDos,auxDos,10);
    itoa(bufferTres,auxTres,10);

    strcpy(buffer, auxUno);
    strcat(buffer, "-");
    strcat(buffer, auxDos);
    strcat(buffer, "-");
    strcat(buffer, auxTres);

    strcpy(pCUIL, buffer);

    retorno=1;

    system("pause");
    system("cls");

    return retorno;
}

void getCuil(const char* MSJ, char* pCUIL)
{
    char buffer[1000];
    char auxUno[10];
    char auxDos[10];
    char auxTres[10];
    int bufferUno;
    int bufferDos;
    int bufferTres;

    system("cls");
    puts(MSJ);
    puts("PRIMEROS DOS DIGITOS\n\n20, 23, 24 Y 27\n\n");
    puts("\n[XX]-XXXXXXXX-X\n");
    printf("\n%c ", 254);
    bufferUno=getInt("INGRESE DIGITOS: ");

    while(bufferUno!=20&&bufferUno!=23&&bufferUno!=24&&bufferUno!=27&&bufferUno!=30&&bufferUno!=33&&bufferUno!=34)
    {
        system("cls");
        puts(MSJ);
        puts("PRIMEROS DOS DIGITOS\n20, 23, 24 Y 27 PESONAS FISICAS\n\n");
        puts("\n[XX]-XXXXXXXX-X\n");
        bufferUno=getInt("\n[ERROR] REINGRESE DIGITOS: ");
    }

    system("cls");
    puts(MSJ);
    puts("\n[7-8 DIGITOS] PARA DNI\n");
    printf("\n%d-[XXXXXXXX]-X\n", bufferUno);
    printf("\n%c ", 254);
    bufferDos=getInt("INGRESE DIGITOS: ");

    while(bufferDos<1000000||bufferDos>100000000)
    {
        system("cls");
        puts(MSJ);
        puts("\n[7-8 DIGITOS] PARA DNI\n");
        printf("\n%d-[XXXXXXXX]-X\n", bufferUno);
        bufferDos=getInt("\n[ERROR] REINGRESE DIGITOS: ");
    }

    system("cls");
    puts(MSJ);
    puts("\nNUMERO VERIFICADOR\n");
    printf("\n%d-%d-[X]\n", bufferUno, bufferDos);
    printf("\n%c ", 254);
    bufferTres=getInt("INGRESE DIGITO: ");

    while(bufferTres<0||bufferTres>9)
    {
        system("cls");
        puts(MSJ);
        puts("\nNUMERO VERIFICADOR\n");
        printf("\n%d-%d-[X]\n", bufferUno, bufferDos);
        bufferTres=getInt("\n[ERROR] REINGRESE DIGITO: ");
    }

    system("cls");

    itoa(bufferUno,auxUno,10);
    itoa(bufferDos,auxDos,10);
    itoa(bufferTres,auxTres,10);

    strcpy(buffer, auxUno);
    strcat(buffer, "-");
    strcat(buffer, auxDos);
    strcat(buffer, "-");
    strcat(buffer, auxTres);

    strcpy(pCUIL, buffer);

    printf("\n[CARGA EXITOSA] CUIL: %s\n\n", pCUIL);

    system("pause");
    system("cls");
}

int getCuilConRetorno(const char* MSJ, char* pCUIL)
{
    char buffer[1000];
    char auxUno[10];
    char auxDos[10];
    char auxTres[10];
    int bufferUno;
    int bufferDos;
    int bufferTres;
    int retorno=0;

    system("cls");
    puts(MSJ);
    puts("PRIMEROS DOS DIGITOS\n\n20, 23, 24 Y 27\n\n");
    puts("\n[XX]-XXXXXXXX-X\n");
    printf("\n%c ", 254);
    bufferUno=getInt("INGRESE DIGITOS: ");

    while(bufferUno!=20&&bufferUno!=23&&bufferUno!=24&&bufferUno!=27&&bufferUno!=30&&bufferUno!=33&&bufferUno!=34)
    {
        system("cls");
        puts(MSJ);
        puts("PRIMEROS DOS DIGITOS\n20, 23, 24 Y 27 PESONAS FISICAS\n\n");
        puts("\n[XX]-XXXXXXXX-X\n");
        bufferUno=getInt("\n[ERROR] REINGRESE DIGITOS: ");
    }

    system("cls");
    puts(MSJ);
    puts("\n[7-8 DIGITOS] PARA DNI\n");
    printf("\n%d-[XXXXXXXX]-X\n", bufferUno);
    printf("\n%c ", 254);
    bufferDos=getInt("INGRESE DIGITOS: ");

    while(bufferDos<1000000||bufferDos>100000000)
    {
        system("cls");
        puts(MSJ);
        puts("\n[7-8 DIGITOS] PARA DNI\n");
        printf("\n%d-[XXXXXXXX]-X\n", bufferUno);
        bufferDos=getInt("\n[ERROR] REINGRESE DIGITOS: ");
    }

    system("cls");
    puts(MSJ);
    puts("\nNUMERO VERIFICADOR\n");
    printf("\n%d-%d-[X]\n", bufferUno, bufferDos);
    printf("\n%c ", 254);
    bufferTres=getInt("INGRESE DIGITO: ");

    while(bufferTres<0||bufferTres>9)
    {
        system("cls");
        puts(MSJ);
        puts("\nNUMERO VERIFICADOR\n");
        printf("\n%d-%d-[X]\n", bufferUno, bufferDos);
        bufferTres=getInt("\n[ERROR] REINGRESE DIGITO: ");
    }

    system("cls");

    itoa(bufferUno,auxUno,10);
    itoa(bufferDos,auxDos,10);
    itoa(bufferTres,auxTres,10);

    strcpy(buffer, auxUno);
    strcat(buffer, "-");
    strcat(buffer, auxDos);
    strcat(buffer, "-");
    strcat(buffer, auxTres);

    strcpy(pCUIL, buffer);

    retorno=1;

    system("pause");
    system("cls");

    return retorno;
}

int getSalida(const char* MSJ)
{
    int confirmar;
    char validar;

    switch(getChar(MSJ))
    {

    case 'S':

        do
        {
            validar=getChar("\nSEGURO QUE DESEA SALIR? [S]-[N]: ");
            if(validar=='S')
            {
                confirmar=1;
            }
            else if(validar=='N')
            {
                confirmar=0;
                printf("\n[CANCELADA]\n");
                system("pause");
                system("cls");
            }
            else
            {
                printf("\nOPCION NO VALIDA\n\n");
                system("pause");
            }
        }
        while(validar!='S'&&validar!='N');

        break;

    case 'N':

        confirmar=0;
        printf("\n[CANCELADA]\n");
        system("pause");
        system("cls");

        break;

    default:
        system("cls");
        printf("\nOPCION NO VALIDA\n\n");
        confirmar=0;
        system("pause");
        system("cls");
        break;
    }

    return confirmar;
}

int getContinuar(const char* MSJ)
{
    int confirmar;

    do
    {
        switch(getChar(MSJ))
        {

        case 'S':

            confirmar=1;
            //printf("\n[OPERACION EXITOSA]");
            break;

        case 'N':

            confirmar=0;
            printf("\n[OPERACION CANCELADA]\n");
            break;

        default:
            system("cls");
            confirmar=2;
            printf("\n[OPCION NO VALIDA], REINGRESE\n");
            system("pause");
            system("cls");
            break;
        }

    }
    while(confirmar==2);

    return confirmar;
}

unsigned long int getDni()
{
    unsigned long int DNI;

    do
    {
        DNI=getInt("INGRESE DNI: ");

        if(DNI<0)
        {
            system("cls");
            printf("[ERROR] RE");
        }
    }
    while(DNI<0);

    return DNI;
}

int getIntRangoMinMax(const char* MSJ, int valorMinimo, int valorMaximo)
{

    int valorInt;
    char buffer[30];

    do
    {
        printf("%s", MSJ);
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

float getFloatPositivo(const char* MSJ)
{

    float valorFlotante;
    char buffer[30];

    do
    {
        printf("%s", MSJ);
        fflush(stdin);
        gets(buffer);

        while(validarNumeroConSignos(buffer)==1)
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


