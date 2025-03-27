#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H 
#include<stdio.h>
#include<stdlib.h>

struct nodo{
    int dato;
    struct nodo *siguiente;
};

struct lista{
    struct nodo *head;
};

//operaciones 
void crearLista(struct lista *);
int insertar(struct lista *,int);
int buscar(struct lista *,int);
int borrar(struct lista *,int);
void verLista(struct lista *);




#endif