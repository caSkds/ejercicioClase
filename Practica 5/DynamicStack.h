#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H

#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int dato;
    struct nodo *siguiente;
};

struct pila {
    struct nodo *tope;
};

void crearPila(struct pila *);
int push(struct pila *, int);
int pop(struct pila *);
void verPila(struct pila *);
void peek(struct pila *);
void empty(struct pila *);
void full(struct pila *);

#endif
