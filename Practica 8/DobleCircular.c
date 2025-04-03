#include <stdio.h>
#include <stdlib.h>
#include "ListaDobleCircular.h"


void crearLista(struct lista *nuevaLista){
    nuevaLista->head=NULL;
    nuevaLista->size=0;
}

int insertar(struct lista *insertarLista, int nuevoDato){
    struct nodo *nuevoNodo=(struct nodo *)malloc(sizeof(struct nodo));
    if(nuevoNodo==NULL){
        return -1;
    }
    nuevoNodo->dato=nuevoDato;
    if(insertarLista->head==NULL){
        insertarLista->head=nuevoNodo;
        insertarLista->head->siguiente=insertarLista->head;
        insertarLista->head->anterior=insertarLista->head;
    }else{
        insertarLista->head->anterior=nuevoNodo;
        nuevoNodo->siguiente=insertarLista->head;
        insertarLista->head=nuevoNodo;
    }
    insertarLista->size++;
    return 0;
}
int buscar(struct lista *buscarLista, int buscarDato){
    struct nodo *buscarNodo=(struct nodo*)malloc(sizeof(struct nodo));
    if(buscarNodo==NULL || buscarLista->head==NULL){
        return -1;
    }
    int iterations =0;
    buscarNodo = buscarLista->head;
    buscarNodo-> dato = buscarDato;
    do{
        if(buscarNodo->dato==buscarDato){
        return buscarNodo->dato;
        iterations++;
    }}
    while(iterations<buscarLista->size);
    return -1;
}

struct nodo * buscarNodo(struct lista *buscarLista, int buscarDato){
    struct nodo *buscarNodo=(struct nodo*)malloc(sizeof(struct nodo));
    if(buscarNodo==NULL || buscarLista->head==NULL){
        return NULL;
    }
    int iterations =0;
    buscarNodo = buscarLista->head;
    buscarNodo-> dato = buscarDato;
    do{
        if(buscarNodo->dato==buscarDato){
        return buscarNodo;
        iterations++;
    }}
    while(iterations<buscarLista->size);
    return NULL;
}

int sizeLista(struct lista *sizeLista){
    return sizeLista->size;
}