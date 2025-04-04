#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H 
#include<stdio.h>
#include<stdlib.h>

struct nodo{
    int dato;
    struct nodo *siguiente;
    struct nodo *anterior;
};

struct lista{
    struct nodo *head;
    int size;
};  


void crearLista(struct lista *);  //ya está
int insertar(struct lista *,int,int); //ya está
int buscar(struct lista *,int,int);  //ya está
int borrar(struct lista *, int);
void verLista(struct lista *);
void verListaPosiciones(struct lista *);
struct nodo * buscarNodo(struct lista *,int, int); //ya está
int borrarIndice(struct lista *,int);
int sizeLista(struct lista *); //ya está
int vaciarLista(struct lista *); //ya está

#endif
