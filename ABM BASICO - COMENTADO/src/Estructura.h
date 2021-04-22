#ifndef ESTRUCTURA_H_
#define ESTRUCTURA_H_

//LIBRERIAS EXTERNAS
#include <General.h>
//TAMAÑOS DE CADENA
#define MAX_CHAR 30
//ESTADOS DE ESTRUCTURA
#define LIBRE 0
#define OCUPADO 1
//NACIONALIDAD
#define EEUU 1
#define CHINA 2
#define OTRO 3
//TIPO
#define IPHONE 1
#define MAC 2
#define IPAD 3
#define ACCESORIOS 4

//ESTRUCTURA
typedef struct {
	int idProducto;
	char descripcion[MAX_CHAR];
	int nacionalidad;
	int tipo;
	float precio;
	int isEmpty;
} eProducto;

//CABECERA DE FUNCIONES
void Menu(void);
void Inicializar(eProducto *array, int TAM);
int eProducto_GetIndexLibre(eProducto *array, int TAM);
int eProducto_GetIndexProducto(eProducto *array, int TAM, int idProducto);
int eProducto_CheckID(eProducto *array, int TAM, int idProducto);
int eProducto_Alta(eProducto *array, int TAM);
int eProducto_Baja(eProducto *array, int TAM);
int eProducto_Modificacion(eProducto *array, int TAM);
void eProducto_Print(eProducto producto);
void eProducto_PrintAll(eProducto *array, int TAM);
void eProducto_MayorPrecio(eProducto *array, int TAM);
void eProducto_PromedioPrecioPorTipo(eProducto *array, int TAM);

/***CRITERIO -> -1 = Menor a Mayor | 1 = Mayor a Menor***/
int eProducto_SortPrecio(eProducto *array, int TAM, int criterio);
int eProducto_SortDescripcion(eProducto *array, int TAM, int criterio);
//CABECERA DE FUNCIONES - FIN

#endif
