#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"

/** \brief  OBTIENE UN NODO DE LA LISTA
 *
 * \param this LinkedList* PUNTERO A LA LISTA
 * \param index int INDICE DEL NODO A OBTENER
 * \return Node* RETORNA (NULL) ERROR: SI EL PUNTERO A LA LISTA ES NULL O (SI EL INDICE ES MENOR A 0 O MAYOR AL LEN DE LA LISTA)
                         (PELEMENT) SI FUNCIONO CORRECTAMENTE
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex);

/** \brief AGREGA Y ENLAZA UN NUEVO NODO A LA LISTA
 *
 * \param this LinkedList* PUNTERO A LA LISTA
 * \param nodeIndex int UBICACION DONDE SE AGREGARA EL NUEVO NODO
 * \param pElement void* PUNTERO AL ELEMENTO A SER CONTENIDO POR EL NUEVO NODO
 * \return int RETORNA  (-1) ERROR: SI EL PUNTERO A LA LISTA ES NULL O (SI EL INDICE ES MENOR A 0 O MAYOR AL LEN DE LA LISTA)
                        ( 0) SI FUNCIONO CORRECTAMENTE
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement);


LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = (LinkedList *)malloc(sizeof(LinkedList));

    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }

    return this;
}


int ll_len(LinkedList* this)
{
    int returnAux=-1;

    if(this != NULL)
    {
        returnAux = this->size;
    }

    return returnAux;
}


static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode;
    int i;
    int cantidadLista;

    cantidadLista=ll_len(this);

    if(this != NULL && cantidadLista > 0)
    {
        if(nodeIndex >= 0 && nodeIndex < cantidadLista)
        {
            pNode = (Node*)malloc(sizeof(Node));

            if(nodeIndex == 0)
            {
                pNode = this->pFirstNode;
            }
            else
            {
                pNode = this->pFirstNode;
                for(i=0; i<nodeIndex; i++)
                {
                    pNode = pNode->pNextNode;
                }
            }
        }
    }
    else
    {
        pNode=NULL;
    }
    return pNode;
}


Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux;
    int cantidadLista;

    Node* pNode=NULL;
    Node* pNodeAnterior=NULL;
    Node* pNodeSiguiente=NULL;

    cantidadLista=ll_len(this);

    if(this!=NULL && nodeIndex>=0 && nodeIndex<=cantidadLista)
    {
        pNode=(Node*)malloc(sizeof(Node));
        pNodeAnterior=(Node*)malloc(sizeof(Node));
        pNodeSiguiente=(Node*)malloc(sizeof(Node));

        if(nodeIndex==0)
        {
            pNode->pNextNode=this->pFirstNode;
            this->pFirstNode=pNode;

            this->size++;
            returnAux=0;
        }
        else
        {
            pNodeAnterior=getNode(this, nodeIndex-1);
            pNodeSiguiente=getNode(this, nodeIndex);
            pNodeAnterior->pNextNode=pNode;
            pNode->pNextNode=pNodeSiguiente;

            this->size++;
            returnAux=0;
        }

        pNode->pElement=pElement;
    }
    else
    {
        returnAux=-1;
    }

    return returnAux;
}


int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


int ll_add(LinkedList* this, void* pElement)
{
    int returnAux;
    int ultimoIndex;

    ultimoIndex=ll_len(this);

    if(this!=NULL)
    {
        addNode(this, ultimoIndex, pElement);
        returnAux=0;
    }
    else
    {
        returnAux=-1;
    }

    return returnAux;
}


void* ll_get(LinkedList* this, int index)
{
    int cantidadLista;
    void* returnAux=NULL;
    Node* pNode=NULL;

    cantidadLista=ll_len(this);

    if(this!=NULL)
    {
        pNode=(Node*)malloc(sizeof(Node));

        if(index>=0&&index<cantidadLista)
        {
            pNode=getNode(this,index);
            returnAux=pNode->pElement;
        }
    }

    return returnAux;
}


int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux;
    int cantidadLista;
    Node* pNode=NULL;

    cantidadLista=ll_len(this);

    if(this!=NULL)
    {
        pNode=(Node*)malloc(sizeof(Node));

        if(index>=0&&index<cantidadLista)
        {
            pNode=getNode(this,index);
            pNode->pElement=pElement;
            returnAux = 0;
        }
        else
        {
            returnAux=-1;
        }
    }
    else
    {
        returnAux=-1;
    }

    return returnAux;

}


int ll_remove(LinkedList* this,int index)
{
    int returnAux;
    int cantidadLista;

    Node* pNode;
    Node* pNodeAnterior=NULL;
    Node* pNodeSiguiente=NULL;


    cantidadLista=ll_len(this);

    if(this!=NULL)
    {
        pNode=(Node*)malloc(sizeof(Node));
        pNodeAnterior=(Node*)malloc(sizeof(Node));
        pNodeSiguiente=(Node*)malloc(sizeof(Node));

        if(index>=0&&index<cantidadLista)
        {
            pNode=getNode(this,index);

            if(index==0)
            {
                this->pFirstNode=pNode->pNextNode;
                this->size--;
            }
            else
            {
                pNodeAnterior=getNode(this,index-1);
                pNodeSiguiente=getNode(this,index+1);
                pNodeAnterior->pNextNode=pNodeSiguiente;
                this->size--;

            }
            free(pNode);
            returnAux=0;
        }
        else
        {
            returnAux=-1;
        }
    }
    else
    {
        returnAux=-1;
    }

    return returnAux;
}


int ll_clear(LinkedList* this)
{
    int returnAux;
    int cantidadLista;
    int i=0;


    cantidadLista=ll_len(this);

    if(this!=NULL&&cantidadLista>0)
    {

        for(i=cantidadLista-1; i>=0; i--)
        {
            ll_remove(this,i);
        }

        returnAux = 0;
    }
    else
    {
        returnAux=-1;
    }

    return returnAux;
}


int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux;

    if(this!=NULL)
    {
        ll_clear(this);
        free(this);

        returnAux = 0;
    }
    else
    {
        returnAux=-1;
    }

    return returnAux;
}


int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux;
    int cantidadLista;
    int i;

    Node* pNode;

    cantidadLista=ll_len(this);

    if(this!=NULL)
    {
        pNode=(Node*)malloc(sizeof(Node));

        for(i=0; i<cantidadLista; i++)
        {
            pNode=getNode(this,i);

            if(pNode->pElement==pElement)
            {
                returnAux=i;
                break;
            }
            else
            {
                returnAux=-1;
            }
        }
    }
    else
    {
        returnAux=-1;
    }

    return returnAux;
}


int ll_isEmpty(LinkedList* this)
{
    int returnAux;
    int cantidadLista;

    if(this!=NULL)
    {
        cantidadLista=ll_len(this);

        if(cantidadLista==0)
        {
            returnAux=1;
        }
        else if(cantidadLista>0)
        {
            returnAux=0;
        }
    }
    else
    {
        returnAux=-1;
    }

    return returnAux;
}


int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux;
    int cantidadLista;

    cantidadLista=ll_len(this);

    if(this!=NULL)
    {
        if(index>=0&&index<=cantidadLista)
        {
            addNode(this, index, pElement);
            returnAux = 0;
        }
        else
        {
            returnAux=-1;
        }
    }
    else
    {
        returnAux=-1;
    }

    return returnAux;
}


void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int cantidadLista;

    cantidadLista=ll_len(this);

    if(this!=NULL)
    {
        if(index>=0&&index<cantidadLista)
        {
            returnAux=(void*)malloc(sizeof(void*));
            returnAux = ll_get(this, index);

            ll_remove(this, index);
        }
    }

    return returnAux;
}


int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux;
    int i;
    int cantidadLista;

    Node* pNode;

    cantidadLista=ll_len(this);

    returnAux=0;

    if(this!=NULL)
    {
        pNode=(Node*)malloc(sizeof(Node));

        for(i=0; i<cantidadLista; i++)
        {
            pNode=getNode(this, i);
            if(pNode->pElement==pElement)
            {
                returnAux=1;
                break;
            }
        }
    }
    else
    {
        returnAux=-1;
    }

    return returnAux;
}


int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux;
    int cantidadLista;
    int i;

    LinkedList* listaUno=this;
    LinkedList* listaDos=this2;
    Node* pNodeListaDos;

    cantidadLista=ll_len(this);

    if(listaUno!=NULL&&listaDos!=NULL)
    {

        pNodeListaDos=(Node*)malloc(sizeof(Node));

        for(i=0; i<cantidadLista; i++)
        {
            pNodeListaDos=getNode(listaDos,i);

            if(ll_contains(listaUno,pNodeListaDos->pElement)!=1)
            {
                returnAux=0;
                break;
            }
            else
            {
                returnAux=1;
            }
        }
    }
    else
    {
        returnAux=-1;
    }

    return returnAux;
}


LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    int cantidadLista;
    int i;
    LinkedList* cloneArray=NULL;
    Node* pNode=NULL;

    if(this!=NULL)
    {
        cantidadLista=ll_len(this);

        if(from>=0&&from<cantidadLista&&to>=0&&to<=cantidadLista&&to>from)
        {
            pNode=(Node*)malloc(sizeof(Node));
            cloneArray=ll_newLinkedList();

            for(i=from; i<to; i++)
            {
                pNode=ll_get(this,i);
                ll_add(cloneArray,pNode);
            }
        }
    }

    return cloneArray;
}


LinkedList* ll_clone(LinkedList* this)
{
    int cantidadLista;
    int i;
    LinkedList* cloneArray=NULL;
    Node* pNode=NULL;

    cantidadLista=ll_len(this);

    if(this!=NULL)
    {
        pNode=(Node*)malloc(sizeof(Node));
        cloneArray=ll_newLinkedList();

        for(i=0; i<cantidadLista; i++)
        {
            pNode=ll_get(this,i);
            ll_add(cloneArray,pNode);
        }
    }

    return cloneArray;
}


int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    int cantidadLista;
    int i;
    int retornoFuncion;
    int encontro;
    int anterior;
    int siguiente;
    void* pElementoUno;
    void* pElementoDos;

    if(this!=NULL&&pFunc!=NULL)
    {
        if(order>=0&&order<=1)
        {
            cantidadLista=ll_len(this);

            do
            {
                encontro=0;
                for(i=0; i<cantidadLista; i++)
                {
                    pElementoUno=(void*)malloc(sizeof(void*));
                    pElementoDos=(void*)malloc(sizeof(void*));

                    pElementoUno=ll_get(this,i);
                    pElementoDos=ll_get(this,i+1);

                    if(pElementoUno!=NULL&&pElementoDos!=NULL)
                    {
                        retornoFuncion=pFunc(pElementoUno, pElementoDos);

                        anterior=i;
                        siguiente=i+1;

                        switch(order)
                        {
                        case 0:
                            if(retornoFuncion==-1)
                            {
                                ll_set(this,anterior,pElementoDos);
                                ll_set(this,siguiente,pElementoUno);
                                encontro=1;
                            }
                            break;

                        case 1:
                            if(retornoFuncion==1)
                            {
                                ll_set(this,anterior,pElementoDos);
                                ll_set(this,siguiente,pElementoUno);
                                encontro=1;
                            }
                            break;
                        }
                    }
                }
            }
            while(encontro==1);

            returnAux=0;
        }
        else
        {
            returnAux=-1;
        }


    }
    else
    {
        returnAux=-1;
    }

    return returnAux;
}

