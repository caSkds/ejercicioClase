#include <stdio.h>
#include <stdlib.h>
#include "DynamicStack.h"
int main()
{
    struct pila pila1;
    int dato;
    crearPila(&pila1);
    printf("Ingrese 15 elementos para la pila dinamica:\n");
    for(int i=0;i<15;i++)
    {
        printf("Ingrese el nuevo dato:\n");
        scanf("%i",&dato);
        push(&pila1,dato);
    }
    verPila(&pila1);
    struct nodo *nodoAux1;
    struct nodo *nodoAux2;
    int aux;
    for(int i=0;i<14;i++)
    {
        nodoAux1=pila1.tope;
        nodoAux2=nodoAux1->siguiente;
        for(int j=0;j<14-i;j++)
        {
            if(nodoAux1->dato>nodoAux2->dato)
            {
                aux=nodoAux1->dato;
                nodoAux1->dato=nodoAux2->dato;
                nodoAux2->dato=aux;
            }
            nodoAux1=nodoAux1->siguiente;
            nodoAux2=nodoAux2->siguiente;
        }
    }
    printf("Pila ordenada:\n");
    verPila(&pila1);
    while(pila1.tope!=NULL)
    {
    	pop(&pila1);
	}
    return 0;
}
void crearPila(struct pila *nuevaPila) {
    nuevaPila->tope = NULL;
    printf("PILA CREADA\n");
}

int push(struct pila *pilaPush, int nuevoDato) {
    struct nodo *nuevoNodo = (struct nodo *)malloc(sizeof(struct nodo));
    if (nuevoNodo == NULL) {
        printf("NO SE ASIGNÓ MEMORIA PARA EL NODO\n");
        return -1;
    }
    nuevoNodo->dato = nuevoDato;
    nuevoNodo->siguiente = pilaPush->tope;
    pilaPush->tope = nuevoNodo;
    return 0;
}

int pop(struct pila *pilaPop) {
    if (pilaPop->tope == NULL) {
        printf("PILA VACÍA\n");
        return -1;
    }
    struct nodo *nodoAux = pilaPop->tope;
    pilaPop->tope = nodoAux->siguiente;
    free(nodoAux);
    return 0;
}

void verPila(struct pila *verPila) {
    printf("Datos de la pila:\n");
    struct nodo *verNodo = verPila->tope;
    while (verNodo != NULL) {
        printf("%d\n", verNodo->dato);
        verNodo = verNodo->siguiente;
    }
}
