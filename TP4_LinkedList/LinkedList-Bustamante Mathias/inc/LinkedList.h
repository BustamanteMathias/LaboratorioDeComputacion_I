/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
/**ESTRUCTURA NODO*/
struct Node
{
    void* pElement;         //PUNTERO DE ELEMENTO A GUARDAR
    struct Node* pNextNode; //PUNTERO AL NODO SIGUIENTE
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;   //PUNTERO AL PRIMERO NODO
    int size;           //TAMAÑO LINKEDLIST
}typedef LinkedList;
#endif

//FUNCIONES PUBLICAS

/** \brief CREA UN NUEVO LINKEDLIST EN MEMORIA DE MANERA DINÁMICA
 *
 *  \param void
 *  \return LinkedList* RETORNA (NULL) EN EL CASO DE NO CONSEGUIR ESPACIO EN MEMORIA
 *                      O EL PUNTERO AL ESPACIO RESERVADO
 */
LinkedList* ll_newLinkedList(void);

/** \brief RETORNA LA CANTIDAD DE ELEMENTOS DE LA LISTA
 *
 * \param this LinkedList* PUNTERO A LA LISTA
 * \return int RETORNA (-1) SI EL PUNTERO ES NULL O LA CANTIDAD DE ELEMENTOS DE LA LISTA
 *
 */
int ll_len(LinkedList* this);

/** \brief  PERMITE REALIZAR EL TEST DE LA FUNCION GETNODE LA CUAL ES PRIVADA
 *
 * \param this LinkedList* PUNTERO A LA LISTA
 * \param index int INDICE DEL NODO A OBTENER
 * \return Node* RETORNA (NULL) ERROR: SI EL PUNTERO A LA LISTA ES NULL O (SI EL INDICE ES MENOR A 0 O MAYOR AL LEN DE LA LISTA)
 *                       (PELEMENT) SI FUNCIONO CORRECTAMENTE
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex);

/** \brief PERMITE REALIZAR EL TEST DE LA FUNCION ADDNODE LA CUAL ES PRIVADA
 *
 * \param this LinkedList* PUNTERO A LA LISTA
 * \param nodeIndex int UBICACIÓN DONDE SE AGREGARA EL NUEVO NODOo
 * \param pElement void* PUNTERO AL ELEMENTO A SER CONTENIDO POR EL NUEVO NODO
 * \return int RETORNA (-1) ERROR: SI EL PUNTERO A LA LISTA ES NULL O (SI EL INDICE ES MENOR A 0 O MAYOR AL LEN DE LA LISTA)
 *                     ( 0) SI FUNCIONO CORRECTAMENTE
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief  AGREGA UN ELEMENTO A LA LISTA
 * \param pList LinkedList* PUNTERO A LA LISTA
 * \param pElement void* PUNTERO AL ELEMENTO A SER AGREGADO
 * \return int RETORNA  (-1) ERROR: SI EL PUNTERO A LA LISTA ES NULL
 *                      ( 0) SI FUNCIONO CORRECTAMENTE
 *
 */
int ll_add(LinkedList* this, void* pElement);

/** \brief PERMITE REALIZAR EL TEST DE LA FUNCION ADDNODE LA CUAL ES PRIVADA
 *
 * \param this LinkedList* PUNTERO A LA LISTA
 * \param nodeIndex int UBICACIÓN DEL ELEMENTO A OBTENER
 * \return void* RETORNA (NULL) ERROR: SI EL PUNTERO A LA LISTA ES NULL O (SI EL INDICE ES MENOR A 0 O MAYOR AL LEN DE LA LISTA)
 *                       (PELEMENT) SI FUNCIONO CORRECTAMENTE
 *
 */
void* ll_get(LinkedList* this, int index);

