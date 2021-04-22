#include "Estructura.h"
#define MAX_ESTRUCTURA 4

int main(void) {
	int opc;
	int opc_aux;
	int criterioDeOrdenamiento;

	//CREO ARRAY DE ESTRUCTURA + HARDCODEO
	eProducto productos[MAX_ESTRUCTURA] = 
	{ 
		{ 1, "DESCRIPCION 1", EEUU, IPHONE, 5000, OCUPADO }, 
		{ 2, "DESCRIPCION 2", OTRO, IPAD, 10500, OCUPADO },
		{ 3, "DESCRIPCION 3", CHINA, ACCESORIOS, 5000, OCUPADO }, 
		{ 4, "DESCRIPCION 4", CHINA, ACCESORIOS, 10000, OCUPADO } 
	};

	setbuf(stdout, NULL);

	//INICIALIAZO ARRAY DE ESTRUCTURA
	//Inicializar(productos, MAX_ESTRUCTURA);

	//BUCLE DE MENU
	do {
		//MENU PRINT
		Menu();

		//MENU SWITCH
		switch (Get_IntRange("OPCION: ", "", 1, 8)) //Retorna opcion de Menu valida
		{
		case 0:
			//SALIR
			if (Validate_Exit_SN("SEGURO QUE DESEA SALIR?\n[S]SI - [N]NO: ",
					"ERROR. REINGRESE: ")) {
				opc = 0;

				puts("SALIENDO...");
			}
			break;
		case 1:
			//ALTA
			if (eProducto_Alta(productos, MAX_ESTRUCTURA)) {
				puts(" * PRODUCTO DADO DE ALTA EXITOSAMENTE");
			} else {
				puts(" * ERROR. SIN ESPACIO PARA ALMACENAR MAS PRODUCTOS");
			}
			system("pause");
			break;
		case 2:
			//BAJA
			if (eProducto_Baja(productos, MAX_ESTRUCTURA)) {
				puts("\n * BAJA DE PRODUCTO EXITOSA");
				eProducto_PrintAll(productos, MAX_ESTRUCTURA);
			} else {
				puts("\n * BAJA DE PRODUCTO CANCELADA");
			}
			system("pause");
			break;
		case 3:
			//MODIFICACION
			if (eProducto_Modificacion(productos, MAX_ESTRUCTURA)) {
				puts("\n * MODIFICACION DE PRODUCTO EXITOSA\n");
				eProducto_PrintAll(productos, MAX_ESTRUCTURA);
			} else {
				puts("\n * MODIFICACION DE PRODUCTO CANCELADA");
			}
			system("pause");
			break;
		case 4:
			//LISTADO PRODUCTOS
			eProducto_PrintAll(productos, MAX_ESTRUCTURA);
			system("pause");
			break;
		case 5:
			//LISTADO ORDENADO POR PRECIO
			opc_aux = Get_IntRange(
					"SELECCIONE OPNCION PARA LISTAR LOS PRODUCTOS\n"
							"[1]MAYOR A MENOR\n[2]MENOR A MAYOR\nOPCION: ",
					"OPCION INVALIDA. REINGRESE: ", 1, 2);

			if (opc_aux == 1) {
				criterioDeOrdenamiento = 1;
			} else {
				criterioDeOrdenamiento = -1;
			}

			if (eProducto_SortPrecio(productos, MAX_ESTRUCTURA,
					criterioDeOrdenamiento)) {
				//SI HABIA ELEMENTOS EN LA LISTA Y SALIO TODO BIEN, MUESTRO ORDEN
				eProducto_PrintAll(productos, MAX_ESTRUCTURA);
			}
			break;
		case 6:
			//LISTADO ORDENADO POR DESCRIPCION
			opc_aux = Get_IntRange(
					"SELECCIONE OPNCION PARA LISTAR LOS PRODUCTOS\n"
							"[1]MAYOR A MENOR\n[2]MENOR A MAYOR\nOPCION: ",
					"OPCION INVALIDA. REINGRESE: ", 1, 2);

			if (opc_aux == 1) {
				criterioDeOrdenamiento = 1;
			} else {
				criterioDeOrdenamiento = -1;
			}

			if (eProducto_SortDescripcion(productos, MAX_ESTRUCTURA,
					criterioDeOrdenamiento)) {
				//SI HABIA ELEMENTOS EN LA LISTA Y SALIO TODO BIEN, MUESTRO ORDEN
				eProducto_PrintAll(productos, MAX_ESTRUCTURA);
			}
			system("pause");
			break;
		case 7:
			//EL O LOS PRODUCTOS MAS CAROS
			eProducto_MayorPrecio(productos, MAX_ESTRUCTURA);
			system("pause");
			break;
		case 8:
			//PROMEDIO DE PRECIO POR TIPO
			eProducto_PromedioPrecioPorTipo(productos, MAX_ESTRUCTURA);
			system("pause");
			break;
		}
	} while (opc != 0);

	return 0;
}
