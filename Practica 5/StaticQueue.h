#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include<stdio.h>
#include <stdlib.h>
struct cola{
int elementos[10];
int head;
int tail;
int size;
};
//Firma
void crearCola(struct cola *);
int encolar(struct cola *,int);
int desencolar(struct cola *);
int front (struct cola *);
int empty (struct cola *);
int full (struct cola *);
int sizeC (struct cola *);


#endif