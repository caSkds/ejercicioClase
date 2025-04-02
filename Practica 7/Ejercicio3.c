#include<stdio.h>
#include<stdlib.h>
#include "ListaSimple.h"

int concatenarParesImpares(struct lista *, struct lista *, struct lista *);

int main()
{
    struct lista lista1, lista2, listaConcatenada;
    int num; 
    crearLista(&lista1); 
    crearLista(&lista2); 
    crearLista(&listaConcatenada);
    
    printf("Ingrese 7 elementos para la primera lista: \n"); 
    for (int i = 0; i < 7; i++){
        printf("Ingrese el elemento %d: ", i+1); 
        scanf("%d", &num); 
        insertar(&lista1, num); 
    } 

    printf("Ingrese 7 elementos para la segunda lista:\n"); 
    for (int i = 0; i < 7; i++) {
        printf("Ingrese el elemento %d: ", i+1); 
        scanf("%d", &num); 
        insertar(&lista2, num); 
    } 
    printf("LISTA 1: \n"); 
    verLista(&lista1);
     
    printf("LISTA 2: \n"); 
    verLista(&lista2); 
    
    concatenarParesImpares(&lista1, &lista2, &listaConcatenada);
    
    printf("LISTA CONCATENADA (pares primero, impares despues): \n"); 
    verLista(&listaConcatenada); 
    
    return 0;
}

void crearLista(struct lista *nuevaLista){
    nuevaLista->head=NULL;
    printf("LISTA CREADA \n");
}

int insertar(struct lista *insertarLista, int nuevoDato){
    struct nodo *nuevoNodo=(struct nodo *)malloc(sizeof(struct nodo));
    if(nuevoNodo==NULL){
        printf("No se asigno memoria \n");
        return -1;
    }
    nuevoNodo->dato=nuevoDato;
    nuevoNodo->siguiente=insertarLista->head;
    insertarLista->head=nuevoNodo;
    return 0;
}

void verLista(struct lista *verLista){
    if(verLista->head==NULL){
        printf("Lista vacia \n");
    }else{
        struct nodo *verNodo=verLista->head;
        printf("Datos de salida \n");
        while(verNodo!=NULL){
            printf("%d \n", verNodo->dato);
            verNodo=verNodo->siguiente;
        }
        printf("\n");
    }

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
    return 0;
}


int concatenarParesImpares(struct lista *listaUno, struct lista *listaDos, struct lista *listaConcatenada) {
    struct nodo *nodoAux = listaUno->head;
    
    // insertarmos pares de la primera lista
    while (nodoAux!= NULL) {
        if (nodoAux->dato % 2 == 0) {
            insertarFinal(listaConcatenada, nodoAux->dato);
        }
        nodoAux=nodoAux->siguiente;
    }

    // insertar pares de la segunda lista
    nodoAux= listaDos->head;
    while (nodoAux != NULL) {
        if (nodoAux->dato % 2 == 0) {
            insertarFinal(listaConcatenada, nodoAux->dato);
        }
        nodoAux=nodoAux->siguiente;
    }

    // insertr impares de la primera lista
    nodoAux = listaUno->head;
    while (nodoAux != NULL) {
        if (nodoAux->dato % 2 != 0) {
            insertarFinal(listaConcatenada, nodoAux->dato);
        }
        nodoAux=nodoAux->siguiente;
    }

    // insertams impares de la segunda lista
    nodoAux= listaDos->head;
    while (nodoAux!= NULL) {
        if (nodoAux->dato % 2 != 0) {
            insertarFinal(listaConcatenada, nodoAux->dato);
        }
        nodoAux = nodoAux->siguiente;
    }

    return 0;
}
