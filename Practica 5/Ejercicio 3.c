#include<stdio.h>
#include<stdlib.h>
#include"StaticStack.h"

int i,j,r;
int main()
{
    int num,aux;
    struct pila Pila;
    crearPila(&Pila);
    for(i=0;i<8;i++)
    {
    printf("Ingrese el %d valor:\t",i+1);
    scanf("%d",&num);
    push(&Pila,num);
    }
    
    printf("Pila ingresada\n");
    ver(&Pila);
    
    invertir(&Pila);
    
    printf("Pila invertida:\n");
    ver(&Pila);
    
    return 0;
}

void crearPila(struct pila *pilaNueva)
{
    pilaNueva->tope=-1;
    printf("Pila creada\n");
}

int pop(struct pila *pilaPop)
{
    if(pilaPop->tope==-1)
    {
        printf("Pila vacia\n");
        return -1;
    }else{
        printf("Elemento eliminado %d\n",pilaPop->elementos[pilaPop->tope]);
        pilaPop->tope--;
        return 0;
    }
}

int push(struct pila *pilaPush,int nuevoDato)
{
    if(pilaPush->tope==7)
    {
        printf("Pila llena\n");
        return -1;
    }else{
        pilaPush->tope++;
        pilaPush->elementos[pilaPush->tope]=nuevoDato;
        printf("Dato ingresado correctamente\n");
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

void invertir(struct pila *pilaInvertir) {
    int valor;
    struct pila auxPila, auxPila2;
    crearPila(&auxPila);
    crearPila(&auxPila2);

    while (pilaInvertir->tope != -1) {
        valor = peek(pilaInvertir);
        push(&auxPila, valor);
        pop(pilaInvertir);
    }

    while (auxPila.tope != -1) {
        valor = peek(&auxPila);
        push(&auxPila2, valor);
        pop(&auxPila);
    }

    while (auxPila2.tope != -1) {
        valor = peek(&auxPila2);
        push(pilaInvertir, valor);
        pop(&auxPila2);
    }
}

void ver(struct pila *pilaVer)
{
    for(i=pilaVer->tope;i>=0;i--)
    {
        printf("%d\n",pilaVer->elementos[i]);
    }
}