/** \brief MODIFICA UN ELEMENTO DE LA LISTA
 *
 * \param this LinkedList* PUNTERO A LA LISTA
 * \param nodeIndex int UBICACIÓN DEL ELEMENTO A MODIFICAR
 * \param pElement void* PUNTERO AL NUEVO ELEMENTO
 * \return int RETORNA  (-1) ERROR: SI EL PUNTERO A LA LISTA ES NULL O (SI EL INDICE ES MENOR A 0 O MAYOR AL LEN DE LA LISTA)
 *                      ( 0) SI FUNCIONO CORRECTAMENTE
 *
 */
int ll_set(LinkedList* this, int index,void* pElement);

/** \brief ELIMINA UN ELEMENTO DE LA LISTA
 *
 * \param this LinkedList* PUNTERO A LA LISTA
 * \param nodeIndex int UBICACIÓN DEL ELEMENTO A ELIMINAR
 * \return int RETORNA  (-1) ERROR: SI EL PUNTERO A LA LISTA ES NULL O (SI EL INDICE ES MENOR A 0 O MAYOR AL LEN DE LA LISTA)
 *                      ( 0) SI FUNCIONO CORRECTAMENTE
 *
 */
int ll_remove(LinkedList* this,int index);

/** \brief ELIMINA TODOS LOS ELEMENTOS DE LA LISTA
 *
 * \param this LinkedList* PUNTERO A LA LISTA
 * \return int RETORNA  (-1) ERROR: SI EL PUNTERO A LA LISTA ES NULL
 *                      ( 0) SI FUNCIONO CORRECTAMENTE
 *
 */
int ll_clear(LinkedList* this);

/** \brief ELIMINA TODOS LOS ELEMENTOS DE LA LISTA Y LA LISTA
 *
 * \param this LinkedList* PUNTERO A LA LISTA
 * \return int RETORNA  (-1) ERROR: SI EL PUNTERO A LA LISTA ES NULL
 *                      ( 0) SI FUNCIONO CORRECTAMENTE
 *
 */
int ll_deleteLinkedList(LinkedList* this);

/** \brief BUSCA EL INDICE DE LA PRIMER OCURRENCIA DEL ELEMENTO PASADO COMO PARÁMETRO
 *
 * \param this LinkedList* PUNTERO A LA LISTA
 * \param pElement void* PUNTERO AL ELEMENTO
 * \return int RETORNA  (-1) ERROR: SI EL PUNTERO A LA LISTA ES NULL
 *                      (INDICE DEL ELEMENTO) SI FUNCIONO CORRECTAMENTE
 *
 */
int ll_indexOf(LinkedList* this, void* pElement);

/** \brief INDICA SI LA LISTA ESTA O NO VACÍA
 *
 * \param this LinkedList* PUNTERO A LA LISTA
 * \return int RETORNA  (-1) ERROR: SI EL PUNTERO A LA LISTA ES NULL
 *                      ( 0) SI LA LISTA NO ESTA VACÍA
 *                      ( 1) SI LA LISTA ESTA VACÍA
 *
 */
int ll_isEmpty(LinkedList* this);

/** \brief INSERTA UN NUEVO ELEMENTO EN LA LISTA EN LA POSICIÓN INDICADA
 *
 * \param this LinkedList* PUNTERO A LA LISTA
 * \param nodeIndex int UBICACIÓN DONDE SE AGREGARA EL NUEVO ELEMENTO
 * \param pElement void* PUNTERO AL NUEVO ELEMENTO
 * \return int RETORNA  (-1) ERROR: SI EL PUNTERO A LA LISTA ES NULL O (SI EL INDICE ES MENOR A 0 O MAYOR AL LEN DE LA LISTA)
 *                      ( 0) SI FUNCIONO CORRECTAMENTE
 *
 */
int ll_push(LinkedList* this, int index, void* pElement);

