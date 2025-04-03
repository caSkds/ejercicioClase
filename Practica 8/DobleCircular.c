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
        insertarLista->head->siguiente=nuevoNodo;
        insertarLista->head->anterior=nuevoNodo;
    }else{
        struct nodo *nodoAux=insertarLista->head;
        while(nodoAux->siguiente!=insertarLista->head){
            nodoAux=nodoAux->siguiente;
        }
        insertarLista->head->anterior=nuevoNodo;
        nuevoNodo->siguiente=insertarLista->head;
        insertarLista->head=nuevoNodo;
        nodoAux->siguiente=insertarLista->head;
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

void verLista(struct lista *listaVer){
    if(listaVer->head==NULL){
        printf("La lista esta vacia\n");
    }else{
        struct nodo *verNodo = listaVer->head;
        printf("%d\n",verNodo->dato);
        
        printf("Datos en la lista \n");
        do{
            printf("%d\n",verNodo->dato);
            verNodo=verNodo->siguiente;
        }while(verNodo!=listaVer->head);
    }
    printf("\n");
}

void verListaPosiciones(struct lista *listaVer){
    if(listaVer->head==NULL){
        printf("La lista esta vacia\n");
    }else{
        struct nodo *verNodo = listaVer->head;
        int indice=listaVer->size;
        printf("Datos en la lista \n");
        do{
            printf("posicion:%d dato:%d\n",indice,verNodo->dato);
            verNodo=verNodo->siguiente;
            indice --;
        }while(verNodo!=listaVer->head);
    }
    printf("\n");
}


int borrarIndice(struct lista *listaBorrar, int indiceBorrar) {
    if (listaBorrar->head == NULL) {
        printf("Lista vacía\n");
        return -1;
    }

    int tamano = listaBorrar->size;


    if (indiceBorrar < 0) { //ajustar indice a positivo
        indiceBorrar = tamano + indiceBorrar;  // desde final
    }

    indiceBorrar = (indiceBorrar % tamano + tamano) % tamano; //ajustar para que indice sea "valido"

    struct nodo *actual = listaBorrar->head;
    int contador = 0;

    while (contador < indiceBorrar) {
        actual = actual->siguiente;
        contador++;
    }

    struct nodo *nodoEliminar = actual;

 
    if (nodoEliminar == listaBorrar->head) {    // Si el nodo a borrar es el head
        listaBorrar->head = nodoEliminar->siguiente;
    }

    nodoEliminar->anterior->siguiente = nodoEliminar->siguiente;
    nodoEliminar->siguiente->anterior = nodoEliminar->anterior;

    if (nodoEliminar->siguiente == nodoEliminar) {   // Si solo había un nodo, la lista estará vacía ahora
        listaBorrar->head = NULL;
    }

    free(nodoEliminar);
    listaBorrar->size--;  // Reducir el tamaño de la lista
    return 0;
}
