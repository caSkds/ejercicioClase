#include <stdio.h>
#include <stdlib.h>
#include "DynamicStack.h"

void crearPila(struct pila *nuevaPila) {
    nuevaPila->tope = NULL;
    printf("PILA CREADA\n");
}

int push(struct pila *pilaPush, int nuevoDato) {
    struct nodo *nuevoNodo = (struct nodo *)malloc(sizeof(struct nodo));
    if (nuevoNodo == NULL) {
        printf("NO SE ASIGNO MEMORIA PARA EL NODO\n");
        return -1;
    }
    nuevoNodo->dato = nuevoDato;
    nuevoNodo->siguiente = pilaPush->tope;
    pilaPush->tope = nuevoNodo;
    return 0;
}

int pop(struct pila *pilaPop) {
    if (pilaPop->tope == NULL) {
        printf("PILA VACIA \n");
        return -1;
    }
    struct nodo *nodoAux = pilaPop->tope;
    pilaPop->tope = nodoAux->siguiente;
    free(nodoAux);
    return 0;
}

void verPila(struct pila *verPila) {
    printf("Datos de la pila:\n");
    struct nodo *verNodo = verPila->tope;
    while (verNodo != NULL) {
        printf("%d\n", verNodo->dato);
        verNodo = verNodo->siguiente;
    }
}

void peek(struct pila *pilaPeek) {
    if (pilaPeek->tope == NULL) {
        printf("PILA VACIA\n");
    } else {
        printf("El valor en el tope de la pila es: %d\n", pilaPeek->tope->dato);
    }
}

void empty(struct pila *pilaChecar) {
    if (pilaChecar->tope == NULL) {
        printf("La pila está vacia\n");
    } else {
        printf("La pila NO esta vacia\n");
    }
}

void full(struct pila *pilaChecar) {
    struct nodo *nuevoNodo = (struct nodo *)malloc(sizeof(struct nodo));
    if (nuevoNodo == NULL) {
        printf("La pila esta llena, sin memoria disponible\n");
    } else {
        printf("Todavia hay memoria disponible para mas nodos\n");
        free(nuevoNodo);
    }
}