/** \brief ELIMINA EL ELEMENTO DE LA POSICIÓN INDICADA Y RETORNA SU PUNTERO
 *
 * \param this LinkedList* PUNTERO A LA LISTA
 * \param nodeIndex int UBICACIÓN DEL ELEMENTO ELIMINAR
 * \return void* RETORNA (NULL) ERROR: SI EL PUNTERO A LA LISTA ES NULL O (SI EL INDICE ES MENOR A 0 O MAYOR AL LEN DE LA LISTA)
 *                       (PELEMENT) SI FUNCIONO CORRECTAMENTE
 *
 */
void* ll_pop(LinkedList* this,int index);

/** \brief  DETERMINA SI LA LISTA CONTIENE O NO EL ELEMENTO PASADO COMO PARÁMETRO
 *
 * \param this LinkedList* PUNTERO A LA LISTA
 * \param pElement void* PUNTERO DEL ELEMENTO A VERIFICAR
 * \return int RETORNA  (-1) ERROR: SI EL PUNTERO A LA LISTA ES NULL
 *                      ( 1) SI CONTIENE EL ELEMENTO
 *                      ( 0) SI NO CONTIENE EL ELEMENTO
*/
int ll_contains(LinkedList* this, void* pElement);

/** \brief  DETERMINA SI TODOS LOS ELEMENTOS DE LA LISTA (THIS2)
            ESTÁN CONTENIDOS EN LA LISTA (THIS)
 *
 * \param this LinkedList* PUNTERO A LA LISTA
 * \param this2 LinkedList* PUNTERO A LA LISTA
 * \return int RETORNA  (-1) ERROR: SI ALGUNO DE LOS PUNTEROS A LAS LISTAS SON NULL
 *                      ( 1) SI LOS ELEMENTOS DE (THIS2) ESTÁN CONTENIDOS EN LA LISTA (THIS)
 *                      ( 0) SI LOS ELEMENTOS DE (THIS2) NO ESTÁN CONTENIDOS EN LA LISTA (THIS)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2);

/** \brief CREA Y RETORNA UNA NUEVA LISTA CON LOS ELEMENTOS INDICADOS
 *
 * \param pList LinkedList* PUNTERO A LA LISTA
 * \param from int INDICE DESDE EL CUAL SE COPIAN LOS ELEMENTOS EN LA NUEVA LISTA
 * \param to int INDICE HASTA EL CUAL SE COPIAN LOS ELEMENTOS EN LA NUEVA LISTA (NO INCLUIDO)
 * \return LinkedList* RETORNA  (NULL) ERROR: SI EL PUNTERO A LA LISTAS ES NULL
 *                              O (SI EL INDICE FROM ES MENOR A 0 O MAYOR AL LEN DE LA LISTA)
 *                              O (SI EL INDICE TO ES MENOR O IGUAL A FROM O MAYOR AL LEN DE LA LISTA)
 *                                (PUNTERO A LA NUEVA LISTA) SI OK
*/
LinkedList* ll_subList(LinkedList* this,int from,int to);

/** \brief CREA Y RETORNA UNA NUEVA LISTA CON LOS ELEMENTOS DE LA LISTA PASADA COMO PARÁMETRO
 *
 * \param pList LinkedList* PUNTERO A LA LISTA
 * \return LinkedList* RETORNA  (NULL) ERROR: SI EL PUNTERO A LA LISTAS ES NULL
 *                              (PUNTERO A LA NUEVA LISTA) SI OK
*/
LinkedList* ll_clone(LinkedList* this);

/** \brief ORDENA LOS ELEMENTOS DE LA LISTA UTILIZANDO LA FUNCIÓN CRITERIO RECIBIDA COMO PARÁMETRO
 * \param pList LinkedList* PUNTERO A LA LISTA
 * \param pFunc (*pFunc) PUNTERO A LA FUNCIÓN CRITERIO
 * \param order int  [1] INDICA ORDEN ASCENDENTE - [0] INDICA ORDEN DESCENDENTE
 * \return int RETORNA  (-1) ERROR: SI EL PUNTERO A LA LISTAS ES NULL
 *                      ( 0) SI OK
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
