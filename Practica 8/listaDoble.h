#ifndef LISTADOBLE_H
#define LISTADOBLE_H

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

//operaciones

void crearLista(struct lista *);
int insertar(struct lista *,int);
int buscar(struct lista *,int);
int borrar(struct lista *, int);
void verLista(struct lista *);
void verListaPosiciones(struct lista *);
struct nodo * buscarNodo(struct lista *,int);
int borrarIndice(struct lista *,int);
int sizeLista(struct lista *);
int insertarCualquierInidice(struct lista*, int, int,int);
int vaciarLista(struct lista*);
#endif
