#include <stdio.h>
#include <stdlib.h>
#include "DynamicQueue.h"

void crearCola(struct cola *nuevaCola) {
    nuevaCola->frente = NULL;
    nuevaCola->final = NULL;
    printf("COLA CREADA\n");
}

int encolar(struct cola *colaEnqueue, int nuevoDato) {
    struct nodo *nuevoNodo = (struct nodo *)malloc(sizeof(struct nodo));
    if (nuevoNodo == NULL) {
        printf("NO SE ASIGNO MEMORIA PARA EL NODO\n");
        return -1;
    }
    nuevoNodo->dato = nuevoDato;
    nuevoNodo->siguiente = NULL;

    if (colaEnqueue->final == NULL) {
        colaEnqueue->frente = nuevoNodo;
    } else {
        colaEnqueue->final->siguiente = nuevoNodo;
    }
    colaEnqueue->final = nuevoNodo;
    return 0;
}

int desencolar(struct cola *colaDequeue) {
    if (colaDequeue->frente == NULL) {
        printf("COLA VACÍA\n");
        return -1;
    }
    struct nodo *nodoAux = colaDequeue->frente;
    colaDequeue->frente = nodoAux->siguiente;

    if (colaDequeue->frente == NULL) {
        colaDequeue->final = NULL;
    }
    free(nodoAux);
    return 0;
}

void verCola(struct cola *verCola) {
    printf("Datos de la cola:\n");
    struct nodo *verNodo = verCola->frente;
    while (verNodo != NULL) {
        printf("%d\n", verNodo->dato);
        verNodo = verNodo->siguiente;
    }
}

int front(struct Cola *colaFront) {
    if (empty(colaFront)) {
        printf("Cola vacia, no hay elemento en el frente\n");
        return -1;
    }
    return colaFront->head->dato;
}

void empty(struct cola *colaChecar) {
    if (colaChecar->frente == NULL) {
        printf("La cola esta vacia\n");
    } else {
        printf("La cola NO esta vacia\n");
    }
}

void full(struct cola *colaChecar) {
    struct nodo *nuevoNodo = (struct nodo *)malloc(sizeof(struct nodo));
    if (nuevoNodo == NULL) {
        printf("La cola está llena, sin memoria disponible\n");
    } else {
        printf("Todavía hay memoria disponible para más nodos\n");
        free(nuevoNodo);
    }
}
