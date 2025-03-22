#ifndef DYNAMICQUEUE_H
#define DYNAMICQUEUE_H

#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int dato;
    struct nodo *siguiente;
};

struct cola {
    struct nodo *frente;
    struct nodo *final;
};

void crearCola(struct cola *);
int encolar(struct cola *, int);
int desencolar(struct cola *);
void verCola(struct cola *);
int front(struct cola *);
int empty(struct cola *);
int full(struct cola *);

#endif
