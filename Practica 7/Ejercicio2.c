#include <stdio.h>
#include <stdlib.h>
#include "ListaSimple.h"

void invertirLista(struct lista *);

int main()
{
    struct lista miLista; 
    crearLista(&miLista); 
  
    printf("Ingrese 7 elementos para la lista:\n"); 
    for (int i = 0; i < 7; i++) { 
        int dato; printf("Elemento %d: ", i + 1); 
        scanf("%d", &dato); 
        insertar(&miLista, dato); 
        } 
        
    
    printf("Lista original: \n"); 
    verLista(&miLista); 
    
    invertirLista(&miLista); 
    
    printf("Lista invertida: \n"); 
    verLista(&miLista); 
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

void invertirLista(struct lista *invertirLista) {
    struct nodo *previo = NULL;
    struct nodo *next = NULL;
    struct nodo *actual = invertirLista->head;

    while (actual != NULL) {
        //empezamos a recorrer los nodoss
        next=actual->siguiente; // guuardamos el siguiente nodo
        actual->siguiente=previo; // Invertimos lo que es el conector
        previo=actual;              
        actual=next;           
    }
    
    invertirLista->head = previo; // El nuevo head es el último nodo original
}
