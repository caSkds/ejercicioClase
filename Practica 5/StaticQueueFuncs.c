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
int peek(struct pila *pilaPeek){
    if(pilaPeek->tope==-1){
        printf("Pila vacia\n");
        return -1;
    }else{
        printf("El tope es: %d\n",pilaPeek->elementos[pilaPeek->tope]);
        
        return pilaPeek->elementos[pilaPeek->tope];
    }
}
int full(struct pila *pilaFull){
    if (pilaFull->tope == 9){
        printf("Pila llena\n");
        return 1;
    }
    else{
        printf("Pila no llena \n");
        return 0;
    }
}
int empty(struct pila *pilaEmpty){
    if (pilaEmpty->tope == -1){
        printf("Pila vacía\n");
        return 1;
    }
    else{
        printf("Pila no vacía \n");
        return 0;
    }
}
int size(struct pila *pilaSize){
    int size = pilaSize->tope +1;
    printf("Tamaño de la pila: %d\n", size);
        return size;
    
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
