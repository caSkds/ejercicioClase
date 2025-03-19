#include<stdio.h>
#include<stdlib.h>
#include"StaticStack.h"

int main()
{
    struct pila pilaFI;
    int elemento,val;
    crearPila(&pilaFI);
    printf("Ingrese los 10 elementos de la pila:\n");
    for(int i=0;i<10;i++)
    {
        printf("Ingrese el elemento %i de la pila:",i+1);
        scanf("%i",&elemento);
        push(&pilaFI,elemento);
    }
    printf("Ingrese el valor por el que se van a multiplicar los valores de la pila:");
    scanf("%i",&val);
    printf("\nPila sin multiplicar:\n");
    for(int i=0;i<10;i++)
    {
        printf("%i\t",pilaFI.elementos[i]);
    }
    for(int i=0;i<10;i++)
    {
        pilaFI.elementos[i]=pilaFI.elementos[i]*val;
    }
    printf("\nPila multiplicada:\n");
    for(int i=0;i<10;i++)
    {
        printf("%i\t",pilaFI.elementos[i]);
    }
    return 0;
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

int push(struct pila *pilaPush,int nuevoDato){
    if(pilaPush->tope==10){
        printf("Pila llena\n");
        return -1;
    }else{
        pilaPush->tope++;
        pilaPush->elementos[pilaPush->tope]=nuevoDato;
    }
}
