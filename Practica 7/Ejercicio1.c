#include <stdio.h>
#include <stdlib.h>
#include "ListaSimple.h"




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
    nuevoNodo->siguiente=insertarLista->head;
    insertarLista->head=nuevoNodo;
    return 0;
}

int buscar(struct lista *buscarLista,int datoBuscar){
    if(buscarLista->head==NULL){
        printf("Lista vacia\n");
        return -1;
    }
    struct nodo *nodoAux = buscarLista->head;
    while(nodoAux!=NULL){
        if(nodoAux->dato==datoBuscar){
            printf("Dato encontrado\n");
            return nodoAux->dato;
        }
        nodoAux=nodoAux->siguiente;
    }
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
    
    //buscar los elementos
    while(nodoEliminar != NULL && nodoEliminar->dato != datoBorrar){
        nodoPrevio=nodoEliminar;
        nodoEliminar=nodoEliminar->siguiente;
    }
    
    if(nodoEliminar==NULL){
        //si no esta el elemento buscado 
        printf("No esta el elemento\n");
        return -1;
    }
    //Si es el primer elemento lista que ingreso
    if(nodoEliminar == borrarLista->head){
        borrarLista->head=nodoEliminar->siguiente;
    }else{
        nodoPrevio->siguiente=nodoEliminar->siguiente;
    }
    free(nodoEliminar);
    return 0;
}

void verLista(struct lista *verLista){
    if(verLista->head==NULL){
        printf("Lista Vacia\n");
    }else{
        struct nodo *verNodo=verLista->head;
        printf("Datos de la lista\n");
        while(verNodo != NULL){
            printf("%d\n",verNodo->dato);
            verNodo=verNodo->siguiente;
        }
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

    while(nodoTam !=NULL)
    {
        tam++;
        nodoTam=nodoTam->siguiente;
    }
    return tam;
}

int insertarIndice(struct lista *nuevaLista, int nuevoDato, int posicion){
    if(posicion>size(nuevaLista)){
        printf("Posicion fuera de rango\n");
        return -1;
    }
    struct nodo *nuevoNodo=(struct nodo *)malloc(sizeof(struct nodo));
    if(nuevoNodo==NULL){
        printf("No se pudo asignar memoria al nodo\n");
        return -1;
    }
    //si si se asigno memoria
    nuevoNodo->dato=nuevoDato;
    nuevoNodo->siguiente=NULL;
    if(posicion==0){
        nuevoNodo->siguiente=nuevaLista->head;
        nuevaLista->head=nuevoNodo;
    }else{
        struct nodo *nodoAuxiliar=nuevaLista->head;
        for(int i=0;i<posicion-1;i++){
            nodoAuxiliar=nodoAuxiliar->siguiente;
            if(nodoAuxiliar==NULL){
                printf("Posicion fuera de rango\n");
                return -1;
            }
        }
        nuevoNodo->siguiente=nodoAuxiliar->siguiente;
        nodoAuxiliar->siguiente=nuevoNodo;
    }
    return 0;
}
int insertarFinal(struct lista *insertarLista, int nuevoDato) {
    struct nodo *nuevoNodo = (struct nodo *)malloc(sizeof(struct nodo));
    nuevoNodo->dato = nuevoDato;
    nuevoNodo->siguiente = NULL;

    if (insertarLista->head == NULL) {  
        // En caso de que no haya datpos en la lista
        insertarLista->head = nuevoNodo;
    } else {
        struct nodo *nodoAux = insertarLista->head;
        while (nodoAux->siguiente != NULL) {  
            // recorremos hasta encontrar el último nodo
            nodoAux = nodoAux->siguiente;
        }
        nodoAux->siguiente = nuevoNodo;  
    }
    return 0;
}

void borrarIndice(struct lista* indiceLista, int indice)
{
    if(indiceLista->head==NULL)
    {
        printf("Lista vacia\n");
    }
    struct nodo *nodoEliminar=indiceLista->head;
    struct nodo *nodoPrevio=NULL;
    int aux=size(indiceLista);
    for(int i=aux-1;i>=indice;i--)
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
