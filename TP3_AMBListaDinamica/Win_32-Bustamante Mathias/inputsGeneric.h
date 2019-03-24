#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

/************************************************************ MENUS*/
/** \brief IMPRIME MENU
 *
 * \return int RETORNA OPCION ELEGIDA
 *
 */
int getMenu();

/** \brief IMPRIME SUB MENU
 *
 * \return int RETORNA OPCION ELEGIDA
 *
 */
int subMenuUno();

/** \brief IMPRIME SUB MENU
 *
 * \return int RETORNA OPCION ELEGIDA
 *
 */
int subMenuDos();
/************************************************************ GETS*/
/** \brief PIDE NOMBRE Y VALIDA EL LARGO
 *
 * \param char* RECIBE PUNTERO DEL NOMBRE
 * \param int TAMAÑO PARA VALIDAR EL LARGO
 * \return void
 *
 */
void getName(char*, int);

/** \brief PIDE APELLIDO Y VALIDA EL LARGO
 *
 * \param char* RECIBE EL PUNTERO DEL APELLIDO
 * \param int TAMAÑO PARA VALIDAR EL LARGO
 * \return void
 *
 */
void getLastName(char*, int);

/** \brief PIDE NOMBRE Y VALIDA EL LARGO
 *
 * \param char* RECIBE EL PUNTERO DEL NOMBRE
 * \param int TAMAÑO PARA VALIDAR EL LARGO
 * \return int RETORNA 1 POR CARGA CORRECTA || RETORNA 0 POR CARGA INCORRECTA
 *
 */
int getNameConRetorno(char*, int);

/** \brief PIDE APELLIDO Y VALIDA EL LARGO
 *
 * \param char* RECIBE EL PUNTERO DEL APELLIDO
 * \param int TAMAÑO PARA VALIDAR EL LARGO
 * \return int RETORNA 1 POR CARGA CORRECTA || RETORNA 0 POR CARGA INCORRECTA
 *
 */
int getLastNameConRetorno(char*, int);

/** \brief PIDE CADENA Y VALIDA EL LARGO, SE ADMITEN NUMEROS Y LETRAS.
 *
 * \param char* PUNTERO DE CADENA
 * \param int TAMAÑO DE CADENA
 * \return int RETORNA 1 POR CARGA CORRECTA || RETORNA 0 POR CARGA INCORRECTA
 *
 */
int getStringConRetorno(char*, int);

/** \brief PIDE ENTERO Y VALIDA QUE SEAN SOLO NUMEROS
 *
 * \param MENSAJE const char* MENSAJE A MOSTRAR
 * \return int RETORNA EL VALOR VALIDADO
 *
 */
int getInt(const char* MENSAJE);

/** \brief PIDE FLOTANTE Y LO VALIDA EXCLUYENDO SIGNOS
 *
 * \param char* const MENSAJE A MOSTRAR
 * \return float RETORNA EL VALOR FLOTANTE YA VALIDADO
 *
 */
float getFloat(const char*);

/** \brief PIDE LETRA, VALIDA QUE SEA UN SOLO CARACTER Y LA RETORNA EN MAYUSCULA
 *
 * \param MSJ const char* MENSAJE A MOSTRAR
 * \return char RETORNA CHAR VALIDADO EN MAYUSCULA
 *
 */
char getChar(const char* MSJ);

/** \brief PIDE CUIT, VALIDA TODOS SUS CAMPOS Y DA MENSAJE DE QUE SE CARGO CORRECTAMENTE
 *
 * \param MSJ const char* MENSAJE A MOSTRAR
 * \param char* PUNTERI DE CUIT A GUARDAR
 * \return void
 *
 */
void getCuit(const char* MSJ, char*);

/** \brief PIDE CUIT, VALIDA TODOS SUS CAMPOS, RETORNA VALIDACION
 *
 * \param MSJ const char* MENSAJE A MOSTRAR
 * \param char* PUNTERO DE CUIT A GUARDAR
 * \return int RETORNA 1 SI FUE EXITOSA LA CARGA, RETORNA 0 SI NO CARGO
 *
 */
int getCuitConRetorno(const char* MSJ, char*);

/** \brief PIDE CUIL, VALIDA TODOS SUS CAMPOS, ALMACENA EN PUNTERO
 *
 * \param MSJ const char* MENSAJE A MOSTRAR
 * \param char* PUNTERO DE CUIL
 * \return void
 *
 */
void getCuil(const char* MSJ, char*);

/** \brief PIDE CUIL, VALIDA TODOS SUS CAMPOS, ALMACENA EN PUNTERO
 *
 * \param MSJ const char* MENSAJE A MOSTRAR
 * \param char* PUNTERO DE CUIL
 * \return int RETORNA 1 SI FUE EXITOSA LA CARGA, RETORNA 0 SI NO CARGO
 *
 */
int getCuilConRetorno(const char* MSJ, char* pCUIL);

/** \brief PIDE CONFIRMACION PARA SALIR
 *
 * \param MSJ const char* MENSAJE A MOSTRAR
 * \return int RETORNA 1 PARA SEGUIR Y 0 PARA NEGAR
 *
 */
int getSalida(const char* MSJ);

/** \brief PIDE UN DNI Y LO RETORNA //LONG INT
 *
 * \return long int
 *
 */
unsigned long int getDni();

/** \brief PIDE VALOR ENTERO ENTRE UN RANGO MINIMO Y MAXIMO CON UN MENSAJE PUESTO POR EL USUARIO
 *
 * \param char* const MENSAJE A MOSTRAR
 * \param int RANGO MINIMO
 * \param int RANGO MAXIMO
 * \return int ENTERO VALIDADO ENTRE RANGO MINIMO Y MAXIMO
 *
 */
int getIntRangoMinMax(const char*,int,int);

/** \brief PIDE NUMERO FLOTANTE Y VALIDA QUE NO ESTE POR DEBAJO DE CERO CON MENSAJE PUESTO POR EL USUARIO
 *
 * \param char* const MENSAJE A MOSTRAR
 * \return float RETORNA VALOR FLOTANTE VALIDADO
 *
 */
float getFloatPositivo(const char*);

/************************************************************ VALIDACIONES*/

/** \brief RECIBE UNA CADENA Y VALIDA QUE SEAN SOLO LETRAS
 *
 * \param char* PUNTERO DE CADENA A VALIDAR
 * \return int RETORNA 1 PARA CADENA VALIDADA SOLO CARACTERES, RETORNA 0 POR CADENA CON CHARS INVALIDOS
 *
 */
int validarString(char*);

/** \brief RECIBE CADENA PARA VALIDAR SOLO NUMEROS
 *
 * \param char* PUNTERO DE CADENA A VALIDAR
 * \return int RETORNA 0 PARA CADENA VALIDADA CORRECTAMENTE, RETORNA 1 POR CADENA INVALIDA
 *
 */
int validarNumero(char*);

/** \brief VALIDA NUMEROS, EXCLUYE SIGNOS ". , -"
 *
 * \param char* CADENA A VALIDAR
 * \return int RETORNA 0 SI SON NUMEROS O RETORNA 1 SI ENCUENTRA LETRAS
 *
 */
int validarNumeroConSignos(char*);

/************************************************************ LISTAR*/

/** \brief CONCATENA CON EL FORMATO "Apellido, Nombre"
 *
 * \param char* PUNTERO DE NOMBRE COMPLETO
 * \param char* PUNTERO CADENA APELLIDO
 * \param char* PUNTERO CADENA NOMBRE
 * \return void
 *
 */
void concatenarNombreApellido(char*, char*, char*);

int getContinuar(const char* MSJ);
