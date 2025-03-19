#include<stdio.h>
#include<stdlib.h>
#include "DynamicQueue.h"

int main() 
{
    struct cola miCola, colaAux;
    crearCola(&miCola);
    crearCola(&colaAux);

    printf("Ingrese los elementos de la cola:\n");
    for(int i = 0; i < 16; i++) 
    {
        int elemento;
        printf("Ingrese el elemento %i:", i+1);
        scanf("%i", &elemento);
        encolar(&miCola, elemento);
    }

    printf("\nAntes del cambio:\n");
    verCola(&miCola);

    int primero = miCola.frente->dato;
    desencolar(&miCola);
    int segundo = miCola.frente->dato;
    desencolar(&miCola);

    for(int i = 0; i < 12; i++) 
    {
        int dato = miCola.frente->dato;
        desencolar(&miCola);
        encolar(&colaAux, dato);
    }

    int tercero = miCola.frente->dato;
    desencolar(&miCola);
    int cuarto = miCola.frente->dato;
    desencolar(&miCola);

    encolar(&miCola, tercero);
    encolar(&miCola, cuarto);

    while(colaAux.frente != NULL) 
    {
        int num = colaAux.frente->dato;
        desencolar(&colaAux);
        encolar(&miCola, num);
    }

    encolar(&miCola, primero);
    encolar(&miCola, segundo);

    printf("Intercambio:\n");
    verCola(&miCola);
    while (miCola.frente != NULL)
    {
        desencolar(&miCola);
	}
    return 0;
}


void crearCola(struct cola *nuevaCola) {
    nuevaCola->frente = NULL;
    nuevaCola->final = NULL;
    printf("COLA CREADA\n");
}

int encolar(struct cola *colaEnqueue, int nuevoDato) {
    struct nodo *nuevoNodo = (struct nodo *)malloc(sizeof(struct nodo));
    if (nuevoNodo == NULL) {
        printf("NO SE ASIGNÓ MEMORIA PARA EL NODO\n");
        return -1;
    }
    nuevoNodo->dato = nuevoDato;
    nuevoNodo->siguiente = NULL;

    if (colaEnqueue->final == NULL) {
        colaEnqueue->frente = nuevoNodo;
    } else {
        colaEnqueue->final->siguiente = nuevoNodo;
    }
    colaEnqueue->final = nuevoNodo;
    return 0;
}

int desencolar(struct cola *colaDequeue) {
    if (colaDequeue->frente == NULL) {
        printf("COLA VACÍA\n");
        return -1;
    }
    struct nodo *nodoAux = colaDequeue->frente;
    colaDequeue->frente = nodoAux->siguiente;

    if (colaDequeue->frente == NULL) {
        colaDequeue->final = NULL;
    }
    free(nodoAux);
    return 0;
}

void verCola(struct cola *verCola) {
    printf("Datos de la cola:\n");
    struct nodo *verNodo = verCola->frente;
    while (verNodo != NULL) {
        printf("%d\n", verNodo->dato);
        verNodo = verNodo->siguiente;
    }
}
