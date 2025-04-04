#include <stdio.h>
#include <stdlib.h>
#include "ListaDobleCircular.h"


void crearLista(struct lista *nuevaLista){
    nuevaLista->head=NULL;
    nuevaLista->size=0;
}

int insertar(struct lista *insertarLista, int nuevoDato, int errorMsg){
    struct nodo *nuevoNodo=(struct nodo *)malloc(sizeof(struct nodo));
    if(nuevoNodo==NULL){
        if(errorMsg ==1){
            printf("No se pudo asignar memoria\n");
        }
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
int buscar(struct lista *buscarLista, int buscarDato, int errorMsg){
    struct nodo *buscarNodo=(struct nodo*)malloc(sizeof(struct nodo));
    if(buscarNodo==NULL || buscarLista->head==NULL){
        if(errorMsg ==1){
            printf("No se pudo asignar memoria\n");
        }
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
    
    if(errorMsg ==1){
            printf("Elemento no encontrado\n");
        }
    return -1;
}


struct nodo * buscarNodo(struct lista *buscarLista, int buscarDato, int errorMsg){
    struct nodo *buscarNodo=(struct nodo*)malloc(sizeof(struct nodo));
    if(buscarNodo==NULL || buscarLista->head==NULL){
        if(errorMsg ==1){
            printf("Lista vacía\n");
        }
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
    if(errorMsg ==1){
        printf("Nodo no enontrado\n");
    }
    return NULL;
}

int sizeLista(struct lista *sizeLista){
    return sizeLista->size;
}

int vaciarLista(struct lista *vaciarLista){
    if (vaciarLista->head == NULL) {
        printf("La lista esta vacia \n");
        return -1;
    }

    struct nodo *actual = vaciarLista->head;
    struct nodo *temp;

    do {
        temp = actual->siguiente;
        free(actual);
        actual = temp;
    } while (actual != vaciarLista->head);

    vaciarLista->head = NULL;
    vaciarLista->size = 0;

    return 0;
}