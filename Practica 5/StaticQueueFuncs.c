#include <stdio.h>
#include <stdlib.h>
#include "StaticQueue.h"


void crearPila(struct pila *pilaNueva){
    pilaNueva->tope=-1;
    printf("Pila creada\n");
}

int pop(struct pila *pilaPop){
    if(pilaPop->tope==-1){
        printf("Pila vacia\n");
        return -1;
    }else{
        printf("Elemento eliminado %d\n",pilaPop->elementos[pilaPop->tope]);
        pilaPop->tope--;
        return 0;
    }
}
int peek(struct pila *pilaPop){
    if(pilaPop->tope==-1){
        printf("Pila vacia\n");
        return -1;
    }else{
        printf("El tope es: %d\n",pilaPop->elementos[pilaPop->tope]);
        
        return pilaPop->elementos[pilaPop->tope];
    }
}

int push(struct pila *pilaPush,int nuevoDato){
    if(pilaPush->tope==9){
        printf("Pila llena\n");
        return -1;
    }else{
        pilaPush->tope++;
        pilaPush->elementos[pilaPush->tope]=nuevoDato;
    }
}   
