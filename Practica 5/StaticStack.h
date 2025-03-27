#ifndef STATIC_STACK_H
#define STATIC_STACK_H
#include<stdio.h>  
#include <stdlib.h>
struct pila{
    int elementos[10];
    int tope;
};
void crearPila(struct pila *);
int pop(struct pila *);
int push(struct pila *,int);
int peek(struct pila *pilaPeek);
int full(struct pila *pilaFull);
int empty(struct pila *pilaEmpty);
int size(struct pila *pilaSize);



#endif