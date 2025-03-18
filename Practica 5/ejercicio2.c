#include<stdio.h>
#include<stdlib.h>
#include"StaticStack.h"

void multiplicar(struct pila *pilaMultiplicar)
{

}

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


int size(struct pila *pilaSize){
    int stackSize = pilaSize->tope +1;
    printf("Tamaño de la pila: %d\n", stackSize);
        return stackSize;

}

int push(struct pila *pilaPush,int nuevoDato){
    if(pilaPush->tope==10){
        printf("Pila llena\n");
        return -1;
    }else{
        pilaPush->tope++;
        pilaPush->elementos[pilaPush->tope]=nuevoDato;
    }
}


int main()
{
    struct pila pilaFI;
    int elemento;
    crearPila(&pilaFI);
    printf("Ingrese los 10 elementos de la pila:\n");
    for(int i=0;i<10;i++)
    {
        printf("Ingrese el elemento %i de la pila:",i+1);
        scanf("%i",&elemento);
        push(&pilaFI,elemento);
    }

}
