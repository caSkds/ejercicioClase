#include "ListaSimple.h"
#include <stdio.h>
#include <stdlib.h>
void crearLista(struct lista *nuevaLista){
    nuevaLista->head=NULL;
    printf("Lista creada\n");
}

int insertar(struct lista *insertarLista,int nuevoDato){
    struct nodo *nuevoNodo=(struct nodo *)malloc(sizeof(struct nodo));
    if(nuevoNodo==NULL){
        printf("No se asigno memoria\n");
        return -1;
    }
    nuevoNodo->dato=nuevoDato;
    
    //preguntamos si es el primer elemento 
    if(insertarLista->head==NULL){
        //vamos insertar el primer elemento
        insertarLista->head=nuevoNodo;
        nuevoNodo->siguiente=insertarLista->head;
    }else{
        //que ya hay nodos en la lista 
        //realizaremos una busqueda para saber quien es el primer nodos
        struct nodo *nodoAux=insertarLista->head;
        while(nodoAux->siguiente!=insertarLista->head){
            nodoAux=nodoAux->siguiente;
        }
        //si ya se encontro el nodoAux
        //imsertamos el nuevo elemento
        nuevoNodo->siguiente=insertarLista->head;
        //cambiamos la posicion de head
        insertarLista->head=nuevoNodo;
        //actualizando el valor de siguiente del primer nodo ingreso
        //o del nodo que este apuntando a head
        nodoAux->siguiente=insertarLista->head;
    }
    return 0;
}

int buscar(struct lista *buscarLista,int datoBuscar){
    if(buscarLista->head==NULL){
        printf("Lista vacia\n");
        return -1;
    }
    struct nodo *nodoAux = buscarLista->head;
    do{
        if(nodoAux->dato==datoBuscar){
            printf("Dato encontrado\n");
            return nodoAux->dato;
        }
        nodoAux=nodoAux->siguiente;
    }while(nodoAux != buscarLista->head);
    printf("Dato no encontrado\n");
    return -1;
}

int borrar(struct lista *borrarLista,int datoBorrar){
    //verificamos que no este vacia
    if(borrarLista->head==NULL){
        printf("Lista vacia\n");
        return -1;
    }
    
    //creamos dos nodos
    struct nodo *nodoEliminar=borrarLista->head;
    struct nodo *nodoPrevio=NULL;
    
    do{
        //primer buscamos el dato a nodoEliminar
        if(nodoEliminar->dato==datoBorrar){
            //si el nodo a eliminar esta apuntado head
            if(nodoEliminar == borrarLista->head){
                //verificamos si es un unico elemento
                if(nodoEliminar->siguiente == nodoEliminar){
                    //si sí es el unico elemento
                    borrarLista->head=NULL;
                }else{
                    //buscamos el elemento que en su variable
                    //siguiente apunte a head
                    struct nodo *nodoTem = borrarLista->head;
                    while(nodoTem->siguiente!=borrarLista->head){
                        nodoTem=nodoTem->siguiente;
                    }
                    borrarLista->head=nodoEliminar->siguiente;
                    nodoTem->siguiente=borrarLista->head;
                }
                
            }else{
                nodoPrevio->siguiente=nodoEliminar->siguiente;
            }
            free(nodoEliminar);
            return 0;
        }
        
        nodoPrevio=nodoEliminar;
        nodoEliminar=nodoEliminar->siguiente;
        
    }while(nodoEliminar!=borrarLista->head);
    return 0;
}

void verLista(struct lista *verLista){
    if(verLista->head==NULL){
        printf("Lista Vacia\n");
    }else{
        struct nodo *verNodo=verLista->head;
        printf("Datos de la lista\n");
        do{
            printf("%d\n",verNodo->dato);
            verNodo=verNodo->siguiente;
        }while(verNodo!=verLista->head);
    }
    printf("\n");
    
}

int size(struct lista *tamLista)
{
    int tam=0;
    if(tamLista->head==NULL)
    {
        printf("Lista vacia\n");
        return -1;
    }
    struct nodo *nodoTam=tamLista->head;
    do
    {
        tam++;
        nodoTam=nodoTam->siguiente;
    }while(nodoTam !=tamLista->head);
    return tam;
}

void borrarIndice(struct lista* indiceLista, int indice)
{
    if(indiceLista->head==NULL)
    {
        printf("Lista vacia\n");
    }
    struct nodo *nodoEliminar=indiceLista->head;
    struct nodo *nodoPrevio=NULL;
    for(int i=0;i<=indice;i++)
    {
        if(i==indice)
        {
            if(nodoEliminar==indiceLista->head)
            {
                indiceLista->head=nodoEliminar->siguiente;
            }
            else
            {
                nodoPrevio->siguiente=nodoEliminar->siguiente;
            }
            free(nodoEliminar);
        }
        nodoPrevio=nodoEliminar;
        nodoEliminar=nodoEliminar->siguiente;
    }

}
