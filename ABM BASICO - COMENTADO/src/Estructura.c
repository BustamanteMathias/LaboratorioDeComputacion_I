#include <Estructura.h>

void Inicializar(eProducto *array, int TAM) {

	//SI EXISTE EL VECTOR
	if (array != NULL) {
		//RECORRO TODO EL VECTOR
		for (int i = 0; i < TAM; i++) {
			//SET ESTADO DE "LIBRE"
			array[i].isEmpty = LIBRE;
		}
	}

}

int eProducto_GetIndexLibre(eProducto *array, int TAM) {
	int rtn = -1;

	//SI EXISTE EL VECTOR
	if (array != NULL) {
		//RECORRO TODO EL VECTOR
		for (int i = 0; i < TAM; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (array[i].isEmpty == LIBRE) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int eProducto_GetIndexProducto(eProducto array[], int TAM, int idProducto) {
	int rtn = -1;

	//SI EXISTE EL VECTOR
	if (array != NULL) {
		//RECORRO TODO EL VECTOR
		for (int i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idProducto == idProducto && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int eProducto_CheckID(eProducto *array, int TAM, int idProducto) {
	int rtn = 0;

	//SI EXISTE EL VECTOR
	if (array != NULL) {
		//RECORRO TODO EL VECTOR
		for (int i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idProducto == idProducto && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE DEVUELVO EL ESTADO DE LA BUSQUEDA
				// 1 = ENCONTRO | 0 = NO ENCONTRO
				//IDEM A FUNCION eProducto_GetIndexProducto(...);
				rtn = 1;
				break;
			}
		}
	}

	return rtn;
}

eProducto eProducto_Set(void) {
	//CREO AUXILIAR PARA CARGAR DATOS
	eProducto aux;

	//PIDO LOS DATOS
	//NO PIDO ID DE PRODUCTO PORQUE LO PIDO POR FUERA PARA VALIDAR SI YA EXISTE
	Get_String("DESCRIPCION: ", "DESCRIPCION INVALIDA. REINGRESE: ",
			aux.descripcion, MAX_CHAR);
	aux.nacionalidad = Get_IntRange("Nacionalidad\n"
			"[1]EEUU [2]CHINA [3]OTRO\n"
			"OPCION: ", "OPCION NO VALIDA. REINGRESE: ", 1, 3);
	aux.tipo = Get_IntRange("Tipo\n"
			"[1]IPHONE [2]MAC [3]IPAD [4]ACCESORIOS\n"
			"OPCION: ", "OPCION NO VALIDA", 1, 4);
	aux.precio = Get_Float("PRECIO: ", "PRECIO INVALIDO. REINGRESE: ");
	//IMPORTANTE: CAMBIAR ESTADO A "OCUPADO"
	aux.isEmpty = OCUPADO;

	//RETORNO EL AUXILIAR DE PRODUCTO
	return aux;
}

int eProducto_Alta(eProducto *array, int TAM) {
	int rtn = 0;
	int auxID;
	eProducto auxProducto;

	//BUSCO ESPACIO EN VECTOR
	int index = eProducto_GetIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO | SI INDEX != -1 TENGO EN INDEX POSICION DE VECTOR
	if (index != -1) {

		//PIDO ID Y VERIFICO QUE NO EXISTA EL MISMO ID EN VECTOR
		auxID = Get_Int("ID PRODUCTO: ", "ID INVALIDO. REINGRESE: ");
		while (eProducto_CheckID(array, TAM, auxID)) {
			auxID = Get_Int("ID REPETIDO. REINGRESE: ",
					"ID INVALIDO. REINGRESE: ");
		}

		//PIDO DATOS PARA UN PRODUCTO Y LO GUARDO EN UN eProducto AUXILIAR
		auxProducto = eProducto_Set();
		auxProducto.idProducto = auxID;

		//SETEO EL VECTOR CON AUXILIAR EN INDEX OBTENIDO PREVIAMENTE
		array[index] = auxProducto;

		rtn = 1;
	}

	return rtn;
}

int eProducto_Baja(eProducto *array, int TAM) {
	int rtn = 0;
	int idProducto;
	int index;

	puts("");
	puts("********************");
	puts("* BAJA DE PRODUCTO *");
	puts("********************");
	puts("");

	//MUESTRO TODOS LOS PRODUCTOS
	eProducto_PrintAll(array, TAM);

	//PIDO ID A DAR DE BAJA
	idProducto = Get_Int("INGRESE ID: ", "ERROR. REINGRESE: ");
	while (eProducto_GetIndexProducto(array, TAM, idProducto) == -1) {
		puts("NO EXISTE ID.");
		idProducto = Get_Int("INGRESE ID: ", "ERROR. REINGRESE: ");
	}

	//OBTENGO INDEX DEL VECTOR DE PRODUCTO A DAR DE BAJA
	index = eProducto_GetIndexProducto(array, TAM, idProducto);

	//PREGUNTO SI DESEA CONTINUAR
	if (Validate_Exit_SN("SEGURO QUE DESEA CONTINUAR?\n[S]SI - [N]NO: ",
			"ERROR. REINGRESE.")) {
		//BAJA ACEPTADA - CAMBIO ESTADO A "LIBRE"
		array[index].isEmpty = LIBRE;
		rtn = 1;
	}

	return rtn;
}

int eProducto_Modificacion(eProducto *array, int TAM) {
	int rtn = 0;
	int idProducto;
	int index;
	int opc_aux;
	eProducto auxProducto;

	puts("");
	puts("****************************");
	puts("* MODIFICACION DE PRODUCTO *");
	puts("****************************");
	puts("");

	//MUESTRO TODOS LOS PRODUCTOS
	eProducto_PrintAll(array, TAM);

	idProducto = Get_Int("INGRESE ID: ", "ERROR. REINGRESE: ");
	while (eProducto_GetIndexProducto(array, TAM, idProducto) == -1) {
		puts("NO EXISTE ID.");
		idProducto = Get_Int("INGRESE ID: ", "ERROR. REINGRESE: ");
	}

	//PIDO ID A MODIFICAR
	index = eProducto_GetIndexProducto(array, TAM, idProducto);

	//HAGO UNA COPIA PARA MODIFICARLA LIBREMENTE
	auxProducto = array[index];

	//PREGUNTO SI DESEA CONTINUAR
	if (Validate_Exit_SN("SEGURO QUE DESEA CONTINUAR?\n[S]SI - [N]NO: ",
			"ERROR. REINGRESE.")) {
		//MODIFICACION ACEPTADA - MUESTRO OPCIONES A MODIFICAR
		puts("");
		printf("MODIFICAR PRODUCTO ID: %d\n", array[index].idProducto);
		puts("[1] PRECIO");
		puts("[2] TIPO");
		opc_aux = Get_IntRange("OPCION: ", "ERROR. REINGRESE: ", 1, 2);

		switch (opc_aux) {
		case 1:
			//MODIFICO PRECIO EN AUXILIAR
			auxProducto.precio = Get_Float("PRECIO NUEVO: ",
					"ERROR. REINGRESE: ");

			break;
		case 2:
			//MODIFICO TIPO EN AUXILIAR
			auxProducto.tipo = Get_IntRange("TIPO -> "
					"[1]IPHONE [2]MAC [3]IPAD [4]ACCESORIOS\n"
					"OPCION: ", "OPCION NO VALIDA", 1, 4);
			break;
		}

		//PREGUNTO NUEVAMENTE SI DESEA REEMPLAZAR
		if (Validate_Exit_SN("REEMPLAZAR CAMBIOS?\n[S]SI - [N]NO: ",
				"ERROR. REINGRESE.")) {
			//CONFIRMA CAMBIOS - SE HACE LA MODIFICACION
			//REEMPLAZO VECTOR ORIGINAL CON LA NUEVA COPIA MODIFICADA
			array[index] = auxProducto;
			rtn = 1;
		}
	}

	return rtn;
}

void eProducto_Print(eProducto producto) {

	//MOSTRAR UN PRODUCTO
	char auxNacionalidad[20];
	char auxTipo[20];

	//CASTEO DEFINE DE NACIONALIDAD A AUXILIAR DEL TIPO CADENA
	switch (producto.nacionalidad) {
	case EEUU:
		strcpy(auxNacionalidad, "EEUU");
		break;
	case CHINA:
		strcpy(auxNacionalidad, "CHINA");
		break;
	case OTRO:
		strcpy(auxNacionalidad, "OTRO");
		break;
	}

	//CASTEO DEFINE DE TIPO A AUXILIAR DEL TIPO CADENA
	switch (producto.tipo) {
	case IPHONE:
		strcpy(auxTipo, "IPHONE");
		break;
	case MAC:
		strcpy(auxTipo, "MAC");
		break;
	case IPAD:
		strcpy(auxTipo, "IPAD");
		break;
	case ACCESORIOS:
		strcpy(auxTipo, "ACCESORIOS");
		break;
	}

	//LO MUESTRO
	printf("%5d %15s %15s %15s %9.2f\n", producto.idProducto,
			producto.descripcion, auxNacionalidad, auxTipo, producto.precio);
}
void eProducto_PrintAll(eProducto *array, int TAM) {
	int countProductos = 0;

	//CABECERA
	puts("\n > PRODUCTOS\n");
	printf("%5s %15s %15s %15s %11s", "ID", "DESCRIPCION", "NACIONALIDAD",
			"TIPO", "PRECIO\n\n");

	//SI EXISTE EL VECTOR
	if (array != NULL) {
		//RECORRO TODO EL VECTOR
		for (int i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO PRODUCTO
				eProducto_Print(array[i]);
				countProductos++;
			}
		}
	}

	//VALIDACION POR SI EL VECTOR ESTA VACIO
	if (countProductos == 0) {
		puts("[LISTA VACIA - SIN PRODUCTOS PARA MOSTRAR]");
	}

	puts("");
}

int eProducto_SortPrecio(eProducto *array, int TAM, int criterio) {
	int rtn = 0;
	eProducto aux;

	//SI EXISTE EL VECTOR Y EL TAM ES VALIDO
	if (array != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			for (int i = 0; i < TAM - 1; i++) {
				for (int j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].precio > array[j].precio) {
							//INTERCAMBIO POSICIONES EN VECTOR
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		case 1:
			for (int i = 0; i < TAM - 1; i++) {
				for (int j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].precio < array[j].precio) {
							//INTERCAMBIO POSICIONES EN VECTOR
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			rtn = 0;
			break;
		}
	}
	return rtn;
}

int eProducto_SortDescripcion(eProducto *array, int TAM, int criterio) {
	int rtn = 0;
	eProducto aux;

	//SI EXISTE EL VECTOR Y EL TAM ES VALIDO
	if (array != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			for (int i = 0; i < TAM - 1; i++) {
				for (int j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (strcmp(array[i].descripcion, array[j].descripcion)
								> 0) {
							//INTERCAMBIO POSICIONES EN VECTOR
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		case 1:
			for (int i = 0; i < TAM - 1; i++) {
				for (int j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (strcmp(array[i].descripcion, array[j].descripcion)
								< 0) {
							//INTERCAMBIO POSICIONES EN VECTOR
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			rtn = 0;
			break;
		}
	}
	return rtn;
}

void eProducto_MayorPrecio(eProducto *array, int TAM) {
	int countProductos = 0;
	int flag = 0;

	float maxPrecio;

	//ME FIJO SI TENGO PRODUCTOS CARGADOS EN EL VECTOR, PREGUNTO POR ESTADO "OCUPADO"
	for (int i = 0; i < TAM; i++) {
		if (array[i].isEmpty == OCUPADO) {
			countProductos++;
		}
	}

	//SI TENGO ELEMENTOS EN EL VECTOR
	if (countProductos > 0) {
		//BUSCO PRECIO MAS ALTO
		for (int i = 0; i < TAM; i++) {
			if (array[i].isEmpty == OCUPADO) {
				//BANDERA PARA SETEAR EL MAXIMO PRECIO LA PRIMERA VEZ
				if (flag == 0) {
					maxPrecio = array[i].precio;
					flag = 1;
				} else {
					//BUSCO PRECIO MAS ALTO QUE AL GUARDADO EN AUXILIAR
					if (array[i].precio > maxPrecio) {
						maxPrecio = array[i].precio;
					}
				}
			}
		}

		//CABECERA
		puts("\n > PRODUCTO/S DE MAYOR PRECIO\n");
		printf("%5s %15s %15s %15s %11s", "ID", "DESCRIPCION", "NACIONALIDAD",
				"TIPO", "PRECIO\n\n");
		//CUANDO TENGO EL PRECIO MAS ALTO BUSCO EN EL VECTOR LOS PRODUCTOS QUE COINCIDAN
		for (int i = 0; i < TAM; i++) {
			if (array[i].isEmpty == OCUPADO && array[i].precio == maxPrecio) {
				eProducto_Print(array[i]);
			}
		}
		puts("");
	} else {
		puts("[LISTA VACIA - SIN PRODUCTOS PARA MOSTRAR]\n");
	}
}

void eProducto_PromedioPrecioPorTipo(eProducto *array, int TAM) {
	float acumIPHONE = 0;
	float acumMAC = 0;
	float acumIPAD = 0;
	float acumACCESORIOS = 0;
	int countIPHONE = 0;
	int countMAC = 0;
	int countIPAD = 0;
	int countACCESORIOS = 0;
	float aux;

//SI EL VECTOR EXISTE
	if (array != NULL) {
		//RECORRO TODO EL VECTOR
		for (int i = 0; i < TAM; i++) {
			//SI TIENE EL ESTADO "OCUPADO" ACUMULO PRECIOS PARA CALCULAR PROMEDIO
			if (array[i].isEmpty == OCUPADO) {
				switch (array[i].tipo) {
				case IPHONE:
					acumIPHONE += array[i].precio;
					countIPHONE++;
					break;
				case MAC:
					acumMAC += array[i].precio;
					countMAC++;
					break;
				case IPAD:
					acumIPAD += array[i].precio;
					countIPAD++;
					break;
				case ACCESORIOS:
					acumACCESORIOS += array[i].precio;
					countACCESORIOS++;
					break;
				}
			}
		}

		printf("\n%10s %20s\n\n", "MARCA", "PROMEDIO DE PRECIO");

		//CALCULO PROMEDIOS Y LOS MUESTRO SI EXISTE PRODUCTOS DE ESE TIPO
		if (countIPHONE) {
			aux = acumIPHONE / countIPHONE;
			printf("%10s %20.2f\n", "IPHONE", aux);
		}
		if (countMAC) {
			aux = acumMAC / countMAC;
			printf("%10s %20.2f\n", "MAC", aux);
		}
		if (countIPAD) {
			aux = acumIPAD / countIPAD;
			printf("%10s %20.2f\n", "IPAD", aux);
		}
		if (acumACCESORIOS) {
			aux = acumACCESORIOS / countACCESORIOS;
			printf("%10s %20.2f\n", "ACCESORIOS", aux);
		}

		puts("");
	}
}

void Menu(void) {
	//MENU BANANA (?
	puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	puts("******************************");
	puts("***     MENU PRODUCTOS     ***");
	puts("******************************");
	puts("*           A B M            *");
	puts("******************************");
	puts("* [1] ALTA                   *");
	puts("* [2] BAJA                   *");
	puts("* [3] MODIFICACION           *");
	puts("******************************");
	puts("*          LISTADOS          *");
	puts("******************************");
	puts("* [4] TODOS LOS PRODUCTOS    *");
	puts("* [5] ORDEN POR PRECIO       *");
	puts("* [6] ORDEN POR DESCRIPCION  *");
	puts("* [7] PRODUCTOS MAS CAROS    *");
	puts("* [8] PRECIO PROMEDIO X TIPO *");
	puts("******************************");
}
