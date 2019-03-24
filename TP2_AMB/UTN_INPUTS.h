/** \brief PIDE NOMBRE Y VALIDA EL LARGO
 *
 * \param char* RECIBE PUNTERO DEL NOMBRE
 * \param int const TAMAÑO PARA VALIDAR EL LARGO
 * \return void
 *
 */
void pedirNombre(char*, const int);

/** \brief PIDE APELLIDO Y VALIDA EL LARGO
 *
 * \param char* RECIBE EL PUNTERO DEL APELLIDO
 * \param int const TAMAÑO PARA VALIDAR EL LARGO
 * \return void
 *
 */
void pedirApellido(char*, const int);

/** \brief RECORRE CARACTERES Y VALIDA QUE SEAN CHARS
 *
 * \param char* PUNTERO A VALIDAR
 * \return int RETORNA 1 SI ENCUENTRA NUMERO, RETORNA 0 SI SON SOLO LETRAS
 *
 */
int validarChars(char*);

/** \brief PIDE NOMBRE, VALIDA EL LARGO Y VERIFICA QUE SEAN TODOS CHARS
 *
 * \param char* PUNTERO DE NOMBRE A VALIDAR
 * \param int const LARGO DEL NOMBRE A VALIDAR
 * \return void
 *
 */
void pedirNombreValidarChars(char*, const int);

/** \brief PIDE APELLIDO, VALIDA EL LARGO Y VERIFICA QUE SEAN TODOS CHARS
 *
 * \param char* PUNTERO DE NOMBRE A VALIDAR
 * \param int const LARGO DEL APELLIDO A VALIDAR
 * \return void
 *
 */
void pedirApellidoValidarChars(char*, const int);

/** \brief IMPRIME MENU
 *
 * \return int RETORNA OPCION ELEGIDA
 *
 */
int imprimirMenu();

/** \brief VALIDA NUMEROS, EXCLUYE SIGNOS ". , -"
 *
 * \param char* CADENA A VALIDAR
 * \return int RETORNA 0 SI SON NUMEROS O RETORNA 1 SI ENCUENTRA LETRAS
 *
 */
int validarNumeroExcluyeSignos(char*);

/** \brief VALIDA SOLO NUMEROS ENTEROS, SIN SIGNOS
 *
 * \param char* CADENA A VALIDAR
 * \return int RETORNA 0 SI SON NUMEROS O RETORNA 1 SI ENCUENTRA LETRAS
 *
 */
int validarNumero(char*);

/** \brief CONCATENA CON EL FORMATO " Apellido, Nombre"
 *
 * \param char* ARRAY DE NOMBRE COMPLETO
 * \param char* CADENA APELLIDO
 * \param char* CADENA NOMBRE
 * \return void
 *
 */
void concatenarNombreApellido(char*, char*, char*);

/** \brief PIDE UN NUMERO ENTERO Y LO VALIDA
 *
 * \param char* const MENSAJE A MOSTRAR
 * \return int RETORNA EL VALOR ENTERO YA VALIDADO
 *
 */
int pedirInt(const char*);

/** \brief PIDE FLOTANTE Y LO VALIDA
 *
 * \param char* const MENSAJE A MOSTRAR
 * \return float RETORNA EL VALOR FLOTANTE YA VALIDADO
 *
 */
float pedirFloat(const char*);

/** \brief PIDE UN CHAR
 *
 * \param char* const MENSAJE A MOSTRAR
 * \return char RETORNA CHAR
 *
 */
char pedirChar(const char*);

/** \brief PIDE STRINGS Y VALIDA QUE SEANSOLO CARACTERES Y EL MAXIMO DE CARACTERES VALIDOS, CONVIERTE PRIMER LETRA A MAYUSCULA Y RESTO A MINUSCULAS
 *
 * \param char* PUNTERO DE CADENA
 * \param int MAXIMO DE CADENA
 * \return void
 *
 */
void pedirCadena(char*, int);

/** \brief IMPRIME SUB MENU
 *
 * \return int RETORNA OPCION ELEGIDA
 *
 */
int imprimirSubMenu();

/** \brief PIDE CONTNUAR POR SI O POR NO
 *
 * \return char RETORNA CHAR CON OPCION TOMADA
 *
 */
char pedirConfirmacion(const char*);

/** \brief PIDE VALOR ENTERO ENTRE UN RANGO MINIMO Y MAXIMO CON UN MENSAJE PUESTO POR EL USUARIO
 *
 * \param char* const MENSAJE A MOSTRAR
 * \param int RANGO MINIMO
 * \param int RANGO MAXIMO
 * \return int ENTERO VALIDADO ENTRE RANGO MINIMO Y MAXIMO
 *
 */
int pedirIntRangoMinMax(const char*,int ,int);

/** \brief PIDE NUMERO FLOTANTE Y VALIDA QUE NO ESTE POR DEBAJO DE CERO CON MENSAJE PUESTO POR EL USUARIO
 *
 * \param char* const MENSAJE A MOSTRAR
 * \return float RETORNA VALOR FLOTANTE VALIDADO
 *
 */
float pedirFloatPositivo(const char*);

